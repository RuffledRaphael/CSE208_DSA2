# Minimum Spanning Tree (MST)

> CSE 208 · [Specification](specification.pdf)

## Objective

Find the **minimum spanning tree** of a weighted undirected graph using **both** classic algorithms —
**Prim's** and **Kruskal's** — and report the MST weight and edges from each.

## Approach

- **Prim's**: grows the tree from a start vertex, repeatedly adding the lightest edge crossing the
  cut (priority-queue driven).
- **Kruskal's**: sorts all edges by weight and adds them greedily, using a **disjoint-set union
  (union-find)** structure to skip edges that would form a cycle.

## Input format (`input.txt`)

```
V E            # vertices, edges
u v w          # E weighted undirected edges
...
```

## Input / Output

Reads `input.txt`; writes the Prim result to [`prim.txt`](prim.txt) and the Kruskal result to
[`kruskal.txt`](kruskal.txt).

## Build &amp; run

```bash
g++ -std=c++17 main.cpp -o mst && ./mst
```
