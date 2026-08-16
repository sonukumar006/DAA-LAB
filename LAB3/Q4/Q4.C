#include <stdio.h>
#include <stdlib.h>

// Allocate memory for an n x n matrix
int** allocateMatrix(int n) {
    int** matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)calloc(n, sizeof(int));
    }
    return matrix;
}

// Free memory of an n x n matrix
void freeMatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Add two matrices: C = A + B
void addMatrix(int** A, int** B, int** C, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Subtract two matrices: C = A - B
void subtractMatrix(int** A, int** B, int** C, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Recursive Strassen's Matrix Multiplication
void strassen(int** A, int** B, int** C, int n) {
    // Base case: 1x1 matrix
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int k = n / 2;

    // Allocate submatrices
    int** A11 = allocateMatrix(k);
    int** A12 = allocateMatrix(k);
    int** A21 = allocateMatrix(k);
    int** A22 = allocateMatrix(k);

    int** B11 = allocateMatrix(k);
    int** B12 = allocateMatrix(k);
    int** B21 = allocateMatrix(k);
    int** B22 = allocateMatrix(k);

    int** C11 = allocateMatrix(k);
    int** C12 = allocateMatrix(k);
    int** C21 = allocateMatrix(k);
    int** C22 = allocateMatrix(k);

    int** M1 = allocateMatrix(k);
    int** M2 = allocateMatrix(k);
    int** M3 = allocateMatrix(k);
    int** M4 = allocateMatrix(k);
    int** M5 = allocateMatrix(k);
    int** M6 = allocateMatrix(k);
    int** M7 = allocateMatrix(k);

    int** tempA = allocateMatrix(k);
    int** tempB = allocateMatrix(k);

    // Divide matrices into 4 quadrants
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];
            A22[i][j] = A[i + k][j + k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }
    }

    // M1 = (A11 + A22) * (B11 + B22)
    addMatrix(A11, A22, tempA, k);
    addMatrix(B11, B22, tempB, k);
    strassen(tempA, tempB, M1, k);

    // M2 = (A21 + A22) * B11
    addMatrix(A21, A22, tempA, k);
    strassen(tempA, B11, M2, k);

    // M3 = A11 * (B12 - B22)
    subtractMatrix(B12, B22, tempB, k);
    strassen(A11, tempB, M3, k);

    // M4 = A22 * (B21 - B11)
    subtractMatrix(B21, B11, tempB, k);
    strassen(A22, tempB, M4, k);

    // M5 = (A11 + A12) * B22
    addMatrix(A11, A12, tempA, k);
    strassen(A11, B22, M5, k);

    // M6 = (A21 - A11) * (B11 + B12)
    subtractMatrix(A21, A11, tempA, k);
    addMatrix(B11, B12, tempB, k);
    strassen(tempA, tempB, M6, k);

    // M7 = (A12 - A22) * (B21 + B22)
    subtractMatrix(A12, A22, tempA, k);
    addMatrix(B21, B22, tempB, k);
    strassen(tempA, tempB, M7, k);

    // C11 = M1 + M4 - M5 + M7
    addMatrix(M1, M4, tempA, k);
    subtractMatrix(tempA, M5, tempB, k);
    addMatrix(tempB, M7, C11, k);

    // C12 = M3 + M5
    addMatrix(M3, M5, C12, k);

    // C21 = M2 + M4
    addMatrix(M2, M4, C21, k);

    // C22 = M1 - M2 + M3 + M6
    subtractMatrix(M1, M2, tempA, k);
    addMatrix(tempA, M3, tempB, k);
    addMatrix(tempB, M6, C22, k);

    // Combine quadrants into C
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            C[i][j] = C11[i][j];
            C[i][j + k] = C12[i][j];
            C[i + k][j] = C21[i][j];
            C[i + k][j + k] = C22[i][j];
        }
    }

    // Free all allocated memory
    freeMatrix(A11, k); freeMatrix(A12, k); freeMatrix(A21, k); freeMatrix(A22, k);
    freeMatrix(B11, k); freeMatrix(B12, k); freeMatrix(B21, k); freeMatrix(B22, k);
    freeMatrix(C11, k); freeMatrix(C12, k); freeMatrix(C21, k); freeMatrix(C22, k);
    freeMatrix(M1, k);  freeMatrix(M2, k);  freeMatrix(M3, k);  freeMatrix(M4, k);
    freeMatrix(M5, k);  freeMatrix(M6, k);  freeMatrix(M7, k);
    freeMatrix(tempA, k); freeMatrix(tempB, k);
}

// Find the next power of 2 for padding non-power-of-two matrices
int nextPowerOfTwo(int n) {
    int p = 1;
    while (p < n) p <<= 1;
    return p;
}

int main() {
    int n;
    printf("Enter matrix dimension n: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    int m = nextPowerOfTwo(n);

    int** A = allocateMatrix(m);
    int** B = allocateMatrix(m);
    int** C = allocateMatrix(m);

    printf("Enter elements of Matrix A (%dx%d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter elements of Matrix B (%dx%d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    strassen(A, B, C, m);

    printf("\nResultant Matrix C (%dx%d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    freeMatrix(A, m);
    freeMatrix(B, m);
    freeMatrix(C, m);

    return 0;
}