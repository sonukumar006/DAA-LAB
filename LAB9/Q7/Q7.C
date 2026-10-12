#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertMaxHeap(int heap[], int *size, int value)
{
    int i = (*size)++;
    heap[i] = value;

    while (i > 0)
    {
        int parent = (i - 1) / 2;

        if (heap[parent] >= heap[i])
            break;

        swap(&heap[parent], &heap[i]);
        i = parent;
    }
}

int removeMax(int heap[], int *size)
{
    int result = heap[0];

    heap[0] = heap[--(*size)];

    int i = 0;

    while (1)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < *size &&
            heap[left] > heap[largest])
            largest = left;

        if (right < *size &&
            heap[right] > heap[largest])
            largest = right;

        if (largest == i)
            break;

        swap(&heap[i], &heap[largest]);
        i = largest;
    }

    return result;
}

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int heap[n];
    int size = 0;

    printf("Enter array elements:\n");

    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);

        /* Make every odd number even */
        if (x % 2 != 0)
            x *= 2;

        insertMaxHeap(heap, &size, x);
    }

    int minValue = INT_MAX;

    for (int i = 0; i < size; i++)
    {
        if (heap[i] < minValue)
            minValue = heap[i];
    }

    int minDeviation = INT_MAX;

    while (size > 0)
    {
        int maxValue = removeMax(heap, &size);

        int deviation = maxValue - minValue;

        if (deviation < minDeviation)
            minDeviation = deviation;

        /*
         * If maximum is odd, it cannot be
         * divided further.
         */
        if (maxValue % 2 != 0)
            break;

        maxValue /= 2;

        if (maxValue < minValue)
            minValue = maxValue;

        insertMaxHeap(heap, &size, maxValue);
    }

    printf("\nMinimum deviation = %d\n",
           minDeviation);

    return 0;
}