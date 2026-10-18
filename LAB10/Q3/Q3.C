
#include <stdio.h>

#define MAXV 100005
#define MAXE 400005

int parent[MAXV], sz[MAXV], active[MAXV];
long long value[MAXV], sum[MAXV];
int head[MAXV], to[MAXE], nextEdge[MAXE];
int edgeCount = 0;
long long best = 0;

int find(int x) {
    while (parent[x] != x) {
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
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
    sum[u] += sum[v];

    if (sum[u] > best)
        best = sum[u];
}

void addEdge(int u, int v) {
    to[edgeCount] = v;
    nextEdge[edgeCount] = head[u];
    head[u] = edgeCount++;

    to[edgeCount] = u;
    nextEdge[edgeCount] = head[v];
    head[v] = edgeCount++;
}

int main(void) {
    int V, E;
    static int order[MAXV];
    static long long ans[MAXV];

    printf("Enter vertices and edges: ");

    if (scanf("%d %d", &V, &E) != 2 ||
        V < 1 || V >= MAXV ||
        E < 0 || E > MAXE / 2) {
        printf("Invalid input\n");
        return 1;
    }

    for (int i = 1; i <= V; i++) {
        parent[i] = i;
        sz[i] = 1;
        head[i] = -1;

        printf("Value of vertex %d: ", i);

        if (scanf("%lld", &value[i]) != 1 ||
            value[i] < 0) {
            printf("Invalid vertex value\n");
            return 1;
        }
    }

    printf("Enter edges:\n");

    for (int i = 0; i < E; i++) {
        int u, v;

        if (scanf("%d %d", &u, &v) != 2 ||
            u < 1 || u > V ||
            v < 1 || v > V) {
            printf("Invalid edge\n");
            return 1;
        }

        addEdge(u, v);
    }

    printf("Enter deletion order:\n");

    for (int i = 1; i <= V; i++) {
        if (scanf("%d", &order[i]) != 1 ||
            order[i] < 1 || order[i] > V ||
            active[order[i]]) {
            printf("Invalid deletion order\n");
            return 1;
        }

        active[order[i]] = 1;
    }

    for (int i = 1; i <= V; i++)
        active[i] = 0;

    best = 0;
    ans[V] = 0;

    for (int i = V - 1; i >= 1; i--) {
        int u = order[i + 1];

        active[u] = 1;
        parent[u] = u;
        sz[u] = 1;
        sum[u] = value[u];

        if (sum[u] > best)
            best = sum[u];

        for (int e = head[u]; e != -1; e = nextEdge[e]) {
            int v = to[e];

            if (active[v])
                unite(u, v);
        }

        ans[i] = best;
    }

    printf("Maximum component sum after each deletion:\n");

    for (int i = 1; i <= V; i++)
        printf("%lld%c", ans[i], i == V ? '\n' : ' ');

    return 0;
}
