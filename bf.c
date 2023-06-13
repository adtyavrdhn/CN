#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    unsigned dist[20];
    unsigned from[20];
} rt[10];

int main(void) {
    int n = 0;
    printf("Enter the number of nodes: \n");
    scanf("%i", &n);

    printf("Enter the cost matrix: \n");

    int cost[n + 1][n + 1];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%i", &cost[i][j]);

            cost[i][i] = 0;

            rt[i].dist[j] = cost[i][j];
            rt[i].from[j] = j;
        }
    }

    int count = 0;
    int maxIterations = n - 1;

    do {
        count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (rt[i].dist[j] > cost[i][k] + rt[k].dist[j]) {
                        rt[i].dist[j] = rt[i].dist[k] + rt[k].dist[j];
                        rt[i].from[j] = k;
                        count++;
                    }
                }
            }
        }
        maxIterations--;
    } while (count != 0 && maxIterations >= 0);

    if (maxIterations < 0) {
        printf("Negative cycle detected!\n");
    } else {
        for (int i = 0; i < n; i++) {
            printf("For router %i\n", i);

            for (int j = 0; j < n; j++) {
                printf("Node %i via %i, Cost: %i \n", j, rt[i].from[j], rt[i].dist[j]);
            }
            printf("\n");
        }
    }
}
