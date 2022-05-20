// Copyright (c) 2022 Welton Leite, wleite. All rights reserved.

#include <iostream>

#define KO "\033[1;31mKO\033[0m"
#define OK "\033[1;32mOK\033[0m"

#include <climits>
#include <ctime>
#include <iomanip>
#include <vector>

#include "../../algorithm.hpp"
#include "../../vector.hpp"

#define AMOUNT 100000

#define FT 42
#define STD 24
#define MAX 22

void print_time(int option = -1, int NAMESPACE = 0) {
  static clock_t t = 0;
  static double time_taken = 0;
  static double total_time_ft = 0;
  static double total_time_std = 0;

  if (option == 1) {
    if (NAMESPACE == FT) {
      std::cout << "FT : ";
    }
    if (NAMESPACE == STD) {
      std::cout << "STD: ";
    }
    t = clock();
  }
  if (option == 2) {
    t = clock() - t;
    time_taken = static_cast<double>(t) / CLOCKS_PER_SEC;
    std::cout << std::setprecision(3) << time_taken << std::endl;
    if (NAMESPACE == FT) {
      total_time_ft += time_taken;
    }
    if (NAMESPACE == STD) {
      total_time_std += time_taken;
    }
  }
  if (option == MAX) {
    std::cout << "MAX: ";
    std::cout << std::setprecision(3) << (time_taken * 20) << std::endl;
  }
  if (option == 4) {
    std::cout << "\n[ TOTAL TIME ]\n";

    std::cout << "FT : ";
    std::cout << std::setprecision(3) << total_time_ft << std::endl;

    std::cout << "STD: ";
    std::cout << std::setprecision(3) << total_time_std << std::endl;

    std::cout << "MAX: ";
    std::cout << std::setprecision(3) << (total_time_std * 20) << std::endl;
  }
}

int main(void) {
  std::cout << "\n===========[ VECTOR ]===========\n";
  {
    std::cout << "\n[ CONSTRUCTOR ]\n";

    print_time(1, FT);
    ft::vector<int> FTvec(AMOUNT, INT_MAX);
    print_time(2, FT);

    print_time(1, STD);
    ft::vector<int> ORvec(AMOUNT, INT_MAX);
    print_time(2, STD);

    print_time(MAX);
  }

  {
    std::cout << "\n[ INSERT ]\n";
    ft::vector<int> FTvec;
    std::vector<int> ORvec;

    print_time(1, FT);
    for (int i = 0; i < AMOUNT; i++) {
      FTvec.insert(FTvec.begin(), i);
    }
    print_time(2, FT);

    print_time(1, STD);
    for (int i = 0; i < AMOUNT; i++) {
      ORvec.insert(ORvec.begin(), i);
    }
    print_time(2, STD);

    print_time(MAX);
  }

  print_time(4);
  std::cout << "\n";

  return (0);
}
