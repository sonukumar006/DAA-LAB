#include <stdio.h>
#include <stdlib.h>

struct Interval {
    int start;
    int end;
};

int compareIntervals(const void *a, const void *b) {
    struct Interval *i1 = (struct Interval *)a;
    struct Interval *i2 = (struct Interval *)b;

    return i1->start - i2->start;
}

int main() {
    int n;

    printf("Enter number of intervals: ");
    scanf("%d", &n);

    struct Interval intervals[n];
    struct Interval result[n];

    printf("Enter intervals:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d %d",
              &intervals[i].start,
              &intervals[i].end);
    }

    // Sort by starting point
    qsort(intervals, n, sizeof(struct Interval),
          compareIntervals);

    int count = 0;

    result[count] = intervals[0];
    count++;

    for (int i = 1; i < n; i++) {

        if (intervals[i].start <= result[count - 1].end) {

            if (intervals[i].end >
                result[count - 1].end) {

                result[count - 1].end =
                    intervals[i].end;
            }
        }
        else {
            result[count] = intervals[i];
            count++;
        }
    }

    printf("\nMerged intervals:\n");

    for (int i = 0; i < count; i++) {
        printf("(%d, %d)\n",
               result[i].start,
               result[i].end);
    }

    return 0;
}