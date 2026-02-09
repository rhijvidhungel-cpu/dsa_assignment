#include <stdio.h>

#define LIMIT 12

int graph[LIMIT][LIMIT];
int mark[LIMIT];
int vertices;

void bfs(int start)
{
    int q[LIMIT];
    int f = 0, r = 0;

    for (int i = 0; i < vertices; i++)
        mark[i] = 0;

    q[r++] = start;
    mark[start] = 1;

    printf("BFS Traversal: ");
    while (f < r)
    {
        int node = q[f++];
        printf("%d ", node);

        for (int j = 0; j < vertices; j++)
        {
            if (graph[node][j] == 1 && mark[j] == 0)
            {
                q[r++] = j;
                mark[j] = 1;
            }
        }
    }
    printf("\n");
}

void dfs(int v)
{
    printf("%d ", v);
    mark[v] = 1;

    for (int i = 0; i < vertices; i++)
    {
        if (graph[v][i] == 1 && mark[i] == 0)
            dfs(i);
    }
}

int main()
{
    int edges;
    int a, b, start;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            graph[i][j] = 0;

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges:\n");
    for (int i = 0; i < edges; i++)
    {
        scanf("%d %d", &a, &b);
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    bfs(start);

    for (int i = 0; i < vertices; i++)
        mark[i] = 0;

    printf("DFS Traversal: ");
    dfs(start);
    printf("\n");

    return 0;
}
