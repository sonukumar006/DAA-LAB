#include <stdio.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int eggDrop(int eggs, int floors)
{
    int dp[20][101];
    int i, j, x;

    for(i = 1; i <= eggs; i++)
    {
        dp[i][0] = 0;
        dp[i][1] = 1;
    }

    for(j = 1; j <= floors; j++)
        dp[1][j] = j;

    for(i = 2; i <= eggs; i++)
    {
        for(j = 2; j <= floors; j++)
        {
            dp[i][j] = 999999;

            for(x = 1; x <= j; x++)
            {
                int attempts = 1 + max(dp[i-1][x-1], dp[i][j-x]);

                if(attempts < dp[i][j])
                    dp[i][j] = attempts;
            }
        }
    }

    return dp[eggs][floors];
}

int main()
{
    int eggs, floors;

    printf("Enter number of eggs: ");
    scanf("%d", &eggs);

    printf("Enter number of floors: ");
    scanf("%d", &floors);

    printf("\nMinimum number of droppings = %d\n",
           eggDrop(eggs, floors));

    return 0;
}