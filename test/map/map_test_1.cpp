// Copyright (c) 2022 Welton Leite, wleite. All rights reserved.

#include <iostream>

template <typename T>
void print(const T& x) {
  std::cout << std::endl;
  std::cout << "===============" << std::endl;
  std::cout << x << std::endl;
  std::cout << "===============" << std::endl;
}

template <typename T>
void print_map(T& map) {
  for (typename T::iterator it = map.begin(); it != map.end(); it++) {
    std::cout << "[" << it->first << "]"
              << "(" << it->second << ")"
              << " ";
  }
  std::cout << std::endl;
}

// NEWLINE
// print_map<FT_PRINT>(FTmap);
// print_map<OR_PRINT>(ORmap);

#define KO "\033[1;31mKO\033[0m"
#define OK "\033[1;32mOK\033[0m"

#define NEWLINE std::cout << "\n";

#define KEY std::string
#define VALUE int
#define FT_TYPE ft::pair<KEY, VALUE>
#define OR_TYPE std::pair<KEY, VALUE>

#define MAP_T KEY, VALUE

#define FT_PRINT ft::map<MAP_T>
#define OR_PRINT std::map<MAP_T>

#include <map>

#include "../../map.hpp"

int main(void) {
  std::cout << "\n===========[ CONSTRUCTORS ]===========\n";
  {
    std::cout << "\n[ CONSTRUCTOR VOID ]\n";
    ft::map<MAP_T> FTmap;

    ft::map<MAP_T>::iterator FTit = FTmap.begin();
    ft::map<MAP_T>::iterator FTite = FTmap.end();

    if ((FTit->first == "") && (FTite->first == "") && (FTit == FTite))
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }

  std::cout << "\n\n===========[ MAP MODIFIERS ]===========\n";
  {
    std::cout << "\n[ INSERT VAL ]\n";
    ft::map<MAP_T> FTmap;
    std::map<MAP_T> ORmap;

    ft::pair<ft::map<MAP_T>::iterator, bool> FTit;
    std::pair<std::map<MAP_T>::iterator, bool> ORit;

    FTit = FTmap.insert(FT_TYPE("a", 8));
    ORit = ORmap.insert(OR_TYPE("a", 8));

    if ((FTit.first->first == ORit.first->first) &&
        (FTit.first->second == ORit.first->second) &&
        (FTit.second == ORit.second))
      std::cout << OK " ";
    else
      std::cout << KO " ";

    FTit = FTmap.insert(FT_TYPE("a", 8));
    ORit = ORmap.insert(OR_TYPE("a", 8));

    if ((FTit.first->first == ORit.first->first) &&
        (FTit.first->second == ORit.first->second) &&
        (FTit.second == ORit.second))
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }
  {
    std::cout << "\n[ INSERT POS ]\n";
    ft::map<MAP_T> FTmap;
    std::map<MAP_T> ORmap;

    ft::map<MAP_T>::iterator FTit;
    std::map<MAP_T>::iterator ORit;

    FTit = FTmap.insert(FTmap.begin(), FT_TYPE("a", 8));
    ORit = ORmap.insert(ORmap.begin(), OR_TYPE("a", 8));

    if ((FTit->first == ORit->first) && (FTit->second == ORit->second))
      std::cout << OK " ";
    else
      std::cout << KO " ";

    FTit = FTmap.insert(FTmap.end(), FT_TYPE("b", 18));
    ORit = ORmap.insert(ORmap.end(), OR_TYPE("b", 18));

    if ((FTit->first == ORit->first) && (FTit->second == ORit->second))
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }

  NEWLINE

  return (0);
}
