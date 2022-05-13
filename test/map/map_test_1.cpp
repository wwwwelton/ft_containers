// Copyright (c) 2022 Welton Leite, wleite. All rights reserved.

#include <iostream>

#define KO "\033[1;31mKO\033[0m"
#define OK "\033[1;32mOK\033[0m"

#define NEWLINE std::cout << "\n";

#define KEY std::string
#define VALUE int
#define TYPE ft::pair<KEY, VALUE>

#define _MAP_T KEY, TYPE

#include <map>

#include "../../map.hpp"

int main(void) {
  std::cout << "\n===========[ CONSTRUCTORS ]===========\n";
  {
    std::cout << "\n[ CONSTRUCTOR VOID ]\n";
    ft::map<_MAP_T> FTmap;

    ft::map<_MAP_T>::iterator FTit = FTmap.begin();
    ft::map<_MAP_T>::iterator FTite = FTmap.end();

    if ((FTit->first == "") && (FTite->first == ""))
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }

  NEWLINE

  return (0);
}
