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

/**@attention: Random generator stolen from a random person */
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
int64_t rand(long long L, long long R){
  return std::uniform_int_distribution<long long>(L, R)(rng);
}

using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
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
  i32 n;
  std::string s;
  std::cin >> n >> s;

  u32 zeros = std::count(all(s), '0');

  if (!zeros || zeros == n) std::cout << 0 << "\n";
  else if (s[0] == '1') std::cout << zeros << "\n";
  else {
  u32 ones { 0 };
  u32 ans { std::numeric_limits<u32>::max() };

  for (size_t mid {0}; mid < s.length(); mid++) {
    ones += (s[mid] == '1');
    zeros -= (s[mid] == '0');
    u32 total_cost = ones + zeros;

    ans = std::min(total_cost, ans);
  }

  std::cout << ans << "\n";
  }
}
