# 📖 ADM Journey

My personal notes, implementations, and exercises as I work through **The Algorithm Design Manual** (3rd ed.) by Steven Skiena.

This isn't a polished project — it's a living document of me actually reading the book, implementing data structures from scratch, grinding through the war stories, and slowly building the algorithmic intuition that separates people who *use* algorithms from people who *understand* them.

---

## 📂 Structure

```
├── src/
│   ├── sorting/            ← sorting algorithms
│   ├── searching/          ← searching algorithms
│   ├── graphs/             ← graph traversal & weighted graph algorithms
│   ├── dynamic_programming/ ← DP implementations
│   ├── data_structures/    ← trees, heaps, hash tables, union-find, etc.
│   └── backtracking/       ← combinatorial search & pruning
└── docs/
    ├── chapter_01/         ← Introduction to Algorithm Design
    ├── chapter_02/         ← Algorithm Analysis
    ├── chapter_03/         ← Data Structures
    └── ...
```

---

## 📍 Progress

| Chapter | Topic | Status |
|---------|-------|--------|
| 1 | Introduction to Algorithm Design | ✅ In Progress |
| 2 | Algorithm Analysis | 🔲 |
| 3 | Data Structures | 🔲 |
| 4 | Sorting and Searching | 🔲 |
| 5 | Graph Traversal | 🔲 |
| 6 | Weighted Graph Algorithms | 🔲 |
| 7 | Combinatorial Search and Heuristic Methods | 🔲 |
| 8 | Dynamic Programming | 🔲 |
| 9 | Intractable Problems and Approximation Algorithms | 🔲 |
| 10 | How to Design Algorithms | 🔲 |

---

## 🛠️ How I Use This Repo

- **`src/`** is organized by problem category, not by chapter. An implementation goes where it conceptually belongs — insertion sort lives in `sorting/`, not in `chapter_04/`. The goal is to be able to implement anything in there from memory, not to have a reference copy.

- **`docs/`** is chapter-by-chapter notes written as I read — not summaries after the fact, but actual in-the-moment understanding being built up section by section. If something clicks, I write down why. If something doesn't, I write that down too.

- **War stories** get their own note in the relevant chapter folder. I focus on the *thinking process* Skienna demonstrates — how the problem was modeled, what failed first, what eventually worked.

---

## 🧠 Why This Book

Most algorithm resources teach you to recognize problem types and apply the right template. Skienna teaches you to *model* problems — to see the abstract structure underneath so you can reach for the right tool yourself.

Also the war stories are genuinely good.

---

*Goal: finish the book, never look up "how does BFS work" again.*
