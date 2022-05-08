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

### How to understand a DP Problem?

1. Think if there are multiple ways by which you are required to check and then from those ways have to get a single solution 
- Which is basically RECURSION!!

2. Think if there are subproblems which are repeated multiple times in this recursion
- If yes, then that means it's a DP problem
- As it satisfies (1) subproblem solve to get bigger problem and (2) repeating subproblem

3. Think of the TOP DOWN APPROACH (recursion) 

4. Think of the TOP DOWN APPROACH (recursion + memoization)

5. Think of the BOTTOM UP APPROACH (iteration)
- Here, we need to think how we approach recursion
- Think about the formula F(N)= F(N-1) + F(N-2)... so similar thing we need to do in array as well

> There is nothing in DP more than this

----