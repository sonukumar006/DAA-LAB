#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int year;
    int type;
} Event;

int compare(const void *a, const void *b)
{
    Event *x = (Event *)a;
    Event *y = (Event *)b;

    if(x->year != y->year)
        return x->year - y->year;

    return x->type - y->type;
}

int main()
{
    int n, i;
    Event events[200];
    int birth, death;
    int alive = 0;
    int maximum = 0;
    int bestYear = 0;

    printf("Enter number of scientists: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter birth and death year of scientist %d: ",
               i + 1);

        scanf("%d %d", &birth, &death);

        events[2*i].year = birth;
        events[2*i].type = 1;

        events[2*i + 1].year = death;
        events[2*i + 1].type = 0;
    }

    qsort(events, 2*n, sizeof(Event), compare);

    for(i = 0; i < 2*n; i++)
    {
        if(events[i].type == 0)
            alive--;
        else
        {
            alive++;

            if(alive > maximum)
            {
                maximum = alive;
                bestYear = events[i].year;
            }
        }
    }

    printf("\nYear with maximum number of scientists alive = %d\n",
           bestYear);

    printf("Maximum number of scientists alive = %d\n",
           maximum);

    return 0;
}