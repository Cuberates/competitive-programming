#include <iostream> 
#include <vector> 

using i64 = int64_t; 

i64 testCount = 0;  
const i64 MAX_N = 3;   

void outTest(std::vector<i64> &v) { 
  std::cout << v.size() << " ";
  for (auto &_ : v) std::cout << _ << " ";
  std::cout << "\n";
}

void genTest(i64 n) {
  std::vector<i64> v(n, -50);  
  i64 curr = 0; 
  while (true) {
    outTest(v); 
    
    if (curr >= n) break; 
    else if (v[curr] >= 50) curr++; 
    else { v[curr]++; }
    
    testCount++; 
  } 
}

int main(void) { 
  const int64_t MAX_N = 4; 
  i64 totalTest = 0; 
  for (i64 l = 2; l <= MAX_N; l++) { 
    totalTest += (101 * l); 
  }
  std::cout << totalTest << "\n"; 
  for (i64 l = 2; l <= MAX_N; l++) { 
    genTest(l); 
  }

}