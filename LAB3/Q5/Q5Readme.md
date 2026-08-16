#  Matrix Multiplication Using Divide and Conquer

## Problem Statement

Two `n × n` square matrices are given, where:

[
n = 2^k
]

for some natural number `k`.

Each matrix has a special recursive structure. When divided into four equal-sized blocks, the two diagonal blocks are identical and the two off-diagonal blocks are identical.

The structure is:

```text
M = | M1  M2 |
    | M2  M1 |
```

The objective is to develop a **Divide and Conquer** algorithm to multiply two such matrices in:

[
\boxed{O(n^2)}
]

time.

---

# Special Matrix Structure

Let the two matrices be:

```text
A = | A1  A2 |
    | A2  A1 |
```

and

```text
B = | B1  B2 |
    | B2  B1 |
```

Their product is:

```text
AB = | A1B1 + A2B2    A1B2 + A2B1 |
     | A1B2 + A2B1    A1B1 + A2B2 |
```

Define:

```text
P = A1 × B1
Q = A2 × B2

R = A1 × B2
S = A2 × B1
```

Then:

```text
C1 = P + Q

C2 = R + S
```

Therefore:

```text
C = | C1  C2 |
    | C2  C1 |
```

The important observation is that the resulting matrix has the **same special structure** as the input matrices.

---

# Divide and Conquer Approach

The algorithm follows these steps:

1. Divide each matrix into four equal blocks.
2. Because of the special structure, only two unique blocks need to be stored from each matrix.
3. Recursively calculate four matrix products:

   * `A1 × B1`
   * `A2 × B2`
   * `A1 × B2`
   * `A2 × B1`
4. Add the appropriate products.
5. Construct the result using the same special structure.
6. Continue until the matrices become `1 × 1`.

---

# Pseudocode

```text
SPECIAL-MULTIPLY(A, B, n)

    if n = 1
        return A × B

    Divide A:
        A = | A1  A2 |
            | A2  A1 |

    Divide B:
        B = | B1  B2 |
            | B2  B1 |

    P = SPECIAL-MULTIPLY(A1, B1)
    Q = SPECIAL-MULTIPLY(A2, B2)

    R = SPECIAL-MULTIPLY(A1, B2)
    S = SPECIAL-MULTIPLY(A2, B1)

    C1 = P + Q
    C2 = R + S

    C = | C1  C2 |
        | C2  C1 |

    return C
```

---

# Base Case

When:

[
n=1
]

each matrix contains only a single integer.

Therefore:

```text
C[0][0] = A[0][0] × B[0][0]
```

No further division is required.

---

# Complexity Analysis

At each recursive level, the algorithm performs **four recursive multiplications**, each on matrices of size `n/2`.

The addition operations required to combine the results take:

[
O(n^2)
]

time.

Therefore, the recurrence is:

[
T(n)=4T(n/2)+O(n^2)
]

Using the Master Theorem:

[
a=4,\quad b=2
]

and:

[
n^{\log_b a}
============

# n^{\log_2 4}

n^2
]

Hence:

[
\boxed{T(n)=O(n^2)}
]

Thus, the required quadratic time complexity is achieved.

---

# Comparison with Other Matrix Multiplication Methods

| Method                             | Recursive Multiplications | Time Complexity |
| ---------------------------------- | ------------------------: | --------------: |
| Conventional Matrix Multiplication |                         8 |         `O(n³)` |
| Strassen's Algorithm               |                         7 |     `O(n²·⁸⁰⁷)` |
| **Special-Pattern D&C**            |                     **4** |       **O(n²)** |

The special recursive structure allows us to reduce the number of recursive multiplications to four.

---

# Example

Consider:

```text
A = | 1  2 |
    | 2  1 |
```

and:

```text
B = | 3  4 |
    | 4  3 |
```

Here:

```text
A1 = 1
A2 = 2

B1 = 3
B2 = 4
```

Calculate:

```text
P = A1 × B1
  = 1 × 3
  = 3

Q = A2 × B2
  = 2 × 4
  = 8
```

Therefore:

```text
C1 = P + Q
   = 3 + 8
   = 11
```

Similarly:

```text
R = A1 × B2
  = 1 × 4
  = 4

S = A2 × B1
  = 2 × 3
  = 6
```

Therefore:

```text
C2 = R + S
   = 4 + 6
   = 10
```

Hence:

```text
AB = | 11  10 |
     | 10  11 |
```

---

# Sample Input

```text
Enter n: 2

Enter Matrix A:
1 2
2 1

Enter Matrix B:
3 4
4 3
```

# Sample Output

```text
Matrix A:
1 2
2 1

Matrix B:
3 4
4 3

A x B:
11 10
10 11
```

---

# Matrix Size Requirement

The basic implementation assumes:

[
n=2^k
]

Therefore, valid matrix sizes include:

```text
2 × 2
4 × 4
8 × 8
16 × 16
32 × 32
64 × 64
...
```

This allows the matrices to be divided evenly into four equal-sized blocks at every recursive level.

---

# Key Concepts

* Divide and Conquer
* Recursive Matrix Multiplication
* Special Matrix Structure
* Matrix Addition
* Recurrence Relations
* Master Theorem
* Time Complexity Analysis

---

# Conclusion

The special recursive structure:

```text
M = | M1  M2 |
    | M2  M1 |
```

can be exploited to perform matrix multiplication more efficiently than conventional matrix multiplication.

The product requires only **four recursive multiplications** of matrices of size `n/2`, resulting in the recurrence:

[
T(n)=4T(n/2)+O(n^2)
]

and therefore:

[
\boxed{T(n)=O(n^2)}
]

Thus, the algorithm achieves the required **quadratic time complexity** by taking advantage of the repeated diagonal and off-diagonal blocks.

---

## Files

```text
question5.c
README.md
```

## Compilation

Using GCC:

```bash
gcc question5.c -o question5
```

Run:

```bash
./question5
```

For Windows:

```bash
gcc question5.c -o question5.exe
question5.exe
```
