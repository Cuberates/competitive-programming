#include <iostream> 
#include <string> 

int main(void) { 
  std::string s; 
  std::cin >> s; 

  bool good = 1; 

  auto pal = [&](int l, int r) { 
    int tot = r - l; 
    for (int i = l; i <= r; i++) { 
      if (s[i] != s[i + tot - (i - l)]) return false; 
    }
    return true; 
  };

  for (int l = 0; l < s.length(); l++) {
    for (int r = l; r < s.length(); r++) { 
      if (pal(l, r) && (r - l + 1) % 2 == 0) { 
        good = false;  
        // for (int i = l; i <= r; i++) std::cout << s[i]; 
        // std::cout << "\n";
      }
    }
  }

  if (!good) std::cout << "Or not. \n";
  else std::cout << "Odd.\n"; 
}