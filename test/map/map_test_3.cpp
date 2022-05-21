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
    std::cout << "\n[ CONSTRUCTOR ]\n";

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

  print_time(4);
  std::cout << "\n";

  return (0);
}
