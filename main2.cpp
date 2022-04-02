// Copyright (c) 2022 Welton Leite, wleite. All rights reserved.

#include <iostream>

#if 0
#include <vector>
namespace ft = std;
#else
#include "./vector.hpp"
#endif

int main(void) {
  ft::vector<int> vec1(2);
  ft::vector<int> vec2(vec1);

  size_t count = 4;

  std::cout << "\n===========[ ADDING VALUES ]==========\n";

  std::cout << "\n[ vec1 ]\n";
  for (size_t i = 0; i < count; i++) {
    vec1[i] = static_cast<int>(i);
  }
  for (size_t i = 0; i < count; i++) {
    std::cout << "index[" << i << "]: " << vec1[i] << std::endl;
  }

  std::cout << "\n[ vec2 ]\n";
  for (size_t i = 0; i < count; i++) {
    vec2[i] = static_cast<int>(i);
  }
  for (size_t i = 0; i < count; i++) {
    std::cout << "index[" << i << "]: " << vec2[i] << std::endl;
  }

  std::cout << "\n======================================\n";
  return (0);
}
