#include <stdio.h>

// Binary Search
int binarySearch(int arr[], int n, int x, int *comparisons)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        (*comparisons)++;

        if (arr[mid] == x)
            return mid;

        if (x < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
}

// Ternary Search
int ternarySearch(int arr[], int n, int x, int *comparisons)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid1 = low + (high - low) / 3;
        int mid2 = high - (high - low) / 3;

        (*comparisons)++;

        if (arr[mid1] == x)
            return mid1;

        (*comparisons)++;

        if (arr[mid2] == x)
            return mid2;

        if (x < arr[mid1])
        {
            high = mid1 - 1;
        }
        else if (x > arr[mid2])
        {
            low = mid2 + 1;
        }
        else
        {
            low = mid1 + 1;
            high = mid2 - 1;
        }
    }

    return -1;
}

int main()
{
    int n, x;
    int binaryComparisons = 0;
    int ternaryComparisons = 0;

    printf("Enter the size of sorted array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements in sorted order:\n", n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &x);

    // Binary Search
    int binaryResult = binarySearch(
        arr, n, x, &binaryComparisons
    );

    // Ternary Search
    int ternaryResult = ternarySearch(
        arr, n, x, &ternaryComparisons
    );

    printf("\n========== RESULTS ==========\n");

    if (binaryResult != -1)
        printf("Binary Search: Element found at index %d\n",
               binaryResult);
    else
        printf("Binary Search: Element not found\n");

    printf("Binary Search Comparisons: %d\n",
           binaryComparisons);

    if (ternaryResult != -1)
        printf("Ternary Search: Element found at index %d\n",
               ternaryResult);
    else
        printf("Ternary Search: Element not found\n");

    printf("Ternary Search Comparisons: %d\n",
           ternaryComparisons);

    printf("\n========== COMPARISON ==========\n");

    if (binaryComparisons < ternaryComparisons)
        printf("Binary Search is better for this input.\n");
    else if (binaryComparisons > ternaryComparisons)
        printf("Ternary Search is better for this input.\n");
    else
        printf("Both performed the same number of comparisons.\n");

    return 0;
}