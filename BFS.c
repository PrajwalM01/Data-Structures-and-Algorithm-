
#include <stdio.h>

#define MAX 10

int n, i, j, visited[MAX], queue[MAX], front = 0, rear = -1;
int adj[MAX][MAX];
int parent[MAX];
int iscycle(int start)
{
    int cur;
    for(i=0;i<n;i++)
    {
        visited[i]=0;
        parent[i]=-1;

    }
    queue[++rear]=start;
    visited[start]=1;
    while(front<=rear)
    {
        cur= queue[front++];
        for(i=0;i<n;i++)
        {
            if(adj[cur][i])
            {
                if(!visited[i])
                  {
                    queue[++rear]=i;
                     visited[i]=1;
                     parent[i]=1;
                  }
                  else if(i != parent[cur])
                     return 1;
            }
        }

    }
    return 0;
}

void bfs(int start) {
    // Enqueue the starting vertex and mark it as visited
    queue[++rear] = start;
    visited[start] = 1;

    printf("BFS Traversal Order:\n");

    while (front <= rear) {
        // Dequeue a vertex from queue
        int current = queue[front++];
        printf("%d ", current);

        // Process all adjacent vertices of the dequeued vertex
        for (i = 0; i < n; i++) {
            if (adj[current][i] && !visited[i]) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int v;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Check if the number of vertices exceeds MAX
    if (n > MAX) {
        printf("Number of vertices exceeds the maximum allowed (%d).\n", MAX);
        return 1;
    }

    // Initialize the visited array and queue
    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("Enter graph data in matrix form:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter the starting vertex (0 to %d): ", n - 1);
    scanf("%d", &v);

    // Validate the starting vertex
    if (v < 0 || v >= n) {
        printf("Invalid starting vertex.\n");
        return 1;
    }

    bfs(v);

    return 0;
}

