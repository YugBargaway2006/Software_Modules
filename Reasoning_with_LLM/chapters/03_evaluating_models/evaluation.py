# Copyright (c) Yug Bargaway under Apache License 2.0
# See LICENSE.txt for details.

"""
    Small evaluation harness for the answer verifier.

    Pipeline:

        Generated response
              |
              v
        Extract answer
              |
              v
        Normalize answer
              |
              v
        Compare with ground truth
              |
              v
        Evaluation result

"""

from pathlib import Path
import sys
from importlib.util import spec_from_file_location, module_from_spec
import torch 
from reasoning_from_scratch.qwen3 import Qwen3Model, Qwen3Tokenizer, QWEN_CONFIG_06_B, KVCache
from datasets import load_dataset


CHAPTER_DIR = Path(__file__).resolve().parent
sys.path.insert(0, str(CHAPTER_DIR))


def load_gsm8k_examples(num_examples=50):
    dataset = load_dataset(
        "openai/gsm8k",
        "main",
        split="test",
    ) 

    examples = []

    for item in dataset.select(range(num_examples)):
        # print(type(item["answer"]))
        # print(item["answer"])

        answer = item["answer"]
        ground_truth = answer.split("####")[-1].strip() 

        examples.append(
            {
                "problem": item["question"],
                "ground_truth":ground_truth,
            }
        )

    return examples


def load_module(filename, module_name):
    path = CHAPTER_DIR / filename

    spec = spec_from_file_location(
        module_name,
        path,
    )

    module = module_from_spec(spec)
    spec.loader.exec_module(module)

    return module


answer_grading = load_module(
    "answer_grading.py",
    "answer_grading",
)

grade_response = answer_grading.grade_response
extract_final_candidate = answer_grading.extract_final_candidate


def load_model_and_tokenizer():
    tokenizer_path = Path("qwen3") / "tokenizer-base.json"
    model_path = Path("qwen3") / "qwen3-0.6B-base.pth"

    tokenizer = Qwen3Tokenizer(
        tokenizer_file_path=tokenizer_path
    )

    device = torch.device(
        "cuda" if torch.cuda.is_available() else "cpu"
    )

    model = Qwen3Model(QWEN_CONFIG_06_B)

    model.load_state_dict(
        torch.load(
            model_path,
            map_location=device,
        )
    )

    model.to(device)
    model.eval()

    return model, tokenizer, device


def render_prompt(problem):
    template = (
        "You are a helpful math assistant.\n"
        "Solve the problem and write the final result on a new line as:\n"
        "\\boxed{ANSWER}\n\n"
        f"Problem:\n{problem}\n\n"
        "Answer:"
    )

    return template


@torch.inference_mode()
def generate_text(
    model,
    tokenizer,
    device,
    prompt,
    max_new_tokens=500,
):
    token_ids = tokenizer.encode(prompt)

    token_ids = torch.tensor(
        token_ids,
        dtype=torch.long,
        device=device,
    ).unsqueeze(0)

    cache = KVCache(
        n_layers=model.cfg["n_layers"]
    )

    model.reset_kv_cache()

    logits = model(
        token_ids,
        cache=cache,
    )

    logits = logits[:, -1, :]

    generated_tokens = []

    for _ in range(max_new_tokens):

        next_token = torch.argmax(
            logits,
            dim=-1,
            keepdim=True,
        )

        if next_token.item() == 151643:
            break

        generated_tokens.append(
            next_token.item()
        )

        logits = model(
            next_token,
            cache=cache,
        )

        logits = logits[:, -1, :]

    generated_text = tokenizer.decode(
        generated_tokens
    )

    return generated_text


def evaluate_model(
    model,
    tokenizer,
    device,
    examples,
    max_new_tokens=500,
):
    results = []

    for index, example in enumerate(examples, start=1):
        problem = example["problem"]
        ground_truth = example["ground_truth"]

        # print("-" * 80)
        # print(f"Example {index}/{len(examples)}")
        # print(f"Problem: {problem}")

        prompt = render_prompt(problem)

        generated_response = generate_text(
            model=model,
            tokenizer=tokenizer,
            device=device,
            prompt=prompt,
            max_new_tokens=max_new_tokens,
        )

        result = evaluate_example(
            problem=problem,
            generated_response=generated_response,
            ground_truth=ground_truth,
        )

        results.append(result)

        # print(f"Generated: {generated_response}")
        # print(f"Extracted: {result['extracted_answer']}")
        # print(f"Ground truth: {ground_truth}")
        # print(
        #     f"Status: "
        #     f"{'PASS' if result['correct'] else 'FAIL'}"
        # )

    return results


def evaluate_example(problem, generated_response, ground_truth):
    extracted_answer = extract_final_candidate(
        generated_response
    )

    correct = grade_response(
        generated_response,
        ground_truth,
    )

    return {
        "problem": problem,
        "generated_response": generated_response,
        "extracted_answer": extracted_answer,
        "ground_truth": ground_truth,
        "correct": correct,
    }


# def evaluate_examples(examples):
#     results = []

#     for example in examples:
#         result = evaluate_example(
#             problem=example["problem"],
#             generated_response=example["generated_response"],
#             ground_truth=example["ground_truth"],
#         )

#         results.append(result)

#     return results


def print_results(results):
    print("-" * 80)

    correct = 0

    for index, result in enumerate(results, start=1):

        if result["correct"]:
            correct += 1

        status = "PASS" if result["correct"] else "FAIL"

        print(f"\nExample {index}:")
        print(f"Problem: {result['problem']}")
        print(f"Generated: {result['generated_response']}")
        print(f"Extracted: {result['extracted_answer']}")
        print(f"Ground truth: {result['ground_truth']}")
        print(f"Status: {status}")

    accuracy = correct / len(results)

    print("\n" + "-" * 80)
    print(f"Correct: {correct}/{len(results)}")
    print(f"Accuracy: {accuracy:.2%}")


def main():
    # examples = [
    #     {
    #         "problem": "What is 17 x 24?",
    #         "ground_truth": "408",
    #     },
    #     {
    #         "problem": "What is 2 + 3?",
    #         "ground_truth": "5",
    #     },
    #     {
    #         "problem": "What is 10 - 4?",
    #         "ground_truth": "6",
    #     },
    #     {
    #         "problem": "What is 5 x 5?",
    #         "ground_truth": "25",
    #     },
    #     {
    #         "problem": "What is -1?",
    #         "ground_truth": "-1",
    #     },
    # ]

    # examples = [
    #     {"problem": "What is 17 x 24?", "ground_truth": "408"},
    #     {"problem": "What is 2 + 3?", "ground_truth": "5"},
    #     {"problem": "What is 10 - 4?", "ground_truth": "6"},
    #     {"problem": "What is 5 x 5?", "ground_truth": "25"},
    #     {"problem": "What is -1?", "ground_truth": "-1"},

    #     {"problem": "What is 12 + 15?", "ground_truth": "27"},
    #     {"problem": "What is 100 - 37?", "ground_truth": "63"},
    #     {"problem": "What is 8 x 7?", "ground_truth": "56"},
    #     {"problem": "What is 81 / 9?", "ground_truth": "9"},
    #     {"problem": "What is 25 + 36?", "ground_truth": "61"},

    #     {"problem": "What is 50 - 18?", "ground_truth": "32"},
    #     {"problem": "What is 9 x 6?", "ground_truth": "54"},
    #     {"problem": "What is 144 / 12?", "ground_truth": "12"},
    #     {"problem": "What is 7 + 19?", "ground_truth": "26"},
    #     {"problem": "What is 90 - 45?", "ground_truth": "45"},

    #     {"problem": "What is 13 x 4?", "ground_truth": "52"},
    #     {"problem": "What is 72 / 8?", "ground_truth": "9"},
    #     {"problem": "What is 33 + 29?", "ground_truth": "62"},
    #     {"problem": "What is 75 - 28?", "ground_truth": "47"},
    #     {"problem": "What is 11 x 11?", "ground_truth": "121"},
    # ]

    examples = load_gsm8k_examples(
        num_examples=10
    )

    model, tokenizer, device = load_model_and_tokenizer()

    results = evaluate_model(
        model=model,
        tokenizer=tokenizer,
        device=device,
        examples=examples,
        max_new_tokens=1000,
    )

    print_results(results)


if __name__ == "__main__":
    main()