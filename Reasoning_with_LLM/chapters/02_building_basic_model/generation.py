# Copyright (c) Yug Bargaway under Apache License 2.0
# See LICENSE.txt for details.

"""
    Basic autoregressive text generation with Qwen3.

    Pipeline:

        Text
        |
        Tokenizer
        |
        Token IDs
        |
        Qwen3
        |
        Logits
        |
        Select highest-probability token
        |
        Append token
        |
        Repeat

"""


from pathlib import Path
import torch
from reasoning_from_scratch.qwen3 import Qwen3Model, Qwen3Tokenizer, QWEN_CONFIG_06_B, KVCache


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
    # model = torch.compile(model)

    return model, tokenizer, device


@torch.inference_mode()
def generate_text(
    model,
    tokenizer,
    token_ids,
    max_new_tokens,
):

    cache = KVCache(
        n_layers=model.cfg["n_layers"]
    )

    model.reset_kv_cache()

    logits = model(
        token_ids,
        cache=cache,
    )

    logits = logits[:, -1, :]
    
    for _ in range(max_new_tokens):
        # Removed after introduction of the KVCache
        # logits = model(token_ids)        
        # logits = logits[:, -1, :]     # Keep only last token

        next_token = torch.argmax(
            logits,
            dim=-1,
            keepdim=True
        )

        if next_token.item() == 151643:
            break;

        # token_ids = torch.cat(
        #     [token_ids, next_token],
        #     dim=1,
        # )

        # Print the newly generated token
        token_text = tokenizer.decode(
            [next_token.item()]
        )
        print(token_text, end="", flush=True)

        # KVCache, process last logit
        logits = model(
            next_token,
            cache=cache,
        )

        logits = logits[:, -1, :]

    return token_ids


def main():
    model, tokenizer, device = load_model_and_tokenizer()
    prompts = [
        "What is 17 x 24?",
        "The capital of France is",
        "Machine learning is",
    ]

    for prompt in prompts:
        token_ids = tokenizer.encode(prompt)

        token_ids = torch.tensor(
            token_ids,
            dtype=torch.long,
            device=device,
        ).unsqueeze(0)

        print("-" * 50)
        print("Prompt: ")
        print(prompt)

        print("\nInput Token ids: ")
        print(token_ids)

        print("\nGenerated text: ")

        output_token_ids = generate_text(
            model=model,
            tokenizer=tokenizer,
            token_ids=token_ids,
            max_new_tokens=500,
        )

        print()
        print("-" * 50)
        print()


if __name__ == "__main__":
    main()