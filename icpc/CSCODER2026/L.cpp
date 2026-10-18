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

  int num_test = 1;
  // std::cin >> num_test;
  for(int nt = 0; nt < num_test; nt++) {
    solve();
  }
}


i64 row, col; 
std::vector<std::string> g; 
std::vector<std::vector<i8>> vis;

void dfs(i64 r, i64 c) { 
  if (r < 0 || r >= row) return; 
  if (c < 0 || c >= col) return; 
  if (vis[r][c] || g[r][c] == '#') return;
  
  vis[r][c] = 1; 
  g[r][c] = '#';

  dfs(r+1, c);
  dfs(r-1, c);
  dfs(r, c+1);
  dfs(r, c-1);
}

void solve() {
  std::cin >> row >> col;  
  
  g = std::vector<std::string>(row);
  vis = std::vector<std::vector<i8>>(row, std::vector<i8>(col, 0)); 
  
  i64 dx, dy;
  for (i64 r = 0; r < row; r++) { 
    std::cin >> g[r];
  }

  i64 puddles = 0; 

  for(i64 r = 0; r < row; r++) { 
    for(i64 c = 0; c < col; c++) { 
      if (g[r][c] == 'D') dfs(r, c);
    }
  }
  for(i64 r = 0; r < row; r++) { 
    for(i64 c = 0; c < col; c++) { 
      if (g[r][c] == '.') { puddles++; dfs(r, c); }
    }
  }

  // for (i64 i = 0; i < row; i++) {
  //   std::cout << g[i] << "\n";
  // }
  
  std::cout << puddles << "\n";
}