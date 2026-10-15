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
#include <bits/stdc++.h>

using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;

namespace Cuberates {
  #define debug(v) std::cout << #v << ": "; Cuberates::_debug(v); std::cout << '\n';
  #define SPACE std::cout << ' ';
  #define NEXTLINE std::cout << '\n';
  template<typename T>
  void _debug(const T& t) { std::cout << t; }
  template<typename T, typename V>
  void _debug(const std::pair<T, V>& ptv) { _debug(ptv.first); SPACE; _debug(ptv.second);}
  template<typename T>
  void _debug(const std::vector<T>& vt) { for (const auto &v : vt) { _debug(v); SPACE; } }
  template<typename T, typename V>
  void _debug(const std::vector<std::pair<T, V>>& vptv) { for (const auto &ptv : vptv) { _debug(ptv); NEXTLINE; }}

};

const i64 MAX_N = 3e5;

#define all(v) (v).begin(), (v).end()
#define fi first
#define se second

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
template<typename T>
T irand(T L, T R){ return std::uniform_int_distribution<T>(L, R)(rng); }
template<typename T>
T rand(T L, T R){ return std::uniform_real_distribution<T>(L, R)(rng); }

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

void solve() {
  u64 x; 
  std::cin >> x;    

  auto diff = [&](u64 a, i64 b) -> u64 { 
    // return std::abs(std::pow(2, a) + std::pow(2, b) - x);
    u64 sum = (1ULL << a) + (1ULL << b); 
    return sum >= x ? sum - x : x - sum; 
  };

  auto search = [&](u64 p) -> u64 { 
    u64 lb = p, ub = 63; 
    while (lb < ub) { 
      u64 mid = lb + (ub - lb) / 2; 
      u64 sum = (1ULL << p) + (1ULL << mid);

      if (sum < x) lb = mid + 1; 
      else ub = mid; 
    }

    u64 ans = diff(p, lb); 
    if (lb > p) ans = std::min(ans, diff(p, lb - 1));
    return ans; 
  };
  
  u64 min_diff = x+1; 

  for (i64 i = 0; i < 64; i++) { 
    min_diff = std::min(min_diff, search(i));
  }
  
  std::cout << min_diff << "\n";
} 