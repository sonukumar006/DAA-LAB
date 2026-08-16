#  Matrix Multiplication Using Strassen's Method

## Problem Statement

Given two square matrices `A` and `B` of size `n × n`, multiply them using **Strassen's Matrix Multiplication algorithm** based on the Divide and Conquer approach.

Strassen's algorithm reduces the number of recursive matrix multiplications from 8 to 7 and therefore improves the asymptotic time complexity over conventional matrix multiplication.

---

## Approach

Suppose the two matrices are divided into four equal-sized blocks:

```text
A = | A11  A12 |
    | A21  A22 |

B = | B11  B12 |
    | B21  B22 |
```

Instead of performing eight recursive multiplications, Strassen's method uses only seven.

### Seven Strassen Products

```text
M1 = (A11 + A22) × (B11 + B22)

M2 = (A21 + A22) × B11

M3 = A11 × (B12 - B22)

M4 = A22 × (B21 - B11)

M5 = (A11 + A12) × B22

M6 = (A21 - A11) × (B11 + B12)

M7 = (A12 - A22) × (B21 + B22)
```

The resulting matrix is calculated as:

```text
C11 = M1 + M4 - M5 + M7

C12 = M3 + M5

C21 = M2 + M4

C22 = M1 - M2 + M3 + M6
```

Therefore:

```text
C = | C11  C12 |
    | C21  C22 |
```

---

## Divide and Conquer Process

The algorithm works recursively:

1. Divide each matrix into four submatrices.
2. Calculate the seven Strassen products recursively.
3. Combine the seven products to obtain the four blocks of the result matrix.
4. Continue until the matrix size becomes `1 × 1`.

### Base Case

For a `1 × 1` matrix:

```text
C[0][0] = A[0][0] × B[0][0]
```

---

## Algorithm

```text
STRASSEN(A, B, n)

    if n == 1
        C = A × B
        return C

    Divide A into:
        A11, A12, A21, A22

    Divide B into:
        B11, B12, B21, B22

    M1 = STRASSEN(A11 + A22, B11 + B22)
    M2 = STRASSEN(A21 + A22, B11)
    M3 = STRASSEN(A11, B12 - B22)
    M4 = STRASSEN(A22, B21 - B11)
    M5 = STRASSEN(A11 + A12, B22)
    M6 = STRASSEN(A21 - A11, B11 + B12)
    M7 = STRASSEN(A12 - A22, B21 + B22)

    C11 = M1 + M4 - M5 + M7
    C12 = M3 + M5
    C21 = M2 + M4
    C22 = M1 - M2 + M3 + M6

    return C
```

---

## Complexity Analysis

### Conventional Matrix Multiplication

Conventional multiplication performs 8 recursive multiplications:

[
T(n)=8T(n/2)+O(n^2)
]

Therefore:

[
\boxed{T(n)=O(n^3)}
]

### Strassen's Algorithm

Strassen performs only 7 recursive multiplications:

[
T(n)=7T(n/2)+O(n^2)
]

Using the Master Theorem:

[
T(n)=O(n^{\log_2 7})
]

Since:

[
\log_2 7 \approx 2.807
]

the complexity becomes:

[
\boxed{O(n^{2.807})}
]

Thus, Strassen's algorithm is asymptotically faster than conventional matrix multiplication.

---

## Example

### Input

```text
Enter the size of matrices: 2

Enter elements of Matrix A:
1 2
3 4

Enter elements of Matrix B:
5 6
7 8
```

### Output

```text
Matrix A:
1 2
3 4

Matrix B:
5 6
7 8

Result Matrix (A x B):
19 22
43 50
```

---

## Matrix Size

The basic implementation works for matrix sizes that are powers of 2:

```text
2 × 2
4 × 4
8 × 8
16 × 16
32 × 32
...
```

For other matrix sizes, the matrices can be padded with zeros to the next power of 2.

---

## Key Concepts

* Divide and Conquer
* Recursive Matrix Multiplication
* Strassen's Algorithm
* Matrix Addition and Subtraction
* Recurrence Relations
* Master Theorem
* Time Complexity Analysis

---

## Conclusion

Strassen's Matrix Multiplication is an efficient Divide and Conquer algorithm that reduces the number of recursive multiplications from **8 to 7**.

As a result, its time complexity is:

[
\boxed{O(n^{2.807})}
]

compared with:

[
\boxed{O(n^3)}
]

for conventional matrix multiplication.

Therefore, Strassen's method provides better asymptotic performance for sufficiently large square matrices.

---

## Files

```text
question4.c
README.md
```

## Compilation

Using GCC:

```bash
gcc question4.c -o question4
```

Run:

```bash
./question4
```

For Windows:

```bash
gcc question4.c -o question4.exe
question4.exe
```
