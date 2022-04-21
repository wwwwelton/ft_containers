// Copyright (c) 2022 Welton Leite, wleite. All rights reserved.

#include <iostream>

#if STD == 1
#include <utility>
namespace ft = std;
#else
#include "../../utility.hpp"
#endif

template <typename T, typename U>
void print_pair(const ft::pair<T, U>& pair_p) {
  std::cout << "\n";
  std::cout << "first: " << pair_p.first << "\n";
  std::cout << "second: " << pair_p.second << "\n";
}

int main(void) {
  std::cout << "\n===========[ CONSTRUCTORS ]===========\n";
  {
    std::cout << "\n[ CONSTRUCTOR 1 ]\n";
    ft::pair<int, int> FTpair;
    print_pair(FTpair);
  }
  {
    std::cout << "\n[ CONSTRUCTOR 2 ]\n";
    ft::pair<int, int> FTpair(24, 42);
    print_pair(FTpair);
  }
  {
    std::cout << "\n[ CONSTRUCTOR 3 ]\n";
    ft::pair<int, int> FTpair1(24, 42);
    ft::pair<int, int> FTpair(FTpair1);
    print_pair(FTpair);
  }

  std::cout << "\n\n============[ OPERATORS ]============\n";

  {
    std::cout << "\n[ OPERATOR = ]\n";
    ft::pair<int, int> FTpair1(24, 42);
    ft::pair<int, int> FTpair = FTpair1;
    print_pair(FTpair);
  }

  std::cout << "\n\n===========[ NON MEMBER FUNCTIONS ]===========\n";

  {
    std::cout << "\n[ MAKE PAIR ]\n";
    ft::pair<int, char> FTpair = ft::make_pair(42, 'a');
    print_pair(FTpair);
  }

  std::cout << "\n\n===========[ RELATIONAL OPERATORS ]===========\n";

  {
    std::cout << "\n[ OPERATOR == ]\n";
    ft::pair<int, char> FTpair1(42, 'a');
    ft::pair<int, char> FTpair2(42, 'a');
    std::cout << "is equal? " << (FTpair1 == FTpair2) << "\n";
  }

  {
    std::cout << "\n[ OPERATOR != ]\n";
    ft::pair<int, char> FTpair1(24, 'a');
    ft::pair<int, char> FTpair2(42, 'b');
    std::cout << "is different? " << (FTpair1 != FTpair2) << "\n";
  }

  {
    std::cout << "\n[ OPERATOR  < ]\n";
    ft::pair<int, char> FTpair1(24, 'a');
    ft::pair<int, char> FTpair2(42, 'b');
    std::cout << "is minor? " << (FTpair1 < FTpair2) << "\n";
  }

  {
    std::cout << "\n[ OPERATOR <= ]\n";
    ft::pair<int, char> FTpair1(24, 'a');
    ft::pair<int, char> FTpair2(42, 'b');
    std::cout << "is minor or equal? " << (FTpair1 <= FTpair2) << "\n";
  }

  {
    std::cout << "\n[ OPERATOR  > ]\n";
    ft::pair<int, char> FTpair1(42, 'b');
    ft::pair<int, char> FTpair2(24, 'a');
    std::cout << "is bigger? " << (FTpair1 > FTpair2) << "\n";
  }

  {
    std::cout << "\n[ OPERATOR >= ]\n";
    ft::pair<int, char> FTpair1(42, 'a');
    ft::pair<int, char> FTpair2(24, 'a');
    std::cout << "is bigger or equal? " << (FTpair1 >= FTpair2) << "\n";
  }

  std::cout << "\n";

  return (0);
}
