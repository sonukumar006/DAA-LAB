#include <stdio.h>

long long comparisons = 0;

void selectionSort(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            comparisons++;

            if (A[j] < A[minIndex])
            {
                minIndex = j;
            }
        }

        // Swap
        int temp = A[i];
        A[i] = A[minIndex];
        A[minIndex] = temp;
    }
}

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int A[n];

    printf("Enter elements:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    selectionSort(A, n);

    printf("\nSorted array:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }

    printf("\n\nNumber of comparisons = %lld\n",
           comparisons);

    printf("Theoretical comparisons = %lld\n",
           (long long)n * (n - 1) / 2);

    return 0;
}