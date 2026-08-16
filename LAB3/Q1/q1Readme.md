#  Binary Search vs Ternary Search

## Problem Statement

In Binary Search, a sorted list of `n` elements is divided into two nearly equal parts. In Ternary Search, the list is divided into three nearly equal parts.

Design and implement a C program to search for an element `x` in a sorted list using both **Binary Search** and **Ternary Search**. Compare their performance based on the number of comparisons and validate that Binary Search is generally better than Ternary Search.

---

## Approach

### Binary Search

Binary Search divides the search space into two parts.

1. Find the middle element.
2. If the middle element is equal to `x`, return its position.
3. If `x` is smaller, search the left half.
4. If `x` is larger, search the right half.
5. Repeat until the element is found or the search space becomes empty.

### Ternary Search

Ternary Search divides the search space into three parts.

Two middle positions are calculated:

```text
mid1 = low + (high - low) / 3
mid2 = high - (high - low) / 3
```

The element is then searched in one of the three intervals.

---

## Complexity Analysis

| Algorithm      | Time Complexity | Space Complexity |
| -------------- | --------------- | ---------------- |
| Binary Search  | `O(log₂ n)`     | `O(1)`           |
| Ternary Search | `O(log₃ n)`     | `O(1)`           |

Although Ternary Search reduces the search space to one-third at every iteration, it generally requires **two comparisons per iteration**, whereas Binary Search generally requires fewer comparisons.

Therefore, Binary Search is generally more efficient for searching in a sorted array.

---

## Sample Input

```text
Enter the size of sorted array: 15

Enter 15 elements in sorted order:
10 20 30 40 50 60 70 80 90 100 110 120 130 140 150

Enter element to search: 130
```

## Sample Output

```text
========== RESULTS ==========

Binary Search: Element found at index 12
Binary Search Comparisons: 3

Ternary Search: Element found at index 12
Ternary Search Comparisons: 5

========== COMPARISON ==========

Binary Search is better for this input.
```

---

## Conclusion

Binary Search and Ternary Search both have logarithmic time complexity. However, Ternary Search requires more comparisons at each iteration because it uses two dividing points.

Hence, for a sorted array, **Binary Search generally performs fewer comparisons and is preferred over Ternary Search**.

---

