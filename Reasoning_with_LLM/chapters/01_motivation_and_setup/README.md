# Introduction to Reasoning Models: From Conventional LLMs to Training and Setup

This markdown serves as the **introductory episode** of a series focused on understanding, coding, and training **reasoning models**—a specialized evolution of large language models (LLMs) that possess enhanced reasoning capabilities. The educational value of building and experimenting with these models from scratch is to achieve a **clear, foundational grasp** beyond high-level visuals or abstract descriptions. The markdown also guides on environment setup and workflow for practical coding required.

## 1. Overview of Reasoning Models and Their Evolution

This section provides a historical and conceptual foundation describing the transformation from **conventional LLMs** to modern **reasoning models** and their deployment through **agent harnesses**.

- **Conventional LLMs** represent early-generation models like the original ChatGPT. These are pretrained but generally lack advanced reasoning capabilities.
- **Reasoning models** are essentially modified LLMs with enhanced abilities to perform logical, stepwise reasoning. These became prevalent from around 2025, popularized by companies like DeepSeek.
- Most leading large models today (e.g., Claude Opus, GPT 5.6, Grok, Kimi, GLM 5) fall into the reasoning model category, leveraging the same base architecture but enriched with reasoning capabilities.
- The term **agent harness** refers to software frameworks that wrap reasoning models to create versatile intelligent agents (e.g., OpenClaw, Codex, Claude Code). Despite this, the underlying reasoning model remains the core engine.
- Understanding the progression—**conventional LLM → reasoning model → agent harness**, is key for AI practitioners who want a deep understanding of how these systems work.

## 2. Educational Value of From-Scratch Implementation

We advocates strongly for the **from-scratch coding approach** for learning, arguing it offers clarity, precision, and a stronger grasp of inner workings than solely relying on diagrams or verbal explanations.

- Code serves as an **unambiguous and precise medium** for demonstrating how concepts work.
- Visual aids provide abstractions; code provides **proof of concept** by enabling live execution and observation of effects (e.g., temperature sampling).
- This approach fosters foundational knowledge that simplifies understanding of newer topics like **cloud text watermarking**, where layered concepts such as sampling, random seeding, and scoring come into play.
- It aims to empower learners to navigate evolving LLM complexities and techniques effectively by building practical knowledge step-by-step.

## 3. Related Resources and Learning Path

The presenter points to complementary materials and outlines flexible learning paths:

| **Resource** | **Focus** | **Relationship to This Series** | **Notes** |
| :--- | :--- | :--- | :--- |
| **Book: Build a Large Language Model from Scratch** | Architecture and pretraining of conventional LLMs | Can be studied before or after reasoning models series | Comprehensive foundation; prerequisite knowledge for architecture details |
| **Current Series and Book: Build a Reasoning Model from Scratch** | Conversion of conventional LLM into reasoning LLM; reinforcement learning | Main focus of this series | Can be standalone; focuses on reasoning capabilities |
| **Article & Future Series: Coding Agent Harness** | Development and explanation of agent harness frameworks | Advanced follow-up after mastering reasoning models | Covers software frameworks wrapping reasoning models |

- Learners can start with either the conventional LLM materials or jump directly into reasoning models based on current interests.

## 4. Technical Environment Setup and Tools

This section outlines step-by-step instructions and best practices to set up the coding environment for the series:

- Code and materials are hosted on GitHub: **github.com/raspt/reasoning-from-scratch**
- The repository is kept small (~5 MB), containing code only. Model checkpoints are downloaded separately.
- **Prerequisites:** Basic knowledge of Python and PyTorch is recommended.
- **Installation methods:**
  - Using `pip` with `requirements.txt`
  - Preferred method: **UV tool** (a combination virtual environment manager and package installer)

### UV Advantages

- Combines virtual environment creation and package installation.
- Ensures project-specific versions without affecting system-wide Python.
- Simple commands like `uv sync` to install/update packages based on `pyproject.toml` and lock files.
- Virtual environments isolate dependencies, making setup and teardown clean and straightforward.

## 5. Hardware and GPU Considerations

The series aims for **accessibility** by enabling code to run on consumer hardware, including Mac Minis without dedicated GPUs.

- Models and training scripts are designed for **small-scale reasoning models**, not large industrial models requiring expensive infrastructure.
- Chapters 6, 7, and 8 benefit significantly from GPU acceleration but are not mandatory initially.
- On Macs without NVIDIA GPUs, Apple's **MPS (Metal Performance Shader)** backend can provide accelerated tensor operations.
- Remote or rented GPU servers can be accessed using the same core workflow, assisted by tools such as Visual Studio Code's **Remote SSH** extension.
- GPU drivers and PyTorch versions can cause compatibility issues.
- Troubleshooting generally involves verifying CUDA drivers and installing a PyTorch version compatible with the installed CUDA version.

## 6. Key Insights and Recommendations

- Reasoning models extend conventional LLMs through changes in **training objectives, inference strategies, and reasoning-oriented post-training**.
- Agent harnesses wrap reasoning models, enabling application-specific AI assistants, but the underlying reasoning model remains the core intelligence.
- Building models from scratch provides a **deep understanding** that helps with troubleshooting, experimentation, and understanding model behavior.
- **UV** is highly recommended for reproducible Python environment and dependency management.
- Small models running on consumer hardware are sufficient for educational purposes.
- Keeping up with updates through the GitHub repository and discussion channels is encouraged for community support and troubleshooting.

## Overall Learning Path

The series can be viewed as the following progression:

**Conventional LLM**
↓
**Understand the architecture and pretrained model**
↓
**Inference & evaluation**
↓
**Reasoning-oriented training**
↓
**Reinforcement Learning**
↓
**Distillation**
↓
**Reasoning Model**
↓
**Agent Harness**
↓
**Practical AI Agent**

This introduction establishes the conceptual and technical foundation for the hands-on implementation of reasoning models, combining **LLM fundamentals, inference, reinforcement learning, distillation, and practical engineering**.