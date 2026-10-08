# Copyright (c) Yug Bargaway under Apache License 2.0
# See LICENSE.txt for details.

"""
    Grade an extracted answer against the ground truth.

    Pipeline:

        Generated text
             |
             v
        Extract answer
             |
             v
        Normalize answer
             |
             v
        Grade answer
             |
             v
        True / False

"""

from pathlib import Path 
import sys 
from importlib.util import spec_from_file_location, module_from_spec


CHAPTER_DIR = Path(__file__).resolve().parent 
sys.path.insert(0, str(CHAPTER_DIR))


def load_module(filename, module_name):
    path = CHAPTER_DIR / filename 

    spec = spec_from_file_location(module_name, path) 
    module = module_from_spec(spec) 
    spec.loader.exec_module(module) 

    return module 


extraction = load_module(
    "answer_extraction.py",
    "answer_extraction",
)

normalization = load_module(
    "answer_normalization.py",
    "answer_normalization",
)

extract_final_candidate = extraction.extract_final_candidate 
normalize_text = normalization.normalize_text 


def grade_answer(candidate, ground_truth):
    candidate = normalize_text(candidate)
    ground_truth = normalize_text(ground_truth)

    return candidate == ground_truth


def grade_response(response, ground_truth):
    candidate = extract_final_candidate(response)

    return grade_answer(candidate, ground_truth)


def run_demo():
    tests = [
        (
            "The answer is \\boxed{408}",
            "408",
            True,
        ),
        (
            "Therefore, \\boxed{−1}",
            "-1",
            True,
        ),
        (
            "The answer is \\boxed{42}",
            "42",
            True,
        ),
        (
            "The answer is \\boxed{15}",
            "12",
            False,
        ),
        (
            "Text around answer 3.",
            "3",
            True,
        ),
    ]

    print(
        f"{'Test':<10} | "
        f"{'Expected':<8} | "
        f"{'Got':<8} | "
        f"Status"
    )

    print("-" * 50)

    passed = 0

    for index, (response, ground_truth, expected) in enumerate(
        tests,
        start=1,
    ):
        got = grade_response(
            response,
            ground_truth,
        )

        status = "PASS" if got == expected else "FAIL"

        if status == "PASS":
            passed += 1

        print(
            f"check_{index:<4} | "
            f"{str(expected):<8} | "
            f"{str(got):<8} | "
            f"{status}"
        )

    print()
    print(f"Passed {passed}/{len(tests)}")


if __name__ == "__main__":
    run_demo()

