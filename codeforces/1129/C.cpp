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

void solve() { 
  i64 n, m; 
  std::cin >> n >> m; 
  std::map<i64, std::vector<i64>> g; 
  for (i64 i = 0; i < n-1; i++) { 
    i64 u, v; 
    std::cin >> u >> v; 
    g[u].push_back(v); 
    g[v].push_back(u); 
  }
  std::vector<i64> vis(n + 1, 0); 
  std::vector<i64> dist(n + 1, -1);
  std::vector<i64> ext(n + 1, 0); 
  i64 branch = false; 
  std::queue<i64> q;
  q.push(n); 
  dist[n] = 0; 
  while (q.size()) { 
    i64 u = q.front(); 
    q.pop(); 
    // std::cout << u << "\n";
    if (vis[u]) continue;  
    vis[u] = 1; 
    if (branch) ext[u] = 1; 
    for (i64 v : g[u]) { 
      if (v == 1) { branch = true; }
      if (dist[v] == -1) { 
        dist[v] = dist[u] + 1; 
        if (u != 1) q.push(v); 
      }
    }
  }
  i64 ans = dist[1]; 
  for (i64 i = 0; i < m; i++) { 
    i64 v; 
    std::cin >> v; 
    if (v != 1 && v != n && dist[v] != -1 && ext[v]) { 
      ans = std::max(dist[v] + 1, ans);  
      ext[v] = 0; 
    }
  }
  std::cout << ans << "\n";
  // std::cout << "dist: "; debug(dist);  
};