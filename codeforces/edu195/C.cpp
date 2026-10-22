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

void solve();

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);
  int num_test = 1;
  std::cin >> num_test;
  for(int nt = 0; nt < num_test; nt++) {
    solve();
  }
}

void debug(const std::vector<i64> &v, i64 l, i64 r) { 
  for (i64 i = l; i <= r; i++) { 
    std::cout << v[i] << " ";
  }
  std::cout << "\n";
}

void solve() {
  i64 n, k; 
  std::cin >> n >> k; 
  std::vector<i64> v(n); 
  for (i64 i = 0; i < n; i++) { 
    std::cin >> v[i];
  }
  std::vector<i64> pref(n + 1); 
  for (i64 i = 0; i <= n; i++) { 
    if (i <= 0) pref[i] = 0; 
    else pref[i] = v[i-1] + pref[i-1];
  }
  auto sum = [&](i64 l, i64 r) { 
    return pref[r] - pref[l-1]; 
  };
}