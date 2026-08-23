# K-Sum Problem

## Problem Statement

Given a set `S` containing `n` integers, an integer `T`, and an integer `k`, determine whether `k` elements of `S` add up to `T`.

The required time complexity is:

```text
O(n^(k-1) log n)
```

## Example

Given:

```text
S = {2, 4, 6, 8, 10}
k = 3
T = 18
```

A valid combination is:

```text
2 + 6 + 10 = 18
```

Therefore, the answer is **Yes**.

## Algorithm

1. Sort the set.
2. Recursively select `k-1` elements.
3. Calculate the required final value:

```text
required = T - current_sum
```

4. Binary-search for `required` among the remaining elements.
5. If found, `k` elements whose sum is `T` exist.
6. Otherwise, continue checking other combinations.

## Why the Complexity is O(n^(k-1) log n)

The algorithm considers approximately:

```text
O(n^(k-1))
```

combinations of the first `k-1` elements.

For each combination, binary search takes:

```text
O(log n)
```

Therefore:

```text
O(n^(k-1) log n)
```

## Space Complexity

Approximately:

```text
O(n + k)
```

for the sorted array and recursion.

## Technique

**Sorting + Recursive Enumeration + Binary Search**

## C Implementation

See [`sorting3.c`](sorting3.c).

## Compilation

```bash
gcc sorting3.c -o sorting3
```

## Run

```bash
./sorting3
```

On Windows:

```bash
sorting3.exe
```

## Key Learning

The K-Sum problem can be reduced by fixing `k-1` elements and efficiently searching for the final required element.
