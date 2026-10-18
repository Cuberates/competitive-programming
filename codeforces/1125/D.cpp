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
using i64 = long long;
using u64 = uint64_t;

#define all(v) (v).begin(), (v).end()

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
  i64 n, k; 
  std::cin >> n >> k; 
  
  std::vector<std::vector<i64>> m(n, std::vector<i64>(3, 0));

  i64 min_sum = std::numeric_limits<i64>::max();
  for (i64 i = 0; i < n; i++) { 
    std::cin >> m[i][0] >> m[i][1] >> m[i][2];
    min_sum = std::min(min_sum, m[i][0] + m[i][1] + m[i][2]);
  }

  auto compute_cost = [&](i64 sum) -> i64 { 
    i64 total_cost = 0; 
    for (i64 i = 0; i < n; i++) { 
      i64 a = m[i][0], b = m[i][1], c = m[i][2];
      i64 curr_sum = a + b + c;
      if (curr_sum >= sum) continue;

      if (a == b && b == c) return k + 1; // Takes infinite cost 

      i64 cost = sum - curr_sum;
      if (a <= b && b <= c) {
        i64 setup = std::min(b - a, c - b) + 1; 
        cost += 2 * setup; 
      }

      if (cost > k - total_cost) return k + 1;
      total_cost += cost;
    }
    return total_cost;   
  };
  auto reachable = [&](i64 sum) -> bool
  {
    i64 cost = compute_cost(sum);  
    return (cost <= k);
  };

  i64 lb = min_sum, ub = min_sum + k + 1;
  while (ub - lb > 1) {
    i64 sum = lb + (ub - lb) / 2;
    
    auto good = reachable(sum);

    if (good) lb = sum;  
    else ub = sum; 
  }
  std::cout << lb << "\n";
}
