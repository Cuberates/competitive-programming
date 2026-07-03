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

  T& operator() (int i, int j); 
  T& operator[] (int k); 
  friend std::ostream& operator<< (std::ostream& os, Mat &m);
};

template<typename T> 
T& Mat<T>::operator() (int i, int j) {
  assert(i < rows);
  assert(j < cols);
  return data[i * cols + j];
}

template<typename T>
T& Mat<T>::operator[] (int i) {
  assert(i < rows * cols); 
  return data[i];
}

template<typename T> 
std::ostream operator<< (std::ostream& os, Mat<T>& m) { 
  for(size_t r {0}; r < m.rows; r++) { 
    for(size_t c {0}; c < m.cols; c++) { 
      std::cout << m.data[r][c] << ' ';
    }
    std::cout << '\n';
  }
}

template<typename T>
void mat_add(Mat<T> &dst, const Mat<T> &a, const Mat<T> &b) { 
  assert(dst.rows == a.rows && dst.cols == a.cols); 
  assert(dst.rows == b.rows && dst.cols == b.cols); 
  assert(a.rows == b.rows && a.cols == b.cols);

  for(size_t i {0}; i < dst.rows * dst.cols; i++) { 
    dst[i] = a[i] + b[i];
  }
};

template<typename T>
void mat_sub(Mat<T> &dst, const Mat<T> &a, const Mat<T> &b) { 
  assert(dst.rows == a.rows && dst.cols == a.cols); 
  assert(dst.rows == b.rows && dst.cols == b.cols); 
  assert(a.rows == b.rows && a.cols == b.cols);
  
  for(size_t i {0}; i < dst.rows * dst.cols; i++) { 
    dst[i] = a[i] - b[i];
  }
}; 
template<typename T>
void mat_mul(Mat<T> &dst, const Mat<T> &a, const Mat<T> &b) { 
  assert(dst.rows == a.rows && dst.cols == b.cols); 
  assert(a.cols == b.rows);
  
  for(size_t i {0}; i < dst.rows; i++) { 
    for(size_t j {0}; j < dst.cols; j++) { 
      for(size_t k {0}; k < dst.rows; k++) { 
        dst[i][j] += (a[i][k] + b[k][j]);
      }
    }
  }
}; 

template<typename T>
void mat_scale(Mat<T> &dst, Mat<T> &a, T k) { 
  for(size_t i {0}; i < dst.rows * dst.cols; i++) { 
    dst[i] = a[i] * k; 
  }
}; 

#endif