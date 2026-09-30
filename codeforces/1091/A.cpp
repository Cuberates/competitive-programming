#include <bits/stdc++.h>

void solve(); 

int main() { 
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);
  
  int num_test = 0;   
  std::cin >> num_test; 
  for(int nt = 0; nt < num_test; nt++) {  
    solve(); 
  }
}

void solve() {  
  int n, k; 
  std::cin >> n >> k;
  std::vector<int> a(n);
  for(int i = 0; i < n; i++) 
    std::cin >> a[i];
  long long sum = 0; 
  for(int i = 0; i < n; i++)
    sum += a[i];

  // std::cout << "sum: " << sum << "\n";

  if (sum % 2 == 0) { 
    if ((n * k) % 2 == 0) std::cout << "YES\n";
    else std::cout << "NO\n";
  } else std::cout << "YES\n";
}