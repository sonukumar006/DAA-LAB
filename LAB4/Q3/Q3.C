#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int binarySearch(int arr[], int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return 1;

        if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return 0;
}

int findKSum(int arr[], int n, int k,
             int start, int target) {

    // Last element
    if (k == 1) {
        return binarySearch(arr, start, n - 1, target);
    }

    for (int i = start; i <= n - k; i++) {

        if (findKSum(arr, n, k - 1,
                     i + 1, target - arr[i])) {
            return 1;
        }
    }

    return 0;
}

int main() {
    int n, k, T;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter k: ");
    scanf("%d", &k);

    printf("Enter target T: ");
    scanf("%d", &T);

    qsort(arr, n, sizeof(int), compare);

    if (k > n || k <= 0) {
        printf("Invalid value of k.\n");
        return 0;
    }

    if (findKSum(arr, n, k, 0, T))
        printf("\nYes, %d elements can sum to %d.\n", k, T);
    else
        printf("\nNo, %d elements can sum to %d.\n", k, T);

    return 0;
}