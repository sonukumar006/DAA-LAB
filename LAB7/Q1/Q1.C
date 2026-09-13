#include <stdio.h>

void printTriangle(int n)
{
    int i, j, k = 1;

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n-i; j++)
            printf("  ");

        for(j = 1; j <= i; j++)
            printf("%2d ", k++);

        printf("\n");
    }
}

int main()
{
    int n, moves;

    printf("Enter number of rows: ");
    scanf("%d", &n);

    printf("\nOriginal triangle:\n");
    printTriangle(n);

    moves = n - 1;

    printf("\nMinimum number of moves = %d\n", moves);
    printf("The triangle can be inverted by moving %d appropriate coins.\n", moves);

    return 0;
}