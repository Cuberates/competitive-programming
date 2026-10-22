#include <algorithm>
#include <cstdint>
#include <iostream>
#include <utility>
#include <vector>

using i64 = std::int64_t;

int n;
std::vector<i64> r;
std::vector<std::vector<std::pair<int, i64>>> g;
std::vector<int> parent, subtree, centroid_parent, centroid_level, cursor;
std::vector<char> removed, vis;
std::vector<std::vector<int>> nearby;
// distance_at[level][v] is the distance to v's centroid ancestor at this level.
std::vector<std::vector<i64>> distance_at;

void decompose(int entry, int previous, int level) {
  std::vector<int> nodes(1, entry);
  parent[entry] = -1;
  for (int i = 0; i < static_cast<int>(nodes.size()); ++i) {
    int u = nodes[i];
    subtree[u] = 1;
    for (auto [v, length] : g[u]) {
      if (removed[v] || v == parent[u]) continue;
      parent[v] = u;
      nodes.push_back(v);
    }
  }
  for (int i = static_cast<int>(nodes.size()) - 1; i > 0; --i) {
    int u = nodes[i];
    subtree[parent[u]] += subtree[u];
  }

  int total = static_cast<int>(nodes.size());
  int c = entry;
  while (true) {
    int heavy = -1;
    for (auto [v, length] : g[c]) {
      if (!removed[v] && parent[v] == c && subtree[v] > total / 2) {
        heavy = v;
        break;
      }
    }
    if (heavy == -1) break;
    c = heavy;
  }

  centroid_parent[c] = previous;
  centroid_level[c] = level;
  removed[c] = true;
  nodes.clear();
  nodes.push_back(c);
  parent[c] = -1;
  auto &distance = distance_at[level];
  distance[c] = 0;
  for (int i = 0; i < static_cast<int>(nodes.size()); ++i) {
    int u = nodes[i];
    for (auto [v, length] : g[u]) {
      if (removed[v] || v == parent[u]) continue;
      parent[v] = u;
      distance[v] = distance[u] + length;
      nodes.push_back(v);
    }
  }
  std::sort(nodes.begin(), nodes.end(), [&](int u, int v) {
    return distance[u] < distance[v];
  });
  nearby[c] = std::move(nodes);

  // Only centroid decomposition recurses; its depth is O(log n).
  for (auto [v, length] : g[c]) {
    if (!removed[v]) decompose(v, c, level + 1);
  }
}

// Find an unvisited outgoing neighbor in the implicit graph
// u -> v iff tree_distance(u, v) <= r[u].
int next_unvisited(int u) {
  for (int c = u; c != -1; c = centroid_parent[c]) {
    const auto &distance = distance_at[centroid_level[c]];
    i64 remaining = r[u] - distance[u];
    if (remaining < 0) continue;
    const auto &nodes = nearby[c];
    int &p = cursor[c];
    while (p < static_cast<int>(nodes.size()) && vis[nodes[p]]) ++p;
    if (p < static_cast<int>(nodes.size()) && distance[nodes[p]] <= remaining) {
      return nodes[p];
    }
  }
  return -1;
}

void dfs(int start, std::vector<int> &stack, std::vector<int> *finish) {
  vis[start] = true;
  stack.push_back(start);
  while (!stack.empty()) {
    int u = stack.back();
    int v = next_unvisited(u);
    if (v == -1) {
      if (finish != nullptr) finish->push_back(u);
      stack.pop_back();
    } else {
      vis[v] = true;
      stack.push_back(v);
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> n;
  r.resize(n);
  for (auto &range : r) std::cin >> range;
  g.resize(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    i64 length;
    std::cin >> u >> v >> length;
    --u;
    --v;
    g[u].emplace_back(v, length);
    g[v].emplace_back(u, length);
  }
  parent.resize(n);
  subtree.resize(n);
  centroid_parent.resize(n);
  centroid_level.resize(n);
  cursor.assign(n, 0);
  removed.assign(n, false);
  vis.assign(n, false);
  nearby.resize(n);
  int levels = 1;
  while ((1LL << levels) <= n) ++levels;
  distance_at.assign(levels, std::vector<i64>(n));
  decompose(0, -1, 0);

  std::vector<int> stack, finish;
  stack.reserve(n);
  finish.reserve(n);
  for (int u = 0; u < n; ++u) {
    if (!vis[u]) dfs(u, stack, &finish);
  }

  std::fill(vis.begin(), vis.end(), false);
  std::fill(cursor.begin(), cursor.end(), 0);
  int answer = 0;
  // Forward DFS in decreasing finish order starts once per source SCC.
  for (auto it = finish.rbegin(); it != finish.rend(); ++it) {
    if (!vis[*it]) {
      ++answer;
      dfs(*it, stack, nullptr);
    }
  }
  std::cout << answer << '\n';
}
