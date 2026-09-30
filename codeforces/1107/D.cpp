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

void solve() {
  int64_t n; std::cin >> n; 
  std::vector<int64_t> a(n), b(n);
  for(int i = 0; i < n; i++) { 
    std::cin >> a[i];
  } 
  for(int i = 0; i < n; i++) { 
    std::cin >> b[i];
  }
  for(int i = n-1; i >= 1; i--) { 
    if (a[i] > b[i]) a[i-1] += (a[i]-b[i]);
    a[i] = b[i];
  }
  int good = true; 
  if (a[0] > b[0]) good = false; 

  std::cout << (good ? "YES" : "NO") << "\n";
} 

/*
- If we only pick l = r = i then the element can only increase
- Decrease a[i] by picking l = i-1, r = i => dst(i, l) = i-(i-1) = 1 =
but then a[i+1] will increase

o1 Pick l=i-1, r=i => a[i-1]++ ; a[i]--; 
o2 Pick l=r=i => a[i]++;

Pick l=i-2, r=i => a[i-2]++; a[i-1]--; a[i]++; 
=> This increases the sum of array by 1;

a[i] < b[i] => Apply o1 b[i]-a[i] times
a[i] > b[i] 
  b[i-1] - a[i-1] = a[i] - b[i] then apply o2 a[i]-b[i] times

*/