# DAA Lab-06 — Q1: 1D Array Operations

## Objective
Perform common operations on an unsorted 1D integer array and analyze their worst-case time complexity.

## Operations
1. Finding maximum
2. Finding first and second largest elements
3. Finding mean
4. Finding median
5. Finding standard deviation
6. Finding mode
7. Removing duplicates
8. Reversing the array
9. Partitioning with respect to a pivot

## Complexity Analysis

| Operation | Worst-case Time Complexity |
|---|---|
| Maximum | O(n) |
| First and second largest | O(n) |
| Mean | O(n) |
| Median | O(n log n) |
| Standard deviation | O(n) |
| Mode | O(n²) |
| Remove duplicates | O(n²) |
| Reverse | O(n) |
| Partition | O(n) |

## Input
First enter the number of elements, followed by the array elements. Select the required operation from the menu.

## Compilation
```bash
gcc q1.c -o q1 -lm
```

## Execution
```bash
./q1
```

## Note
The program validates the array operations experimentally. The median operation uses sorting, giving O(n log n), while the direct mode and duplicate-removal approaches are O(n²).
