# Approach Documentation Format

Each approach in this repository should have its own `.cpp` implementation and `.md` explanation.

The `.md` file should document the **reasoning behind the approach**, not reproduce the code.

---

## Standard Structure

Every approach `.md` should follow this structure where applicable:

```markdown
# Problem Name — Approach Name

## Approach

Explain the core idea of the approach in plain language.

Describe the sequence of operations and the important observation that makes the approach work.

Use small examples when they make the idea easier to understand.

## Why It Works

Explain the reasoning that guarantees correctness.

Focus on the invariant, observation, or property that makes the approach valid.

Avoid simply restating the implementation.

## Complexity

- **Time:** `O(...)`
- **Auxiliary Space:** `O(...)`
- **Output Space:** `O(...)`

Mention implementation-dependent details when relevant.

## Why Use This Approach?

Explain the practical tradeoffs of the approach.

Examples:
- Why it is faster than a previous approach.
- Why it uses less memory.
- Why it is simpler.
- Why it avoids a particular limitation.
- Why it is useful despite not being optimal.

## Key Learning

End with the main DSA pattern or insight learned from the approach.

Prefer a concise general principle that can transfer to other problems.
```

---

## Section Guidelines

### 1. Title

Use:

```markdown
# Problem Name — Approach Name
```

The title should identify both the problem and the specific technique.

Examples:

```text
# Contains Duplicate — Sorting + Adjacent Comparison
# Product of Array Except Self — Total Product + Zero Count
# Product of Array Except Self — Prefix + Suffix Products
```

---

### 2. Approach

Explain **what the algorithm does and why the idea occurred**.

This section should answer:

> "What am I doing?"

Include:
- The central observation.
- The sequence of operations.
- Important cases.
- A small example if useful.

Do not include the full C++ implementation.

---

### 3. Why It Works

Explain **why the approach is correct**.

This should answer:

> "Why does this actually solve the problem?"

Focus on the underlying reasoning rather than implementation details.

For example, if sorting makes duplicates adjacent, explain why sorting guarantees that property.

If using prefix/suffix products, explain why every element except the current one belongs to exactly one of those two groups.

---

### 4. Complexity

Always explicitly document:

- Time complexity.
- Auxiliary space complexity.
- Output space when relevant.

Distinguish between **auxiliary space** and the space required for the output.

For example:

```markdown
- **Time:** `O(n)`
- **Auxiliary Space:** `O(1)`
- **Output Space:** `O(n)`
```

If a standard-library operation has implementation-dependent extra space, mention it where relevant.

---

### 5. Why Use This Approach?

Explain the **tradeoff and purpose** of the approach.

This is especially important when a problem has multiple approaches in the repository.

For a non-optimal solution, explain why it is still useful.

For an optimal solution, explain what makes it preferable.

Avoid generic statements such as "this is efficient." Be specific about what is gained or sacrificed.

---

### 6. Key Learning

Finish with one transferable DSA lesson.

Good examples:

> **Transform the data into an ordered form so that a global property becomes locally detectable.**

> **Calculate shared information once and reuse it instead of repeatedly recalculating it.**

> **Use a data structure when faster lookup is worth the additional memory.**

The goal is to capture the **pattern**, not just the solution to one problem.

---

## Multiple Approaches for One Problem

When a problem has multiple approaches, document each approach separately.

Example:

```text
238 Product of Array Except Self
│
├── Brute Force Approach.Cpp
├── Brute Force Approach.md
├── Division + Zero Count Approach.Cpp
├── Division + Zero Count Approach.md
├── Prefix & Suffix Approach.Cpp
└── Prefix & Suffix Approach.md
```

Each `.md` should explain only its corresponding approach.

Do not create one large explanation containing all approaches unless the problem specifically benefits from a comparison document.

---

## What NOT to Put in Approach `.md` Files

Do not:

- Paste the complete C++ solution.
- Explain every line of code.
- Write a generic tutorial about the entire topic.
- Include unnecessary personal commentary.
- Repeat the problem statement verbatim.
- Claim an approach is optimal without checking its complexity.
- Hide important tradeoffs.

The `.md` should explain **the algorithm and the reasoning**, while the `.cpp` file contains **the implementation**.

---

## Writing Style

Keep explanations:

- Clear
- Technical
- Concise
- Reasoning-focused
- Easy to scan

Use examples and diagrams when they genuinely clarify the idea.

Prefer:

> "Sorting guarantees that equal values become adjacent."

over:

> "First we sort the array, and then we iterate through it and check..."

The documentation should explain **why**, not merely narrate the code.

---

## Core Philosophy

The repository is not just a collection of accepted LeetCode solutions.

Each problem should preserve the progression:

```text
Problem
   ↓
Initial idea
   ↓
Correctness
   ↓
Complexity
   ↓
Limitations / tradeoffs
   ↓
Optimization
   ↓
Generalizable learning
```

The purpose of the `.md` files is to make the **reasoning reusable**, so that the same pattern can be recognized and derived in a different problem later.
