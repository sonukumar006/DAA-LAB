# DAA Lab-07 — Problem 3: Reve's Puzzle

## Problem
Reve's puzzle contains `n` disks and four pegs. Initially all disks are on the first peg in decreasing size order. The objective is to transfer all disks to another peg without placing a larger disk on a smaller disk.

The lab problem asks for a solution for 8 disks in 33 moves and a generalized solution for `n` disks.

## Approach
The program uses a dynamic-programming formulation based on the Frame-Stewart idea. A split point is selected for each number of disks to minimize the total number of moves.

## Algorithm
1. Set `dp[0] = 0` and `dp[1] = 1`.
2. For each number of disks `n`:
   - Try every possible split `k`.
   - Calculate the corresponding total move count.
   - Store the minimum value.
3. Store the best split for reconstruction.
4. For 8 disks, verify the required minimum of 33 moves.

## Time Complexity
The DP calculation uses two nested loops:

**O(n²)**

The actual puzzle-move sequence is exponential because the number of moves grows exponentially.

## Space Complexity
**O(n)** for the DP and split arrays.

## Input
Number of disks.

## Output
Minimum number of moves and the selected strategy.

