#  Sort Items by Colour

## Problem Statement

Assume that we are given `n` pairs of items as input, where the first item is a number and the second item is one of three colours:

- Red
- Blue
- Yellow

The items are already sorted by number.

The objective is to sort the items by colour in the order:

```text
Red → Blue → Yellow
```

while ensuring that the numbers belonging to the same colour remain sorted.

## Example

### Input

```text
6
1 blue
3 red
5 yellow
7 red
9 blue
11 yellow
```

### Output

```text
3 red
7 red
1 blue
9 blue
5 yellow
11 yellow
```

The relative numerical order within each colour is preserved.

## Algorithm

Since the input is already sorted by number, use three separate arrays:

```text
red[]
blue[]
yellow[]
```

1. Traverse the input once.
2. Put each item into the corresponding colour array.
3. Concatenate `red`, `blue`, and `yellow` in that order.
4. Since the original input is sorted by number, each colour array is automatically sorted by number.

## Complexity

- Time Complexity: **O(n)**
- Space Complexity: **O(n)**

## Technique

**Bucket-based grouping / stable partitioning**

## C Implementation

See [`sorting1.c`](sorting1.c).

## Compilation

```bash
gcc sorting1.c -o sorting1
```

## Run

```bash
./sorting1
```

On Windows:

```bash
sorting1.exe
```

## Key Learning

This problem demonstrates how a special property of the input—already being sorted by number—can be used to achieve linear-time sorting by category.
