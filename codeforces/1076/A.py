num_test = int(input())

for tt in range(0, num_test): 
  n, s, x = input().split(' ')
  n = int(n)
  s = int(s) 
  x = int(x)
  a = [int(i) for i in input().split(' ')]
  
  sum = 0 
  for i in range(0, n):
    sum = sum + a[i]
  s -= sum
  if (s % x != 0 or s < 0): 
    print("NO \n")
  else: print("YES \n")
  