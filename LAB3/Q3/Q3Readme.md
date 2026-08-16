# Max and Min Using Divide and Conquer

## Problem Statement

Given an array of `n` elements, find both the **maximum** and **minimum** elements using the **Divide and Conquer** approach.

The algorithm should minimize the number of comparisons and ensure that the number of comparisons is bounded by:

[
\frac{3n}{2}
]

---

## Approach

The array is recursively divided into two halves.

For each half:

1. Find the minimum element.
2. Find the maximum element.
3. Compare the minimums of both halves to obtain the overall minimum.
4. Compare the maximums of both halves to obtain the overall maximum.

### Base Cases

#### One Element

If the subarray contains only one element:

```text
min = max = A[i]
```

No comparison is required.

#### Two Elements

If the subarray contains two elements, compare them once:

```text
if A[i] < A[j]
    min = A[i]
    max = A[j]
else
    min = A[j]
    max = A[i]
```

Thus, only **one comparison** is required for two elements.

---

## Divide and Conquer Algorithm

```text
MAX-MIN(A, low, high)

    if low == high
        min = A[low]
        max = A[low]
        return

    if high == low + 1
        compare A[low] and A[high]

        assign smaller element to min
        assign larger element to max

        return

    mid = (low + high) / 2

    MAX-MIN(A, low, mid)
    MAX-MIN(A, mid + 1, high)

    compare the two minimums
    compare the two maximums

    return overall minimum and maximum
```

---

## Complexity Analysis

For an even number of elements, the recurrence is:

[
T(n)=2T(n/2)+2
]

with:

[
T(2)=1
]

The total number of comparisons is:

[
T(n)=\frac{3n}{2}-2
]

Therefore:

[
T(n)\leq\frac{3n}{2}
]

Hence, the required comparison bound is satisfied.

### Time Complexity

The algorithm visits every element and performs a constant amount of work at each level.

Therefore:

[
\boxed{O(n)}
]

### Space Complexity

The recursive call stack requires:

[
\boxed{O(\log n)}
]

auxiliary stack space.

---

## Example

### Input

```text
Enter the size of array: 8

Enter 8 elements:
12 5 7 20 3 15 8 10
```

### Output

```text
========== RESULT ==========

Minimum element = 3
Maximum element = 20

Number of comparisons = 10
Maximum allowed comparisons = 12

Comparison bound is satisfied.
```

---

## Comparison with Straightforward Approach

A straightforward method separately finds the minimum and maximum.

Finding minimum:

[
n-1
]

comparisons.

Finding maximum:

[
n-1
]

comparisons.

Total:

[
2n-2
]

comparisons.

The Divide and Conquer approach requires approximately:

[
\frac{3n}{2}-2
]

comparisons.

Therefore, the Divide and Conquer approach performs fewer comparisons.

| Approach           | Comparisons |
| ------------------ | ----------: |
| Straightforward    |    `2n - 2` |
| Divide and Conquer |  `3n/2 - 2` |

---

## Key Concepts

* Divide and Conquer
* Recursion
* Minimum and Maximum
* Comparison Optimization
* Recurrence Relations
* Time Complexity Analysis

---

## Conclusion

The Divide and Conquer approach efficiently finds both the minimum and maximum elements of an array while reducing the number of comparisons.

The algorithm requires at most:

[
\boxed{\frac{3n}{2}-2}
]

comparisons for even `n`, which satisfies the required bound of `3n/2`.

Its overall time complexity is:

[
\boxed{O(n)}
]

---

## Files

```text
question3.c
README.md
```

## Compilation

Using GCC:

```bash
gcc question3.c -o question3
```

Run:

```bash
./question3
```

For Windows:

```bash
gcc question3.c -o question3.exe
question3.exe
```
