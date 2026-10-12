#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int distance;
    int fuel;
} Station;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void push(int heap[], int *size, int value)
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

int popMax(int heap[], int *size)
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
    int n, D, F;

    printf("Enter target distance: ");
    scanf("%d", &D);

    printf("Enter initial fuel: ");
    scanf("%d", &F);

    printf("Enter number of stations: ");
    scanf("%d", &n);

    Station stations[n];

    printf("Enter station distance and fuel:\n");

    for (int i = 0; i < n; i++)
        scanf("%d %d",
              &stations[i].distance,
              &stations[i].fuel);

    int heap[n];
    int heapSize = 0;

    int currentFuel = F;
    int previous = 0;
    int stops = 0;

    for (int i = 0; i <= n; i++)
    {
        int position =
            (i == n) ? D : stations[i].distance;

        int distance = position - previous;

        currentFuel -= distance;

        while (currentFuel < 0 && heapSize > 0)
        {
            currentFuel +=
                popMax(heap, &heapSize);

            stops++;
        }

        if (currentFuel < 0)
        {
            printf("Target cannot be reached.\n");
            return 0;
        }

        if (i < n)
            push(heap, &heapSize, stations[i].fuel);

        previous = position;
    }

    printf("Minimum number of refuelling stops = %d\n",
           stops);

    return 0;
}