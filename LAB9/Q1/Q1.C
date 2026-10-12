#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    double value;
    double weight;
    double lambda;
    double remaining;
} Item;

int main()
{
    int n;
    double W;

    printf("Enter number of items: ");
    scanf("%d", &n);

    Item items[n];

    printf("Enter value, weight and decay rate for each item:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%lf %lf %lf",
              &items[i].value,
              &items[i].weight,
              &items[i].lambda);

        items[i].remaining = items[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%lf", &W);

    double time = 0.0;
    double totalValue = 0.0;
    double remainingCapacity = W;

    printf("\nSelected order:\n");

    while (remainingCapacity > 0)
    {
        int best = -1;
        double bestDensity = -1e100;

        /* Find item with highest current density */
        for (int i = 0; i < n; i++)
        {
            if (items[i].remaining > 1e-9)
            {
                double initialDensity =
                    items[i].value / items[i].weight;

                double currentDensity =
                    initialDensity - items[i].lambda * time;

                if (currentDensity > bestDensity)
                {
                    bestDensity = currentDensity;
                    best = i;
                }
            }
        }

        if (best == -1 || bestDensity <= 0)
            break;

        double amount;

        if (items[best].remaining < remainingCapacity)
            amount = items[best].remaining;
        else
            amount = remainingCapacity;

        /*
         * Value obtained by consuming this amount.
         * Density changes during consumption.
         *
         * Integral of:
         * (initialDensity - lambda*t)
         * over the consumption interval.
         */
        double d0 =
            items[best].value / items[best].weight;

        double startTime = time;
        double endTime =
            time + amount;

        double obtainedValue =
            d0 * amount
            - 0.5 * items[best].lambda *
              (endTime * endTime -
               startTime * startTime);

        totalValue += obtainedValue;

        printf("Item %d: %.2f units, time %.2f to %.2f\n",
               best + 1,
               amount,
               startTime,
               endTime);

        items[best].remaining -= amount;
        remainingCapacity -= amount;
        time = endTime;
    }

    printf("\nTotal value = %.2f\n", totalValue);
    printf("Used capacity = %.2f\n", W - remainingCapacity);

    return 0;
}