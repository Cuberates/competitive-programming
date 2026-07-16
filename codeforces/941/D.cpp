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

using ll = long long; 

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
  int n;
  std::cin >> n; 

  std::vector<std::vector<int> > points(n+1, std::vector<int>(2, 0));


  ll ans = 0; 

  for(int i = 0; i < n; i++) { 
    ll x, y; 
    std::cin >> x >> y; 
    points[x][y] = 1; 
  }

  for(int x = 0; x <= n; x++) { 
    for(int y = 0; y < 2; y++) {
      if (points[x][y] == 1) {
        if (y && points[x][0]) ans = ans + n - 2; 
        else if (!y && points[x][1]) ans = ans + n - 2;
      }
    }
  }
  ans /= 2; 

  for(int x = 0; x <= n; x++) { 
    if (points[x][1] && x-1 >= 0 && x+1 <= n && points[x-1][0] && points[x+1][0]) ans++; 
  }
  for(int x = 0; x <= n; x++) { 
    if (points[x][0] && x-1 >= 0 && x+1 <= n && points[x-1][1] && points[x+1][1]) ans++; 
  }


  std::cout << ans << "\n";

}
/**
P1 = (x1, y1)
P2 = (x2, y2)
P3 = (x3, y3)

triangle inequality???


if 2 points p1, p2 lie on the same vertical line, then the number of triangles = n-2?

they are unique proof: fixing p1, p2 there are n-2 other point, since these points are pairwise unique, 
the triangles must be unique

lemma there is only one triangle with mid point;
proof: i made it up
*/
