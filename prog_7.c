#include <stdio.h>
#include <limits.h>

#define TOTAL_VERTICES 6

int getNearestVertex(int distances[], int visitedVertices[]) {
    int minDistance = INT_MAX;
    int minVertex = -1;
    for (int i = 0; i < TOTAL_VERTICES; i++) {
        if (!visitedVertices[i] && distances[i] <= minDistance) {
            minDistance = distances[i];
            minVertex = i;
        }
    }
    return minVertex;
}

void calculateShortestPaths(int adjacencyMatrix[TOTAL_VERTICES][TOTAL_VERTICES], int startVertex) {
    int shortestDistances[TOTAL_VERTICES];
    int visitedVertices[TOTAL_VERTICES] = {0};

    for (int i = 0; i < TOTAL_VERTICES; i++)
        shortestDistances[i] = INT_MAX;

    shortestDistances[startVertex] = 0;

    for (int count = 0; count < TOTAL_VERTICES - 1; count++) {
        int u = getNearestVertex(shortestDistances, visitedVertices);
        visitedVertices[u] = 1;

        for (int v = 0; v < TOTAL_VERTICES; v++) {
            if (!visitedVertices[v] && adjacencyMatrix[u][v] != 0 &&
                shortestDistances[u] != INT_MAX &&
                shortestDistances[u] + adjacencyMatrix[u][v] < shortestDistances[v]) {
                shortestDistances[v] = shortestDistances[u] + adjacencyMatrix[u][v];
            }
        }
    }

    printf("\nVertex\tShortest Distance from Source %d\n", startVertex);
    for (int i = 0; i < TOTAL_VERTICES; i++) {
        if (shortestDistances[i] == INT_MAX)
            printf("%d\tINF\n", i);
        else
            printf("%d\t%d\n", i, shortestDistances[i]);
    }
}

int main() {
    int graphMatrix[TOTAL_VERTICES][TOTAL_VERTICES] = {
        {0, 2, 0, 1, 0, 0},
        {2, 0, 3, 2, 0, 0},
        {0, 3, 0, 0, 1, 5},
        {1, 2, 0, 0, 3, 0},
        {0, 0, 1, 3, 0, 2},
        {0, 0, 5, 0, 2, 0}
    };

    int startVertex = 0;
    printf("Calculating shortest paths from vertex %d...\n", startVertex);
    calculateShortestPaths(graphMatrix, startVertex);

    return 0;
}
