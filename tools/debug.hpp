#ifndef Cuberates
#define Cuberates
#pragma once

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

/**
*
*
*/

namespace Cuberates {
   template<typename T, std::enable_if_t<std::is_arithmetic_v<T>, int> = 0>
   void print(const T& numerical) { std::cerr << numerical; }

   inline void print(const std::string& text) { std::cerr << text; }

   template<typename K, typename V>
   void print(const std::pair<K, V>& value) {
   std::cerr << '(';
   print(value.first);
   std::cerr << ", ";
   print(value.second);
   std::cerr << ')';
   }

   template<typename T, typename Allocator>
   void print(const std::vector<T, Allocator>& values);

   template<typename T, typename Allocator>
   void print(const std::vector<T, Allocator>& values) {
   std::cerr << '[';
   bool first = true;
   for (const auto& value : values) {
      if (!first) std::cerr << ", ";
      print(value);
      first = false;
   }
   std::cerr << ']';
   }

   template<typename T, typename Container>
   void print(std::stack<T, Container> values) {
   std::cerr << '[';
   bool first = true;
   while (!values.empty()) {
      if (!first) std::cerr << ", ";
      print(values.top());
      values.pop();
      first = false;
   }
   std::cerr << ']';
   }

   template<typename T, typename Container, typename Compare>
   void print(std::priority_queue<T, Container, Compare> values) {
   std::cerr << '[';
   bool first = true;
   while (!values.empty()) {
      if (!first) std::cerr << ", ";
      print(values.top());
      values.pop();
      first = false;
   }
   std::cerr << ']';
   }

};

#define debug(v)                       \
   do {                                 \
   std::cerr << #v << " = ";          \
   Cuberates::print(v);               \
   std::cerr << '\n';                 \
   } while (false)

#endif
