# DAA Lab-07 — Problem 4: Security Switches

## Problem
There are `n` switches arranged in a row. The rightmost switch can be toggled at will. Any other switch can be toggled only when the switch immediately to its right is on and all switches further to its right are off. Only one switch can be toggled at a time.

The objective is to turn all initially-on switches off using the minimum number of moves.

## Approach
The program represents the switches using an array and simulates the required toggling operations.

## Algorithm
1. Read the number of switches.
2. Initialize all switches to ON.
3. Follow the required toggling sequence.
4. Count every toggle as one move.
5. Display the final configuration and total moves.

## Time Complexity
For the implemented direct simulation:

**O(n)**

## Space Complexity
**O(n)** for the switch array.

## Input
Number of switches `n`.

## Output
Switch configurations during the process and total number of moves.

