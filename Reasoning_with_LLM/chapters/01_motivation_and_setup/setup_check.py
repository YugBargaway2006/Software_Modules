import sys 

import torch 
import transformers 


def main():
    print("-" * 50)
    print("Reasoning from scratch - env check")
    print("-" * 50)

    print(f"Python       : {sys.version.split()[0]}")
    print(f"PyTorch      : {torch.__version__}")
    print(f"Transformers : {transformers.__version__}")

    print(f"CUDA available : {torch.cuda.is_available()}")

    if torch.cuda.is_available():
        print(f"GPU          : {torch.cuda.get_device_name(0)}")
        print(f"CUDA version : {torch.version.cuda}")
    else:
        print("GPU          : NOT AVAILABLE")

    print("-" * 50)
    print("Env check complete!")
    print("-" * 50)


if __name__ == "__main__":
    main()