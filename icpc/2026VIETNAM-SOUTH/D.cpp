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

#define all(v) (v).begin() (v).end()
#define fi first
#define se second

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

void solve() {
  std::string s; 
  std::cin >> s; 

  i64 n = s.length(); 

  std::map<char, i64> freq; 
  for (i64 i = 0; i < n; i++) { 
    freq[s[i]]++;
  }

  i64 min = 0; 
  i64 odds = 0;
  i64 dist = 0; 
  for (char c = 'A'; c <= 'Z'; c++) { 
    min += (freq[c] / 2); 
    odds += (freq[c] % 2 != 0);
    dist += (freq[c] > 0);
  }

  if (dist <= 1) { std::cout << "-1\n"; }
  else { 
    if (!odds) std::cout << min-1 << "\n";
    else if (odds <= 1) std::cout << min << "\n";
    else std::cout << min+1 << "\n";
  }
} 