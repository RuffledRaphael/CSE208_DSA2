# Approximation Algorithm — Metric TSP

> CSE 208 · [Specification](specification.docx)

## Objective

Study an **approximation algorithm** for the (metric) **Travelling Salesman Problem** and measure
empirically how close its tours come to the true optimum.

## Approach

- **Approximate (`approxPrim`)**: build a **minimum spanning tree** with Prim's algorithm, then take a
  preorder walk of the MST to produce a Hamiltonian tour — the classic **2-approximation** for metric
  TSP.
- **Exact (`exactDP`)**: solve TSP optimally with the **Held-Karp** bitmask dynamic program
  (`O(2ⁿ · n²)`), feasible for the small instances used here.
- The driver generates several random test cases and prints the **approximation ratio**
  `approximate / exact` for each, empirically confirming the ratio stays within the theoretical bound.

## Input / Output

The program is **self-driven / interactive**: it reads the number of test cases `T`, generates random
graphs, and prints the approximation ratio per test case. Reference material:
[`Dasgupta-Papadimitriou-Vazirani.pdf`] (the course textbook chapter) is kept locally.

## Build &amp; run

```bash
g++ -std=c++17 main.cpp -o approx && ./approx
```
