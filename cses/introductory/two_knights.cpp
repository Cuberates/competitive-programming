#include <iostream> 

void solve(const int64_t &k) { 
  // Answer = # of possible post. - # knights attacking.
  
  // Compute # ways to put two knights on the board.
  // total = k*k choose 2
  int64_t total = (k*k)*(k*k-1)/2;

  // Compute # ways to arrange 2 knights so that they attack
  // The number of 2x3 verticle and horizontal squares

  int64_t vertical = (k-1)*(k-2)*2;
  int64_t horizontal = (k-2)*(k-1)*2; 
  int64_t attacks = vertical + horizontal; 

  std::cout << total - attacks << "\n";
}

int main(void) { 
  int64_t n;
  std::cin >> n; 
  for(int64_t k = 1; k <= n; k++) { 
    solve(k);
  }
}