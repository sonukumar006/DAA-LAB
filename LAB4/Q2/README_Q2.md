#  Two Sets Sum to X

## Problem Statement

Given two sets `S1` and `S2`, each containing `n` elements, and an integer `x`, determine whether there exists a pair of elements such that:

```text
a ∈ S1
b ∈ S2
a + b = x
```

The required time complexity is:

```text
O(n log n)
```

## Example

Given:

```text
S1 = {1, 4, 7, 10}
S2 = {2, 5, 8, 12}
x = 13
```

A valid pair is:

```text
1 + 12 = 13
```

Therefore, the answer is **Yes**.

## Algorithm

1. Sort `S2`.
2. For every element `a` in `S1`, calculate:

```text
required = x - a
```

3. Perform binary search for `required` in sorted `S2`.
4. If the element is found, a valid pair exists.
5. If no required value is found after checking all elements of `S1`, no such pair exists.

## Complexity Analysis

Sorting `S2`:

```text
O(n log n)
```

For every element of `S1`, binary search takes:

```text
O(log n)
```

For `n` elements:

```text
O(n log n)
```

Therefore, total complexity is:

**O(n log n)**

## Space Complexity

- `O(n)` for storing the input arrays.

## Technique

**Sorting + Binary Search**

## C Implementation

See [`sorting2.c`](sorting2.c).

## Compilation

```bash
gcc sorting2.c -o sorting2
```

## Run

```bash
./sorting2
```

On Windows:

```bash
sorting2.exe
```

## Key Learning

Sorting one set allows every required complement to be found efficiently using binary search.
