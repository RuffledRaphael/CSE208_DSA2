<h1 align="center">CSE 208 — Data Structures and Algorithms II (Sessional)</h1>

<p align="center">
  <img alt="Language" src="https://img.shields.io/badge/Language-C%2B%2B-00599C?logo=cplusplus&logoColor=white">
  <img alt="Course" src="https://img.shields.io/badge/Course-CSE%20208-2C3E50">
  <img alt="Term" src="https://img.shields.io/badge/Term-L--2%20T--2%20(Jan%202023)-16A085">
  <img alt="Institute" src="https://img.shields.io/badge/BUET-Dept.%20of%20CSE-B31B1B">
</p>

<p align="center">
  <b>Undergraduate lab coursework — Bangladesh University of Engineering and Technology (BUET)</b><br>
  Implementations of advanced data structures and graph / optimization algorithms, each built from
  scratch in C++ and driven by file-based I/O.
</p>

---

## 📖 About this course

**CSE 208** is the second data-structures-and-algorithms laboratory in the BUET CSE undergraduate
curriculum, building on CSE 204. It moves into balanced trees, advanced heaps, hashing, and the
core algorithms of graph theory and combinatorial optimization — shortest paths, spanning trees,
network flow, and approximation.

Each assignment folder contains its **problem specification**, the **C++ source**, sample **input /
output**, and a short **README** describing the approach.

## 🗂️ Assignments

| Topic | Folder | Highlights |
|-------|--------|-----------|
| **AVL Tree** | [`AVL tree`](AVL%20tree) | Self-balancing BST — insert/delete/search with rotations, timing analysis |
| **Binomial Heap** | [`Binomial Heap`](Binomial%20Heap) | Mergeable heap — union, insert, extract-min, decrease-key |
| **Hashing** | [`Hashing`](Hashing) | Separate chaining vs. open addressing, collision & probe analysis |
| **MST** | [`MST`](MST) | Minimum spanning tree via **Prim** and **Kruskal** |
| **SSSP** | [`SSSP`](SSSP) | Single-source shortest path — **Dijkstra** and **Bellman-Ford** |
| **APSP** | [`APSP`](APSP) | All-pairs shortest path — **Floyd-Warshall** and matrix-multiplication |
| **Max Flow** | [`MaxFlow`](MaxFlow) | Ford-Fulkerson max flow + **baseball elimination** application |
| **Approximation** | [`approximation`](approximation) | Approximation algorithm with empirical approximation-ratio analysis |

## ⚙️ Building &amp; running

Most assignments read from an input file and write to an output file in the same directory:

```bash
cd MST
g++ -std=c++17 main.cpp -o main      # tested with g++ 14.2
./main                                # reads input.txt → prim.txt, kruskal.txt
```

The exact input/output filenames for each task are listed in that folder's `README.md`.

> Build artifacts (`*.exe`, `.dist/`, `.vscode/`), archives (`*.zip`), and bulky stress-test data are
> excluded via `.gitignore`.

## 👤 Author

**Md. Rafiul Islam** — Student ID `2005035`
Department of Computer Science &amp; Engineering, BUET

---

<p align="center"><sub>Archived academic coursework · CSE 208 · January 2023 term</sub></p>
