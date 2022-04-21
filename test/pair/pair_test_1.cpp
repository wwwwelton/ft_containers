// Copyright (c) 2022 Welton Leite, wleite. All rights reserved.

#include <iostream>

#define KO "\033[1;31mKO\033[0m"
#define OK "\033[1;32mOK\033[0m"

#include <utility>

#include "../../utility.hpp"

int main(void) {
  std::cout << "\n===========[ CONSTRUCTORS ]===========\n";
  {
    std::cout << "\n[ CONSTRUCTOR 1 ]\n";
    ft::pair<int, int> FTpair;
    std::pair<int, int> ORpair;
    if ((FTpair.first == ORpair.first) && (FTpair.second == ORpair.second))
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }
  {
    std::cout << "\n[ CONSTRUCTOR 2 ]\n";
    ft::pair<int, int> FTpair(24, 42);
    std::pair<int, int> ORpair(24, 42);
    if ((FTpair.first == ORpair.first) && (FTpair.second == ORpair.second))
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }
  {
    std::cout << "\n[ CONSTRUCTOR 3 ]\n";
    ft::pair<int, int> FTpair1(24, 42);
    std::pair<int, int> ORpair1(24, 42);
    ft::pair<int, int> FTpair(FTpair1);
    std::pair<int, int> ORpair(ORpair1);
    if ((FTpair.first == ORpair.first) && (FTpair.second == ORpair.second))
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }

  std::cout << "\n\n============[ OPERATORS ]============\n";

  {
    std::cout << "\n[ OPERATOR = ]\n";
    ft::pair<int, int> FTpair1(24, 42);
    std::pair<int, int> ORpair1(24, 42);
    ft::pair<int, int> FTpair = FTpair1;
    std::pair<int, int> ORpair = ORpair1;
    if ((FTpair.first == ORpair.first) && (FTpair.second == ORpair.second))
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }

  std::cout << "\n\n===========[ NON MEMBER FUNCTIONS ]===========\n";

  {
    std::cout << "\n[ MAKE PAIR ]\n";
    ft::pair<int, char> FTpair = ft::make_pair(42, 'a');
    std::pair<int, int> ORpair = std::make_pair(42, 'a');
    if ((FTpair.first == ORpair.first) && (FTpair.second == ORpair.second))
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }

  std::cout << "\n\n===========[ RELATIONAL OPERATORS ]===========\n";

  {
    std::cout << "\n[ OPERATOR == ]\n";
    ft::pair<int, char> FTpair1(42, 'a');
    ft::pair<int, char> FTpair2(42, 'a');
    if (FTpair1 == FTpair2)
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }

  {
    std::cout << "\n[ OPERATOR != ]\n";
    ft::pair<int, char> FTpair1(24, 'a');
    ft::pair<int, char> FTpair2(42, 'b');
    if (FTpair1 != FTpair2)
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }

  {
    std::cout << "\n[ OPERATOR  < ]\n";
    ft::pair<int, char> FTpair1(24, 'a');
    ft::pair<int, char> FTpair2(42, 'b');
    if (FTpair1 < FTpair2)
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }

  {
    std::cout << "\n[ OPERATOR <= ]\n";
    ft::pair<int, char> FTpair1(24, 'a');
    ft::pair<int, char> FTpair2(42, 'b');
    if (FTpair1 <= FTpair2)
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }

  {
    std::cout << "\n[ OPERATOR  > ]\n";
    ft::pair<int, char> FTpair1(42, 'b');
    ft::pair<int, char> FTpair2(24, 'a');
    if (FTpair1 > FTpair2)
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }

  {
    std::cout << "\n[ OPERATOR >= ]\n";
    ft::pair<int, char> FTpair1(42, 'a');
    ft::pair<int, char> FTpair2(24, 'a');
    if (FTpair1 >= FTpair2)
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }

  std::cout << "\n";

  return (0);
}
