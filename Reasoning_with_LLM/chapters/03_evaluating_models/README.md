# LLM Evaluation for Mathematical Reasoning

## 1. Main Goal

The video introduces a **verifier-based evaluation pipeline** for measuring how well an LLM solves mathematical reasoning problems.

Main idea:

```text
Problem
  ↓
LLM generates solution
  ↓
Extract final answer
  ↓
Normalize answer
  ↓
Verify mathematically
  ↓
Correct / Incorrect
  ↓
Accuracy
```

This evaluation framework becomes the baseline for later **inference improvements and RL/RLVR training**.

---

## 2. Why Verifier-Based Evaluation?

For math, correctness can often be determined objectively using a **ground-truth answer**.

Unlike subjective evaluation or LLM-as-a-judge:

```text
Prediction ↔ Ground Truth
```

can be checked automatically.

This is especially useful for **RLVR (Reinforcement Learning with Verifiable Rewards)** because:

```text
Correct → Reward
Incorrect → No/low reward
```

---

## 3. Answer Extraction

LLMs usually generate explanations rather than just the final answer.

Example:

```text
...solution...
Therefore, the answer is \boxed{42}.
```

The evaluator must extract:

```text
42
```

Common formats:

- `\boxed{...}`
- `Final answer: ...`
- `Answer = ...`
- Plain numerical/algebraic answer

**Important:** A correct model answer can be marked wrong if extraction fails.

---

## 4. Answer Normalization

Different representations can mean the same thing:

```text
1/2 = 0.5 = 2/4
```

Therefore, simple string comparison is insufficient.

```text
"1/2" != "0.5"       X
1/2 = 0.5            |/
```

Normalization converts answers into a form suitable for mathematical comparison.

---

## 5. Symbolic Verification

A symbolic mathematics library is used to check **mathematical equivalence**, rather than exact string equality.

Example:

```text
Prediction:  1/2
Ground truth: 0.5

→ mathematically equivalent
→ CORRECT
```

This is more robust for:

- Fractions
- Decimals
- Algebraic expressions
- Different LaTeX representations

---

## 6. Math 500 Benchmark

The model is evaluated on **Math 500**, a benchmark of challenging mathematical problems.

Accuracy:

\[
Accuracy =
\frac{\text{Correct Answers}}
{\text{Total Problems}}
\]

Approximate results discussed:

```text
Base model       → ~15% accuracy
Reasoning model  → >50% accuracy
```

The exact number depends on model, prompt, generation settings, etc.

---

## 7. Base Model vs Reasoning Model

### Base model

```text
Shorter generation
      ↓
Less computation
      ↓
Lower reasoning accuracy
```

### Reasoning model

```text
Longer reasoning
      ↓
More generated tokens
      ↓
More computation
      ↓
Higher accuracy
```

Main trade-off:

> **Better reasoning ↔ higher inference cost and latency**

---

## 8. Prompt Engineering Matters

The prompt can significantly affect both:

- Answer quality
- Output format

For example, instructing the model to:

```text
Solve carefully and put the final answer inside \boxed{...}
```

makes extraction easier and can improve accuracy.

The video shows that prompt changes can sometimes produce **large accuracy differences**.

Therefore:

> The prompt is part of the evaluation setup.

---

## 9. Hardware Variability

Results can differ across:

```text
CPU
CUDA GPU
Apple MPS
```

because of differences in:

- Floating-point operations
- Parallel execution
- Backend implementations
- Randomness/sampling

Therefore, exact reproducibility is not always guaranteed across hardware.

For fair experiments, record:

```text
Model + Prompt + Dataset + Generation Settings
+ Hardware + Software Versions
```

---

## 10. Why This Evaluator Matters

The evaluator creates a reliable **baseline**.

Future experiments can follow:

```text
Baseline
   ↓
Inference improvement
   ↓
Evaluate
   ↓
Fine-tuning
   ↓
Evaluate
   ↓
RL / RLVR
   ↓
Evaluate
```

Without a reliable evaluator, we cannot confidently determine whether an improvement actually worked.

---

# Key Concepts to Remember

| Concept | Meaning |
|---|---|
| **Verifier** | Checks whether model answer is correct |
| **Extraction** | Finds final answer from model output |
| **Normalization** | Converts answer into comparable form |
| **Symbolic verification** | Checks mathematical equivalence |
| **Math 500** | Benchmark for mathematical reasoning |
| **RLVR** | Uses verifiable rewards for RL training |
| **Prompt engineering** | Can strongly affect accuracy/output |
| **Reasoning model** | Uses longer reasoning to improve accuracy |

---

## Core Pipeline

```text
LLM
 ↓
Generate Solution
 ↓
Extract Final Answer
 ↓
Normalize
 ↓
Symbolic Verification
 ↓
Correct / Incorrect
 ↓
Benchmark Accuracy
```

### One-Line Takeaway

> **Build a reliable verifier first; then use it to measure and improve reasoning models through better inference, fine-tuning, and RLVR.**