// Copyright (c) 2022 Welton Leite, wleite. All rights reserved.

#include <climits>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <list>
#include <set>
#include <sstream>

#include "../../set.hpp"
#include "../../utility.hpp"

#define AMOUNT 10000

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
  std::stringstream ss;
  std::string str;

  std::cout << "\n===========[ SET ]===========\n";
  {
    std::cout << "\n[ CONSTRUCTOR 1 ]\n";

    print_time(1, FT);
    for (int i = 0; i < AMOUNT; i++) {
      ft::set<std::string> FTset;
    }
    print_time(2, FT);

    print_time(1, STD);
    for (int i = 0; i < AMOUNT; i++) {
      std::set<std::string> ORset;
    }
    print_time(2, STD);

    print_time(MAX);
  }

  {
    std::cout << "\n[ CONSTRUCTOR 2 ]\n";

    ft::set<std::string> FTset_source;
    std::set<std::string> ORset_source;
    for (int i = 0; i < AMOUNT; i++) {
      ss << i << " ", ss >> str;
      FTset_source.insert(str);
      ORset_source.insert(str);
    }

    print_time(1, FT);
    ft::set<std::string> FTset(FTset_source.begin(), FTset_source.end());
    print_time(2, FT);

    print_time(1, STD);
    std::set<std::string> ORset(ORset_source.begin(), ORset_source.end());
    print_time(2, STD);

    print_time(MAX);
  }

  {
    std::cout << "\n[ CONSTRUCTOR 3 ]\n";

    ft::set<std::string> FTset_source;
    std::set<std::string> ORset_source;
    for (int i = 0; i < AMOUNT; i++) {
      ss << i << " ", ss >> str;
      FTset_source.insert(str);
      ORset_source.insert(str);
    }

    print_time(1, FT);
    ft::set<std::string> FTset(FTset_source);
    print_time(2, FT);

    print_time(1, STD);
    std::set<std::string> ORset(ORset_source);
    print_time(2, STD);

    print_time(MAX);
  }

  {
    std::cout << "\n[ ASSIGNMENT OPERATOR = ]\n";

    ft::set<std::string> FTset_source;
    std::set<std::string> ORset_source;
    for (int i = 0; i < AMOUNT; i++) {
      ss << i << " ", ss >> str;
      FTset_source.insert(str);
      ORset_source.insert(str);
    }

    print_time(1, FT);
    ft::set<std::string> FTset = FTset_source;
    print_time(2, FT);

    print_time(1, STD);
    std::set<std::string> ORset = ORset_source;
    print_time(2, STD);

    print_time(MAX);
  }

  {
    std::cout << "\n[ INSERT ]\n";

    ft::set<std::string> FTset;
    std::set<std::string> ORset;

    print_time(1, FT);
    for (int i = 0; i < AMOUNT; i++) {
      ss << i << " ", ss >> str;
      FTset.insert(str);
    }
    print_time(2, FT);

    print_time(1, STD);
    for (int i = 0; i < AMOUNT; i++) {
      ss << i << " ", ss >> str;
      ORset.insert(str);
    }
    print_time(2, STD);

    print_time(MAX);
  }

  {
    std::cout << "\n[ ERASE ]\n";

    ft::set<std::string> FTset;
    std::set<std::string> ORset;
    for (int i = 0; i < AMOUNT; i++) {
      ss << i << " ", ss >> str;
      FTset.insert(str);
      ORset.insert(str);
    }

    print_time(1, FT);
    for (int i = 0; i < AMOUNT; i++) {
      ss << i << " ", ss >> str;
      FTset.erase(str);
    }
    print_time(2, FT);

    print_time(1, STD);
    for (int i = 0; i < AMOUNT; i++) {
      ss << i << " ", ss >> str;
      ORset.erase(str);
    }
    print_time(2, STD);

    print_time(MAX);
  }

  {
    std::cout << "\n[ CLEAR ]\n";

    ft::set<std::string> FTset;
    std::set<std::string> ORset;
    for (int i = 0; i < AMOUNT; i++) {
      ss << i << " ", ss >> str;
      FTset.insert(str);
      ORset.insert(str);
    }

    print_time(1, FT);
    FTset.clear();
    print_time(2, FT);

    print_time(1, STD);
    ORset.clear();
    print_time(2, STD);

    print_time(MAX);
  }

  {
    std::cout << "\n[ FIND ]\n";

    ft::set<std::string> FTset;
    std::set<std::string> ORset;

    for (int i = 0; i < AMOUNT; i++) {
      ss << i << " ", ss >> str;
      FTset.insert(str);
      ORset.insert(str);
    }

    print_time(1, FT);
    for (int i = 0; i < AMOUNT; i++) {
      ss << AMOUNT << " ", ss >> str;
      FTset.find(str);
    }
    print_time(2, FT);

    print_time(1, STD);
    for (int i = 0; i < AMOUNT; i++) {
      ss << AMOUNT << " ", ss >> str;
      ORset.find(str);
    }
    print_time(2, STD);

    print_time(MAX);
  }

  {
    std::cout << "\n[ LOWER_BOND ]\n";

    ft::set<std::string> FTset;
    std::set<std::string> ORset;

    for (int i = 0; i < AMOUNT; i++) {
      ss << i << " ", ss >> str;
      FTset.insert(str);
      ORset.insert(str);
    }

    print_time(1, FT);
    ss << AMOUNT << " ", ss >> str;
    for (int i = 0; i < AMOUNT; i++) {
      ss << i << " ", ss >> str;
      ft::set<std::string>::iterator FTit = FTset.lower_bound(str);
      (void)FTit;
    }
    print_time(2, FT);

    print_time(1, STD);
    ss << AMOUNT << " ", ss >> str;
    for (int i = 0; i < AMOUNT; i++) {
      ss << i << " ", ss >> str;
      std::set<std::string>::iterator ORit = ORset.lower_bound(str);
      (void)ORit;
    }
    print_time(2, STD);

    print_time(MAX);
  }

  {
    std::cout << "\n[ UPPER_BOUND ]\n";

    ft::set<std::string> FTset;
    std::set<std::string> ORset;

    for (int i = 0; i < AMOUNT; i++) {
      ss << i << " ", ss >> str;
      FTset.insert(str);
      ORset.insert(str);
    }

    print_time(1, FT);
    ss << AMOUNT << " ", ss >> str;
    for (int i = 0; i < AMOUNT; i++) {
      ss << i << " ", ss >> str;
      ft::set<std::string>::iterator FTit = FTset.upper_bound(str);
      (void)FTit;
    }
    print_time(2, FT);

    print_time(1, STD);
    ss << AMOUNT << " ", ss >> str;
    for (int i = 0; i < AMOUNT; i++) {
      ss << i << " ", ss >> str;
      std::set<std::string>::iterator ORit = ORset.upper_bound(str);
      (void)ORit;
    }
    print_time(2, STD);

    print_time(MAX);
  }

  {
    std::cout << "\n[ EQUAL_RANGE ]\n";

    ft::set<std::string> FTset;
    std::set<std::string> ORset;

    for (int i = 0; i < AMOUNT; i++) {
      ss << i << " ", ss >> str;
      FTset.insert(str);
      ORset.insert(str);
    }

    print_time(1, FT);
    ss << AMOUNT << " ", ss >> str;
    for (int i = 0; i < AMOUNT; i++) {
      ss << i << " ", ss >> str;
      FTset.equal_range(str);
    }
    print_time(2, FT);

    print_time(1, STD);
    ss << AMOUNT << " ", ss >> str;
    for (int i = 0; i < AMOUNT; i++) {
      ss << i << " ", ss >> str;
      ORset.equal_range(str);
    }
    print_time(2, STD);

    print_time(MAX);
  }

  print_time(4);
  std::cout << "\n";

  return (0);
}
