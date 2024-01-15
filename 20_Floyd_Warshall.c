#include <stdio.h>
#include <limits.h>
void floydWarshall(int n) {
    int dist[n][n];
    // Input the distance matrix
    printf("Enter the distance matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);
            if (i != j && dist[i][j] == 0) {
                // Replace 0 with INT_MAX for unconnected vertices (excluding the diagonal)
                dist[i][j] = INT_MAX;
            }
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    // Output the shortest distances
    printf("Shortest distances between every pair of vertices:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INT_MAX) {
                printf("INF\t");
            } else {
                printf("%d\t", dist[i][j]);
            }
        }
        printf("\n");
    }
}
int main() {
    int n;
    printf("Enter the number of vertices (n): ");
    scanf("%d", &n);
    floydWarshall(n);
    return 0;
}
