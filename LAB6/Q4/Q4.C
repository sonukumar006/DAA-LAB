#include <stdio.h>
#include <stdlib.h>

long long total_reversal_cost = 0;

void reverse_subsegment(int p[], int i, int j) {
    if (i >= j) return;
    total_reversal_cost += (j - i + 1);
    while (i < j) {
        int temp = p[i];
        p[i] = p[j];
        p[j] = temp;
        i++;
        j--;
    }
}

// Swaps block p[l1..r1] with adjacent block p[l2..r2] using 3 reversals
void swap_adjacent_blocks(int p[], int l1, int r1, int r2) {
    if (l1 > r1 || r1 + 1 > r2) return;
    reverse_subsegment(p, l1, r1);
    reverse_subsegment(p, r1 + 1, r2);
    reverse_subsegment(p, l1, r2);
}

// In-place merge step using reversals: O(k log k) cost
void merge_by_reversals(int p[], int l, int mid, int r) {
    if (l >= r || mid < l || mid >= r) return;
    if (p[mid] <= p[mid + 1]) return; // Already sorted

    if (r - l == 1) {
        if (p[l] > p[r]) reverse_subsegment(p, l, r);
        return;
    }

    int left_mid = l + (mid - l) / 2;
    int right_mid = mid + 1 + (r - (mid + 1)) / 2;

    // Find partition in left & right segments
    int l_idx = l;
    while (l_idx <= mid && p[l_idx] <= p[mid + 1]) l_idx++;

    int r_idx = mid + 1;
    while (r_idx <= r && p[r_idx] < p[mid]) r_idx++;

    // Swap intermediate out-of-order blocks
    swap_adjacent_blocks(p, l_idx, mid, r_idx - 1);
    int new_mid = l_idx + (r_idx - 1 - (mid + 1));

    merge_by_reversals(p, l, l_idx - 1, new_mid);
    merge_by_reversals(p, new_mid + 1, r_idx - 1, r);
}

// Master Divide-and-Conquer Sort: O(n log^2 n) cost
void sort_permutation_reversals(int p[], int l, int r) {
    if (l >= r) return;
    int mid = l + (r - l) / 2;
    sort_permutation_reversals(p, l, mid);
    sort_permutation_reversals(p, mid + 1, r);
    merge_by_reversals(p, l, mid, r);
}

int main() {
    int perm[] = {5, 2, 8, 1, 9, 3, 7, 4, 6};
    int n = sizeof(perm) / sizeof(perm[0]);

    printf("Original Permutation:\n");
    for (int i = 0; i < n; i++) printf("%d ", perm[i]);
    printf("\n");

    sort_permutation_reversals(perm, 0, n - 1);

    printf("Sorted Permutation:\n");
    for (int i = 0; i < n; i++) printf("%d ", perm[i]);
    printf("\nTotal reversal cost incurred: %lld\n", total_reversal_cost);

    return 0;
}
