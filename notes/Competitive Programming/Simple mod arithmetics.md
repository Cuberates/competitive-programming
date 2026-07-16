```
Modular expansion

(a + b) mod m = ((a mod m) + (b mod m)) mod m 
(a - b) mod m = ((a mod m) - (b mod m)) mod m 
ab mod m  = (a mod m . b mod m) mod m
```

```
For modular incrementation (m > 1): 
	(a + 1) mod m = a mod m + 1 mod m
				     = (a mod m + 1) mod m
This is extremely common for many counting problems
```

```c++
ll mod (ll a, ll m ) { 
	return (a > 0 ? a % m : m - ((-a) % m));
}
ll add(ll a, ll b) { 
	return mod((mod(a, m) + mod(b, m)), m); 
}
ll mul(ll a, ll b) { 
	return mod(mod(a, m) * mod(b, m), m);
}
```
