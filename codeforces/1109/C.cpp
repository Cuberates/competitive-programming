#include <random> 
#include <numeric>
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

using ll = long long; 

/**@attention: Random generator stolen from a random person */
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
long long rand(long long L, long long R){
  return std::uniform_int_distribution<long long>(L, R)(rng);
}

uint32_t solve(); 

int main() { 
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);
  
  int num_test = 0;   
  std::cin >> num_test; 
  for(int nt = 0; nt < num_test; nt++) {  
    solve(); 
  }
} 

uint32_t solve() { 
  size_t n; 
  ll x, y; 
  std::cin >> n >> x >> y; 

  std::vector<ll> perm(n);

  for(size_t i {0}; i < n; i++) { 
    std::cin >> perm[i];
  } 

  ll g = std::gcd(x, y);

  // benzout: there exists a, b such that a * x + b * y = multiples of g;
  // check if they are in the same residue class; 

  for(size_t i = 0; i < n; i++) { 
    int rem = (i+1) % g; 
    if (rem != perm[i] % g) { 
      std::cout << "NO \n";
      return 0; 
    }
  }
  std::cout << "YES \n"; 
}