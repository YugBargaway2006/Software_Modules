# Copyright (c) Yug Bargaway under Apache License 2.0
# See LICENSE.txt for details.

"""
    Tokenization experiment for the Qwen3 model.

    This script demonstrates:

    1. Loading the Qwen3 tokenizer.
    2. Encoding text into token IDs.
    3. Inspecting individual tokens.
    4. Decoding token IDs back into text.
    5. Comparing tokenization across different inputs.

"""

from pathlib import Path 
from reasoning_from_scratch.qwen3 import Qwen3Tokenizer 


def load_tokenizer():
    tokenizer_path = Path("qwen3") / "tokenizer-base.json"
    tokenizer = Qwen3Tokenizer(
        tokenizer_file_path=tokenizer_path
    )

    return tokenizer 


def inspect_text(tokenizer, text):
    token_ids = tokenizer.encode(text)

    print("\n" + "-" * 60)
    print("Text: ")
    print(text)

    print("\nToken IDs: ")
    print(token_ids) 

    print("\nNumber of Tokens: ")
    print(len(token_ids))

    decoded_text = tokenizer.decode(token_ids)

    print("\n")
    for token_id in token_ids:
        token = tokenizer.decode([token_id])
        print(f"{token_id:>6} -> {repr(token)}")

    print("\nDecoded Text: ")
    print(decoded_text)

    return token_ids 


def main():
    tokenizer = load_tokenizer()

    texts = [
        "Hello, how are you?",
        "What is 17 x 24?",
        "Reasoning models generate tokens step by step",
        "<|endoftext|>"
    ]

    for text in texts:
        inspect_text(tokenizer, text)


if __name__ == "__main__":
    main()
