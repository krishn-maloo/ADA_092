#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

void dfs(int graph[MAX_SIZE][MAX_SIZE], int vertex, bool visited[], int numVertices) {
    visited[vertex] = true;
    printf("%d ", vertex);

    for (int i = 0; i < numVertices; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            dfs(graph, i, visited, numVertices);
        }
    }
}

int main() {
    int numVertices;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    int graph[MAX_SIZE][MAX_SIZE];
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    bool visited[MAX_SIZE];
    for (int i = 0; i < numVertices; i++) {
        visited[i] = false;
    }

    int startVertex;
    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    printf("Depth-First Search traversal: ");
    dfs(graph, startVertex, visited, numVertices);
    printf("\n");

    return 0;
}
