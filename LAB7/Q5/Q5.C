#include <stdio.h>

int main()
{
    int n, target, shot;
    int i;

    printf("Enter number of hiding spots: ");
    scanf("%d", &n);

    printf("Enter initial target position: ");
    scanf("%d", &target);

    printf("\nShooter's strategy:\n");

    /*
       Shoot from left to right while skipping
       one position at the boundary.
    */
    for(i = 1; i <= n; i++)
    {
        shot = i;

        printf("Shot at position %d", shot);

        if(target == shot)
        {
            printf(" -> TARGET HIT\n");
            printf("\nTarget successfully hit.\n");
            return 0;
        }

        printf(" -> Missed\n");

        /*
           Target moves to adjacent position.
           This simulation assumes movement toward
           the next available position.
        */
        if(target < n)
            target++;
        else
            target--;
    }

    printf("\nThe particular simulated movement was not hit.\n");

    return 0;
}