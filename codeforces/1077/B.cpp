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
#include <algorithm>

void solve();

int main(void) { 
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);
  
  uint32_t num_test = 0;   
  std::cin >> num_test; 
  for(uint32_t nt = 0; nt < num_test; nt++) {
    solve(); 
  }
}

void solve() { 
  uint32_t n; 
  std::string s; 
  std::cin >> n >> s;

  if (n <= 1) { 
    s[0] = '0';
    std::cout << "1\n";
    return; 
  }

  uint32_t ans = 0;

  for(int i = 0; i < n; i++) { 
    if (s[i] == '0') { 
      if (i <= 0 && i+1 <= n-1 && s[i+1] == '0') { 
        s[i] = '1';
        ans++; 
      }
      else if (i > 0 && i-1 >= 0 && s[i-1] == '0' && i+1 <= n-1 && s[i+1] == '0') { 
        s[i] = '1';
        ans++; 
      }
      else continue; 
    } else continue;
  }
  std::cout << ans << "\n";
} 
