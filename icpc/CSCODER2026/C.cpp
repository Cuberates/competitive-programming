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

template<typename T> 
using vec = std::vector<T>; 
template<typename T> 
using vec2 = std::vector<std::vector<T>>; 

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

const i64 INF = std::numeric_limits<i64>::max();

i64 n, m, p;
vec2<std::pair<i64, i64>> g;  // (destination, fare)
vec<std::array<i64, 3>> dist;

void dijkstra(i64 s) {
  // States: 0 = unused, 1 = first route covered, 2 = both routes covered.
  dist.assign(n, {INF, INF, INF});
  using State = std::tuple<i64, i64, int>;  // (cost, stop, pass state)
  std::priority_queue<State, vec<State>, std::greater<State>> pq;
  dist[s][0] = 0;
  pq.emplace(0, s, 0);

  while (!pq.empty()) {
    auto [cost, u, state] = pq.top();
    pq.pop();
    if (cost != dist[u][state]) continue;

    auto relax = [&, cost = cost](i64 v, int next_state, i64 extra) {
      if (cost > INF - extra) return;  // Avoid signed overflow.
      i64 next_cost = cost + extra;
      if (next_cost < dist[v][next_state]) {
        dist[v][next_state] = next_cost;
        pq.emplace(next_cost, v, next_state);
      }
    };

    // Keep exploring even at stop n: a half-used pass must be completed.
    for (auto [v, w] : g[u]) {
      if (state == 0) {
        relax(v, 0, w);  // Pay normally.
        relax(v, 1, p);  // Buy the pass and cover the first route.
      } else if (state == 1) {
        relax(v, 2, 0);  // The very next route completes the pass.
      } else {
        relax(v, 2, w);  // The pass has already been used.
      }
    }
  }
}

void solve() {
  std::cin >> n >> m >> p;
  g.assign(n, {});

  for (i64 i = 0; i < m; i++) {
    i64 u, v, w;
    std::cin >> u >> v >> w;
    g[u - 1].emplace_back(v - 1, w);
  }

  dijkstra(0);
  i64 answer = std::min(dist[n - 1][0], dist[n - 1][2]);
  std::cout << (answer == INF ? -1 : answer) << '\n';
}
