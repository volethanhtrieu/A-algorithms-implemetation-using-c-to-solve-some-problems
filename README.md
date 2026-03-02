# A* Pathfinding: From Theory to Implementation

This project explores the **A* (A-star) Search Algorithm**, a powerful and widely used pathfinding technique in AI and robotics. [cite_start]This repository provides a modular C++ implementation of A* across various scenarios, from abstract graphs to complex grid-based mazes[cite: 7, 110, 111].

---

## 🚀 Overview

[cite_start]The A* algorithm finds the shortest path by combining the actual distance traveled with a heuristic "guess" of the remaining distance[cite: 72]. It is designed to be both efficient and optimal.

### The Cost Function
The core of the algorithm is the evaluation function[cite: 74]:

$$f(n) = g(n) + h(n)$$

* [cite_start]**$g(n)$**: The actual cost to reach the current node from the start[cite: 75].
* [cite_start]**$h(n)$**: The heuristic estimate of the cost from the current node to the goal[cite: 76].
* **$f(n)$**: The total estimated cost of the cheapest solution through node $n$[cite: 77].



---

## 🛠 Features & Tasks

The implementation covers four distinct challenges, as outlined in the project requirements[cite: 110]:

1.  **Shortest Path via Adjacency Matrix**: Implements A* on a graph represented by an $n \times n$ matrix[cite: 117].
2.  [cite_start]**2D Space Navigation**: Pathfinding using coordinates and two selectable heuristic modes[cite: 134]:
    * **Mode 1: Manhattan Distance**: $h(n) = |x_1 - x_2| + [cite_start]|y_1 - y_2|$[cite: 143].
    * **Mode 2: Euclidean Distance**: $h(n) = \sqrt{(x_1 - x_2)^2 + (y_1 - y_2)^2}$[cite: 145].
3.  **Grid Maze Navigation**: Navigating an $m \times n$ grid with obstacles, supporting 8 possible moves (cardinal and diagonal)[cite: 147, 156].
4.  **Maze-to-Graph Reconstruction**: Converts a grid maze into a formal weighted graph before executing the search.

### Movement Costs (Tasks 3 & 4)
* [cite_start]**Horizontal/Vertical**: 1.0 unit[cite: 161, 173].
* [cite_start]**Diagonal**: 1.5 units[cite: 162, 174].

---

## 💻 Technical Implementation

[cite_start]This project is built using **C++** and follows a modular structure to ensure code clarity and reusability[cite: 111, 247].

### Core Data Structure
[cite_start]The solution path is represented as a custom linked list of `PathNode` objects[cite: 196]:
* `name`: The label of the node (e.g., coordinate or index)[cite: 198].
* [cite_start]`f, g, h`: The calculated costs for each specific step[cite: 199, 200, 201].
* [cite_start]`next`: A pointer to the next step in the path[cite: 202].

---

## 🏃 How to Run

### Prerequisites
* A C++ compiler (e.g., `g++`).

### Build and Execute
To build the project and run the Task 4 (Maze Navigation) test suite:

```bash
# Compile the project
g++ -o main -I. src/Algo.cpp src/PathNode.cpp tests/test_findPathInMaze.cpp

# Run the executable
./main
