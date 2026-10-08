### Experiment: Multiple Prompts

Tested greedy autoregressive generation with three prompts:

1. "What is 17 x 24?"
2. "The capital of France is"
3. "Machine learning is"

Observations:
- The model generates tokens autoregressively and produces coherent continuations.
- For the mathematical prompt, the model generated a multi-step solution ending in 408.
- For "The capital of France is", the model continued the learned country-capital pattern and eventually became repetitive.
- For "Machine learning is", the model generated an article-like continuation rather than treating the prompt as an explicit question.
- This demonstrates that the base model performs next-token prediction/text continuation rather than guaranteed instruction following.



### Prompt Template Experiment

**Objective:** Test whether structured prompting improves the Qwen3 base model's answer generation.

- **Raw prompt:** `What is 2 + 3?` → model often continued with unrelated arithmetic questions; accuracy was **2/5 (40%)**.
- **Structured prompt:** Added explicit instructions to solve the problem and provide the final answer in `\boxed{ANSWER}` format.
- **Result:** Accuracy improved to **5/5 (100%)** on the same five examples.
- **Observation:** Prompt structure significantly influenced the behavior of the base model and made its output much more suitable for the answer-extraction and grading pipeline.

**Conclusion:** A well-designed prompt is an important part of the evaluation pipeline, especially when working with a base language model rather than an instruction-tuned model.




### Larger Evaluation — 20 Examples

**Objective:** Test whether the structured prompt continues to produce correct answers beyond the initial 5-example experiment.

- **Dataset:** 20 manually created arithmetic problems
- **Prompt:** Structured math prompt with explicit final-answer formatting
- **Correct:** 20/20
- **Accuracy:** **100%**
- **Observation:** The model correctly generated and the verifier correctly extracted all 20 answers.
- **Conclusion:** The evaluation pipeline works correctly on this simple arithmetic set. However, the dataset is too small and homogeneous to make strong claims about general mathematical reasoning.