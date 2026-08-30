#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i)
{
    int largest = i;

    int left = 2 * i + 1;

    int right = 2 * i + 2;

    

    if (left < n && arr[left] > arr[largest])
        largest = left;


    if (right < n && arr[right] > arr[largest])
        largest = right;

    

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    

    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    

    for (int i = n - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);

        heapify(arr, i, 0);
    }
}

int main()
{
    int n, arr[1000];
    FILE *fp;

    printf("Enter number of random elements: ");
    scanf("%d", &n);

    srand(time(NULL));

    /* Create file */

    fp = fopen("heap_input.txt", "w");

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

    

    fp = fopen("heap_input.txt", "r");

    for (int i = 0; i < n; i++)
    {
        fscanf(fp, "%d", &arr[i]);
    }

    fclose(fp);



    heapSort(arr, n);

    

    fp = fopen("heap_output.txt", "w");

    fprintf(fp, "Sorted Numbers:\n");

    printf("\n\nSorted Numbers:\n");

    for (int i = 0; i < n; i++)
    {
        fprintf(fp, "%d ", arr[i]);

        printf("%d ", arr[i]);
    }

    fclose(fp);

    printf("\n\nSorted numbers stored in heap_output.txt");

    return 0;
}