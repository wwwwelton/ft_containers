// Copyright (c) 2022 Welton Leite, wleite. All rights reserved.

#include <iostream>
#include <vector>

#include "./vector.hpp"

// namespace ft = std;

int main(void) {
  ft::vector<int> vec(2, 42);
  ft::vector<int> vecX(vec);
  std::vector<int> vec2(2);

  std::cout << "Hello Wordl\n";
  return (0);
}
