#  Maximum Number of People at a Party

## Problem Statement

A camera at the door records the entry time `ai` and exit time `bi` for each of `n` people attending a party.

For every person:

```text
bi > ai
```

The objective is to determine the time when the maximum number of people were simultaneously present.

All entry and exit times are distinct.

## Example

Consider:

```text
Person 1: 1 5
Person 2: 2 7
Person 3: 4 6
Person 4: 8 10
```

At time `4`, three people are present.

Therefore:

```text
Maximum people = 3
Time = 4
```

## Algorithm

Represent every entry and exit as an event:

```text
Entry → +1
Exit  → -1
```

Thus, `n` people produce `2n` events.

1. Create all entry and exit events.
2. Sort the events according to time.
3. Initialize:

```text
current = 0
maximum = 0
```

4. Scan the sorted events.
5. For an entry, increment `current`.
6. For an exit, decrement `current`.
7. Whenever `current > maximum`, update the maximum and store that time.

## Complexity

There are `2n` events.

Sorting:

```text
O(n log n)
```

Scanning:

```text
O(n)
```

Overall:

**O(n log n)**

## Space Complexity

**O(n)**

## Technique

**Event Sorting + Sweep Line**

## C Implementation

See [`sorting4.c`](sorting4.c).

## Compilation

```bash
gcc sorting4.c -o sorting4
```

## Run

```bash
./sorting4
```

On Windows:

```bash
sorting4.exe
```

## Key Learning

Entry and exit information can be converted into events, sorted chronologically, and processed using a sweep-line technique.
