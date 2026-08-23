#  Merge Overlapping Intervals

## Problem Statement

Given a list `I` of `n` intervals represented as:

```text
(xi, yi)
```

return a list in which all overlapping intervals are merged.

For example:

```text
I = {(1,3), (2,6), (8,10), (7,18)}
```

The expected output is:

```text
{(1,6), (7,18)}
```

The algorithm must run in worst-case:

```text
O(n log n)
```

## Algorithm

1. Sort all intervals according to their starting point.
2. Store the first interval as the current merged interval.
3. For every remaining interval:
   - If its starting point is less than or equal to the current ending point, the intervals overlap.
   - Extend the ending point if necessary.
   - Otherwise, store the current interval and start a new merged interval.
4. Print all merged intervals.

## Overlap Condition

For intervals:

```text
(a,b)
(c,d)
```

they overlap when:

```text
c <= b
```

after sorting by starting point.

## Example

Original intervals:

```text
(1,3)
(2,6)
(8,10)
(7,18)
```

After sorting:

```text
(1,3)
(2,6)
(7,18)
(8,10)
```

Merge operations:

```text
(1,3) + (2,6)  → (1,6)
(7,18) + (8,10) → (7,18)
```

Final result:

```text
(1,6)
(7,18)
```

## Complexity

Sorting:

```text
O(n log n)
```

Merging:

```text
O(n)
```

Overall:

**O(n log n)**

## Space Complexity

**O(n)**

## Technique

**Sorting + Greedy Interval Merging**

## C Implementation

See [`sorting5.c`](sorting5.c).

## Compilation

```bash
gcc sorting5.c -o sorting5
```

## Run

```bash
./sorting5
```

On Windows:

```bash
sorting5.exe
```

## Key Learning

Sorting intervals by their starting points makes it possible to merge all overlapping intervals in a single linear scan after sorting.
