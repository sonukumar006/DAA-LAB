# DAA Lab-07 — Problem 2: Super Egg Testing Experiment

## Problem
Given `E` eggs and `F` floors, determine the minimum number of egg droppings required in the worst case to find the highest safe floor.

For the specific case of 2 eggs and 100 floors, the minimum guaranteed number of droppings is **14**.

## Approach
Dynamic Programming is used.

Let:

`dp[e][f]` = minimum number of trials required with `e` eggs and `f` floors.

For every possible dropping floor `x`:

`dp[e][f] = 1 + max(dp[e-1][x-1], dp[e][f-x])`

The minimum over all possible `x` is selected.

## Algorithm
1. Initialize the cases for zero and one floor.
2. With one egg, `f` floors require `f` trials.
3. For every number of eggs and floors:
   - Try every possible dropping floor.
   - Consider both cases: egg breaks and egg does not break.
   - Take the minimum worst-case result.
4. Return `dp[E][F]`.

## Time Complexity
**O(E × F²)**

## Space Complexity
**O(E × F)**

## Input
Number of eggs `E` and number of floors `F`.

## Output
Minimum number of droppings required.

