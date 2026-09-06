# DAA Lab-06 — Q2: 2D Matrix Operations

## Objective
Perform basic operations on square matrices and analyze their computational complexity.

## Operations
1. Matrix addition
2. Matrix multiplication
3. Check whether a matrix is a zero matrix
4. Check whether a matrix is symmetric
5. Compute determinant
6. Transpose the matrix in place
7. Compute an eigenvalue and corresponding eigenvector

## Complexity Analysis

| Operation | Worst-case Time Complexity |
|---|---|
| Matrix addition | O(n²) |
| Matrix multiplication | O(n³) |
| Zero matrix check | O(n²) |
| Symmetric matrix check | O(n²) |
| Determinant | O(n³) |
| In-place transpose | O(n²) |
| Eigenvalue/eigenvector | Approximately O(n³) |

## Input
Enter the order n of the square matrix and its elements. Select the required operation.

## Compilation
```bash
gcc q2.c -o q2 -lm
```

## Execution
```bash
./q2
```

## Note
The eigenvalue/eigenvector implementation uses an iterative power-method approach and therefore demonstrates the dominant eigenvalue/eigenvector rather than all eigenvalues.
