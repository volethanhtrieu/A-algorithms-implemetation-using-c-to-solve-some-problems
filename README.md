# A* Pathfinding: From Theory to Implementation

This project explores the **A* (A-star) Search Algorithm**, a powerful and widely used pathfinding technique in AI and robotics. This repository provides a modular C++ implementation of A* across various scenarios, from abstract graphs to complex grid-based mazes.

---

## 🚀 Overview

The A* algorithm finds the shortest path by combining the actual distance traveled with a heuristic "guess" of the remaining distance. It is designed to be both efficient and optimal.

### The Cost Function
The core of the algorithm is the evaluation function:

$$f(n) = g(n) + h(n)$$

* **$g(n)$**: The actual cost to reach the current node from the start.
* **$h(n)$**: The heuristic estimate of the cost from the current node to the goal.
* **$f(n)$**: The total estimated cost of the cheapest solution through node $n$.

[Image of A* algorithm search expansion]

---

## 🛠 Features & Tasks

The implementation covers four distinct challenges, as outlined in the project requirements:

1.  **Shortest Path via Adjacency Matrix**: Implements A* on a graph represented by an $n \times n$ matrix.
2.  **2D Space Navigation**: Pathfinding using coordinates and two selectable heuristic modes:
    * **Mode 1: Manhattan Distance**: $h(n) = |x_1 - x_2| + |y_1 - y_2|$.
    * **Mode 2: Euclidean Distance**: $h(n) = \sqrt{(x_1 - x_2)^2 + (y_1 - y_2)^2}$.
3.  **Grid Maze Navigation**: Navigating an $m \times n$ grid with obstacles, supporting 8 possible moves (cardinal and diagonal).
4.  **Maze-to-Graph Reconstruction**: Converts a grid maze into a formal weighted graph before executing the search.

### Movement Costs (Tasks 3 & 4)
* **Horizontal/Vertical**: 1.0 unit.
* **Diagonal**: 1.5 units.

---

## 💻 Technical Implementation

This project is built using **C++** and follows a modular structure to ensure code clarity and reusability.

### Core Data Structure
The
