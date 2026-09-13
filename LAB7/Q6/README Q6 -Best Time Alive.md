# DAA Lab-07 — Problem 6: The Best Time to Be Alive

## Problem
Given the birth and death years of prominent scientists, find the year in which the largest number of scientists were alive.

If one scientist died in the same year another was born, the death is considered to occur before the birth.

## Approach
The program uses an event-based sorting technique.

Each scientist generates two events:
- Birth event
- Death event

Events are sorted by year. For the same year, death events are processed before birth events.

## Algorithm
1. Read the birth and death year of every scientist.
2. Create a birth and death event for each scientist.
3. Sort all events by year.
4. For equal years, process death before birth.
5. Maintain the current number of living scientists.
6. Update the maximum and corresponding year whenever a new maximum is reached.

## Time Complexity
Sorting `2n` events takes:

**O(n log n)**

Scanning the events takes `O(n)`.

Therefore, overall:

**O(n log n)**

## Space Complexity
**O(n)**

## Input
Number of scientists followed by their birth and death years.

## Output
Year with the maximum number of scientists alive and the maximum count.

