
#include <stdio.h>
#include <limits.h>

#define MAX 100

struct Block {
    long long weight;
    int original;
};

void printBlocks(struct Block blocks[], int n) {
    int i;

    printf("[ ");
    for (i = 0; i < n; i++) {
        printf("%lld", blocks[i].weight);
        printf("%s", blocks[i].original ? "(O)" : "(A)");

        if (i != n - 1)
            printf(" ");
    }
    printf(" ]\n");
}

void buildPrefix(struct Block blocks[], int n, int prefix[]) {
    int i;
    prefix[0] = 0;

    for (i = 0; i < n; i++)
        prefix[i + 1] = prefix[i] + blocks[i].original;
}

int isCompatible(int left, int right, int prefix[]) {
    if (left > right) {
        int temp = left;
        left = right;
        right = temp;
    }

    return prefix[right] - prefix[left + 1] == 0;
}

void findMinimumCompatibleWeights(
    struct Block blocks[], int n, int prefix[],
    long long minCompatible[]) {

    int i, j;

    for (i = 0; i < n; i++) {
        minCompatible[i] = LLONG_MAX;

        for (j = 0; j < n; j++) {
            if (i != j && isCompatible(i, j, prefix)) {
                if (blocks[j].weight < minCompatible[i])
                    minCompatible[i] = blocks[j].weight;
            }
        }
    }
}

void findBestPair(
    struct Block blocks[], int n, int prefix[],
    int *bestLeft, int *bestRight) {

    long long minCompatible[MAX];
    long long bestSum = LLONG_MAX;
    int i, j;

    *bestLeft = -1;
    *bestRight = -1;

    findMinimumCompatibleWeights(
        blocks, n, prefix, minCompatible);

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (isCompatible(i, j, prefix) &&
                blocks[i].weight == minCompatible[j] &&
                blocks[j].weight == minCompatible[i]) {

                long long sum =
                    blocks[i].weight + blocks[j].weight;

                if (sum < bestSum) {
                    bestSum = sum;
                    *bestLeft = i;
                    *bestRight = j;
                }
            }
        }
    }
}

void mergeBlocks(struct Block blocks[], int *n,
                 int left, int right) {
    int i;

    blocks[left].weight += blocks[right].weight;
    blocks[left].original = 0;

    for (i = right; i < *n - 1; i++)
        blocks[i] = blocks[i + 1];

    (*n)--;
}

int main(void) {
    struct Block blocks[MAX];
    int prefix[MAX + 1];
    int n, i, left, right;
    long long totalCost = 0;
    long long totalWeight = 0;

    printf("Enter number of weights: ");

    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX) {
        printf("Invalid number of weights.\n");
        return 1;
    }

    printf("Enter positive weights in alphabetic order:\n");

    for (i = 0; i < n; i++) {
        if (scanf("%lld", &blocks[i].weight) != 1 ||
            blocks[i].weight <= 0) {
            printf("Invalid weight. Use positive integers.\n");
            return 1;
        }

        if (blocks[i].weight > LLONG_MAX - totalWeight) {
            printf("Sum of weights exceeds supported range.\n");
            return 1;
        }

        totalWeight += blocks[i].weight;
        blocks[i].original = 1;
    }

    if (n > 1 &&
        totalWeight > LLONG_MAX / (n - 1)) {
        printf("Weights are too large for safe cost calculation.\n");
        return 1;
    }

    printf("\nInitial blocks: ");
    printBlocks(blocks, n);

    while (n > 1) {
        buildPrefix(blocks, n, prefix);

        findBestPair(blocks, n, prefix, &left, &right);

        if (left == -1) {
            printf("No compatible pair found.\n");
            return 1;
        }

        long long mergedWeight =
            blocks[left].weight + blocks[right].weight;

        printf("\nMerge: %lld + %lld = %lld\n",
               blocks[left].weight,
               blocks[right].weight,
               mergedWeight);

        totalCost += mergedWeight;

        mergeBlocks(blocks, &n, left, right);

        printf("Blocks after merge: ");
        printBlocks(blocks, n);
    }

    printf("\nMinimum weighted path-length cost = %lld\n",
           totalCost);

    return 0;
}
