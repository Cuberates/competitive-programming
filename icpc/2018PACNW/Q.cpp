#include <random>
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

using i8 = int8_t; 
using u8 = uint8_t; 
using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;

i64 brute(i64 n) { 
  i64 tot = n*(n-1)/2; 

  int count = 0; 
  for (int i = 1; i <= n; i++) { 
    for (int j = i + 1; j <= n; j++) { 
      count++; 
      if (count >= tot/2 + (tot % 2 != 0)) {
        return i; 
      }
    }
  }
}

i64 solve(i64 n) { 
  i64 tot = n*(n-1)/2;  
  auto cnt = [&](i64 k) -> i64 { 
    i64 suff = (n-k)*(n-k+1)/2; 
    return tot - suff; 
  }; 
  i64 l = 1, r = n; 
  while (r - l > 1) { 
    i64 mid = l + (r - l)/2; 
    if (cnt(mid) >= tot / 2 + (tot % 2 != 0)) r = mid; 
    else l = mid; 
  }
  return l; 
}

void benchmark() { 
  for (i64 test = 10000; test <= 30000; test++) { 
    i64 ans = solve(test); 
    i64 brut = brute(test);
    // std::cout << test << " " << ans << " " << brut << "\n";
    if (ans != brut) { 
      std::cout << test << " " << brut << " " << ans << "\n";
      return; 
    }
  }
  std::cout << "Passed all test!\n";
}

int main(void) { 
  i64 n; 
  std::cin >> n; 
  // i64 ans = solve(n);
  // // verify(n, ans);
  // benchmark();
  // i64 n; std::cin >> n; 
  std::cout << solve(n) << "\n"; 
}