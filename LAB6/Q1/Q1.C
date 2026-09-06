#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void maximum(int a[], int n)
{
    int max = a[0];

    for (int i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];

    printf("Maximum = %d\n", max);
}

void firstSecondLargest(int a[], int n)
{
    int first = a[0], second = -2147483648;

    for (int i = 1; i < n; i++)
    {
        if (a[i] > first)
        {
            second = first;
            first = a[i];
        }
        else if (a[i] > second && a[i] != first)
        {
            second = a[i];
        }
    }

    printf("First Largest = %d\n", first);
    printf("Second Largest = %d\n", second);
}

void mean(int a[], int n)
{
    double sum = 0;

    for (int i = 0; i < n; i++)
        sum += a[i];

    printf("Mean = %.2lf\n", sum / n);
}

void median(int a[], int n)
{
    int *b = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        b[i] = a[i];

    qsort(b, n, sizeof(int), compare);

    if (n % 2 == 0)
        printf("Median = %.2lf\n", (b[n / 2 - 1] + b[n / 2]) / 2.0);
    else
        printf("Median = %.2lf\n", (double)b[n / 2]);

    free(b);
}

void standardDeviation(int a[], int n)
{
    double sum = 0, mean, variance = 0;

    for (int i = 0; i < n; i++)
        sum += a[i];

    mean = sum / n;

    for (int i = 0; i < n; i++)
        variance += (a[i] - mean) * (a[i] - mean);

    variance /= n;

    printf("Standard Deviation = %.2lf\n", sqrt(variance));
}

void mode(int a[], int n)
{
    int mode = a[0], maxCount = 1;

    for (int i = 0; i < n; i++)
    {
        int count = 0;

        for (int j = 0; j < n; j++)
        {
            if (a[i] == a[j])
                count++;
        }

        if (count > maxCount)
        {
            maxCount = count;
            mode = a[i];
        }
    }

    if (maxCount == 1)
        printf("No mode\n");
    else
        printf("Mode = %d\n", mode);
}

void removeDuplicates(int a[], int *n)
{
    for (int i = 0; i < *n; i++)
    {
        for (int j = i + 1; j < *n;)
        {
            if (a[i] == a[j])
            {
                for (int k = j; k < *n - 1; k++)
                    a[k] = a[k + 1];

                (*n)--;
            }
            else
            {
                j++;
            }
        }
    }
}

void reverseArray(int a[], int n)
{
    int i = 0, j = n - 1;

    while (i < j)
    {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        i++;
        j--;
    }
}

void partitionArray(int a[], int n, int pivot)
{
    int i = 0, j = n - 1;

    while (i <= j)
    {
        while (i < n && a[i] >= pivot)
            i++;

        while (j >= 0 && a[j] < pivot)
            j--;

        if (i < j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
}

void display(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
}

int main()
{
    int n, choice, pivot;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *a = malloc(n * sizeof(int));

    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("\n1. Maximum");
    printf("\n2. First and Second Largest");
    printf("\n3. Mean");
    printf("\n4. Median");
    printf("\n5. Standard Deviation");
    printf("\n6. Mode");
    printf("\n7. Remove Duplicates");
    printf("\n8. Reverse");
    printf("\n9. Partition");
    printf("\nEnter choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            maximum(a, n);
            break;

        case 2:
            firstSecondLargest(a, n);
            break;

        case 3:
            mean(a, n);
            break;

        case 4:
            median(a, n);
            break;

        case 5:
            standardDeviation(a, n);
            break;

        case 6:
            mode(a, n);
            break;

        case 7:
            removeDuplicates(a, &n);
            printf("Array after removing duplicates: ");
            display(a, n);
            break;

        case 8:
            reverseArray(a, n);
            printf("Reversed array: ");
            display(a, n);
            break;

        case 9:
            printf("Enter pivot: ");
            scanf("%d", &pivot);
            partitionArray(a, n, pivot);
            printf("Partitioned array: ");
            display(a, n);
            break;

        default:
            printf("Invalid choice\n");
    }

    free(a);
    return 0;
}