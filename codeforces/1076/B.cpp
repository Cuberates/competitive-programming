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
  int n; std::cin >> n; 
  std::vector<int> p(n);
  for(int i = 0; i < n; i++)
    std::cin >> p[i];

  std::vector<int> sorted_p = p; 
  std::sort(sorted_p.begin(), sorted_p.end(), std::greater<int>());

  for(int i = 0; i < n; i++) { 
    if (sorted_p[i] != p[i]) { 
      int pivot; 
      for (pivot=i+1; pivot < n && p[pivot] != sorted_p[i]; pivot++);
      std::reverse(p.begin()+i, p.end()-(n-(pivot+1)));
      break;
    } else continue;
  }

  for(int i = 0; i < n; i++) { 
    std::cout << p[i] << " ";
  }
  std::cout << "\n";
}
