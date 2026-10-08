# Copyright (c) Yug Bargaway under Apache License 2.0
# See LICENSE.txt for details.

"""
    Extract the final answer candidate from a generated response.

    Pipeline:

        Generated text
             |
             v
        Answer extraction
             |
             v
        Final candidate

"""

import re 


def extract_boxed_answers(text):
    answers = []
    marker = r"\boxed{"
    start = 0

    while True:
        start = text.find(marker, start)

        if start == -1:
            break

        i = start + len(marker)
        depth = 1

        while i < len(text) and depth > 0:
            if text[i] == "{":
                depth += 1
            elif text[i] == "}":
                depth -= 1

            i += 1

        if depth == 0:
            answer = text[start + len(marker):i - 1].strip()
            answers.append(answer)

        start = i

    return answers


import re


def extract_boxed_answers(text):
    """
    Extract contents of all \\boxed{...} expressions.

    Handles nested braces inside the boxed expression.
    """
    answers = []
    marker = r"\boxed{"
    start = 0

    while True:
        start = text.find(marker, start)

        if start == -1:
            break

        i = start + len(marker)
        depth = 1

        while i < len(text) and depth > 0:
            if text[i] == "{":
                depth += 1
            elif text[i] == "}":
                depth -= 1

            i += 1

        if depth == 0:
            answer = text[start + len(marker):i - 1].strip()
            answers.append(answer)

        start = i

    return answers


def extract_final_candidate(text):
    boxed_answers = extract_boxed_answers(text)    # Find boxed answers

    if boxed_answers:
        return boxed_answers[-1].strip()

    patterns = [
        r"(?:final answer|final result)\s*(?:is|:|-)?\s*"
        r"([-+]?\d+(?:,\d{3})*(?:\.\d+)?)",

        r"(?:answer)\s*(?:is|:|-)\s*"
        r"([-+]?\d+(?:,\d{3})*(?:\.\d+)?)",

        r"(?:therefore|thus|hence)[^.\n]*?"
        r"([-+]?\d+(?:,\d{3})*(?:\.\d+)?)",
    ]

    matches = []

    for pattern in patterns:
        matches.extend(re.findall(pattern, text, flags=re.IGNORECASE))

    if matches:
        return matches[-1].replace(",", "").strip()

    lines = [
        line.strip()
        for line in text.splitlines()
        if line.strip()
    ]

    if not lines:
        return ""

    last_line = lines[-1]

    match = re.search(
        r"[-+]?\d+(?:,\d{3})*(?:\.\d+)?",
        last_line,
    )

    if match:
        return match.group(0).replace(",", "").strip()

    return last_line


def main():
    examples = [
        r"""
        We calculate:
        17 × 24 = 408.

        \boxed{408}
        """,

        r"""
        Therefore the answer is:
        \boxed{-3}
        """,

        """
        Text around answer 42.
        """,

        """
        The answer is 7.
        """,
    ]

    for text in examples:
        candidate = extract_final_candidate(text)

        print("-" * 60)
        print("Generated text: ")
        print(text.strip())

        print("\nExtracted Candidate: ")
        print(candidate)


if __name__ == "__main__":
    main()