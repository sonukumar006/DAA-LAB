
#include <stdio.h>
#include <stdlib.h>

#define MAX 100005

int parent[MAX], sz[MAX], A[MAX];
int vertices[MAX], values[MAX];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int u, int v) {
    u = find(u);
    v = find(v);

    if (u == v)
        return;

    if (sz[u] < sz[v]) {
        int t = u;
        u = v;
        v = t;
    }

    parent[v] = u;
    sz[u] += sz[v];
}

int cmp(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;

    return (x > y) - (x < y);
}

int main(void) {
    int n, m;

    printf("Enter n and m: ");
    scanf("%d %d", &n, &m);

    if (n < 1 || n >= MAX || m < 0) {
        printf("Invalid input\n");
        return 1;
    }

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }

    printf("Enter permutation:\n");

    for (int i = 1; i <= n; i++)
        scanf("%d", &A[i]);

    printf("Enter allowed swap pairs:\n");

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        if (u < 1 || u > n || v < 1 || v > n) {
            printf("Invalid edge\n");
            return 1;
        }

        unite(u, v);
    }

    for (int root = 1; root <= n; root++) {
        if (find(root) != root)
            continue;

        int count = 0;

        for (int i = 1; i <= n; i++) {
            if (find(i) == root) {
                vertices[count] = i;
                values[count] = A[i];
                count++;
            }
        }

        qsort(vertices, count, sizeof(int), cmp);
        qsort(values, count, sizeof(int), cmp);

        for (int i = 0; i < count; i++)
            A[vertices[i]] = values[i];
    }

    printf("Lexicographically smallest permutation:\n");

    for (int i = 1; i <= n; i++)
        printf("%d ", A[i]);

    printf("\n");

    return 0;
}
