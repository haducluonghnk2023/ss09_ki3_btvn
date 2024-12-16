#include <stdio.h>

#define MAX 100

void calculateDegree(int graph[MAX][MAX], int n, int isDirected) {
    int degree[MAX] = {0};
    int maxDegree = 0, maxDegreeVertex = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] != 0) {
                degree[i]++;
                if (!isDirected) {
                    degree[j]++;
                }
            }
        }
    }

    printf("Bac cua tung dinh:\n");
    for (int i = 0; i < n; i++) {
        printf("Dinh %d: %d\n", i, degree[i]);
        if (degree[i] > maxDegree) {
            maxDegree = degree[i];
            maxDegreeVertex = i;
        }
    }
    printf("\nDinh co bac lon nhat: %d\n", maxDegreeVertex);
}

int main() {
    int graph[MAX][MAX];
    int n, edges, isDirected;
    int u, v;

    printf("Nhap so luong dinh cua do thi: ");
    scanf("%d", &n);

    printf("Nhap so luong canh cua do thi: ");
    scanf("%d", &edges);

    printf("Do thi co huong? (1 = Co huong, 0 = Vo huong): ");
    scanf("%d", &isDirected);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Nhap danh sach cac canh (dinh1 dinh2):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        if (!isDirected) {
            graph[v][u] = 1;
        }
    }

    calculateDegree(graph, n, isDirected);

    return 0;
}

