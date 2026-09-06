# DAA Lab-06 — Q4: Sorting by Reversal

## Objective
Sort a permutation of 1 to n using only reversal operations and analyze the reversal cost.

## Reversal Operation
For a range [i, j], reverse(p, i, j) reverses all elements in that range.

The cost of one reversal is:

|j - i| + 1

## Algorithm
The program recursively partitions the permutation into smaller value ranges and uses reversals to arrange the elements before recursively sorting the two parts.

## Required Analysis

At a recursion level, the partitioning work is bounded by O(n log n) reversal cost. There are O(log n) levels.

Therefore, the target total cost is:

O(n log² n)

The number of reversals is separately counted, and the cost of each reversal is accumulated.

## Input
Enter n followed by a permutation of 1, 2, ..., n.

## Compilation
```bash
gcc q4.c -o q4
```

## Execution
```bash
./q4
```

## Output
The program displays:
- Original permutation
- Sorted permutation
- Number of reversals
- Total reversal cost
- Whether sorting was successful
