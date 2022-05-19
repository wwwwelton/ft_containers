// Copyright (c) 2022 Welton Leite, wleite. All rights reserved.

#include <iostream>

#define KO "\033[1;31mKO\033[0m"
#define OK "\033[1;32mOK\033[0m"

#include <ctime>
#include <iomanip>
#include <vector>

#include "../../algorithm.hpp"
#include "../../vector.hpp"

#define K10 10000

int main(void) {
  clock_t t;
  double time_taken;

  std::cout << "\n===========[ VECTOR ]===========\n";
  {
    std::cout << "\n[ INSERT 1 - 10K ]\n";
    ft::vector<int> FTvec;
    std::vector<int> ORvec;

    std::cout << "FT : ";
    t = clock();
    for (int i = 0; i < K10; i++) {
      FTvec.insert(FTvec.begin(), i);
    }
    t = clock() - t;
    time_taken = static_cast<double>(t) / CLOCKS_PER_SEC;
    std::cout << std::setprecision(3) << time_taken << std::endl;

    std::cout << "STD: ";
    t = clock();
    for (int i = 0; i < K10; i++) {
      ORvec.insert(ORvec.begin(), i);
    }
    t = clock() - t;
    time_taken = static_cast<double>(t) / CLOCKS_PER_SEC;
    std::cout << std::setprecision(3) << time_taken;
    std::cout << " | Max: => " << std::setprecision(3)
              << time_taken * 20 << std::endl;
  }
  {
    std::cout << "\n[ PUSH BACK - 10K ]\n";
    ft::vector<int> FTvec;
    std::vector<int> ORvec;

    std::cout << "FT : ";
    t = clock();
    for (int i = 0; i < K10; i++) {
      FTvec.push_back(i);
    }
    t = clock() - t;
    time_taken = static_cast<double>(t) / CLOCKS_PER_SEC;
    std::cout << std::setprecision(3) << time_taken << std::endl;

    std::cout << "STD: ";
    t = clock();
    for (int i = 0; i < K10; i++) {
      ORvec.push_back(i);
    }
    t = clock() - t;
    time_taken = static_cast<double>(t) / CLOCKS_PER_SEC;
    std::cout << std::setprecision(3) << time_taken;
    std::cout << " | Max: => " << std::setprecision(3)
              << time_taken * 20 << std::endl;
  }

  std::cout << "\n";

  return (0);
}
