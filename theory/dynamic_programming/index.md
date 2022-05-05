## Dynamic Programming (DP)

### What is DP ?
- DP is an optimization technique

### Where to apply DP ?
- Problems with optimal substructure && Overlapping subproblems

**What is optimal substructure ?**
- If a problem can be divided into smaller parts which can then add up to give solution for the bigger problem is called optimial substructure

For example: Fibonacci Recursion or Merge sort

**What is Overlapping subproblems ?**
- If a optimal substructure problem has multiple smaller groups for which we are finding solution multiple times then that's an overlapping subproblem

For example: Fibonnaci series using recursion

> If you see closely Fib Series with recursion is both optimal substructure && overlapping subproblem hence we can apply DP on it

> While merge sort is just optimal substructure but it's not an overlapping subproblem hence we can't implement DP on it.

### Types of DP Solutions?

1. Top Down: Recursion + memoization (Fib series with recursion)

2. Bottom Up: Iterative (Fib series when we take it from 0, 1... and go all the way to required num)

- In general Bottom Up is faster as it doesn't have that stack overhead, while top down is easier to implement