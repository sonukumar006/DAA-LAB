#include <stdio.h>

int weighingCount = 0;

/*
    Compare two groups of coins.

    Returns:
    -1 -> left group is lighter
     0 -> both groups have equal weight
     1 -> left group is heavier
*/
int compare(int weights[], int start1, int start2, int count)
{
    int sum1 = 0, sum2 = 0;

    for (int i = 0; i < count; i++)
    {
        sum1 += weights[start1 + i];
        sum2 += weights[start2 + i];
    }

    weighingCount++;

    if (sum1 < sum2)
        return -1;

    if (sum1 > sum2)
        return 1;

    return 0;
}

/*
    Find defective coin in the range [start, start+n-1].

    Returns:
    index of defective coin
    -1 if no defective coin exists
*/
int findDefective(int weights[], int start, int n)
{
    // Base case: one coin
    if (n == 1)
    {
        /*
            With only one coin left, we cannot determine
            whether it is defective without a genuine reference.

            This case is handled by the structure of the
            algorithm, so we return its index as a candidate.
        */
        return start;
    }

    // Base case: two coins
    if (n == 2)
    {
        int result = compare(weights, start, start + 1, 1);

        if (result < 0)
            return start;

        if (result > 0)
            return start + 1;

        return -1;
    }

    // Special case: three coins
    if (n == 3)
    {
        int result = compare(weights, start, start + 1, 1);

        if (result < 0)
            return start;

        if (result > 0)
            return start + 1;

        /*
            First two coins are equal.
            Compare the third coin with either one.
        */
        result = compare(weights, start + 2, start, 1);

        if (result < 0)
            return start + 2;

        return -1;
    }

    /*
        Divide the coins into three groups.
        k = size of first and second groups.
    */
    int k = n / 3;

    int group1 = start;
    int group2 = start + k;
    int group3 = start + 2 * k;

    int result = compare(weights, group1, group2, k);

    // Group 1 is lighter
    if (result < 0)
    {
        return findDefective(weights, group1, k);
    }

    // Group 2 is lighter
    else if (result > 0)
    {
        return findDefective(weights, group2, k);
    }

    /*
        Groups 1 and 2 have equal weight.

        Therefore, the defective coin, if it exists,
        must be in the remaining group.
    */
    else
    {
        int remaining = n - 2 * k;

        return findDefective(weights, group3, remaining);
    }
}

int main()
{
    int n;

    printf("Enter number of coins: ");
    scanf("%d", &n);

    int weights[n];

    printf("Enter the weights of %d coins:\n", n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &weights[i]);
    }

    weighingCount = 0;

    int result = findDefective(weights, 0, n);

    printf("\n-----------------------------\n");

    if (result == -1)
    {
        printf("No defective coin found.\n");
    }
    else
    {
        printf("Defective coin found at position: %d\n",
               result + 1);

        printf("Weight of defective coin: %d\n",
               weights[result]);
    }

    printf("Number of weighings: %d\n", weighingCount);

    return 0;
}