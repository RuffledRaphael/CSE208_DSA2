# AVL Tree

> CSE 208 · [Specification](specification.pdf)

## Objective

Implement a **self-balancing AVL tree** supporting insertion, deletion, search, and in-order
traversal, keeping the tree height-balanced (`|balance factor| ≤ 1`) at every node through
rotations — and measure the running time of each operation.

## Approach

- Each node stores its height; after every insert/delete the balance factor is checked and the tree
  is rebalanced with the four classic rotations (**LL, RR, LR, RL**).
- The tree is printed in a parenthesised nested form `key(left,right)`, making the structure visible.
- `main.cpp` also **times** insert / delete / search / traversal over large randomized inputs and
  writes the results to `report_avl.txt`.

## Command language

| Command | Meaning |
|---------|---------|
| `I x` | Insert key `x` |
| `D x` | Delete key `x` |
| `F x` | Find key `x` |
| `T` | Print in-order traversal |

## Input / Output

- The program reads `in.txt` and writes `out_avl.txt` (plus a timing summary to `report_avl.txt`).
- A **small illustrative sample** is provided as [`sample_in.txt`](sample_in.txt) →
  [`sample_out_avl.txt`](sample_out_avl.txt). *(The full local `in.txt` is a multi-hundred-thousand-line
  randomized stress test used for the timing analysis and is excluded from the repo for size.)*

## Build &amp; run

```bash
g++ -std=c++17 main.cpp -o avl && ./avl
```
