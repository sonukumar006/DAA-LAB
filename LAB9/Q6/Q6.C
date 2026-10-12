#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ASCII 256

typedef struct
{
    char ch;
    int frequency;
} Node;

void swap(Node *a, Node *b)
{
    Node temp = *a;
    *a = *b;
    *b = temp;
}

void push(Node heap[], int *size, Node value)
{
    int i = (*size)++;

    heap[i] = value;

    while (i > 0)
    {
        int parent = (i - 1) / 2;

        if (heap[parent].frequency >=
            heap[i].frequency)
            break;

        swap(&heap[parent], &heap[i]);
        i = parent;
    }
}

Node pop(Node heap[], int *size)
{
    Node result = heap[0];

    heap[0] = heap[--(*size)];

    int i = 0;

    while (1)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < *size &&
            heap[left].frequency >
            heap[largest].frequency)
            largest = left;

        if (right < *size &&
            heap[right].frequency >
            heap[largest].frequency)
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
    char S[1000];
    int K;

    printf("Enter string: ");
    scanf("%s", S);

    printf("Enter K: ");
    scanf("%d", &K);

    int n = strlen(S);

    if (K <= 1)
    {
        printf("Reorganized string = %s\n", S);
        return 0;
    }

    int frequency[ASCII] = {0};

    for (int i = 0; i < n; i++)
        frequency[(unsigned char)S[i]]++;

    Node heap[ASCII];
    int heapSize = 0;

    for (int i = 0; i < ASCII; i++)
    {
        if (frequency[i] > 0)
        {
            Node node;

            node.ch = (char)i;
            node.frequency = frequency[i];

            push(heap, &heapSize, node);
        }
    }

    Node queue[ASCII];
    int queueStart = 0;
    int queueEnd = 0;

    char result[1000];
    int resultIndex = 0;

    while (resultIndex < n)
    {
        /*
         * Release characters whose K-distance
         * restriction has expired.
         */
        if (queueStart < queueEnd)
        {
            Node front = queue[queueStart];

            if (resultIndex - 1 -
                (queueStart) >= K - 1)
            {
                push(heap, &heapSize, front);
                queueStart++;
            }
        }

        if (heapSize == 0)
        {
            printf("Reorganization is impossible.\n");
            return 0;
        }

        Node current = pop(heap, &heapSize);

        result[resultIndex++] = current.ch;

        current.frequency--;

        if (current.frequency > 0)
            queue[queueEnd++] = current;
    }

    result[resultIndex] = '\0';

    printf("Reorganized string = %s\n", result);

    return 0;
}