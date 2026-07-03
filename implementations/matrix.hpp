#ifndef MATRIX_H
#define MATRIX_H
#include <vector> 
#include <cassert>

template <typename T>
class Mat {
  public:
  size_t rows, cols; 
  std::vector<T> data;    
  Mat(size_t rows, size_t cols) : 
    rows {rows}, 
    cols {cols}, 
    data {std::vector<T>(rows * cols, 0) } {}

  operator() (int i, int j)
  operator[] (int k)
  friend ostream& operator<< (ostream& os, Mat &m)
};

// template<typename T>
// void mat_add(Mat<T> &dst, Mat<T> &a, Mat<T> &b) { 

// }; 
// template<typename T>
// void mat_sub(Mat<T> &dst, Mat<T> &a, Mat<T> &b) { 

// }; 
// template<typename T>
// void mat_mul(Mat<T> &dst, Mat<T> &a, Mat<T> &b) { 

// }; 
// template<typename T>
// void mat_scale(Mat<T> &dst, Mat<T> &a, Mat<T> &b) { 

// }; 




#endif