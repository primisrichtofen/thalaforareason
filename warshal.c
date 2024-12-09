#include <stdio.h>

#define V 6  // Number of vertices

// Function to apply Warshall's algorithm and compute the transitive closure
void warshall(int graph[V][V]) {
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
            }
        }
    }
}

// Function to find the topological sort of the graph using Warshall's algorithm
void topologicalSort(int graph[V][V]) {
    int reach[V][V];
    
    // Initialize reachability matrix as the adjacency matrix
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            reach[i][j] = graph[i][j];
        }
    }

    // Apply Warshall's algorithm
    warshall(reach);
    
    // For topological sort, select vertices with no incoming edges
    int visited[V] = {0};  // To track visited vertices
    printf("Topological Order: ");

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (!visited[j]) {
                int canVisit = 1;
                for (int k = 0; k < V; k++) {
                    if (reach[k][j] && !visited[k]) {
                        canVisit = 0;
                        break;
                    }
                }
                if (canVisit) {
                    printf("%d ", j);
                    visited[j] = 1;
                    break;
                }
            }
        }
    }
    printf("\n");
}

int main() {
    // Example graph (Adjacency matrix for a DAG)
    int graph[V][V] = {
        {0, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 1, 0, 0, 1},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0}
    };

    topologicalSort(graph);
    return 0;
}
