# Copyright (c) Yug Bargaway under Apache License 2.0 (see LICENSE.txt)
# Source taken reference from for "Build a Reasoning Model (From Scratch)": https://mng.bz/lZ5B
# Code repository: https://github.com/YugBargaway2006/Software_Modules/Reasoning_with_LLM

"""
    Load the pretrained Qwen3 model and tokenizer and test its workings.

    1. Load Tokenizer
    2. Load Model
    3. Move model to appropriate device
    4. Print Model information
    5. Exit Successfully

"""

import torch 
from importlib.metadata import version 
from reasoning_from_scratch.qwen3 import download_qwen3_small
from pathlib import Path 
from reasoning_from_scratch.qwen3 import Qwen3Tokenizer
from reasoning_from_scratch.qwen3 import Qwen3Model, QWEN_CONFIG_06_B


def check_versions():
    used_libraries = [
        "reasoning_from_scratch",
        "torch",
        "tokenizers"
    ]

    for lib in used_libraries:
        print(f"{lib} version: {version(lib)}")


def get_device(enable_tensor_cores=True):
    if torch.cuda.is_available():
        device = torch.device("cuda")
        print("Using NVIDIA CUDA GPU")

        if enable_tensor_cores:
            major, minor = map(int, torch.__version__.split(".")[:2])
            # PyTorch 2.9 and 2.10 still reads the legacy TF32 setting in torch.compile
            # See https://github.com/pytorch/pytorch/issues/166387
            if (major, minor) >= (2, 11):
                torch.backends.cuda.matmul.fp32_precision = "tf32"
                torch.backends.cudnn.conv.fp32_precision = "tf32"
            else:
                torch.backends.cuda.matmul.allow_tf32 = True
                torch.backends.cudnn.allow_tf32 = True

    elif torch.backends.mps.is_available():
        device = torch.device("mps")
        print("Using Apple Silicon GPU (MPS)")

    elif torch.xpu.is_available():
        device = torch.device("xpu")
        print("Using Intel GPU")

    else:
        device = torch.device("cpu")
        print("Using CPU")

    return device


def print_model_info(model):
    total_params = sum(p.numel() for p in model.parameters())
    trainable_params = sum(
        p.numel()
        for p in model.parameters()
        if p.requires_grad
    )

    print("\n" + "-" * 50)
    print("Model Information")
    print("-" * 50)
    print(f"Model type       : {model.__class__.__name__}")
    print(f"Total parameters : {total_params:,}")
    print(f"Trainable params : {trainable_params:,}")
    print(f"Device           : {next(model.parameters()).device}")
    print(f"Dtype            : {next(model.parameters()).dtype}")

    if hasattr(model, "cfg"):
        print(f"Context length   : {model.cfg["context_length"]}")
        print(f"Embedding dim    : {model.cfg["emb_dim"]}")
        print(f"Layers           : {model.cfg["n_layers"]}")
        print(f"Attention heads  : {model.cfg["n_heads"]}")

    print("-" * 50)


def main():
    print(f"PyTorch Version {torch.__version__}")

    if torch.cuda.is_available():
        print(f"CUDA/ROCm GPU: {torch.cuda.get_device_name(0)}")
    elif torch.xpu.is_available():
        print(f"Intel GPU: {torch.xpu.get_device_name(0)}")
    elif torch.backends.mps.is_available():
        print("Apple Silicon GPU")
    else:
        print("Only CPU")


    download_qwen3_small(kind="base", tokenizer_only=True, out_dir="qwen3")

    tokenizer_path = Path("qwen3") / "tokenizer-base.json"
    tokenizer = Qwen3Tokenizer(tokenizer_file_path=tokenizer_path)

    device = get_device()

    download_qwen3_small(kind="base", tokenizer_only=False, out_dir="qwen3")

    model_path = Path("qwen3") / "qwen3-0.6B-base.pth"

    model = Qwen3Model(QWEN_CONFIG_06_B)
    model.load_state_dict(torch.load(model_path))

    model.to(device)

    print_model_info(model)


if __name__ == "__main__":
    check_versions()
    main()