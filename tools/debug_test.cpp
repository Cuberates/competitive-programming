#include "debug.hpp"

#include <cassert>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

template <typename T>
void expect_print(const T& value, const std::string& expected) {
  std::ostringstream output;
  auto* original_buffer = std::cerr.rdbuf(output.rdbuf());
  Cuberates::print(value);
  std::cerr.rdbuf(original_buffer);
  assert(output.str() == expected);
}

int main() {
  expect_print(42, "42");
  expect_print(3.5, "3.5");
  expect_print(std::string("hello"), "hello");
  expect_print(std::make_pair(1, std::string("one")), "(1, one)");

  const std::vector<int> values{1, 2, 3};
  expect_print(values, "[1, 2, 3]");

  const std::vector<std::pair<int, std::string>> pairs{
    {1, "one"}, {2, "two"}};
  expect_print(pairs, "[(1, one), (2, two)]");

  const std::vector<std::vector<int>> nested{{1, 2}, {3, 4}};
  expect_print(nested, "[[1, 2], [3, 4]]");

  std::stack<int> stack;
  stack.push(1);
  stack.push(2);
  stack.push(3);
  expect_print(stack, "[3, 2, 1]");
  assert(stack.size() == 3);

  std::priority_queue<int> priority_queue;
  priority_queue.push(1);
  priority_queue.push(3);
  priority_queue.push(2);
  expect_print(priority_queue, "[3, 2, 1]");
  assert(priority_queue.size() == 3);

  std::ostringstream output;
  auto* original_buffer = std::cerr.rdbuf(output.rdbuf());
  debug(values);
  std::cerr.rdbuf(original_buffer);
  assert(output.str() == "values = [1, 2, 3]\n");

  std::cout << "All debug tests passed.\n";
}
