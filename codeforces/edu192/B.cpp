#include <random> 
#include <random> 
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

using ll = long long; 
const ll INF = 2e5+1;

void gabagoo(); 

int main() { 
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);
  
  int num_test = 0;   
  std::cin >> num_test; 
  for(int nt = 0; nt < num_test; nt++) {  
    gabagoo(); 
  }
}

void gabagoo() {   
  ll n; 
  std::cin >> n; 
  std::vector<ll> v(n);
  for(ll i = 0; i < n; i++) { 
    std::cin >> v[i];
  }

  std::vector<int> cnt1(n+1, 0), cnt2(n+1, 0);
  
  for(int i = 1; i <= n; i++) { 
    cnt1[i] = cnt1[i-1] + (v[i-1] == 1 ? 1 : -1);
    cnt2[i] = cnt2[i-1] + (v[i-1] == 3 ? -1 : 1);
  }

  std::vector<int> min2(n+1, INF);  

  bool good = false; 
  
  for(int i = 1; i <= n; i++) {
    min2[i] = min2[i-1]; 
    if (cnt1[i] >= 0) min2[i] = std::min(min2[i-1], cnt2[i]);
  }

  for(int y = 2; y <= n-1; y++) { 
    if (cnt2[y] >= min2[y-1]) good = true; 
  }

  std::cout << (good ? "YES" : "NO") << '\n';
} 


