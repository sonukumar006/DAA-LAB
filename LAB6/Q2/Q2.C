#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 20

void inputMatrix(double a[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%lf", &a[i][j]);
}

void display(double a[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%8.2lf ", a[i][j]);

        printf("\n");
    }
}

void addition(double a[MAX][MAX], double b[MAX][MAX],
              double c[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            c[i][j] = a[i][j] + b[i][j];
}

void multiplication(double a[MAX][MAX], double b[MAX][MAX],
                    double c[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            c[i][j] = 0;

            for (int k = 0; k < n; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
}

int isZeroMatrix(double a[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (fabs(a[i][j]) > 1e-9)
                return 0;

    return 1;
}

int isSymmetric(double a[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (fabs(a[i][j] - a[j][i]) > 1e-9)
                return 0;

    return 1;
}

double determinant(double a[MAX][MAX], int n)
{
    double temp[MAX][MAX];
    double det = 1;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            temp[i][j] = a[i][j];

    for (int i = 0; i < n; i++)
    {
        int pivot = i;

        for (int j = i + 1; j < n; j++)
            if (fabs(temp[j][i]) > fabs(temp[pivot][i]))
                pivot = j;

        if (fabs(temp[pivot][i]) < 1e-9)
            return 0;

        if (pivot != i)
        {
            for (int j = 0; j < n; j++)
            {
                double x = temp[i][j];
                temp[i][j] = temp[pivot][j];
                temp[pivot][j] = x;
            }

            det = -det;
        }

        det *= temp[i][i];

        for (int j = i + 1; j < n; j++)
        {
            double factor = temp[j][i] / temp[i][i];

            for (int k = i; k < n; k++)
                temp[j][k] -= factor * temp[i][k];
        }
    }

    return det;
}

void transpose(double a[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            double temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
}

void eigenvalues(double a[MAX][MAX], int n)
{
    double x[MAX] = {0};

    x[0] = 1;

    for (int iteration = 0; iteration < 1000; iteration++)
    {
        double y[MAX] = {0};
        double norm = 0;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                y[i] += a[i][j] * x[j];

        for (int i = 0; i < n; i++)
            norm += y[i] * y[i];

        norm = sqrt(norm);

        for (int i = 0; i < n; i++)
            x[i] = y[i] / norm;
    }

    double y[MAX] = {0};

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            y[i] += a[i][j] * x[j];

    double lambda = 0;

    for (int i = 0; i < n; i++)
        lambda += x[i] * y[i];

    printf("Dominant Eigenvalue = %.6lf\n", lambda);
    printf("Corresponding Eigenvector:\n");

    for (int i = 0; i < n; i++)
        printf("%.6lf\n", x[i]);
}

int main()
{
    int n, choice;
    double A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];

    printf("Enter order of matrix: ");
    scanf("%d", &n);

    printf("Enter Matrix A:\n");
    inputMatrix(A, n);

    printf("\n1. Addition");
    printf("\n2. Multiplication");
    printf("\n3. Zero Matrix");
    printf("\n4. Symmetric Matrix");
    printf("\n5. Determinant");
    printf("\n6. In-place Transpose");
    printf("\n7. Eigenvalue and Eigenvector");
    printf("\nEnter choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter Matrix B:\n");
            inputMatrix(B, n);

            addition(A, B, C, n);

            printf("A + B =\n");
            display(C, n);
            break;

        case 2:
            printf("Enter Matrix B:\n");
            inputMatrix(B, n);

            multiplication(A, B, C, n);

            printf("A * B =\n");
            display(C, n);
            break;

        case 3:
            if (isZeroMatrix(A, n))
                printf("Matrix is a zero matrix.\n");
            else
                printf("Matrix is not a zero matrix.\n");
            break;

        case 4:
            if (isSymmetric(A, n))
                printf("Matrix is symmetric.\n");
            else
                printf("Matrix is not symmetric.\n");
            break;

        case 5:
            printf("Determinant = %.2lf\n", determinant(A, n));
            break;

        case 6:
            transpose(A, n);
            printf("Transpose:\n");
            display(A, n);
            break;

        case 7:
            eigenvalues(A, n);
            break;

        default:
            printf("Invalid choice\n");
    }

    return 0;
}