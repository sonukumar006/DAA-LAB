# Point with Maximum Interval Overlap

## Problem Statement

Given a set `S` of `n` intervals on a line, where the `i`th interval is represented by:

```text
(li, ri)
```

find a point `p` that belongs to the largest possible number of intervals.

An endpoint counts as being inside its interval.

## Example

Given:

```text
S = {
    (10,40),
    (20,60),
    (50,90),
    (15,70)
}
```

At:

```text
p = 50
```

the following intervals contain the point:

```text
(20,60)
(50,90)
(15,70)
```

Therefore:

```text
Maximum overlap = 3
```

and one valid point is:

```text
p = 50
```

## Algorithm

Convert every interval into two events:

```text
Left endpoint  → +1
Right endpoint → -1
```

There are `2n` events.

1. Create all endpoint events.
2. Sort the events by their coordinate.
3. If two endpoints have the same coordinate, process the left endpoint before the right endpoint because endpoints are included in intervals.
4. Maintain the number of currently active intervals.
5. Whenever the active count becomes greater than the previous maximum, store the current point.
6. After processing all events, the stored point is a point contained in the maximum number of intervals.

## Important Detail

Because an endpoint counts as part of its interval, for equal coordinates:

```text
Left endpoint must be processed before right endpoint.
```

This ensures that an interval ending and another interval beginning at the same point are both counted at that point.

## Complexity

There are `2n` endpoint events.

Sorting:

```text
O(n log n)
```

Scanning:

```text
O(n)
```

Overall:

**O(n log n)**

## Space Complexity

**O(n)**

## Technique

**Sweep Line + Endpoint Sorting**

## C Implementation

See [`sorting6.c`](sorting6.c).

## Compilation

```bash
gcc sorting6.c -o sorting6
```

## Run

```bash
./sorting6
```

On Windows:

```bash
sorting6.exe
```

## Key Learning

Interval-overlap problems can often be solved efficiently by converting interval endpoints into events and processing them in sorted order.
