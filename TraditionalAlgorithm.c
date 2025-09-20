#include <stdio.h>
#include <time.h>  // for clock()

#define MAX 20   // maximum size for matrix

int main() {
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
    int n, i, j, k;
    clock_t start, end;   // clock variables

    printf("Enter order of square matrix: ");
    scanf("%d", &n);

    printf("\nEnter elements of Matrix A:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("\nEnter elements of Matrix B:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // initialize C matrix
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            C[i][j] = 0;
        }
    }

    // start clock
    start = clock();

    // multiplication logic
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            for(k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // end clock
    end = clock();

    printf("\nResultant Matrix (A*B) is:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    // memory usage
    size_t memory = sizeof(int) * n * n * 3; // A, B, C matrices
    printf("\nMemory used by matrices: %zu bytes\n", memory);

    // time taken
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for multiplication: %.6f seconds\n", time_taken);

    return 0;
}
