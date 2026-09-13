# DAA Lab-07 — Problem 7: Matrix Chain Multiplication

## Problem
Given a chain of matrices, determine the parenthesization that minimizes the number of scalar multiplications required to multiply all matrices.

## Approach
Dynamic Programming is used.

Let:

`dp[i][j]` = minimum scalar multiplications needed to multiply matrices `Ai` through `Aj`.

For every possible split `k`:

`dp[i][j] = min(dp[i][k] + dp[k+1][j] + p[i-1] × p[k] × p[j])`

The split position is stored to reconstruct the optimal parenthesization.

## Algorithm
1. Read the number of matrices.
2. Read the dimension array.
3. Set the cost of multiplying a single matrix to zero.
4. Consider chains of increasing length.
5. Try every possible split position.
6. Store the minimum multiplication cost and split position.
7. Recursively print the optimal parenthesization.

## Time Complexity
There are three nested loops over the matrix chain:

**O(n³)**

## Space Complexity
**O(n²)**

## Input
Number of matrices followed by `n + 1` matrix dimensions.

## Output
Minimum number of scalar multiplications and optimal parenthesization.

## Example
For dimensions:

`40 20 30 10 30`

the minimum cost is:

`26000`

with optimal ordering:

`((A1 × (A2 × A3)) × A4)`

