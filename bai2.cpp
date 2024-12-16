#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int isSymmetric(int matrix[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                return 0;
            }
        }
    }
    return 1; 
}

int main() {
    int n, edges;
    int matrix[MAX][MAX] = {0}; 

    printf("Nhap so luong dinh cua do thi: ");
    scanf("%d", &n);

    printf("Nhap so luong canh cua do thi: ");
    scanf("%d", &edges);

    printf("Nhap cac canh cua do thi ( c1, c2 ):\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        matrix[u][v] = 1; 
        matrix[v][u] = 1; 
    }

    printf("\nMa tran ke cua do thi:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    if (isSymmetric(matrix, n)) {
        printf("\nMa tran ke la doi xung.\n");
    } else {
        printf("\nMa tran ke la khong doi xung.\n");
    }

    return 0;
}

