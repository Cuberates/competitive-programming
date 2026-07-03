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
#include "matrix.hpp"

/**@attention: Random generator stolen from a random person */
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
long long rand(long long L, long long R){
  return std::uniform_int_distribution<long long>(L, R)(rng);
}

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

const int64_t MOD = 998244353;

int64_t mod_add(const int64_t& a, const int64_t& b) { 
  return ((a % MOD) + (b % MOD)) % MOD;
}

int64_t mod_mul(const int64_t& a, const int64_t& b) { 
  return ((a % MOD) * (b % MOD)) % MOD; 
}

int64_t fast_pow(const int64_t& a_, const int64_t& b_) {
  int64_t a = a_, b = b_; 
  int64_t res = 1; 
  while (b > 0) { 
    if (b & 1) { res = mod_mul(res, a); }
    a = mod_add(a, a);
    b = (b >> 1);
  } 
  return res;
}

void solve() {
  size_t n, m, r, c; 
  std::cin >> n >> m >> r >> c; 

  int64_t ans = 0; 
  int64_t p1 = mod_mul(n,m); 
  
  int64_t x2 = mod_add(r,1);
  int64_t x3 = mod_add(n, -x2);

  int64_t y1 = mod_add(c, 1);
  int64_t y2 = mod_add(m, -y1);

  int64_t mul1 = mod_mul(x3, y2); 
  int64_t sub1 = mod_add(p1, -mul1);

  ans = fast_pow(2, sub1);
  std::cout << ans << "\n";
}