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
  int n; 
  std::cin >> n; 
  std::vector<long long> a(n), b(n);
  for(int i = 0; i < n; i++) { std::cin >> a[i]; } 
  for(int i = 0; i < n; i++) { std::cin >> b[i]; }

  std::sort(a.begin(), a.end(), std::greater<int>());
  std::vector<long long> need(n+1, 0);

  for(int i = 0; i <= n; i++) { 
    if (i <= 0) need[i] = 0;
    else need[i] = need[i-1] + b[i-1]; 
  }
  
  long long ans = -1; 
  
  for(int i = 0; i < n; i++) { 
    long long diff = a[i];
    long long num_swords = i+1; 

    long long passed = std::upper_bound(need.begin(), need.end(), num_swords)-need.begin()-1;
    long long score = passed * diff;
    ans = std::max(ans, score);
  }

  std::cout << ans << "\n";
}
