#include <iostream> 
#include <string> 
#include <bitset>

int bit_reps = 16;

// Generate gray code using cp-algorithms
std::string gray_code(const int64_t& n) { 


  std::string res; 
  int64_t g = n ^ (n >> 1);
  
  
  return res = std::bitset<16>(g).to_string();
}

void out(std::string& s) { 
  for(size_t i = 0; i < s.length(); i++) { 
    if (s.length() - i <= bit_reps) std::cout << s[i];
  }
}

void set_bit_reps(const int64_t& n) {
  int64_t res = 0; 
  while (n > (1 << res)) { res++; }
  bit_reps = res; 
}

int main(void) { 
  int64_t n; 
  std::cin >> n;
  set_bit_reps(1 << n);

  // std::cout << bit_reps << "\n";

  for(int64_t i = 0; i < (1 << n); i++) { 
    std::string gray = gray_code(i);
    out(gray);
    std::cout << '\n';
  }
}
