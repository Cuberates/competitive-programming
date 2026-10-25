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

void debug(std::vector<i64>& v) { 
  for (auto &_ : v) std::cout << _ << " "; 
  std::cout << '\n';
}
void debug(i64 &v) { 
  std::cout << v << " ";
}
void debug(i64 &&v) { 
  std::cout << v << " "; 
}

struct Graph { 
  std::map<i64, std::vector<i64>> g; // g[u][v] contains connection 
  void add(i64 u, i64 v) { g[u].push_back(v); g[v].push_back(u); };
  void dfs(i64 root, i64 depth = 0); 
}; 

std::vector<i64> vis(5e5+1, false); 

i64 maxDepth = 0; 
void Graph::dfs(i64 root, i64 depth = 0) { 
  if (!root || vis[root] || !g[root].size()) { 
    maxDepth = std::max(maxDepth, depth); 
    return; 
  }
  vis[root] = true; 
  for (auto &v : g[root]) { dfs(v, depth + 1); }
}

void setup() { 
  std::fill(vis.begin(), vis.end(), false); 
  maxDepth = -1; 
}

void solve() {  
  i64 n, m; 
  std::cin >> n >> m; 
  std::vector<i64> ops(m);
  Graph g {}; 
  for (i64 i = 0; i < n-1; i++) {
    i64 u, v; 
    std::cin >> u >> v; 
    g.add(u, v);
  }
  
  for (i64 i = 0; i < m; i++) { 
    std::cin >> ops[i]; 
  }

  setup(); 
  g.dfs(1); 

  i64 ans = maxDepth + (m / 2); 
  std::cout << ans << "\n";
}

