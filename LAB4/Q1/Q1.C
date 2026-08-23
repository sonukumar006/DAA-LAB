#include <stdio.h>
#include <string.h>

struct Item {
    int number;
    char color[10];
};

int main() {
    int n;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item a[n], result[n];

    printf("Enter number and color (red/blue/yellow):\n");

    for (int i = 0; i < n; i++) {
        scanf("%d %s", &a[i].number, a[i].color);
    }

    int k = 0;

    
    for (int i = 0; i < n; i++) {
        if (strcmp(a[i].color, "red") == 0) {
            result[k++] = a[i];
        }
    }

    
    for (int i = 0; i < n; i++) {
        if (strcmp(a[i].color, "blue") == 0) {
            result[k++] = a[i];
        }
    }

    
    for (int i = 0; i < n; i++) {
        if (strcmp(a[i].color, "yellow") == 0) {
            result[k++] = a[i];
        }
    }

    printf("\nSorted by color:\n");

    for (int i = 0; i < n; i++) {
        printf("%d %s\n", result[i].number, result[i].color);
    }

    return 0;
}