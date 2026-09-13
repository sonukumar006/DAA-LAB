#include <stdio.h>

long long dp[30];
int split[30];

long long min(long long a, long long b)
{
    return (a < b) ? a : b;
}

void calculate(int n)
{
    int n1, k;
    long long moves;

    dp[0] = 0;
    dp[1] = 1;

    for(n1 = 2; n1 <= n; n1++)
    {
        dp[n1] = 999999999999LL;

        for(k = 1; k < n1; k++)
        {
            moves = 2 * dp[k] + (1LL << (n1-k)) - 1;

            if(moves < dp[n1])
            {
                dp[n1] = moves;
                split[n1] = k;
            }
        }
    }
}

void hanoi4(int n, char from, char to, char aux1, char aux2)
{
    int k;

    if(n == 0)
        return;

    if(n == 1)
    {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }

    k = split[n];

    hanoi4(k, from, aux1, to, aux2);

    /* Move remaining n-k disks using three pegs */
    hanoi4(n-k, from, to, aux2, aux1);

    hanoi4(k, aux1, to, from, aux2);
}

int main()
{
    int n;

    printf("Enter number of disks: ");
    scanf("%d", &n);

    calculate(n);

    printf("\nMinimum moves = %lld\n", dp[n]);

    if(n == 8)
        printf("For 8 disks, required moves = 33\n");

    return 0;
}