# From a Base LLM to an Efficient Reasoning Model

> **Topic:** Loading, understanding, implementing, and optimizing a pretrained LLM  
> **Model:** Qwen3  
> **Framework:** PyTorch  
> **Goal:** Build the foundations required to eventually train a language model for reasoning using reinforcement learning and other reasoning techniques.

---

## 1. Overview

A modern reasoning model is still fundamentally a **language model**.

Before attempting techniques such as:

- Reinforcement Learning (RL)
- Reinforcement Learning from Verifiable Rewards (RLVR)
- Chain-of-thought reasoning
- Supervised fine-tuning (SFT)
- Preference optimization
- Reward modeling

we first need to understand how a conventional pretrained LLM actually works.

The workflow in this chapter can be summarized as:

```text
Pretrained Model
      │
      ├── Load Model Weights
      │
      ├── Load Tokenizer
      │
      ▼
   Text Input
      │
      ▼
   Tokenization
      │
      ▼
 Integer Token IDs
      │
      ▼
 Transformer
      │
      ▼
 Next-Token Logits
      │
      ▼
 Token Selection
      │
      ▼
 Generated Token
      │
      └──────────────┐
                     │
                     ▼
              Feed Token Back
                     │
                     ▼
               Next Token
```

This process continues until a stopping condition is reached.

---

# 2. Why Start With a Base LLM?

A pretrained language model has already learned statistical relationships between tokens from a very large corpus.

However, a base model is not necessarily a reasoning model.

A useful conceptual distinction is:

```text
Base LLM
    │
    │ Predict next token
    ▼
Text Generation
```

versus:

```text
Reasoning Model
    │
    ├── Understand problem
    ├── Explore reasoning
    ├── Generate intermediate steps
    ├── Verify / evaluate
    └── Produce final answer
```

The purpose of this chapter is therefore **not yet to teach the model how to reason**.

Instead, the objective is to understand the inference machinery that reasoning techniques will eventually build upon.

---

# 3. Loading the Pretrained Model

The first step is obtaining:

1. The pretrained model weights.
2. The tokenizer associated with those weights.
3. The appropriate computational device.

A typical Hugging Face workflow looks conceptually like:

```python
from transformers import AutoTokenizer, AutoModelForCausalLM

model_name = "Qwen/Qwen3-..."

tokenizer = AutoTokenizer.from_pretrained(model_name)

model = AutoModelForCausalLM.from_pretrained(
    model_name
)
```

The exact model checkpoint depends on the experiment.

The important idea is that the **tokenizer and model must correspond to each other**.

---

# 4. Model Weights

A pretrained model contains millions or billions of numerical parameters.

These parameters are learned during pretraining.

Conceptually:

```text
Training Dataset
       │
       ▼
Tokenized Text
       │
       ▼
Transformer
       │
       ▼
Loss
       │
       ▼
Gradient Descent
       │
       ▼
Updated Parameters
```

After training, the resulting parameters are stored as model weights.

During inference, these weights are normally **frozen**.

```python
model.eval()
```

and gradients are disabled:

```python
with torch.no_grad():
    ...
```

or:

```python
with torch.inference_mode():
    ...
```

This prevents unnecessary gradient computation and reduces memory usage.

---

# 5. The Tokenizer

An LLM does not directly process strings such as:

```text
Hello, how are you?
```

Instead, text must first be converted into numerical representations.

The tokenizer performs approximately:

```text
Text
 │
 ▼
Tokens
 │
 ▼
Token IDs
```

For example:

```text
"Hello world"
```

might become something conceptually similar to:

```text
["Hello", " world"]
```

and then:

```text
[15339, 1917]
```

The exact tokens and IDs depend on the tokenizer.

---

# 6. Why Tokenization Is Necessary

Neural networks operate on numerical tensors.

Therefore, the model cannot directly receive:

```python
"Explain quantum mechanics"
```

Instead, the tokenizer converts it into integers:

```python
input_ids = tokenizer(
    "Explain quantum mechanics",
    return_tensors="pt"
)
```

Conceptually:

```text
"Explain quantum mechanics"
          │
          ▼
      Tokenizer
          │
          ▼
[ID_1, ID_2, ID_3, ...]
          │
          ▼
       Tensor
```

The IDs are indices into the model's vocabulary.

---

# 7. Tokenization Is Not Necessarily Word-Level

A common misconception is:

> One word = one token.

This is generally false.

Modern LLM tokenizers commonly use **subword tokenization** or related approaches.

For example, a word might be represented as:

```text
"unbelievable"
```

→

```text
"un"
"believ"
"able"
```

The exact decomposition depends on the tokenizer.

This allows the model to represent words that it has never encountered as complete units.

---

# 8. Vocabulary

The tokenizer maintains a vocabulary.

Conceptually:

```text
Token              ID
-----------------------
"hello"            15496
"world"             995
"ing"                ...
" the"               ...
```

The model's output layer ultimately produces a score for every possible vocabulary token.

If the vocabulary size is:

```text
V
```

then the output logits for one position have approximately:

```text
[V]
```

shape.

For a sequence:

```text
[batch_size, sequence_length]
```

the logits generally have shape:

```text
[batch_size, sequence_length, vocabulary_size]
```

---

# 9. Decoding

The reverse operation is decoding.

```text
Token IDs
    │
    ▼
Tokenizer
    │
    ▼
Text
```

For example:

```python
tokenizer.decode([15339, 1917])
```

might produce:

```text
"Hello world"
```

Therefore:

```text
Encoding:

Text → Tokens → IDs

Decoding:

IDs → Tokens → Text
```

These two operations form the interface between human-readable text and the numerical model.

---

# 10. The Transformer Receives Token IDs

The token IDs themselves are not directly meaningful to the transformer.

They are converted into embeddings.

Conceptually:

```text
Token ID
   │
   ▼
Embedding Table
   │
   ▼
Vector
```

For example:

```text
Token ID 15339
      │
      ▼
Embedding
      │
      ▼
[0.12, -0.48, 0.31, ...]
```

The embedding vector then passes through the transformer layers.

---

# 11. Autoregressive Language Modeling

The fundamental objective of a causal language model is:

> Given previous tokens, predict the next token.

Suppose the input is:

```text
The cat is
```

The model predicts a probability distribution over the next token:

```text
sat       → 0.42
sleeping  → 0.18
running   → 0.11
...
```

The model then selects one token.

Suppose:

```text
sat
```

is selected.

The sequence becomes:

```text
The cat is sat
```

The model is then used again to predict the next token.

---

# 12. Generation Is Iterative

This is one of the most important concepts in the entire chapter.

LLMs generate text **autoregressively**.

Consider:

```text
Input:
"The capital of France is"
```

The generation process can be visualized as:

```text
"The capital of France is"
              │
              ▼
          predict
              │
              ▼
           "Paris"
              │
              ▼
"The capital of France is Paris"
              │
              ▼
          predict
              │
              ▼
            ...
```

Each generated token becomes part of the input for the next prediction.

---

# 13. Next-Token Prediction

Suppose the sequence is:

```text
x₁, x₂, x₃, ..., xₜ
```

The model predicts:

```text
P(xₜ₊₁ | x₁, x₂, ..., xₜ)
```

After selecting the next token:

```text
xₜ₊₁
```

the model predicts:

```text
P(xₜ₊₂ | x₁, x₂, ..., xₜ, xₜ₊₁)
```

This continues recursively.

Therefore:

```text
x₁ → x₂ → x₃ → ... → xₙ
```

---

# 14. Logits

The model does not directly output probabilities.

It generally produces **logits**.

For example:

```text
Token       Logit
-----------------
Paris       8.2
London      4.7
Berlin      3.9
Rome        2.1
...
```

A softmax operation converts logits into probabilities:

\[
P(x_i) =
\frac{e^{z_i}}
{\sum_j e^{z_j}}
\]

where:

- \(z_i\) is the logit for token \(i\)
- \(P(x_i)\) is its probability

---

# 15. Greedy Decoding

One of the simplest token-selection strategies is **greedy decoding**.

The model chooses the token with the highest probability.

```python
next_token = logits.argmax(dim=-1)
```

Conceptually:

```text
Paris      0.72  ← SELECT
London     0.10
Berlin     0.07
Rome       0.04
...
```

Therefore:

```text
next_token = argmax(probabilities)
```

Greedy decoding is deterministic.

---

# 16. Why Greedy Decoding Is Useful Here

The purpose of this chapter is to understand the mechanics of generation.

Greedy decoding is therefore useful because it removes additional complexity.

Later, more sophisticated sampling techniques can be introduced:

- Temperature
- Top-k sampling
- Top-p / nucleus sampling
- Typical sampling
- Beam search
- Speculative decoding

But the fundamental generation loop remains similar.

---

# 17. Basic Generation Algorithm

The simplest generation algorithm is:

```text
1. Tokenize prompt
2. Run model
3. Obtain logits
4. Select next token
5. Append token
6. Repeat
7. Stop when EOS is produced
```

Pseudocode:

```python
tokens = tokenize(prompt)

for _ in range(max_new_tokens):

    logits = model(tokens)

    next_token = argmax(logits)

    tokens = append(tokens, next_token)

    if next_token == EOS:
        break

return decode(tokens)
```

This is the core of autoregressive generation.

---

# 18. Minimal PyTorch Generation Function

A simplified implementation looks like:

```python
import torch


def generate(model, tokenizer, prompt, max_new_tokens=100):

    inputs = tokenizer(
        prompt,
        return_tensors="pt"
    )

    input_ids = inputs["input_ids"]

    for _ in range(max_new_tokens):

        with torch.no_grad():

            outputs = model(input_ids)

        logits = outputs.logits

        next_token = logits[:, -1, :].argmax(
            dim=-1,
            keepdim=True
        )

        input_ids = torch.cat(
            [input_ids, next_token],
            dim=-1
        )

        if next_token.item() == tokenizer.eos_token_id:
            break

    return tokenizer.decode(
        input_ids[0],
        skip_special_tokens=True
    )
```

The important line is:

```python
logits[:, -1, :]
```

This selects the logits corresponding to the **last position**.

Those logits are used to predict the next token.

---

# 19. Understanding the Tensor Shapes

Suppose:

```text
batch_size = 1
sequence_length = 20
vocabulary_size = 151936
```

Then the model output might have shape:

```text
[1, 20, 151936]
```

The final position is:

```python
logits[:, -1, :]
```

giving:

```text
[1, 151936]
```

This represents the next-token scores.

Then:

```python
argmax(...)
```

selects one vocabulary index.

---

# 20. End-of-Sequence Token

Generation should not necessarily continue forever.

Models therefore have special tokens such as:

```text
EOS
```

meaning:

> End of Sequence

The generation loop can terminate when the model produces EOS.

```python
if next_token.item() == tokenizer.eos_token_id:
    break
```

There is also a maximum generation length:

```python
max_new_tokens
```

which provides a second safety mechanism.

Therefore:

```text
Stop if:

EOS generated
       OR
maximum number of tokens reached
```

---

# 21. The Problem With Naive Generation

The basic generation implementation works, but it is inefficient.

Suppose the prompt contains:

```text
100 tokens
```

and we want to generate:

```text
100 additional tokens
```

The naive approach repeatedly feeds the entire sequence through the transformer.

Conceptually:

```text
Step 1:
100 tokens → model

Step 2:
101 tokens → model

Step 3:
102 tokens → model

...

Step 100:
199 tokens → model
```

The model repeatedly processes information it has already seen.

This is wasteful.

---

# 22. Why This Is Expensive

Transformer self-attention involves interactions between tokens.

Without caching, previously processed tokens are repeatedly recomputed.

During generation:

```text
Existing tokens
      │
      ▼
Recompute attention
      │
      ▼
Generate next token
```

Then:

```text
Existing tokens + new token
      │
      ▼
Recompute attention again
```

The already-processed portion of the sequence has not changed.

Therefore, recomputing it is unnecessary.

---

# 23. Key-Value (KV) Caching

The solution is **KV caching**.

Transformer attention uses:

```text
Query (Q)
Key   (K)
Value (V)
```

Attention is approximately:

\[
Attention(Q,K,V)
=
softmax
\left(
\frac{QK^T}{\sqrt{d_k}}
\right)V
\]

For previously processed tokens, the Key and Value representations do not need to be recomputed during each generation step.

They can be stored.

---

# 24. What the KV Cache Stores

For each transformer layer, we maintain:

```text
Key Cache
Value Cache
```

Conceptually:

```text
Layer 1
 ├── K cache
 └── V cache

Layer 2
 ├── K cache
 └── V cache

...

Layer N
 ├── K cache
 └── V cache
```

At each generation step, the new token contributes a new K/V pair.

The cache becomes:

```text
Old K/V + New K/V
```

instead of recomputing:

```text
K/V for every previous token
```

---

# 25. Naive Generation vs KV Cache

### Without KV Cache

```text
Token 1
   ↓
Recompute

Token 1 + Token 2
   ↓
Recompute

Token 1 + Token 2 + Token 3
   ↓
Recompute

...
```

### With KV Cache

```text
Token 1
   ↓
Store K/V

Token 2
   ↓
Reuse old K/V
+
Compute only new K/V

Token 3
   ↓
Reuse old K/V
+
Compute only new K/V
```

This dramatically reduces redundant computation.

---

# 26. Complexity Intuition

For a sequence of length \(n\), self-attention involves interactions between tokens and has approximately quadratic dependence on sequence length:

\[
O(n^2)
\]

During autoregressive generation, repeatedly processing the entire prefix causes substantial redundant work.

KV caching avoids recomputing the K/V representations for previous tokens.

The effective per-token generation work becomes much more manageable and scales approximately linearly with the amount of cached context that must still participate in attention.

A useful intuition is:

```text
Without KV cache:

Recompute everything
─────────────────────
Every generation step

With KV cache:

Reuse previous computation
──────────────────────────
Compute only what changed
```

---

# 27. Implementing KV Cache

Modern transformer implementations generally expose a cache mechanism.

Conceptually:

```python
past_key_values = None

for _ in range(max_new_tokens):

    outputs = model(
        input_ids,
        past_key_values=past_key_values,
        use_cache=True
    )

    logits = outputs.logits

    past_key_values = outputs.past_key_values

    next_token = logits[:, -1, :].argmax(
        dim=-1,
        keepdim=True
    )

    input_ids = next_token
```

The exact API depends on the model and Transformers version.

The important conceptual change is:

```text
First step:
Process the prompt.

Later steps:
Process only the newly generated token
while reusing cached K/V states.
```

---

# 28. Why KV Cache Produces Such a Large Speedup

The benchmark in the walkthrough demonstrates the difference clearly.

Without caching, generation may achieve only around:

```text
4–5 tokens/sec
```

on the demonstrated Apple MPS setup.

With KV caching:

```text
~27–29 tokens/sec
```

This represents a large improvement.

The exact values are hardware- and implementation-dependent, so these numbers should be interpreted as **illustrative benchmark results**, not universal performance guarantees.

---

# 29. Model Compilation

After implementing KV caching, another optimization can be applied:

```python
torch.compile(...)
```

PyTorch provides `torch.compile` as a way to optimize execution by transforming and compiling portions of the computation graph.

Conceptually:

```text
Python Model
     │
     ▼
torch.compile
     │
     ▼
Optimized Graph
     │
     ▼
Fused / optimized operations
```

---

# 30. Why Compilation Helps

A neural network contains many individual operations.

For example:

```text
Operation A
     ↓
Operation B
     ↓
Operation C
     ↓
Operation D
```

There can be overhead associated with launching and coordinating these operations.

Compilation attempts to optimize the computation graph.

Potential benefits include:

- Operator fusion
- Reduced framework overhead
- Better kernel selection
- Improved execution scheduling
- Reduced Python-level overhead

---

# 31. Example

Conceptually:

```python
model = torch.compile(model)
```

Then generation proceeds using the compiled model.

However, compilation is not always a guaranteed improvement.

Performance depends on:

- Hardware
- PyTorch version
- CUDA version
- MPS implementation
- Model architecture
- Tensor shapes
- Dynamic vs static shapes
- Backend implementation

---

# 32. Benchmark Results

The walkthrough gives an illustrative progression similar to:

| Configuration | Approx. Throughput |
|---|---:|
| Naive generation | 4–5 tokens/s |
| KV caching | 27–29 tokens/s |
| KV cache + compilation | up to ~71 tokens/s |

The important observation is the **relative improvement**, not the exact numbers.

The benchmark demonstrates:

```text
Naive
  ↓
KV Cache
  ↓
Compilation
```

Each optimization reduces a different source of computational overhead.

---

# 33. Why Hardware Matters

The same optimization does not necessarily produce the same speedup on every machine.

Possible environments include:

```text
CPU
 │
 ├── Intel / AMD
 │
 ▼
GPU
 ├── NVIDIA CUDA
 ├── AMD ROCm
 └── Apple MPS
```

Each backend has different:

- Kernels
- Compiler support
- Memory systems
- Graph optimizations
- Operator coverage

Therefore, benchmarking should always be performed on the target hardware.

---

# 34. Device Selection

A practical implementation can choose the best available device.

Conceptually:

```python
if torch.cuda.is_available():
    device = "cuda"

elif torch.backends.mps.is_available():
    device = "mps"

else:
    device = "cpu"
```

Then:

```python
model = model.to(device)
```

and:

```python
input_ids = input_ids.to(device)
```

The model and tensors must generally reside on compatible devices.

---

# 35. CUDA

For NVIDIA GPUs:

```python
device = "cuda"
```

CUDA provides access to NVIDIA GPU acceleration.

For example:

```python
torch.cuda.is_available()
```

can be used to determine whether CUDA is available.

---

# 36. Apple MPS

Apple Silicon systems can use:

```text
MPS
```

which stands for:

> Metal Performance Shaders

PyTorch provides the MPS backend for Apple GPUs.

A typical check is:

```python
torch.backends.mps.is_available()
```

If available:

```python
device = "mps"
```

---

# 37. MPS Compatibility Issues

MPS support has improved significantly, but some operations can still behave differently from CUDA or CPU execution.

Potential issues include:

- Unsupported operations
- Different numerical behavior
- Compilation problems
- Memory-related issues
- Backend-specific crashes
- Unexpected performance regressions

Therefore, when debugging an MPS problem, CPU execution can be extremely useful.

---

# 38. CPU Fallback

A useful debugging strategy is:

```text
Problem on MPS
      │
      ▼
Run same code on CPU
      │
      ├── Works on CPU
      │       ↓
      │   Investigate MPS
      │
      └── Fails on CPU
              ↓
          Likely code/model issue
```

This isolates whether the problem is:

```text
Model / Code
```

or:

```text
Hardware Backend
```

---

# 39. Why CPU Is Still Useful

Even when CPU inference is much slower, it is valuable for:

- Debugging
- Unit testing
- Verifying tensor shapes
- Reproducing numerical errors
- Checking model behavior
- Validating generation logic

A reliable workflow is:

```text
First make it correct
        ↓
Run on CPU
        ↓
Move to GPU
        ↓
Optimize
        ↓
Benchmark
```

---

# 40. Correctness Before Optimization

A crucial engineering principle from this walkthrough is:

> **Do not optimize code before you understand and validate the basic implementation.**

The recommended progression is:

```text
1. Load model
2. Load tokenizer
3. Generate text
4. Verify output
5. Understand tensor shapes
6. Implement naive generation
7. Add EOS handling
8. Add KV caching
9. Benchmark
10. Add compilation
11. Benchmark again
```

This makes debugging significantly easier.

---

# 41. Measuring Generation Speed

A basic benchmark can measure elapsed time:

```python
import time

start = time.time()

output = generate(
    model,
    tokenizer,
    prompt,
    max_new_tokens=100
)

end = time.time()

elapsed = end - start

tokens_per_second = 100 / elapsed

print(tokens_per_second)
```

A more careful benchmark should account for:

- Prompt processing time
- Generated tokens
- Warm-up iterations
- Synchronization
- Device-specific execution behavior

---

# 42. Warm-Up Runs

GPU execution may have initialization overhead.

Therefore, the first execution may be slower.

A benchmark should often perform several warm-up iterations:

```text
Warm-up
Warm-up
Warm-up
────────────
Benchmark
Benchmark
Benchmark
```

Then average the measured runs.

This produces more reliable results.

---

# 43. Prefill vs Decode

LLM inference can be conceptually divided into two phases.

### Prefill

The model processes the initial prompt:

```text
Prompt
  ↓
Transformer
  ↓
KV Cache
```

### Decode

The model generates new tokens one by one:

```text
Token
 ↓
Transformer
 ↓
Next token
 ↓
Transformer
 ↓
Next token
```

KV caching primarily provides its major benefit during the **decode phase**.

---

# 44. Important Mental Model

A useful way to think about generation is:

```text
Prompt
  │
  ▼
PREFILL
  │
  ▼
KV Cache
  │
  ▼
DECODE
  │
  ├── Generate token
  ├── Update KV cache
  ├── Generate token
  ├── Update KV cache
  └── ...
```

This distinction becomes increasingly important when studying LLM inference optimization.

---

# 45. Why Reasoning Models Need Efficient Inference

Reasoning models may generate significantly more tokens than ordinary conversational responses.

For example:

```text
Normal response:
20–100 tokens
```

versus:

```text
Reasoning trajectory:
100s–1000s+ tokens
```

Therefore, inference efficiency becomes extremely important.

If generation is slow:

```text
Long reasoning
     ↓
More tokens
     ↓
More computation
     ↓
Longer training / evaluation time
```

Optimizations such as KV caching can therefore have a substantial effect on experimentation speed.

---

# 46. Connection to Reinforcement Learning

The ultimate objective of this learning sequence is to move toward reasoning-oriented training.

A simplified future pipeline might look like:

```text
Pretrained LLM
      │
      ▼
Supervised Fine-Tuning
      │
      ▼
Reasoning-Oriented Data
      │
      ▼
RL / RLVR
      │
      ▼
Reasoning Model
```

The model must first be capable of efficiently generating sequences.

Therefore, understanding inference is foundational.

---

# 47. Why Token Generation Matters for RL

Suppose an RL training procedure generates:

```text
1000 responses
```

and every response contains:

```text
500 tokens
```

Then the system must generate roughly:

\[
1000 \times 500 = 500,000
\]

tokens.

If generation is inefficient, the training loop becomes a major bottleneck.

Thus:

```text
Faster inference
      ↓
More rollouts
      ↓
More experiments
      ↓
Faster research iteration
```

---

# 48. The Complete Inference Pipeline

The concepts from the walkthrough can be combined into one pipeline:

```text
                  ┌───────────────┐
                  │ User Prompt   │
                  └───────┬───────┘
                          │
                          ▼
                  ┌───────────────┐
                  │   Tokenizer   │
                  └───────┬───────┘
                          │
                          ▼
                  ┌───────────────┐
                  │  Token IDs    │
                  └───────┬───────┘
                          │
                          ▼
                  ┌───────────────┐
                  │ Transformer   │
                  └───────┬───────┘
                          │
                          ▼
                     Logits
                          │
                          ▼
                  Token Selection
                          │
                          ▼
                  Next Token
                          │
                          ▼
                  Update KV Cache
                          │
                          ▼
                   EOS reached?
                    /          \
                  No            Yes
                  │              │
                  ▼              ▼
             Generate       Decode text
             next token
```

---

# 49. Naive vs Optimized Architecture

## Naive

```text
Prompt
  ↓
Full Transformer
  ↓
Token
  ↓
Prompt + Token
  ↓
Full Transformer
  ↓
Token
  ↓
...
```

The model repeatedly recomputes information.

## Optimized

```text
Prompt
  ↓
Transformer
  ↓
KV Cache
  ↓
New Token
  ↓
Only new computation
  ↓
Updated KV Cache
  ↓
Next Token
```

This is the key inference optimization.

---

# 50. Important Concepts to Remember

## Tokenization

```text
Text → Token IDs
```

The tokenizer converts human-readable text into the discrete symbols understood by the model.

---

## Decoding

```text
Token IDs → Text
```

This converts generated token IDs back into readable text.

---

## Autoregressive Generation

```text
Predict one token
       ↓
Append token
       ↓
Predict next token
       ↓
Repeat
```

---

## Logits

Raw scores produced by the model for each vocabulary token.

---

## Softmax

Converts logits into a probability distribution.

\[
softmax(z_i)
=
\frac{e^{z_i}}
{\sum_j e^{z_j}}
\]

---

## Greedy Decoding

Select:

\[
\arg\max_i z_i
\]

---

## EOS

Special token indicating that generation should terminate.

---

## KV Cache

Stores previously calculated attention keys and values.

```text
K₁ K₂ K₃ ... Kₙ
V₁ V₂ V₃ ... Vₙ
```

so they do not need to be recomputed.

---

## `torch.compile`

Attempts to optimize the model's computation graph and execution.

---

# 51. Common Mistakes

### Mistake 1 — Thinking the model generates the whole answer at once

Incorrect:

```text
Prompt → Complete answer
```

Better mental model:

```text
Prompt
 → Token
 → Token
 → Token
 → Token
 → ...
```

---

### Mistake 2 — Confusing tokens with words

Tokens are not necessarily words.

```text
word ≠ token
```

A word can consist of multiple tokens.

---

### Mistake 3 — Forgetting the EOS condition

Without a termination condition, generation may continue until:

```text
max_new_tokens
```

is reached.

---

### Mistake 4 — Recomputing the entire sequence unnecessarily

This is the fundamental inefficiency addressed by KV caching.

---

### Mistake 5 — Assuming `torch.compile` is always faster

Compilation can improve performance, but its effectiveness depends on the environment.

Always benchmark.

---

### Mistake 6 — Assuming CUDA and MPS behave identically

Different backends have different levels of support.

A model working on CUDA does not guarantee identical behavior on MPS.

---

# 52. Debugging Checklist

When generation fails:

```text
[ ] Is the tokenizer loaded correctly?
[ ] Does the model match the tokenizer?
[ ] Are model and input tensors on the same device?
[ ] Are tensor shapes correct?
[ ] Is model.eval() enabled?
[ ] Is gradient computation disabled?
[ ] Is EOS configured correctly?
[ ] Does naive generation work?
[ ] Does CPU execution work?
[ ] Does GPU execution work?
[ ] Does KV-cache generation work?
[ ] Does compilation work?
```

Do not debug all optimizations simultaneously.

---

# 53. Recommended Development Strategy

A robust implementation strategy is:

### Stage 1 — Basic model

```text
Load model
Load tokenizer
Run one forward pass
```

### Stage 2 — Generation

```text
Implement token-by-token generation
```

### Stage 3 — Correctness

```text
Add EOS
Add maximum token limit
Verify decoded output
```

### Stage 4 — Performance

```text
Add KV cache
Benchmark
```

### Stage 5 — Further optimization

```text
Add torch.compile
Benchmark
```

### Stage 6 — Advanced research

```text
Training
SFT
RL
RLVR
Reasoning optimization
```

---

# 54. Learning Strategy

The recommended learning strategy is not simply:

```text
Watch video → Move on
```

Instead:

```text
              ┌───────────────────┐
              │ High-level reading│
              └─────────┬─────────┘
                        ▼
              ┌───────────────────┐
              │ Understand concepts│
              └─────────┬─────────┘
                        ▼
              ┌───────────────────┐
              │ Implement yourself│
              └─────────┬─────────┘
                        ▼
              ┌───────────────────┐
              │ Benchmark/debug   │
              └─────────┬─────────┘
                        ▼
              ┌───────────────────┐
              │ Apply to project  │
              └───────────────────┘
```

---

# 55. Suggested Note-Taking Method

For each concept, record four things:

### 1. What?

Definition.

### 2. Why?

Why the technique exists.

### 3. How?

Implementation details.

### 4. Trade-offs?

When it helps and when it can fail.

For example:

```text
Concept: KV Cache

What?
Stores attention K/V tensors.

Why?
Avoids recomputing previous tokens.

How?
Maintain past_key_values across generation steps.

Trade-offs?
Consumes additional GPU memory.
```

This structure is particularly useful for research-oriented learning.

---

# 56. Practical Exercises

After studying the material, implement these yourself.

### Exercise 1

Load the tokenizer and print:

```text
Tokens
Token IDs
Decoded text
```

---

### Exercise 2

Write a function:

```python
generate(prompt, max_new_tokens)
```

using greedy decoding.

---

### Exercise 3

Add EOS handling.

---

### Exercise 4

Benchmark generation without KV caching.

Record:

```text
Prompt length
Generated tokens
Elapsed time
Tokens/sec
```

---

### Exercise 5

Implement KV caching.

Compare:

```text
Naive generation
vs
KV-cache generation
```

---

### Exercise 6

Add:

```python
torch.compile(model)
```

and benchmark again.

---

### Exercise 7

Run the same generation on:

```text
CPU
GPU
```

and compare throughput.

---

# 57. Benchmark Table Template

Use a table like this when running your own experiments:

| Configuration | Device | Generated Tokens | Time | Tokens/sec |
|---|---|---:|---:|---:|
| Naive | CPU | 100 | — | — |
| KV Cache | CPU | 100 | — | — |
| Naive | GPU | 100 | — | — |
| KV Cache | GPU | 100 | — | — |
| KV Cache + Compile | GPU | 100 | — | — |

This makes optimization gains measurable instead of relying on subjective impressions.

---

# 58. Key Takeaways

The most important lessons from this chapter are:

1. **LLMs operate on tokens, not raw text.**
2. **Tokenizers convert text into integer token IDs.**
3. **The model predicts the next token from the preceding context.**
4. **Generation is autoregressive and happens one token at a time.**
5. **Greedy decoding selects the highest-scoring next token.**
6. **EOS tokens provide a natural stopping criterion.**
7. **Naive generation repeatedly recomputes information that has not changed.**
8. **KV caching stores attention keys and values to avoid this redundant computation.**
9. **KV caching can dramatically increase generation throughput.**
10. **`torch.compile` can provide additional optimization, but results are hardware-dependent.**
11. **CUDA, MPS, and CPU have different capabilities and failure modes.**
12. **CPU execution is an important debugging baseline.**
13. **Inference optimization becomes especially important for reasoning models because they may generate long reasoning trajectories.**
14. **Understanding inference is a prerequisite for understanding RL-based reasoning-model training.**

---

# 59. The Bigger Picture

This chapter should be viewed as the first layer of a larger reasoning-model learning path.

```text
                 PRETRAINED LLM
                       │
                       ▼
              ┌─────────────────┐
              │ Tokenization    │
              └────────┬────────┘
                       ▼
              ┌─────────────────┐
              │ Transformer     │
              └────────┬────────┘
                       ▼
              ┌─────────────────┐
              │ Generation      │
              └────────┬────────┘
                       ▼
              ┌─────────────────┐
              │ KV Caching      │
              └────────┬────────┘
                       ▼
              ┌─────────────────┐
              │ Fast Inference  │
              └────────┬────────┘
                       ▼
              ┌─────────────────┐
              │ SFT             │
              └────────┬────────┘
                       ▼
              ┌─────────────────┐
              │ Reasoning Data  │
              └────────┬────────┘
                       ▼
              ┌─────────────────┐
              │ RL / RLVR       │
              └────────┬────────┘
                       ▼
              ┌─────────────────┐
              │ Reasoning Model │
              └─────────────────┘
```

The key idea is:

> **Before teaching an LLM to reason, understand exactly how it generates. Before optimizing reasoning, understand inference. Before training with RL, understand the model, tokenizer, generation loop, and computational bottlenecks.**

That foundation makes the later reasoning-model chapters much easier to understand and implement.