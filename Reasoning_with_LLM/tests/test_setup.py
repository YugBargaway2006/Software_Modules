import torch
import transformers


def test_pytorch_import():
    assert torch.__version__ is not None


def test_transformers_import():
    assert transformers.__version__ is not None


def test_reasoning_package_import():
    import reasoning

    assert reasoning is not None


def test_cuda_available():
    print(f"\nCUDA available: {torch.cuda.is_available()}")

    if torch.cuda.is_available():
        print(f"GPU: {torch.cuda.get_device_name(0)}")