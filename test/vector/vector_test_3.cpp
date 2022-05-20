// Copyright (c) 2022 Welton Leite, wleite. All rights reserved.

#include <iostream>

#define KO "\033[1;31mKO\033[0m"
#define OK "\033[1;32mOK\033[0m"

#include <ctime>
#include <iomanip>
#include <vector>

#include "../../algorithm.hpp"
#include "../../vector.hpp"

#define K10 100000

void print_time(int option) {
  static clock_t t = 0;
  static double time_taken = 0;

  if (option == 1) {
    t = clock();
  }
  if (option == 2) {
    t = clock() - t;
    time_taken = static_cast<double>(t) / CLOCKS_PER_SEC;
    std::cout << std::setprecision(3) << time_taken << std::endl;
  }
  if (option == 3) {
    std::cout << std::setprecision(3) << (time_taken * 20) << std::endl;
  }
}

int main(void) {
  std::cout << "\n===========[ VECTOR ]===========\n";
  {
    std::cout << "\n[ INSERT ]\n";
    ft::vector<int> FTvec;
    std::vector<int> ORvec;

    std::cout << "FT : ";
    print_time(1);
    for (int i = 0; i < K10; i++) {
      FTvec.insert(FTvec.begin(), i);
    }
    print_time(2);

    std::cout << "STD: ";
    print_time(1);
    for (int i = 0; i < K10; i++) {
      ORvec.insert(ORvec.begin(), i);
    }
    print_time(2);

    std::cout << "MAX: ";
    print_time(3);
  }

  std::cout << "\n";

  return (0);
}
