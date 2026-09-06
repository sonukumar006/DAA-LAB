# DAA Lab-06 — Q3: Convolution of Vectors

## Objective
Compute the convolution of two vectors. The laboratory question asks for an O(n log n) divide-and-conquer solution.

## Method
The submitted program uses FFT-based convolution:
1. Pad both vectors to a suitable power-of-two size.
2. Apply FFT to both vectors.
3. Multiply their frequency-domain representations.
4. Apply inverse FFT.
5. Read the first m+n-1 values as the convolution.

## Complexity

The FFT recurrence is:

T(n) = 2T(n/2) + O(n)

Therefore:

T(n) = O(n log n)

Two forward FFTs, point-wise multiplication, and one inverse FFT together give O(n log n) time.

## Input
Enter the lengths m and n, with n >= m, followed by the elements of vectors A and B.

## Compilation
```bash
gcc q3.c -o q3 -lm
```

## Execution
```bash
./q3
```

## Output
The program prints C[k] for k = 0 to m+n-2.

## Space Complexity
O(n), apart from recursion-stack considerations.
