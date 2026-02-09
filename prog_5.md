# Checking balance number of parenthesis

## Objective:
The objective of this program is to represent an undirected graph using an adjacency matrix and perform Breadth First Search (BFS) and Depth First Search (DFS) traversals starting from a given vertex.

### Defining Data-Structures:
```c
#define LIMIT 12
int graph[LIMIT][LIMIT];
int mark[LIMIT];
int vertices;
```

**Explanation:**
* graph[LIMIT][LIMIT] represents the adjacency matrix of the graph.

* mark[LIMIT] is used to keep track of visited vertices.

* vertices stores the total number of vertices in the graph.

* LIMIT defines the maximum number of vertices allowed.

**Functions:**
* bfs(int start):

 * Performs Breadth First Search traversal starting from the given vertex.

 * Uses a queue to visit vertices level by level.

* dfs(int v):

 * Performs Depth First Search traversal starting from the given vertex.

 * Uses recursion to explore each branch completely before backtracking.

* main():

 * Accepts the number of vertices and edges from the user.

 * Takes edge information to build the adjacency matrix.

 * Accepts a starting vertex.

 * Calls BFS and DFS functions.

 * Displays the traversal order.

**Sample Output:**
Enter number of vertices: 6
Enter number of edges: 7
Enter edges:
0 1
0 3
1 2
1 4
2 5
3 4
4 5
Enter starting vertex: 1
BFS Traversal: 1 0 2 4 3 5 
DFS Traversal: 1 0 3 4 5 2 