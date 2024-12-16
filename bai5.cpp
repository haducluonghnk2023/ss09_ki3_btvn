#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

void dijkstra(int graph[MAX][MAX], int n, int start) {
    int distance[MAX];
    int visited[MAX] = {0};
    int i, j, minDistance, nextVertex;

    for (i = 0; i < n; i++) {
        distance[i] = INF;
    }
    distance[start] = 0;

    for (i = 0; i < n - 1; i++) {
        minDistance = INF;
        for (j = 0; j < n; j++) {
            if (!visited[j] && distance[j] < minDistance) {
                minDistance = distance[j];
                nextVertex = j;
            }
        }
        visited[nextVertex] = 1;

        for (j = 0; j < n; j++) {
            if (!visited[j] && graph[nextVertex][j] != 0 && distance[nextVertex] != INF &&
                distance[nextVertex] + graph[nextVertex][j] < distance[j]) {
                distance[j] = distance[nextVertex] + graph[nextVertex][j];
            }
        }
    }

    printf("Khoang cach ngan nhat tu dinh %d den cac dinh khac:\n", start);
    for (i = 0; i < n; i++) {
        if (distance[i] == INF) {
            printf("Dinh %d: Khong the di toi\n", i);
        } else {
            printf("Dinh %d: %d\n", i, distance[i]);
        }
    }
}

int main() {
    int graph[MAX][MAX];
    int n, edges, i, j, start, u, v, weight;

    printf("Nhap so luong dinh cua do thi: ");
    scanf("%d", &n);

    printf("Nhap so luong canh cua do thi: ");
    scanf("%d", &edges);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Nhap danh sach cac canh (dinh1 dinh2 trong so):\n");
    for (i = 0; i < edges; i++) {
        scanf("%d %d %d", &u, &v, &weight);
        graph[u][v] = weight;
        graph[v][u] = weight; // Bo dong nay neu do thi co huong
    }

    printf("Nhap dinh bat dau: ");
    scanf("%d", &start);

    dijkstra(graph, n, start);

    return 0;
}

