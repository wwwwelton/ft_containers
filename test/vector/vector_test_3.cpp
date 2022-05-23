// Copyright (c) 2022 Welton Leite, wleite. All rights reserved.

#include <climits>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <list>
#include <vector>

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
    std::cout << "\n[ RESIZE ]\n";
    ft::vector<int> FTvec;
    std::vector<int> ORvec;

    for (int i = 0; i < AMOUNT; i++) {
      FTvec.insert(FTvec.begin(), i);
    }
    print_time(1, FT);
    FTvec.resize(AMOUNT * 2);
    print_time(2, FT);

    for (int i = 0; i < AMOUNT; i++) {
      ORvec.insert(ORvec.begin(), i);
    }
    print_time(1, STD);
    ORvec.resize(AMOUNT * 2);
    print_time(2, STD);

    print_time(MAX);
  }

  {
    std::cout << "\n[ RESERVE ]\n";
    ft::vector<int> FTvec;
    std::vector<int> ORvec;

    for (int i = 0; i < AMOUNT; i++) {
      FTvec.insert(FTvec.begin(), i);
    }
    print_time(1, FT);
    FTvec.reserve(AMOUNT * 2);
    print_time(2, FT);

    for (int i = 0; i < AMOUNT; i++) {
      ORvec.insert(ORvec.begin(), i);
    }
    print_time(1, STD);
    ORvec.reserve(AMOUNT * 2);
    print_time(2, STD);

    print_time(MAX);
  }

  {
    std::cout << "\n[ ASSIGN ]\n";
    ft::vector<int> FTvec;
    std::vector<int> ORvec;

    std::list<int> ORlist;
    for (int i = 0; i < AMOUNT; i++) {
      ORlist.push_back(i);
    }

    print_time(1, FT);
    FTvec.assign(ORlist.begin(), ORlist.end());
    print_time(2, FT);

    print_time(1, STD);
    ORvec.assign(ORlist.begin(), ORlist.end());
    print_time(2, STD);

    print_time(MAX);
  }

  {
    std::cout << "\n[ PUSH_BACK ]\n";
    ft::vector<int> FTvec;
    std::vector<int> ORvec;

    print_time(1, FT);
    for (int i = 0; i < AMOUNT; i++) {
      FTvec.push_back(i);
    }
    print_time(2, FT);

    print_time(1, STD);
    for (int i = 0; i < AMOUNT; i++) {
      ORvec.push_back(i);
    }
    print_time(2, STD);

    print_time(MAX);
  }

  {
    std::cout << "\n[ INSERT 1 ]\n";
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

  {
    std::cout << "\n[ INSERT 2 ]\n";
    ft::vector<int> FTvec;
    std::vector<int> ORvec;

    print_time(1, FT);
    FTvec.insert(FTvec.begin(), AMOUNT, 1);
    print_time(2, FT);

    print_time(1, STD);
    ORvec.insert(ORvec.begin(), AMOUNT, 1);
    print_time(2, STD);

    print_time(MAX);
  }

  {
    std::cout << "\n[ INSERT 3 ]\n";
    ft::vector<int> FTvec;
    std::vector<int> ORvec;
    ft::vector<int> FTvec_copy;
    std::vector<int> ORvec_copy;

    for (int i = 0; i < AMOUNT; i++) {
      FTvec_copy.push_back(i);
      ORvec_copy.push_back(i);
    }

    print_time(1, FT);
    FTvec.insert(FTvec.begin(), FTvec_copy.begin(), FTvec_copy.end());
    print_time(2, FT);

    print_time(1, STD);
    ORvec.insert(ORvec.begin(), ORvec_copy.begin(), ORvec_copy.end());
    print_time(2, STD);

    print_time(MAX);
  }

  {
    std::cout << "\n[ ERASE POSITION ]\n";
    ft::vector<int> FTvec;
    std::vector<int> ORvec;

    for (int i = 0; i < AMOUNT; i++) {
      FTvec.push_back(i);
      ORvec.push_back(i);
    }

    print_time(1, FT);
    while (!FTvec.empty()) {
      FTvec.erase(FTvec.begin());
    }
    print_time(2, FT);

    print_time(1, STD);
    while (!ORvec.empty()) {
      ORvec.erase(ORvec.begin());
    }
    print_time(2, STD);

    print_time(MAX);
  }

  {
    std::cout << "\n[ ERASE ITERATOR ]\n";
    ft::vector<int> FTvec;
    std::vector<int> ORvec;

    for (int i = 0; i < AMOUNT * 10; i++) {
      FTvec.push_back(i);
      ORvec.push_back(i);
    }

    print_time(1, FT);
    FTvec.erase(FTvec.begin() + 1, FTvec.end() - 1);
    print_time(2, FT);

    print_time(1, STD);
    ORvec.erase(ORvec.begin() + 1, ORvec.end() - 1);
    print_time(2, STD);

    print_time(MAX);
  }

  print_time(4);
  std::cout << "\n";

  return (0);
}
