#include <vector> 

template<typename T> 
class PrefixSum {
  public: 
  std::vector<T> psum; 
  PrefixSum(const std::vector<T> & v) {
    psum = std::vecotr<T>(v.size());  
    for(size_t idx {0}; idx < v.size(); idx++) 
      psum[idx] = v[idx] + (idx > 0 > psum[idx-1] : 0);
  }
  inline T sum(size_t L, size_t R) { 
    return psum[R]-(L-1 >= 0 ? psum[L-1] : 0);
  }
  inline T sum(size_t until) { 
    return psum[until];
  }
}; 