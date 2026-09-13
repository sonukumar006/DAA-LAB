# DAA Lab-07 — Problem 1: Invert the Coin Triangle

## Problem
Given an equilateral triangle formed by closely packed coins, flip the triangle upside down by sliding one coin at a time to a new position. Find the minimum number of moves.

## Approach
The solution uses the compact mathematical result that a triangle of `n` rows can be inverted in:

**Minimum moves = n - 1**

The program takes the number of rows as input and displays the original triangle.

## Algorithm
1. Read the number of rows `n`.
2. Display the triangular arrangement of coins.
3. Calculate the minimum number of moves using `n - 1`.
4. Display the result.

## Time Complexity
- Displaying the triangle: **O(n²)**
- Calculating the minimum moves: **O(1)**
- Overall program complexity: **O(n²)**

## Space Complexity
**O(1)** apart from the output representation.

## Input
Number of rows of the coin triangle.

## Output
Original triangle and the minimum number of moves.


