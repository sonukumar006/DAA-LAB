#include <stdio.h>

#define MAX 64

// Add two matrices
void addMatrix(int A[MAX][MAX], int B[MAX][MAX],
               int C[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Subtract two matrices
void subtractMatrix(int A[MAX][MAX], int B[MAX][MAX],
                    int C[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Strassen Matrix Multiplication
void strassen(int A[MAX][MAX], int B[MAX][MAX],
              int C[MAX][MAX], int n)
{
    // Base case
    if (n == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int k = n / 2;

    int A11[MAX][MAX], A12[MAX][MAX];
    int A21[MAX][MAX], A22[MAX][MAX];

    int B11[MAX][MAX], B12[MAX][MAX];
    int B21[MAX][MAX], B22[MAX][MAX];

    int M1[MAX][MAX], M2[MAX][MAX];
    int M3[MAX][MAX], M4[MAX][MAX];
    int M5[MAX][MAX], M6[MAX][MAX];
    int M7[MAX][MAX];

    int temp1[MAX][MAX], temp2[MAX][MAX];

    // Divide A and B into four submatrices

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
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

    addMatrix(A11, A22, temp1, k);
    addMatrix(B11, B22, temp2, k);
    strassen(temp1, temp2, M1, k);

    // M2 = (A21 + A22) * B11

    addMatrix(A21, A22, temp1, k);
    strassen(temp1, B11, M2, k);

    // M3 = A11 * (B12 - B22)

    subtractMatrix(B12, B22, temp2, k);
    strassen(A11, temp2, M3, k);

    // M4 = A22 * (B21 - B11)

    subtractMatrix(B21, B11, temp2, k);
    strassen(A22, temp2, M4, k);

    // M5 = (A11 + A12) * B22

    addMatrix(A11, A12, temp1, k);
    strassen(temp1, B22, M5, k);

    // M6 = (A21 - A11) * (B11 + B12)

    subtractMatrix(A21, A11, temp1, k);
    addMatrix(B11, B12, temp2, k);
    strassen(temp1, temp2, M6, k);

    // M7 = (A12 - A22) * (B21 + B22)

    subtractMatrix(A12, A22, temp1, k);
    addMatrix(B21, B22, temp2, k);
    strassen(temp1, temp2, M7, k);

    // C11 = M1 + M4 - M5 + M7

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            C[i][j] =
                M1[i][j] +
                M4[i][j] -
                M5[i][j] +
                M7[i][j];
        }
    }

    // C12 = M3 + M5

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            C[i][j + k] =
                M3[i][j] +
                M5[i][j];
        }
    }

    // C21 = M2 + M4

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            C[i + k][j] =
                M2[i][j] +
                M4[i][j];
        }
    }

    // C22 = M1 - M2 + M3 + M6

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            C[i + k][j + k] =
                M1[i][j] -
                M2[i][j] +
                M3[i][j] +
                M6[i][j];
        }
    }
}

// Print matrix
void printMatrix(int A[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", A[i][j]);
        }

        printf("\n");
    }
}

// Check whether n is a power of 2
int isPowerOfTwo(int n)
{
    return (n > 0 && (n & (n - 1)) == 0);
}

int main()
{
    int n;

    int A[MAX][MAX];
    int B[MAX][MAX];
    int C[MAX][MAX];

    printf("Enter the size of matrices: ");
    scanf("%d", &n);

    if (!isPowerOfTwo(n))
    {
        printf("Matrix size must be a power of 2.\n");
        printf("Example: 2, 4, 8, 16, 32...\n");
        return 0;
    }

    if (n > MAX)
    {
        printf("Matrix size exceeds maximum limit.\n");
        return 0;
    }

    printf("\nEnter elements of Matrix A:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    printf("\nEnter elements of Matrix B:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &B[i][j]);
        }
    }

    // Perform Strassen multiplication
    strassen(A, B, C, n);

    printf("\nMatrix A:\n");
    printMatrix(A, n);

    printf("\nMatrix B:\n");
    printMatrix(B, n);

    printf("\nResult Matrix (A x B):\n");
    printMatrix(C, n);

    return 0;
}
