#include <stdio.h>

int switches[20];
int moves = 0;

void printSwitches(int n)
{
    int i;

    for(i = 0; i < n; i++)
        printf("%d ", switches[i]);

    printf("\n");
}

void turnOff(int n)
{
    int i;

    if(n == 0)
        return;

    if(n == 1)
    {
        switches[0] = 0;
        moves++;
        printf("Toggle switch 1\n");
        printSwitches(n);
        return;
    }

    /*
       First make the required right-side configuration,
       then toggle the current switch.
    */
    turnOff(n - 1);

    switches[n - 1] = 0;
    moves++;

    printf("Toggle switch %d\n", n);
    printSwitches(n);

    for(i = 0; i < n - 1; i++)
        switches[i] = 1;
}

int main()
{
    int n, i;

    printf("Enter number of switches: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
        switches[i] = 1;

    printf("\nInitial configuration:\n");
    printSwitches(n);

    moves = 0;

    /*
       Direct simulation of the legal sequence.
    */
    for(i = n - 1; i >= 0; i--)
    {
        switches[i] = 0;
        moves++;

        printf("Toggle switch %d\n", i + 1);
        printSwitches(n);
    }

    printf("\nTotal moves = %d\n", moves);

    return 0;
}