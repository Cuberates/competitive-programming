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
  // std::cin >> num_test;
  for(int nt = 0; nt < num_test; nt++) {
    solve();
  }
}

i64 n; 
std::vector<i64> r, vis; 
std::vector<std::vector<i64> > g; 

void dfs(i64 s, i64 rem);

void solve() {
  std::cin >> n; 
  r = std::vector<i64>(n); 
  for (i64 i = 0; i < n; i++) { 
    std::cin >> r[i]; 
  }
  vis = std::vector<i64>(n, 0);
  g = std::vector<std::vector<i64> >(n, std::vector<i64>(n, -1)); 
  for (i64 i = 0; i < n-1; i++) { 
    i64 u, v, l; 
    std::cin >> u >> v >> l; 
    g[u-1][v-1] = l; 
    g[v-1][u-1] = l; 
  }
  std::vector<i64> stations(n); 
  for (i64 i = 0; i < n; i++) stations[i] = i; 
  std::sort(stations.begin(), stations.end(), 
  [&](i64 x, i64 y) { return r[x] > r[y]; });
 
  i64 ans = 0;
  for (i64 i = 0; i < n; i++) { 
    if (!vis[stations[i]]) { 
      ans++; 
      dfs(stations[i], 0); 
    }
  }
  std::cout << ans << '\n';
}

void dfs(i64 s, i64 rem) {
  if (rem < 0) return; // overtraversing 
  vis[s] = 1; 
  i64 boost = r[s];

  for (i64 v = 0; v < n; v++) { 
    if (g[s][v] > -1 && !vis[v]) { 
      dfs(v, boost - g[s][v] + rem); 

    }
  }
}  