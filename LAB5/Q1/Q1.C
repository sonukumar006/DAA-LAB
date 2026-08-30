#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }

    swap(&arr[i], &arr[high]);

    return i;
}

int quickSelect(int arr[], int low, int high, int k)
{
    if (low == high)
        return arr[low];

    int pivotIndex = partition(arr, low, high);

    if (pivotIndex == k)
        return arr[pivotIndex];

    else if (k < pivotIndex)
        return quickSelect(arr, low, pivotIndex - 1, k);

    else
        return quickSelect(arr, pivotIndex + 1, high, k);
}

int main()
{
    int n, arr[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    if (n % 2 != 0)
    {
        int median = quickSelect(arr, 0, n - 1, n / 2);

        printf("Median = %d", median);
    }
    else
    {
        int median1 = quickSelect(arr, 0, n - 1, n / 2 - 1);

        int median2 = quickSelect(arr, 0, n - 1, n / 2);

        printf("Median = %.2f", (median1 + median2) / 2.0);
    }

    return 0;
}