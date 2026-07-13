# Single-Source Shortest Path (SSSP)

> CSE 208 · [Specification](specification.pdf)

## Objective

Compute shortest paths from a single source in a **weighted directed graph** using **Dijkstra's**
algorithm (non-negative weights) and the **Bellman-Ford** algorithm (handles negative edges and
detects negative cycles).

## Approach

- **Dijkstra**: priority-queue greedy relaxation; optimal when all edge weights are non-negative.
- **Bellman-Ford**: relaxes every edge `V−1` times, so it works with negative weights and flags a
  negative-weight cycle if any edge can still be relaxed afterwards.
- Both report the shortest distance and reconstruct the actual path.

## Input format (`input.txt`)

```
V E            # vertices, edges
u v w          # E weighted directed edges
...
src dst        # source and destination
```

## Input / Output

Reads `input.txt`, writes [`output.txt`](output.txt) (Bellman-Ford result followed by Dijkstra).

## Build &amp; run

```bash
g++ -std=c++17 main.cpp -o sssp && ./sssp
```
