**Problem statement:** [A. Nim Game Is XOR Game](https://codeforces.com/problemset/problem/2239/A)
Alice and Bob are playing a game with array $A$ consisting of $n$ non-negative integers. Alice goes first. In each turn the player chooses an array $B$ satisfying the following: 
- $\sum_{i=1}^{n}b_i > 0$ (The array cannot be entirely 0)
- $\text{XOR}_{i=1}^{n} b_i = 0$ (XORing all the elements give 0)
- $b_i \le a_i$ for all $1 \leq i \leq n$.
### Solution
* It can be proven that the first player is guaranteed to win as long as there are at least TWO non-negative numbers. 	
* We can pick two elements $a_i, a_j$ with $a_i \le a_j$ and construct an array where $b_i = b_j = min(a_i, a_j)$ and 0 at every other spots. Then after the operation, $a_i = 0, a_j = a_j - a_i \ge 0$. The number of usable elements decrease by 1. 
* Let M be the number of non-negative elements in the original array. If M = 2 then apply the operation once, and Bob the remaining elements is 1. Otherwise: 
	(1) If M is even then, we exhaust one element, Bob has to exhaust one element, and due to the parity the remaining array will have one usable element when it's Bob's turn. 
	(2) If M is odd, then we only need to decrease a pair of elements by 1. If Bob tries to exhaust the element, then we do the same operation. Due to the parity the remaining number of usable element is 1, and it's Bob turn again.
* Then the answer is the number of indices such that $a_i \ \text{XOR} \ X  < a_i$