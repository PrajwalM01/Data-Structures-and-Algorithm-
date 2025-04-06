#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int n, i, j, inDegree[MAX], adj[MAX][MAX], topoStack[MAX];
int topoTop = -1, count = 0;

// Function to perform topological sort using Kahn's algorithm
void topologicalSort() {
    int queue[MAX], front = 0, rear = 0;
    
    // Initialize in-degrees and queue
    for (i = 0; i < n; i++) {
        inDegree[i] = 0;
    }
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (adj[i][j]) {
                inDegree[j]++;
            }
        }
    }
    
    // Add nodes with zero in-degree to the queue
    for (i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    // Process nodes in the queue
    while (front != rear) {
        int u = queue[front++];
        topoStack[++topoTop] = u; // Add node to topological order
        
        for (j = 0; j < n; j++) {
            if (adj[u][j]) {
                inDegree[j]--;
                if (inDegree[j] == 0) {
                    queue[rear++] = j;
                }
            }
        }
    }

    // Check for cycles: if topoTop != n-1, there was a cycle
    if (topoTop == n - 1) {
        // Print the topological order
        printf("Topological Sort Order:\n");
        for (i = 0; i <= topoTop; i++) {
            printf("%d ", topoStack[i]);
        }
        printf("\n");
    } else {
        printf("The graph is not a DAG. Topological sorting is not possible.\n");
    }
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter graph data in adjacency matrix form:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    topologicalSort();
    
    // Write to file
    FILE *fp = fopen("topologicalbest.txt", "a");
    if (fp != NULL) {
        fprintf(fp, "%d\n", n);
        for (i = 0; i <= topoTop; i++) {
            fprintf(fp, "%d ", topoStack[i]);
        }
        fprintf(fp, "\n");
        fclose(fp);
    } else {
        printf("Error opening file for writing.\n");
    }

    return 0;
}
