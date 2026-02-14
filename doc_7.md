# Dijkstra’s Shortest Path Algorithm

This program implements **Dijkstra’s Algorithm** using an adjacency matrix representation. It calculates the shortest distance from a single source vertex to all other vertices in a weighted graph.

---

## (a) Data Structure Definition

The program uses the following key data structures:

* **Adjacency Matrix (`adjacencyMatrix[TOTAL_VERTICES][TOTAL_VERTICES]`)**: A 2D array where `adjacencyMatrix[i][j]` represents the weight of the edge between vertex `i` and vertex `j`. A value of `0` indicates no direct edge exists.  
* **Distance Array (`shortestDistances[TOTAL_VERTICES]`)**: Stores the shortest distance from the source vertex to each vertex. Initially, all distances are set to `INT_MAX` (infinity).  
* **Visited Array (`visitedVertices[TOTAL_VERTICES]`)**: Tracks which vertices have already been finalized (visited) during the algorithm.

---

## (b) Function Descriptions

### 1. `int getNearestVertex(int distances[], int visitedVertices[])`
* **Purpose**: Finds the unvisited vertex with the smallest current distance value.  
* **Logic**: Iterates through the `distances` array and returns the index of the vertex that has the minimum distance and has not been visited yet. This is the "greedy" step of Dijkstra’s Algorithm.

### 2. `void calculateShortestPaths(int adjacencyMatrix[TOTAL_VERTICES][TOTAL_VERTICES], int startVertex)`
* **Purpose**: Computes the shortest paths from the specified source vertex to all other vertices.  
* **Logic**:
    1. **Initialization**: Sets all distances to `INT_MAX` and the distance to the source vertex to `0`.  
    2. **Relaxation**: Repeatedly selects the unvisited vertex with the minimum distance. For each of its neighbors, if a shorter path exists through the current vertex, the neighbor’s distance is updated:  
       ```
       shortestDistances[neighbor] = shortestDistances[current] + adjacencyMatrix[current][neighbor]
       ```  
    3. **Completion**: The process continues until all vertices have been visited.  
* **Output**: Prints a table showing the shortest distance from the source vertex to all vertices.

---

## (c) Main Method Organization

The `main()` function organizes the program as follows:

1. **Graph Definition**: Creates a weighted graph as an adjacency matrix. A `0` value indicates no direct edge between two vertices.  
2. **Source Vertex Selection**: Sets the starting vertex for shortest path calculation (`startVertex`).  
3. **Execution**: Calls `calculateShortestPaths()` with the adjacency matrix and the source vertex.  
4. **Output Display**: Prints the shortest distances from the source to all other vertices.

---

## (d) Sample Output

```text
Calculating shortest paths from vertex 0...

Vertex   Shortest Distance from Source 0
0        0
1        2
2        5
3        1
4        4
5        6
