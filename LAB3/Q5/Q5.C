#include <stdio.h>

#define MAX 64

void add(int A[MAX][MAX], int B[MAX][MAX],
         int C[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void specialMultiply(int A[MAX][MAX],
                     int B[MAX][MAX],
                     int C[MAX][MAX],
                     int n)
{
    // Base case
    if (n == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int k = n / 2;

    int A1[MAX][MAX] = {0};
    int A2[MAX][MAX] = {0};

    int B1[MAX][MAX] = {0};
    int B2[MAX][MAX] = {0};

    int P[MAX][MAX] = {0};
    int Q[MAX][MAX] = {0};
    int R[MAX][MAX] = {0};
    int S[MAX][MAX] = {0};

    int C1[MAX][MAX] = {0};
    int C2[MAX][MAX] = {0};

    /*
        A = | A1 A2 |
            | A2 A1 |

        B = | B1 B2 |
            | B2 B1 |
    */

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            A1[i][j] = A[i][j];
            A2[i][j] = A[i][j + k];

            B1[i][j] = B[i][j];
            B2[i][j] = B[i][j + k];
        }
    }

    // P = A1 * B1
    specialMultiply(A1, B1, P, k);

    // Q = A2 * B2
    specialMultiply(A2, B2, Q, k);

    // R = A1 * B2
    specialMultiply(A1, B2, R, k);

    // S = A2 * B1
    specialMultiply(A2, B1, S, k);

    // C1 = P + Q
    add(P, Q, C1, k);

    // C2 = R + S
    add(R, S, C2, k);

    /*
        C = | C1 C2 |
            | C2 C1 |
    */

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            C[i][j] = C1[i][j];
            C[i][j + k] = C2[i][j];

            C[i + k][j] = C2[i][j];
            C[i + k][j + k] = C1[i][j];
        }
    }
}

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

int main()
{
    int n;
    int A[MAX][MAX] = {0};
    int B[MAX][MAX] = {0};
    int C[MAX][MAX] = {0};

    printf("Enter n: ");
    scanf("%d", &n);

    if (n <= 0 || (n & (n - 1)) != 0)
    {
        printf("n must be a power of 2.\n");
        return 0;
    }

    printf("Enter Matrix A:\n");

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    printf("Enter Matrix B:\n");

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &B[i][j]);

    specialMultiply(A, B, C, n);

    printf("\nMatrix A:\n");
    printMatrix(A, n);

    printf("\nMatrix B:\n");
    printMatrix(B, n);

    printf("\nA x B:\n");
    printMatrix(C, n);

    return 0;
}