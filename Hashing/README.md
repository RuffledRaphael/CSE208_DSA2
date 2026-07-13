# Hashing

> CSE 208 · [Specification](specification.pdf) · [Analysis report](report.pdf)

## Objective

Build a **hash table** for string keys and empirically compare collision-resolution strategies —
**separate chaining** vs. **open addressing** (linear probing, quadratic probing, and double
hashing) — measuring the average number of probes for successful and unsuccessful searches at
different load factors.

## Approach

- Two independent string hash functions are implemented; the second seeds the step size for double
  hashing.
- The table is populated from a dictionary of words, then queried; the program counts probes and
  reports averages for each scheme, which are analysed in [`report.pdf`](report.pdf).

## Input / Output

- [`words.txt`](words.txt) — the dictionary of input words (the key corpus).
- The program is **interactive**: it prompts for the table size `N'`, number of insertions, a
  randomizer seed, and the search count, then prints the probe statistics.

## Build &amp; run

```bash
g++ -std=c++17 main.cpp -o hashing && ./hashing   # then follow the prompts
```
