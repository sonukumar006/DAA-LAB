#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(int heap[], int *size, int value)
{
    int i = (*size)++;
    heap[i] = value;

    while (i > 0)
    {
        int parent = (i - 1) / 2;

        if (heap[parent] <= heap[i])
            break;

        swap(&heap[parent], &heap[i]);
        i = parent;
    }
}

int extractMin(int heap[], int *size)
{
    int result = heap[0];

    heap[0] = heap[--(*size)];

    int i = 0;

    while (1)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < *size &&
            heap[left] < heap[smallest])
            smallest = left;

        if (right < *size &&
            heap[right] < heap[smallest])
            smallest = right;

        if (smallest == i)
            break;

        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }

    return result;
}

int main()
{
    int n;

    printf("Enter number of sticks: ");
    scanf("%d", &n);

    int heap[n];

    printf("Enter stick lengths:\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &heap[i]);

    int size = n;

    /* Build min heap */
    for (int i = 1; i < n; i++)
    {
        int j = i;

        while (j > 0)
        {
            int parent = (j - 1) / 2;

            if (heap[parent] <= heap[j])
                break;

            swap(&heap[parent], &heap[j]);
            j = parent;
        }
    }

    long long totalCost = 0;

    while (size > 1)
    {
        int x = extractMin(heap, &size);
        int y = extractMin(heap, &size);

        int combined = x + y;

        totalCost += combined;

        insert(heap, &size, combined);

        printf("Connect %d + %d = %d\n",
               x, y, combined);
    }

    printf("Minimum total cost = %lld\n",
           totalCost);

    return 0;
}