**Problem.** Given an integer array coins[] representing different denominations of currency and an integer *sum*. We need to find the number of ways we can make *sum* by using different combinations from coins[].

```
Let count[s] be the number of ways to add to s. Let c be a coin denominator, we can see that count[s] = count[s - c]; 
dp[x] = sum of all i's dp[x-coins[i]]

for(int64_t s = 0; s <= sum; s++) { 
	if (s == 0) dp[s] = 1; // there is one way for sum = 0, do nothing. 
	for(size_t i = 0; i < coins.size(); i++ ) { 
		if (s - coins[i] >= 0) dp[s] += (dp [s-coins[i]]); 
	}
}
output(dp[sum]);
```



