// Copyright (c) 2022 Welton Leite, wleite. All rights reserved.

#include <iostream>

#define KO "\033[1;31mKO\033[0m"
#define OK "\033[1;32mOK\033[0m"

#include <stack>

#include "../../stack.hpp"

int main(void) {
  std::cout << "\n===========[ CONSTRUCTORS ]===========\n";
  {
    std::cout << "\n[ CONSTRUCTOR 1 ]\n";
    ft::stack<int> FTsta;
    std::stack<int> ORsta;
    for (size_t i = 0; i < 10; i++) {
      FTsta.push(i);
      ORsta.push(i);
    }
    if (FTsta.top() == ORsta.top())
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }

  std::cout << "\n\n===========[ MEMBER FUNCTIONS ]===========\n";

  {
    std::cout << "\n[ EMPTY ]\n";
    ft::stack<int> FTsta;
    std::stack<int> ORsta;
    if (FTsta.empty() == ORsta.empty())
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }
  {
    ft::stack<int> FTsta;
    std::stack<int> ORsta;
    for (size_t i = 0; i < 10; i++) {
      FTsta.push(i);
      ORsta.push(i);
    }
    for (size_t i = 0; i < 10; i++) {
      FTsta.pop();
      ORsta.pop();
    }
    if (FTsta.size() == ORsta.size() && FTsta.empty() == ORsta.empty())
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }

  {
    std::cout << "\n[ SIZE ]\n";
    ft::stack<int> FTsta;
    std::stack<int> ORsta;
    if (FTsta.size() == ORsta.size())
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }
  {
    ft::stack<int> FTsta;
    std::stack<int> ORsta;
    for (size_t i = 0; i < 10; i++) {
      FTsta.push(i);
      ORsta.push(i);
    }
    if (FTsta.size() == ORsta.size())
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }

  {
    std::cout << "\n[ TOP ]\n";
    ft::stack<int> FTsta;
    std::stack<int> ORsta;
    FTsta.push(42);
    ORsta.push(42);
    if (FTsta.top() == ORsta.top())
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }
  {
    ft::stack<int> FTsta;
    std::stack<int> ORsta;
    for (size_t i = 0; i < 10; i++) {
      FTsta.push(i);
      ORsta.push(i);
    }
    if (FTsta.top() == ORsta.top())
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }

  {
    std::cout << "\n[ PUSH ]\n";
    ft::stack<int> FTsta;
    std::stack<int> ORsta;
    for (size_t i = 0; i < 10; i++) {
      FTsta.push(i);
      ORsta.push(i);
    }
    if (FTsta.top() == ORsta.top())
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }

  {
    std::cout << "\n[ POP ]\n";
    ft::stack<int> FTsta;
    std::stack<int> ORsta;
    for (size_t i = 0; i < 10; i++) {
      FTsta.push(i);
      ORsta.push(i);
    }
    for (size_t i = 0; i < 5; i++) {
      FTsta.pop();
      ORsta.pop();
    }
    if (FTsta.top() == ORsta.top())
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }

  std::cout << "\n\n===========[ RELATIONAL OPERATORS ]===========\n";

  {
    std::cout << "\n[ OPERATOR == ]\n";
    ft::stack<int> FTsta1;
    ft::stack<int> FTsta2;
    for (int i = 0; i < 10; i++) {
      FTsta1.push(i);
      FTsta2.push(i);
    }
    if (FTsta1 == FTsta2)
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }

  {
    std::cout << "\n[ OPERATOR != ]\n";
    ft::stack<int> FTsta1;
    ft::stack<int> FTsta2;
    for (int i = 0; i < 10; i++) {
      FTsta1.push(i);
      FTsta2.push(i + 10);
    }
    if (FTsta1 != FTsta2)
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }

  {
    std::cout << "\n[ OPERATOR < ]\n";
    ft::stack<int> FTsta1;
    ft::stack<int> FTsta2;
    for (int i = 0; i < 9; i++) {
      FTsta1.push(i);
    }
    for (int i = 0; i < 10; i++) {
      FTsta2.push(i);
    }
    if (FTsta1 < FTsta2)
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }

  {
    std::cout << "\n[ OPERATOR <= ]\n";
    ft::stack<int> FTsta1;
    ft::stack<int> FTsta2;
    for (int i = 0; i < 10; i++) {
      FTsta1.push(i);
    }
    for (int i = 0; i < 10; i++) {
      FTsta2.push(i);
    }
    if (FTsta1 <= FTsta2)
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }

  {
    std::cout << "\n[ OPERATOR > ]\n";
    ft::stack<int> FTsta1;
    ft::stack<int> FTsta2;
    for (int i = 0; i < 10; i++) {
      FTsta1.push(i);
    }
    for (int i = 0; i < 9; i++) {
      FTsta2.push(i);
    }
    if (FTsta1 > FTsta2)
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }

  {
    std::cout << "\n[ OPERATOR >= ]\n";
    ft::stack<int> FTsta1;
    ft::stack<int> FTsta2;
    for (int i = 0; i < 10; i++) {
      FTsta1.push(i);
    }
    for (int i = 0; i < 10; i++) {
      FTsta2.push(i);
    }
    if (FTsta1 >= FTsta2)
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }

  std::cout << "\n";

  return (0);
}
