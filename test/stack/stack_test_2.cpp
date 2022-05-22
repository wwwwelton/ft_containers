// Copyright (c) 2022 Welton Leite, wleite. All rights reserved.

#include <iostream>

#if STD == 1
#include <stack>
namespace ft = std;
#else
#include "../../stack.hpp"
#endif

#include <deque>
#include <list>
#include <vector>

template <typename T>
void print_stack(T& stack) {
  for (size_t i = 0; i < stack.size(); i++) {
    std::cout << stack.top() << " ";
    stack.pop();
  }
  std::cout << "\n";
  std::cout << "size: " << stack.size() << "\n";
}

template <typename T>
void fill_stack(T& stack, int size) {
  for (int i = 0; i < size; i++) {
    stack.push(i);
  }
}

int main(void) {
  std::cout << "\n===========[ CONSTRUCTORS ]===========\n";
  {
    std::cout << "\n[ CONSTRUCTOR 1 ]\n";
    ft::stack<int> FTsta;
    fill_stack(FTsta, 10);
    print_stack(FTsta);
  }
  {
    std::cout << "\n[ CONSTRUCTOR 2 - DEQUE ]\n";
    ft::stack<int, std::deque<int> > FTsta;
    fill_stack(FTsta, 10);
    print_stack(FTsta);
  }
  {
    std::cout << "\n[ CONSTRUCTOR 2 - LIST ]\n";
    ft::stack<int, std::list<int> > FTsta;
    fill_stack(FTsta, 10);
    print_stack(FTsta);
  }
  {
    std::cout << "\n[ CONSTRUCTOR 3 - VECTOR ]\n";
    ft::stack<int, std::list<int> > FTsta;
    fill_stack(FTsta, 10);
    print_stack(FTsta);
  }

  std::cout << "\n\n===========[ MEMBER FUNCTIONS ]===========\n";

  {
    std::cout << "\n[ EMPTY ]\n";
    ft::stack<int> FTsta;
    std::cout << "is empty? " << FTsta.empty() << "\n";
  }
  {
    ft::stack<int> FTsta;
    for (size_t i = 0; i < 10; i++) {
      FTsta.push(i);
    }
    for (size_t i = 0; i < 10; i++) {
      FTsta.pop();
    }
    std::cout << "is empty? " << FTsta.empty() << "\n";
  }

  {
    std::cout << "\n[ SIZE ]\n";
    ft::stack<int> FTsta;
    fill_stack(FTsta, 5);
    print_stack(FTsta);
  }
  {
    ft::stack<int> FTsta;
    fill_stack(FTsta, 10);
    print_stack(FTsta);
  }

  {
    std::cout << "\n[ TOP ]\n";
    ft::stack<int> FTsta;
    FTsta.push(42);
    std::cout << "top? " << FTsta.top() << "\n";
  }
  {
    ft::stack<int> FTsta;
    fill_stack(FTsta, 10);
    std::cout << "top? " << FTsta.top() << "\n";
  }

  {
    std::cout << "\n[ PUSH ]\n";
    ft::stack<int> FTsta;
    for (size_t i = 0; i < 10; i++) {
      FTsta.push(42);
    }
    print_stack(FTsta);
  }

  {
    std::cout << "\n[ POP ]\n";
    ft::stack<int> FTsta;
    for (size_t i = 0; i < 10; i++) {
      FTsta.push(i);
    }
    for (size_t i = 0; i < 5; i++) {
      FTsta.pop();
    }
    print_stack(FTsta);
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
    std::cout << "is equal? " << (FTsta1 == FTsta2) << "\n";
  }

  {
    std::cout << "\n[ OPERATOR != ]\n";
    ft::stack<int> FTsta1;
    ft::stack<int> FTsta2;
    for (int i = 0; i < 10; i++) {
      FTsta1.push(i);
      FTsta2.push(i + 10);
    }
    std::cout << "is different? " << (FTsta1 != FTsta2) << "\n";
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
    std::cout << "is minor? " << (FTsta1 < FTsta2) << "\n";
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
    std::cout << "is minor or equal? " << (FTsta1 <= FTsta2) << "\n";
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
    std::cout << "is bigger? " << (FTsta1 > FTsta2) << "\n";
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
    std::cout << "is bigger or equal? " << (FTsta1 >= FTsta2) << "\n";
  }

  std::cout << "\n";

  return (0);
}
