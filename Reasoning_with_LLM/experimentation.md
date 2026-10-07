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