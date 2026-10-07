from pathlib import Path 
from reasoning_from_scratch.qwen3 import Qwen3Tokenizer


TOKENIZER_PATH = Path("qwen3") / "tokenizer-base.json"


def load_tokenizer():
    return Qwen3Tokenizer(
        tokenizer_file_path=TOKENIZER_PATH
    )


def test_tokenizer_initialization():
    tokenizer = load_tokenizer()

    assert tokenizer is not None 


def test_tokenizer_encode():
    tokenizer = load_tokenizer()

    text = "Hello, how are you?"
    token_ids = tokenizer.encode(text)

    assert token_ids is not None 
    assert len(token_ids) > 0
    assert all(isinstance(token_id, int) for token_id in token_ids)


def test_tokenizer_decode():
    tokenizer = load_tokenizer()

    text = "Hello, how are you?"
    token_ids = tokenizer.encode(text)
    decoded_text = tokenizer.decode(token_ids)

    assert text == decoded_text

    