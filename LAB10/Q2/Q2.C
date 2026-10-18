
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int *parent, *sz;
char *land;

int find(int x) {
    while (parent[x] != x) {
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}

int unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b)
        return 0;

    if (sz[a] < sz[b]) {
        int t = a;
        a = b;
        b = t;
    }

    parent[b] = a;
    sz[a] += sz[b];
    return 1;
}

int main(void) {
    int R, C, Q;

    printf("Enter rows, columns and operations: ");

    if (scanf("%d %d %d", &R, &C, &Q) != 3 ||
        R <= 0 || C <= 0 || Q < 0 ||
        (size_t)R > SIZE_MAX / (size_t)C ||
        (size_t)R * (size_t)C > 10000000) {
        printf("Invalid input or dimensions\n");
        return 1;
    }

    size_t N = (size_t)R * (size_t)C;

    parent = malloc(N * sizeof(int));
    sz = malloc(N * sizeof(int));
    land = calloc(N, sizeof(char));

    if (parent == NULL || sz == NULL || land == NULL) {
        printf("Memory allocation failed\n");
        free(parent);
        free(sz);
        free(land);
        return 1;
    }

    for (size_t i = 0; i < N; i++) {
        parent[i] = (int)i;
        sz[i] = 1;
    }

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    int islands = 0;

    printf("Enter cell positions (1-based):\n");

    for (int q = 0; q < Q; q++) {
        int r, c;

        if (scanf("%d %d", &r, &c) != 2) {
            printf("Invalid or incomplete operation input\n");
            free(parent);
            free(sz);
            free(land);
            return 1;
        }

        if (r < 1 || r > R || c < 1 || c > C) {
            printf("Invalid position\n");
            free(parent);
            free(sz);
            free(land);
            return 1;
        }

        r--;
        c--;

        int id = r * C + c;

        if (!land[id]) {
            land[id] = 1;
            islands++;

            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];

                if (nr < 0 || nr >= R ||
                    nc < 0 || nc >= C)
                    continue;

                int nid = nr * C + nc;

                if (land[nid] && unite(id, nid))
                    islands--;
            }
        }

        printf("%d%c", islands, q == Q - 1 ? '\n' : ' ');
    }

    if (Q == 0)
        printf("\n");

    free(parent);
    free(sz);
    free(land);

    return 0;
}
