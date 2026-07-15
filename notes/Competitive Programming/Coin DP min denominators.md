Recall [[Coin DP count arrangements]]
We want to find the min number of denominators to use. 

```
let dp[s] be the answer for sum = s; 

For a coin denominator coins[i], we can either choose it or don't. If you choose a coin, dp[s] = dp[s-coins[i]]+1 otherwise, we move to a different denominator. The answer for this subproblem is the min of all denominators

Recurrence: dp[s] = min(dp[s], dp[s-coins[i]]+1);

fill(dp.begin(), dp.end(), INF);  

for(int i = 0; i <= sum; i++) { 
	if (i == 0) { dp[i] = 0; continue; }
	for(int j = 0; j < coins.size(); j++) { 
		if (i-a[j] >= 0) dp[i] = min(dp[i], dp[i-coins[j]]+1);
	}
}
// It is possible to not have a possible arrangements
// Example: coins = [2, 4], sum = 1 or sum = 7
std::cout << (dp[sum] == INF ? "NO SOLUTION" : dp[sum]) << "\n";
```