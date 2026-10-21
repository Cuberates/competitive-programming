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

#define FOR(i, a, b) for (i64 (i) = (a); (i) < (b); (i)++)
#define FFOR(i, a, b) for (i64 (i) = (a); (i) >= (b); (i)--)
#define ALL(v) (v).begin(), (v).end()

void solve();

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);
  int num_test = 1;
  for(int nt = 0; nt < num_test; nt++) {
    solve();
  }
}

i64 n, m, x, y, vx, vy, negx = false, negy = false; 
i64 q, t;

std::vector<std::pair<i64, i64>> ans;

i64 reflectX (i64 totalDist) { 
  i64 r = ((totalDist % (2 * n)) + 2*n) % (2*n);
  return r <= n ? r : 2*n - r; 
}

i64 reflectY (i64 totalDist) { 
  i64 r = ((totalDist % (2 * m)) + 2*n) % (2*n); 
  return r <= m ? r : 2*m - r;  
}

void query(i64 totalTime) { 
  i64 totalDistX = totalTime * vx + x; 
  i64 totalDistY = totalTime * vy + y;

  i64 finalX = reflectX(totalDistX);
  i64 finalY = reflectY(totalDistY);

  if (negy) finalY = m - finalY; 
  if (negx) finalX = n - finalX;
  // std::cout << "(finalx, finaly): " << finalX << " " << finalY << "\n"; 
  // std::cout << finalX << " " << finalY << "\n";
  ans.push_back(std::make_pair(finalX, finalY));
} 

void solve() {
  std::cin >> n >> m >> x >> y >> vx >> vy >> q;
  if (vx < 0) {
    negx = true;  
    vx = -vx; 
    x = n-x; 
  } 
  if (vy < 0) {
    negy = true;  
    vy = -vy; 
    y = n-y; 
  }
  FOR(i, 0, q) { 
    std::cin >> t; 
    query(t);
  }
  for(auto &a : ans) { 
    std::cout << a.first << " " << a.second << '\n';
  }
}   
