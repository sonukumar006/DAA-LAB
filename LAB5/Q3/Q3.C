#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;

            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);

    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);

        quickSort(arr, pivotIndex + 1, high);
    }
}

int main()
{
    int n, arr[1000];
    FILE *fp;

    printf("Enter number of random elements: ");
    scanf("%d", &n);

    srand(time(NULL));

    

    fp = fopen("input.txt", "w");

    if (fp == NULL)
    {
        printf("File cannot be opened.");
        return 1;
    }

    printf("\nRandom Numbers:\n");

    for (int i = 0; i < n; i++)
    {
        int num = rand() % 1000;

        fprintf(fp, "%d ", num);

        printf("%d ", num);
    }

    fclose(fp);

    

    fp = fopen("input.txt", "r");

    for (int i = 0; i < n; i++)
    {
        fscanf(fp, "%d", &arr[i]);
    }

    fclose(fp);

    

    quickSort(arr, 0, n - 1);



    fp = fopen("output.txt", "w");

    fprintf(fp, "Sorted Numbers:\n");

    printf("\n\nSorted Numbers:\n");

    for (int i = 0; i < n; i++)
    {
        fprintf(fp, "%d ", arr[i]);

        printf("%d ", arr[i]);
    }

    fclose(fp);

    printf("\n\nSorted numbers stored in output.txt");

    return 0;
}