# Binomial Heap

> CSE 208 · [Specification](specification.pdf)

## Objective

Implement a **binomial heap** — a mergeable min-heap made of a forest of binomial trees — supporting
insertion, find-min, extract-min, union (merge), and decrease-key.

## Approach

- The heap is a linked list of binomial trees of distinct orders; `union` merges two heaps by linking
  trees of equal order, mirroring binary addition.
- `insert` is a union with a single-node heap; `extract-min` removes the minimum root and unions its
  children back in; `decrease-key` sifts a node up toward the root.

## Command language (`in.txt`)

| Command | Meaning |
|---------|---------|
| `I x` | Insert key `x` |
| `P` | Print the heap (binomial trees, level by level) |
| `F` | Find-min |
| `E` | Extract-min |
| `U k v …` | Union in a set of keys |

## Input / Output

Reads `in.txt`, writes `out.txt`. A small sample input is provided in [`in.txt`](in.txt).

> ⚠️ **Known issue:** this implementation is a work in progress and currently crashes at runtime on
> some inputs (see the commit history). The source and problem specification are included here for
> completeness; the course-provided reference test cases were used during development.

## Build &amp; run

```bash
g++ -std=c++17 main.cpp -o binheap && ./binheap
```
