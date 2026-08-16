#include <stdio.h>

int comparisons = 0;

struct MinMax
{
    int min;
    int max;
};

struct MinMax findMinMax(int arr[], int low, int high)
{
    struct MinMax result;
    struct MinMax left;
    struct MinMax right;

    // Base case: only one element
    if (low == high)
    {
        result.min = arr[low];
        result.max = arr[low];

        return result;
    }

    // Base case: two elements
    if (high == low + 1)
    {
        comparisons++;

        if (arr[low] < arr[high])
        {
            result.min = arr[low];
            result.max = arr[high];
        }
        else
        {
            result.min = arr[high];
            result.max = arr[low];
        }

        return result;
    }

    // Divide
    int mid = (low + high) / 2;

    // Conquer
    left = findMinMax(arr, low, mid);
    right = findMinMax(arr, mid + 1, high);

    // Combine: find minimum
    comparisons++;

    if (left.min < right.min)
        result.min = left.min;
    else
        result.min = right.min;

    // Combine: find maximum
    comparisons++;

    if (left.max > right.max)
        result.max = left.max;
    else
        result.max = right.max;

    return result;
}

int main()
{
    int n;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    struct MinMax result = findMinMax(arr, 0, n - 1);

    printf("\n========== RESULT ==========\n");

    printf("Minimum element = %d\n", result.min);
    printf("Maximum element = %d\n", result.max);

    printf("Number of comparisons = %d\n", comparisons);

    printf("Maximum allowed comparisons (3n/2) = %.0f\n",
           1.5 * n);

    if (comparisons <= 1.5 * n)
        printf("Comparison bound is satisfied.\n");
    else
        printf("Comparison bound is NOT satisfied.\n");

    return 0;
}