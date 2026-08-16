#  Use of Loop Invariants in Sorting

## Problem Statement

Given an array `A[1...n]`, sort the array using the following approach:

1. Find the smallest element in `A[1...n]` and exchange it with `A[1]`.
2. Find the smallest element in `A[2...n]` and exchange it with `A[2]`.
3. Continue this process until the first `n-1` elements are correctly positioned.

This algorithm is known as **Selection Sort**.

The objective is to:

* Write the pseudocode for the algorithm.
* Identify and prove the loop invariant.
* Explain why only `n-1` elements need to be processed.
* Determine the best-case and worst-case running times.
* Implement the algorithm in C and validate the complexity.

---

## Algorithm

Selection Sort maintains two portions of the array:

```text
Sorted portion | Unsorted portion
---------------|----------------
A[0 ... i-1]   | A[i ... n-1]
```

During every iteration, the smallest element from the unsorted portion is selected and placed at its correct position.

### Pseudocode

```text
SELECTION-SORT(A, n)

    for i = 1 to n - 1

        min = i

        for j = i + 1 to n

            if A[j] < A[min]
                min = j

        exchange A[i] with A[min]

    return A
```

---

## Loop Invariant

The loop invariant of the outer loop is:

> **At the beginning of each iteration `i`, the subarray `A[1...i-1]` contains the `i-1` smallest elements of the original array in sorted order.**

The array can therefore be viewed as:

```text
A[1 ... i-1] | A[i ... n]
-------------|-------------
   Sorted    |   Unsorted
```

---

# Correctness Proof

A loop invariant is proved using three steps:

1. Initialization
2. Maintenance
3. Termination

---

## 1. Initialization

Before the first iteration:

```text
i = 1
```

The sorted portion is:

```text
A[1...0]
```

which is empty.

An empty array is trivially sorted.

Therefore, the loop invariant is true before the first iteration.

---

## 2. Maintenance

Assume the loop invariant is true at the beginning of iteration `i`.

Therefore:

```text
A[1...i-1]
```

already contains the `i-1` smallest elements in sorted order.

The algorithm searches for the smallest element in:

```text
A[i...n]
```

and exchanges it with `A[i]`.

Therefore, after the exchange:

```text
A[1...i]
```

contains the `i` smallest elements in sorted order.

Hence, the loop invariant is maintained for the next iteration.

---

## 3. Termination

The outer loop terminates after processing the first `n-1` elements.

At this point:

```text
A[1...n-1]
```

contains the `n-1` smallest elements in sorted order.

Only one element remains at `A[n]`.

Since all other elements are already correctly positioned, the remaining element must be the largest element.

Therefore:

```text
A[1...n]
```

is completely sorted.

Hence, the algorithm is correct.

---

# Why Only `n-1` Elements?

It is unnecessary to explicitly process the last element.

After placing the smallest element at `A[1]`, the second smallest at `A[2]`, and so on, after `n-1` iterations the first `n-1` elements are correctly positioned.

The only remaining element must automatically be the largest.

Therefore:

[
\boxed{\text{Only }n-1\text{ iterations are required}}
]

---

# Complexity Analysis

During the first iteration, the algorithm performs:

[
n-1
]

comparisons.

During the second:

[
n-2
]

comparisons.

This continues until:

[
1
]

comparison.

Therefore, the total number of comparisons is:

[
(n-1)+(n-2)+\cdots+2+1
]

[
=\frac{n(n-1)}{2}
]

Thus:

[
\boxed{\Theta(n^2)}
]

---

## Best Case

Even when the array is already sorted, Selection Sort still searches the entire unsorted portion to find its minimum.

Therefore:

[
\boxed{\text{Best Case}=\Theta(n^2)}
]

## Average Case

[
\boxed{\text{Average Case}=\Theta(n^2)}
]

## Worst Case

[
\boxed{\text{Worst Case}=\Theta(n^2)}
]

### Complexity Table

| Case         | Time Complexity |
| ------------ | --------------- |
| Best Case    | `Θ(n²)`         |
| Average Case | `Θ(n²)`         |
| Worst Case   | `Θ(n²)`         |

### Space Complexity

Selection Sort sorts the array in-place and requires only a constant amount of additional memory.

[
\boxed{O(1)}
]

---

# Example

### Input

```text
64 25 12 22 11
```

### Iteration 1

Minimum = `11`

```text
11 25 12 22 64
```

### Iteration 2

Minimum = `12`

```text
11 12 25 22 64
```

### Iteration 3

Minimum = `22`

```text
11 12 22 25 64
```

### Iteration 4

Minimum = `25`

```text
11 12 22 25 64
```

### Final Sorted Array

```text
11 12 22 25 64
```

---

# Sample Input

```text
Enter the number of elements: 5

Enter 5 elements:
64 25 12 22 11
```

# Sample Output

```text
Original Array:
64 25 12 22 11

Sorted Array:
11 12 22 25 64

Number of comparisons = 10
```

For `n = 5`:

[
\frac{5(5-1)}{2}
================

# \frac{20}{2}

10
]

Thus, the experimental result matches the theoretical number of comparisons.

---

# Validation of Complexity

For different values of `n`, the number of comparisons grows as follows:

|  `n` | Comparisons |
| ---: | ----------: |
|    5 |          10 |
|   10 |          45 |
|   20 |         190 |
|   50 |        1225 |
|  100 |        4950 |
| 1000 |      499500 |

The number of comparisons follows:

[
\frac{n(n-1)}{2}
]

which confirms the quadratic growth rate:

[
\boxed{\Theta(n^2)}
]

---

# Key Concepts

* Selection Sort
* Loop Invariants
* Initialization
* Maintenance
* Termination
* Correctness Proof
* In-place Sorting
* Comparison Counting
* Time Complexity
* Space Complexity

---

# Conclusion

Selection Sort repeatedly selects the minimum element from the unsorted portion and places it at its correct position.

The loop invariant proves that at the beginning of every iteration, the sorted portion contains the smallest elements in their correct order.

The algorithm requires exactly:

[
\frac{n(n-1)}{2}
]

comparisons, resulting in:

[
\boxed{\Theta(n^2)}
]

time complexity in the best, average, and worst cases.

Its auxiliary space complexity is:

[
\boxed{O(1)}
]

Thus, the implementation validates that Selection Sort has a quadratic running time regardless of whether the input array is already sorted or completely unsorted.

---

## Files

```text
question6.c
README.md
```

## Compilation

Using GCC:

```bash
gcc question6.c -o question6
```

Run:

```bash
./question6
```

For Windows:

```bash
gcc question6.c -o question6.exe
question6.exe
```
