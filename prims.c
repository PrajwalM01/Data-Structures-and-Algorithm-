#include <stdio.h>
#include <limits.h> // For INT_MAX

#define MAX 10

int dcount = 0; // Global counter for basic operations

void prims(int n, int cost[MAX][MAX]) {
    int parent[MAX];  // Array to store the parent of each vertex in the MST
    int key[MAX];     // Key values used to pick the minimum weight edge
    int visited[MAX]; // To keep track of vertices included in the MST
    int totalCost = 0; // Variable to store the total cost of the MST

    // Initialize all keys as infinity and visited as false
    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        visited[i] = 0;
    }

    // Start with the first vertex
    key[0] = 0; // The starting vertex is always included in MST first
    parent[0] = -1; // The root node does not have a parent

    for (int count = 0; count < n - 1; count++) {
        // Find the vertex with the minimum key value that is not yet included in the MST
        int min = INT_MAX, u;
        for (int v = 0; v < n; v++) {
            if (!visited[v] && key[v] < min) {
                min = key[v];
                u = v;
            }
        }

        // Add the selected vertex to the MST
        visited[u] = 1;
       // totalCost += key[u]; // Add the weight of the edge connecting u to its parent to the total cost

        // Update the key values and parent of the adjacent vertices
        for (int v = 0; v < n; v++) {
            if (cost[u][v] && !visited[v] && cost[u][v] < key[v]) {
                parent[v] = u;
                key[v] = cost[u][v];
                dcount++; // Increment operation count
            }
        }
    }

    // Print the constructed MST
    printf("Edge \tWeight\n");
    for (int i = 1; i < n; i++) {
        printf("%d - %d \t%d\n", parent[i], i, cost[i][parent[i]]);
        totalCost += cost[i][parent[i]];
    }

    // Print the total cost of the MST
    printf("Total cost of the Minimum Spanning Tree: %d\n", totalCost);
    printf("Basic count %d\n", dcount);
}

int main() {
    int n, cost[MAX][MAX];

    printf("Enter the number of nodes in the graph\n");
    scanf("%d", &n);

    printf("Enter the cost matrix\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (i != j && cost[i][j] == 0) {
                cost[i][j] = INT_MAX; // Use INT_MAX to represent no direct path
            }
        }
    }

    prims(n, cost);

    return 0;
}
