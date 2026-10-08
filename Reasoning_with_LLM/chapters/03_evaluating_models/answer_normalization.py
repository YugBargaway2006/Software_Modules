# Copyright (c) Yug Bargaway under Apache License 2.0
# See LICENSE.txt for details.

"""
    Normalize an extracted answer before grading.

    Pipeline:

        Extracted answer
              |
              v
        Normalization
              |
              v
        Canonical answer

"""


def normalize_text(text):
    text = text.replace("−", "-")
    text = text.strip()

    return text


def main():
    examples = [
        ("408", "408"),
        (" 408 ", "408"),
        ("−1", "-1"),
        ("  −42  ", "-42"),
        ("Paris", "Paris"),
    ]

    for original, expected in examples:
        normalized = normalize_text(original)

        print("-" * 60)
        print("Original:")
        print(repr(original))

        print("Normalized:")
        print(repr(normalized))

        print("Expected:")
        print(repr(expected))

        print("Match:", normalized == expected)


if __name__ == "__main__":
    main()