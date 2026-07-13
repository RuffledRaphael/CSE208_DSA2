# All-Pairs Shortest Path (APSP)

> CSE 208 · [Specification](specification.pdf)

## Objective

Compute the shortest distance between **every pair** of vertices in a weighted directed graph, using
the **Floyd-Warshall** dynamic-programming algorithm and a **matrix-multiplication** based method,
and print the resulting distance matrices.

## Approach

- **Floyd-Warshall**: for each intermediate vertex `k`, relax `dist[i][j]` through `k` — an
  `O(V³)` DP over all pairs.
- **Matrix multiplication**: repeatedly "multiply" the weight matrix under the (min, +) semiring to
  extend shortest paths by one more edge, doubling the path length each round.

## Input format (`input.txt`)

```
V E            # vertices, edges
u v w          # E weighted directed edges (supports negative weights)
...
```

## Input / Output

Reads `input.txt`, writes [`output.txt`](output.txt) (both distance matrices).

## Build &amp; run

```bash
g++ -std=c++17 main.cpp -o apsp && ./apsp
```
