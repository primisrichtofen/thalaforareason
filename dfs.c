#include <stdio.h>

#define V 5 // Number of vertices

void DFS(int graph[V][V], int visited[], int vertex) {
    visited[vertex] = 1; // Mark the current node as visited
    printf("%d ", vertex); // Print the current node

    // Recur for all adjacent vertices
    for (int i = 0; i < V; i++) {
        if (graph[vertex][i] && !visited[i]) {
            DFS(graph, visited, i);
        }
    }
}

int main() {
    int graph[V][V] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 0, 1},
        {0, 1, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };
    
    int visited[V] = {0}; // Keep track of visited vertices
    int startVertex = 0;  // Starting vertex for DFS

    printf("DFS Traversal starting from vertex %d:\n", startVertex);
    DFS(graph, visited, startVertex);

    return 0;
}
