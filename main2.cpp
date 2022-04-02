// Copyright (c) 2022 Welton Leite, wleite. All rights reserved.

#include <iostream>
#include <vector>

#include "./vector.hpp"

// namespace ft = std;

int main(void) {
  ft::vector<int> FTvec(2);
  ft::vector<int> FTvecX(FTvec);
  std::vector<int> ORvec(2);
  std::vector<int> ORvecX(ORvec);

  size_t count = 4;

  std::cout << "\n===========[ ADDING VALUES ]==========\n";

  std::cout << "\n[ FTvec ]\n";
  for (size_t i = 0; i < count; i++) {
    FTvec[i] = static_cast<int>(i);
  }
  for (size_t i = 0; i < count; i++) {
    std::cout << "index[" << i << "]: " << FTvec[i] << std::endl;
  }

  std::cout << "\n[ FTvecX ]\n";
  for (size_t i = 0; i < count; i++) {
    FTvecX[i] = static_cast<int>(i);
  }
  for (size_t i = 0; i < count; i++) {
    std::cout << "index[" << i << "]: " << FTvecX[i] << std::endl;
  }

  std::cout << "\n[ ORvec ]\n";
  for (size_t i = 0; i < count; i++) {
    ORvec[i] = static_cast<int>(i);
  }
  for (size_t i = 0; i < count; i++) {
    std::cout << "index[" << i << "]: " << ORvec[i] << std::endl;
  }

  std::cout << "\n[ ORvecX ]\n";
  for (size_t i = 0; i < count; i++) {
    ORvecX[i] = static_cast<int>(i);
  }
  for (size_t i = 0; i < count; i++) {
    std::cout << "index[" << i << "]: " << ORvecX[i] << std::endl;
  }

  std::cout << "\n======================================\n";
  return (0);
}
