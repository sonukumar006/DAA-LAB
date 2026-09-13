# DAA Lab-07 — Problem 5: Hitting a Moving Target

## Problem
A shooter can fire at any of `n > 1` hiding spots arranged in a line. The shooter cannot see the target and only knows that the target moves to an adjacent spot between consecutive shots.

The task is to design a strategy that guarantees hitting the target or prove that no such strategy exists.

## Approach
The program demonstrates a sequential shooting strategy and simulates target movement.

Because the target is unobservable, the theoretical guarantee depends on the exact movement model. The program is intended as a validation/simulation of the stated strategy rather than as an observation-based targeting system.

## Algorithm
1. Read the number of hiding spots.
2. Read the initial target position for simulation.
3. Fire at the selected positions sequentially.
4. After each missed shot, move the simulated target to an adjacent position.
5. Stop when the target is hit or the sequence ends.

## Time Complexity
For `n` hiding spots:

**O(n)**

## Space Complexity
**O(1)**

## Input
Number of hiding spots and simulated initial target position.

## Output
Each shot result and whether the target was hit.

