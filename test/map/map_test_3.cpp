// Copyright (c) 2022 Welton Leite, wleite. All rights reserved.

#include <climits>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <sstream>

#include "../../map.hpp"
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

  std::cout << "\n===========[ MAP ]===========\n";
  {
    std::cout << "\n[ CONSTRUCTOR 1 ]\n";

    print_time(1, FT);
    for (int i = 0; i < AMOUNT; i++) {
      ft::map<std::string, int> FTmap;
    }
    print_time(2, FT);

    print_time(1, STD);
    for (int i = 0; i < AMOUNT; i++) {
      std::map<std::string, int> ORmap;
    }
    print_time(2, STD);

    print_time(MAX);
  }

  {
    std::cout << "\n[ CONSTRUCTOR 2 ]\n";

    ft::map<std::string, int> FTmap_source;
    std::map<std::string, int> ORmap_source;
    for (int i = 0; i < AMOUNT; i++) {
      ss << i << " ", ss >> str;
      FTmap_source.insert(ft::make_pair(str, i));
      ORmap_source.insert(std::make_pair(str, i));
    }

    print_time(1, FT);
    ft::map<std::string, int> FTmap(FTmap_source.begin(), FTmap_source.end());
    print_time(2, FT);

    print_time(1, STD);
    std::map<std::string, int> ORmap(ORmap_source.begin(), ORmap_source.end());
    print_time(2, STD);

    print_time(MAX);
  }

  {
    std::cout << "\n[ CONSTRUCTOR 3 ]\n";

    ft::map<std::string, int> FTmap_source;
    std::map<std::string, int> ORmap_source;
    for (int i = 0; i < AMOUNT; i++) {
      ss << i << " ", ss >> str;
      FTmap_source.insert(ft::make_pair(str, i));
      ORmap_source.insert(std::make_pair(str, i));
    }

    print_time(1, FT);
    ft::map<std::string, int> FTmap(FTmap_source);
    print_time(2, FT);

    print_time(1, STD);
    std::map<std::string, int> ORmap(ORmap_source);
    print_time(2, STD);

    print_time(MAX);
  }

  {
    std::cout << "\n[ ASSIGNMENT OPERATOR = ]\n";

    ft::map<std::string, int> FTmap_source;
    std::map<std::string, int> ORmap_source;
    for (int i = 0; i < AMOUNT; i++) {
      ss << i << " ", ss >> str;
      FTmap_source.insert(ft::make_pair(str, i));
      ORmap_source.insert(std::make_pair(str, i));
    }

    print_time(1, FT);
    ft::map<std::string, int> FTmap = FTmap_source;
    print_time(2, FT);

    print_time(1, STD);
    std::map<std::string, int> ORmap = ORmap_source;
    print_time(2, STD);

    print_time(MAX);
  }

  {
    std::cout << "\n[ EMPTY ]\n";

    ft::map<std::string, int> FTmap;
    std::map<std::string, int> ORmap;

    for (int i = 0; i < AMOUNT; i++) {
      ss << i << " ", ss >> str;
      FTmap.insert(ft::make_pair(str, i));
      ORmap.insert(std::make_pair(str, i));
    }

    print_time(1, FT);
    for (int i = 0; i < AMOUNT; i++) {
      FTmap.empty();
    }
    print_time(2, FT);

    print_time(1, STD);
    for (int i = 0; i < AMOUNT; i++) {
      ORmap.empty();
    }
    print_time(2, STD);

    print_time(MAX);
  }

  {
    std::cout << "\n[ SIZE ]\n";

    ft::map<std::string, int> FTmap;
    std::map<std::string, int> ORmap;

    for (int i = 0; i < AMOUNT; i++) {
      ss << i << " ", ss >> str;
      FTmap.insert(ft::make_pair(str, i));
      ORmap.insert(std::make_pair(str, i));
    }

    print_time(1, FT);
    for (int i = 0; i < AMOUNT; i++) {
      FTmap.size();
    }
    print_time(2, FT);

    print_time(1, STD);
    for (int i = 0; i < AMOUNT; i++) {
      ORmap.size();
    }
    print_time(2, STD);

    print_time(MAX);
  }

  {
    std::cout << "\n[ OPERATOR[] ]\n";

    ft::map<std::string, int> FTmap;
    std::map<std::string, int> ORmap;

    for (int i = 0; i < AMOUNT; i++) {
      ss << i << " ", ss >> str;
      FTmap.insert(ft::make_pair(str, i));
      ORmap.insert(std::make_pair(str, i));
    }

    print_time(1, FT);
    for (int i = 0; i < AMOUNT; i++) {
      FTmap["1"];
    }
    print_time(2, FT);

    print_time(1, STD);
    for (int i = 0; i < AMOUNT; i++) {
      ORmap["1"];
    }
    print_time(2, STD);

    print_time(MAX);
  }

  {
    std::cout << "\n[ INSERT 1 ]\n";

    ft::map<std::string, int> FTmap;
    std::map<std::string, int> ORmap;

    print_time(1, FT);
    for (int i = 0; i < AMOUNT; i++) {
      ss << i << " ", ss >> str;
      FTmap.insert(ft::make_pair(str, i));
    }
    print_time(2, FT);

    print_time(1, STD);
    for (int i = 0; i < AMOUNT; i++) {
      ss << i << " ", ss >> str;
      ORmap.insert(std::make_pair(str, i));
    }
    print_time(2, STD);

    print_time(MAX);
  }

  {
    std::cout << "\n[ INSERT 2 ]\n";

    ft::map<std::string, int> FTmap;
    std::map<std::string, int> ORmap;

    print_time(1, FT);
    for (int i = 0; i < AMOUNT; i++) {
      ss << i << " ", ss >> str;
      FTmap.insert(FTmap.begin(), ft::make_pair(str, i));
    }
    print_time(2, FT);

    print_time(1, STD);
    for (int i = 0; i < AMOUNT; i++) {
      ss << i << " ", ss >> str;
      ORmap.insert(ORmap.begin(), std::make_pair(str, i));
    }
    print_time(2, STD);

    print_time(MAX);
  }

  {
    std::cout << "\n[ INSERT 3 ]\n";

    ft::map<std::string, int> FTmap_copy;
    std::map<std::string, int> ORmap_copy;
    ft::map<std::string, int> FTmap;
    std::map<std::string, int> ORmap;

    for (int i = 0; i < AMOUNT; i++) {
      ss << i << " ", ss >> str;
      FTmap_copy.insert(ft::make_pair(str, i));
      ORmap_copy.insert(std::make_pair(str, i));
    }

    print_time(1, FT);
    FTmap.insert(FTmap_copy.begin(), FTmap_copy.end());
    print_time(2, FT);

    print_time(1, STD);
    ORmap.insert(ORmap_copy.begin(), ORmap_copy.end());
    print_time(2, STD);

    print_time(MAX);
  }

  {
    std::cout << "\n[ ERASE POSITION ]\n";

    ft::map<std::string, int> FTmap;
    std::map<std::string, int> ORmap;
    for (int i = 0; i < AMOUNT; i++) {
      ss << i << " ", ss >> str;
      FTmap.insert(ft::make_pair(str, i));
      ORmap.insert(std::make_pair(str, i));
    }

    print_time(1, FT);
    while (!FTmap.empty()) {
      FTmap.erase(FTmap.begin());
    }
    print_time(2, FT);

    print_time(1, STD);
    while (!ORmap.empty()) {
      ORmap.erase(ORmap.begin());
    }
    print_time(2, STD);

    print_time(MAX);
  }

  {
    std::cout << "\n[ ERASE KEY ]\n";

    ft::map<std::string, int> FTmap;
    std::map<std::string, int> ORmap;
    for (int i = 0; i < AMOUNT; i++) {
      ss << i << " ", ss >> str;
      FTmap.insert(ft::make_pair(str, i));
      ORmap.insert(std::make_pair(str, i));
    }

    print_time(1, FT);
    for (int i = 0; i < AMOUNT; i++) {
      ss << i << " ", ss >> str;
      FTmap.erase(str);
    }
    print_time(2, FT);

    print_time(1, STD);
    for (int i = 0; i < AMOUNT; i++) {
      ss << i << " ", ss >> str;
      ORmap.erase(str);
    }
    print_time(2, STD);

    print_time(MAX);
  }

  {
    std::cout << "\n[ ERASE ITERATOR ]\n";

    ft::map<std::string, int> FTmap;
    std::map<std::string, int> ORmap;
    for (int i = 0; i < AMOUNT; i++) {
      ss << i << " ", ss >> str;
      FTmap.insert(ft::make_pair(str, i));
      ORmap.insert(std::make_pair(str, i));
    }

    print_time(1, FT);
    FTmap.erase(++FTmap.begin(), --FTmap.end());
    print_time(2, FT);

    print_time(1, STD);
    ORmap.erase(++ORmap.begin(), --ORmap.end());
    print_time(2, STD);

    print_time(MAX);
  }

  {
    std::cout << "\n[ SWAP ]\n";

    ft::map<std::string, int> FTmap_copy;
    std::map<std::string, int> ORmap_copy;
    ft::map<std::string, int> FTmap;
    std::map<std::string, int> ORmap;

    for (int i = 0; i < AMOUNT; i++) {
      ss << i << " ", ss >> str;
      FTmap_copy.insert(ft::make_pair(str, i));
      ORmap_copy.insert(std::make_pair(str, i));
    }

    print_time(1, FT);
    FTmap.swap(FTmap_copy);
    print_time(2, FT);

    print_time(1, STD);
    ORmap.swap(ORmap_copy);
    print_time(2, STD);

    print_time(MAX);
  }

  {
    std::cout << "\n[ CLEAR ]\n";

    ft::map<std::string, int> FTmap;
    std::map<std::string, int> ORmap;
    for (int i = 0; i < AMOUNT; i++) {
      ss << i << " ", ss >> str;
      FTmap.insert(ft::make_pair(str, i));
      ORmap.insert(std::make_pair(str, i));
    }

    print_time(1, FT);
    FTmap.clear();
    print_time(2, FT);

    print_time(1, STD);
    ORmap.clear();
    print_time(2, STD);

    print_time(MAX);
  }

  {
    std::cout << "\n[ FIND ]\n";

    ft::map<std::string, int> FTmap;
    std::map<std::string, int> ORmap;

    for (int i = 0; i < AMOUNT; i++) {
      ss << i << " ", ss >> str;
      FTmap.insert(ft::make_pair(str, i));
      ORmap.insert(std::make_pair(str, i));
    }

    print_time(1, FT);
    for (int i = 0; i < AMOUNT; i++) {
      ss << AMOUNT << " ", ss >> str;
      FTmap.find(str);
    }
    print_time(2, FT);

    print_time(1, STD);
    for (int i = 0; i < AMOUNT; i++) {
      ss << AMOUNT << " ", ss >> str;
      ORmap.find(str);
    }
    print_time(2, STD);

    print_time(MAX);
  }

  {
    std::cout << "\n[ COUNT ]\n";

    ft::map<std::string, int> FTmap;
    std::map<std::string, int> ORmap;

    for (int i = 0; i < AMOUNT; i++) {
      ss << i << " ", ss >> str;
      FTmap.insert(ft::make_pair(str, i));
      ORmap.insert(std::make_pair(str, i));
    }

    print_time(1, FT);
    for (int i = 0; i < AMOUNT; i++) {
      ss << AMOUNT << " ", ss >> str;
      FTmap.count(str);
    }
    print_time(2, FT);

    print_time(1, STD);
    for (int i = 0; i < AMOUNT; i++) {
      ss << AMOUNT << " ", ss >> str;
      ORmap.count(str);
    }
    print_time(2, STD);

    print_time(MAX);
  }

  {
    std::cout << "\n[ LOWER_BOND ]\n";

    ft::map<std::string, int> FTmap;
    std::map<std::string, int> ORmap;

    for (int i = 0; i < AMOUNT; i++) {
      ss << i << " ", ss >> str;
      FTmap.insert(ft::make_pair(str, i));
      ORmap.insert(std::make_pair(str, i));
    }

    print_time(1, FT);
    ss << AMOUNT << " ", ss >> str;
    for (int i = 0; i < AMOUNT; i++) {
      ss << i << " ", ss >> str;
      ft::map<std::string, int>::iterator FTit = FTmap.lower_bound(str);
      (void)FTit;
    }
    print_time(2, FT);

    print_time(1, STD);
    ss << AMOUNT << " ", ss >> str;
    for (int i = 0; i < AMOUNT; i++) {
      ss << i << " ", ss >> str;
      std::map<std::string, int>::iterator ORit = ORmap.lower_bound(str);
      (void)ORit;
    }
    print_time(2, STD);

    print_time(MAX);
  }

  {
    std::cout << "\n[ UPPER_BOUND ]\n";

    ft::map<std::string, int> FTmap;
    std::map<std::string, int> ORmap;

    for (int i = 0; i < AMOUNT; i++) {
      ss << i << " ", ss >> str;
      FTmap.insert(ft::make_pair(str, i));
      ORmap.insert(std::make_pair(str, i));
    }

    print_time(1, FT);
    ss << AMOUNT << " ", ss >> str;
    for (int i = 0; i < AMOUNT; i++) {
      ss << i << " ", ss >> str;
      ft::map<std::string, int>::iterator FTit = FTmap.upper_bound(str);
      (void)FTit;
    }
    print_time(2, FT);

    print_time(1, STD);
    ss << AMOUNT << " ", ss >> str;
    for (int i = 0; i < AMOUNT; i++) {
      ss << i << " ", ss >> str;
      std::map<std::string, int>::iterator ORit = ORmap.upper_bound(str);
      (void)ORit;
    }
    print_time(2, STD);

    print_time(MAX);
  }

  {
    std::cout << "\n[ EQUAL_RANGE ]\n";

    ft::map<std::string, int> FTmap;
    std::map<std::string, int> ORmap;

    for (int i = 0; i < AMOUNT; i++) {
      ss << i << " ", ss >> str;
      FTmap.insert(ft::make_pair(str, i));
      ORmap.insert(std::make_pair(str, i));
    }

    print_time(1, FT);
    ss << AMOUNT << " ", ss >> str;
    for (int i = 0; i < AMOUNT; i++) {
      ss << i << " ", ss >> str;
      FTmap.equal_range(str);
    }
    print_time(2, FT);

    print_time(1, STD);
    ss << AMOUNT << " ", ss >> str;
    for (int i = 0; i < AMOUNT; i++) {
      ss << i << " ", ss >> str;
      ORmap.equal_range(str);
    }
    print_time(2, STD);

    print_time(MAX);
  }

  print_time(4);
  std::cout << "\n";

  return (0);
}
