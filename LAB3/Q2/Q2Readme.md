# Question 2 – Search the Defective Coin

## Problem Statement

There are `n` coins, where at most one coin may be defective. All normal coins have identical weights, while the defective coin, if present, is guaranteed to be **lighter** than the normal coins.

Using a balance weighing scale, design and implement a **Divide and Conquer** algorithm to find the defective coin or determine that there is no defective coin.

The algorithm should have logarithmic running time.

---

## Divide and Conquer Approach

The coins are divided into three approximately equal groups:

```text
Group A | Group B | Group C
```

Group A is weighed against Group B.

There are three possible outcomes.

### Case 1: Group A is lighter

The defective coin must be present in Group A.

```text
Search Group A
```

### Case 2: Group B is lighter

The defective coin must be present in Group B.

```text
Search Group B
```

### Case 3: Both groups have equal weight

Neither Group A nor Group B contains a lighter coin.

Therefore, the defective coin, if it exists, must be in Group C.

```text
Search Group C
```

The same process is repeated recursively until the defective coin is found or it is determined that no defective coin exists.

---

## Algorithm

```text
DEFECTIVE-COIN(coins, n)

    if n is small
        determine the defective coin directly

    Divide coins into three groups:
        A, B and C

    Weigh A against B

    if A is lighter
        search A

    else if B is lighter
        search B

    else
        search C
```

---

## Complexity Analysis

At every recursive step, the problem size is reduced to approximately one-third.

The recurrence is:

```text
T(n) = T(n/3) + O(1)
```

Therefore:

```text
T(n) = O(log₃ n)
```

Since:

```text
log₃ n = log₂ n / log₂ 3
```

the algorithm is logarithmic and satisfies the required bound:

```text
O(log₂ n + c)
```

where `c` is a positive constant.

---

## Sample Input

```text
Enter number of coins: 9

Enter the weights of 9 coins:
10 10 10 10 8 10 10 10 10
```

## Sample Output

```text
Defective coin found at position: 5
Weight of defective coin: 8
```

### Case Where No Defective Coin Exists

Input:

```text
6
10 10 10 10 10 10
```

Output:

```text
No defective coin found.
```

---

## Key Concepts

* Divide and Conquer
* Recursive Search
* Balance Scale
* Problem Size Reduction
* Logarithmic Time Complexity
* Recurrence Relations

---

## Conclusion

The defective coin problem can be solved efficiently using a Divide and Conquer strategy. By dividing the candidate coins into three groups and using the balance scale to eliminate two groups whenever possible, the number of candidate coins is reduced by approximately a factor of three at every step.

Thus, the algorithm has:

```text
O(log₃ n)
```

time complexity and successfully identifies the lighter defective coin or reports that no defective coin exists.

---



