
#include <stdio.h>

#define MAX 1005

int parent[MAX], sz[MAX], parity[MAX];

int find(int x) {
    if (parent[x] == x)
        return x;

    int p = parent[x];
    parent[x] = find(p);
    parity[x] ^= parity[p];

    return parent[x];
}

int addEdge(int u, int v) {
    int ru = find(u);
    int pu = parity[u];

    int rv = find(v);
    int pv = parity[v];

    if (ru == rv)
        return (pu ^ pv) == 1;

    if (sz[ru] < sz[rv]) {
        int t = ru;
        ru = rv;
        rv = t;
    }

    parent[rv] = ru;
    parity[rv] = pu ^ pv ^ 1;
    sz[ru] += sz[rv];

    return 1;
}

int main(void) {
    int V, E, u, v;

    printf("Enter vertices and edges: ");
    scanf("%d %d", &V, &E);

    if (V < 1 || V >= MAX || E < 0) {
        printf("Invalid input\n");
        return 1;
    }

    for (int i = 1; i <= V; i++) {
        parent[i] = i;
        sz[i] = 1;
        parity[i] = 0;
    }

    printf("Enter edges (u v) in arrival order:\n");

    for (int i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);

        if (u < 1 || u > V || v < 1 || v > V) {
            printf("Invalid edge\n");
            continue;
        }

        if (addEdge(u, v))
            printf("Edge (%d,%d): Accepted\n", u, v);
        else
            printf("Edge (%d,%d): Rejected\n", u, v);
    }

    return 0;
}
