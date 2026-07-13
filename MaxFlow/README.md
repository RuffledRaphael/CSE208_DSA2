# Maximum Flow &amp; Baseball Elimination

> CSE 208 · [Specification](specification.pdf)

## Objective

Implement **maximum flow** in a flow network (Ford-Fulkerson / augmenting paths), then apply it to
the classic **baseball elimination** problem: decide whether a given team can still finish in first
place.

## Approach

- **Max flow** (`MaxFlow.cpp`): repeatedly finds an augmenting path from source to sink in the
  residual graph and pushes flow equal to the bottleneck capacity until no augmenting path remains.
- **Baseball elimination** (`baseball.cpp`): builds a flow network from the standings — game nodes
  and team nodes with capacities derived from wins and remaining games. A team is eliminated iff the
  max flow cannot saturate all the game edges; the min-cut identifies the set of teams responsible.

## Input format (`input.txt`)

```
n
name  wins  losses  remaining  g1 g2 … gn   # per team: record + games left against each other team
...
```

## Input / Output

Reads `input.txt`, writes [`output.txt`](output.txt) — which team (if any) is eliminated and the
supporting arithmetic.

## Build &amp; run

```bash
g++ -std=c++17 main.cpp     -o maxflow  && ./maxflow
g++ -std=c++17 baseball.cpp -o baseball && ./baseball
```
