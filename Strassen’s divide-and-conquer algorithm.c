#include <stdio.h>
#include <stdlib.h>
#include <time.h>  // for clock()

// function to allocate memory for n x n matrix
int** createMatrix(int n) {
    int **mat = (int**)malloc(n * sizeof(int*));
    for(int i = 0; i < n; i++) {
        mat[i] = (int*)malloc(n * sizeof(int));
    }
    return mat;
}

// add two matrices
void addMatrix(int **A, int **B, int **C, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// subtract two matrices
void subMatrix(int **A, int **B, int **C, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

// recursive multiplication using divide & conquer
void multiply(int **A, int **B, int **C, int n) {
    if(n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int k = n/2;

    // allocate submatrices
    int **A11 = createMatrix(k); int **A12 = createMatrix(k);
    int **A21 = createMatrix(k); int **A22 = createMatrix(k);
    int **B11 = createMatrix(k); int **B12 = createMatrix(k);
    int **B21 = createMatrix(k); int **B22 = createMatrix(k);
    int **C11 = createMatrix(k); int **C12 = createMatrix(k);
    int **C21 = createMatrix(k); int **C22 = createMatrix(k);
    int **M1  = createMatrix(k); int **M2  = createMatrix(k);

    // dividing matrices into parts
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < k; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j+k];
            A21[i][j] = A[i+k][j];
            A22[i][j] = A[i+k][j+k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j+k];
            B21[i][j] = B[i+k][j];
            B22[i][j] = B[i+k][j+k];
        }
    }

    // recursive multiplications
    multiply(A11, B11, C11, k);
    multiply(A12, B21, M1, k);
    addMatrix(C11, M1, C11, k);

    multiply(A11, B12, C12, k);
    multiply(A12, B22, M1, k);
    addMatrix(C12, M1, C12, k);

    multiply(A21, B11, C21, k);
    multiply(A22, B21, M1, k);
    addMatrix(C21, M1, C21, k);

    multiply(A21, B12, C22, k);
    multiply(A22, B22, M2, k);
    addMatrix(C22, M2, C22, k);

    // combining result
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < k; j++) {
            C[i][j]       = C11[i][j];
            C[i][j+k]     = C12[i][j];
            C[i+k][j]     = C21[i][j];
            C[i+k][j+k]   = C22[i][j];
        }
    }
}

int main() {
    int n;
    clock_t start, end;  // clock variables

    printf("Enter order of square matrix (power of 2): ");
    scanf("%d", &n);

    int **A = createMatrix(n);
    int **B = createMatrix(n);
    int **C = createMatrix(n);

    printf("\nEnter Matrix A:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("\nEnter Matrix B:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // initialize C
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            C[i][j] = 0;
        }
    }

    // start clock
    start = clock();
    multiply(A, B, C, n);
    // end clock
    end = clock();

    printf("\nResultant Matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    // memory usage (for matrices A, B, C)
    size_t memory = sizeof(int) * n * n * 3;
    printf("\nMemory used by matrices: %zu bytes\n", memory);

    // time taken
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for multiplication: %.6f seconds\n", time_taken);

    return 0;
}

