#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <random>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <thread>

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
  int n; 
  std::cin >> n; 
  std::vector<int> a(n), b(n);
  for(int i = 0; i < n; i++) { std::cin >> a[i]; }
  for(int i = 0; i < n; i++) { std::cin >> b[i]; }

  // std::sort(a.begin(), a.end()); 

  // binary search for x; 
  long long l = 0, r = 1e9+1; 
  while (r-l > 1) { 
    int dl = ((2*l)+r)/3; 
    int dr = (l+(2*r))/3;
    int count_l = 0, count_r = 0; 
    for(int i = 0; i < n; i++) { 
      count_l += (a[i] >= dl);
      count_r += (a[i] >= dr);
    }
    // std::cout << "count_l: " << count_l << "\n";
    // std::cout << "count_r: " << count_r << "\n";
    int ll; 
    for(ll = 0; ll < n; ll++) { 
      if(count_l - b[ll] >= 0) count_l-=b[ll];
      else break;
    }
    int lr; 
    for(lr=0; lr<n;lr++) { 
      if(count_r - b[lr] >= 0) count_r-=b[lr];
      else break;
    }
    long long sl = ll * dl;
    long long sr = lr * dr;
    // std::cout << "sl: " << sl << "\n";
    // std::cout << "sr: " << sr << "\n"; 
    if(sl < sr) { 
      l = dl; 
      r = dr;
    } else { 
      r = dr;
    }
  }
  int count = 0; 
  for(int i = 0; i < n; i++) { 
    count += (a[i] >= r);
  }
  int level; 
  for(level = 0; level < n; level++) { 
    if (count - b[level] >= 0) count -= b[level];
    else break;
  }
  std::cout << level * r << "\n";
}
