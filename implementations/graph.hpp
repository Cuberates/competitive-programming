#ifndef GRAPH_H
#define GRAPH_H
#include <vector> 
#include <cassert>

class Graph {
  public: 
  int size; 
  using arr2d = std::vector<std::vector<int> >;   
  using arr1d = std::vector<int>;
  arr1d data;
  arr2d edge; // 1 if {u,v} in E, 0 otherwise;
  
  Graph(int n) : 
    size {n}, 
    data { arr1d(n) }, 
    edge { arr2d(n, arr1d(n, 0)) } {} 
  
  void read(int u, int v) { 
    assert(0 <= u <= size-1 && 0 <= v <= size-1); 
    edge[u][v] = 1; 
  }
  void read(arr1d& vec) { 
    assert(size == vec.size()); 
    data = std::move(vec);
  }
};

#endif