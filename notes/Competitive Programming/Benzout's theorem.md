```markdown
Let a, b be integers, and g = gcd(a, b). Then there exists x, y such that: ax + by = multiples of g.
```

```markdown
Define [a] mod class modulo g these are the following properties: 
(1) if b is in [a] then b mod g = a mod g; 
(2) if b in in [a] then b - a = multiple of g 
(3) let [a], [b] be mod classes, if b mod g = a mod g then [b] = [a]
```

```markdown
Suppose that we have multiple coin denominators coins[] = [a, b, c, ...] , and we want to see if there is an arrangement such that we can make 'sum'. 

Let g = gcd(a, b, c, d, ...);
Then by Benzout's theorem: 
ax + by + cz + dy + ... = nd;

If sum is not a multiple of d then we cannot make it
```

