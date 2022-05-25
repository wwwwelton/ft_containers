// Copyright (c) 2022 Welton Leite, wleite. All rights reserved.

#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <utility>
#include <vector>

#include "./map.hpp"
#include "./set.hpp"
#include "./stack.hpp"
#include "./utility.hpp"
#include "./vector.hpp"

int main(void) {
  std::cout << "\n===========[ VECTOR ]===========\n";
  {
    ft::vector<int> FTvector;
    std::vector<int> STDvector;

    FTvector.push_back(1);
    FTvector.push_back(2);
    FTvector.push_back(3);
    FTvector.push_back(4);

    STDvector.push_back(1);
    STDvector.push_back(2);
    STDvector.push_back(3);
    STDvector.push_back(4);

    for (size_t i = 0; i < 4; i++) {
      std::cout << FTvector[i] << " ";
    }

    std::cout << "\n";

    for (size_t i = 0; i < 4; i++) {
      std::cout << STDvector[i] << " ";
    }
  }

  std::cout << "\n";

  std::cout << "\n===========[ STACK ]===========\n";
  {
    ft::stack<int> FTstack;
    std::stack<int> STDstack;

    FTstack.push(1);
    FTstack.push(2);
    FTstack.push(3);
    FTstack.push(4);

    STDstack.push(1);
    STDstack.push(2);
    STDstack.push(3);
    STDstack.push(4);

    while (!FTstack.empty()) {
      std::cout << FTstack.top() << " ";
      FTstack.pop();
    }

    std::cout << "\n";

    while (!STDstack.empty()) {
      std::cout << STDstack.top() << " ";
      STDstack.pop();
    }
  }

  std::cout << "\n";

  std::cout << "\n===========[ MAP ]===========\n";
  {
    ft::map<char, int> FTmap;
    std::map<char, int> STDmap;

    FTmap.insert(ft::pair<char, int>('a', 1));
    FTmap.insert(ft::pair<char, int>('b', 2));
    FTmap.insert(ft::pair<char, int>('c', 3));
    FTmap.insert(ft::pair<char, int>('d', 4));

    STDmap.insert(std::pair<char, int>('a', 1));
    STDmap.insert(std::pair<char, int>('b', 2));
    STDmap.insert(std::pair<char, int>('c', 3));
    STDmap.insert(std::pair<char, int>('d', 4));

    for (ft::map<char, int>::iterator it = FTmap.begin(); it != FTmap.end(); it++) {
      std::cout << "[" << it->first << "]"
                << "=";
      std::cout << it->second << " ";
    }

    std::cout << "\n";

    for (std::map<char, int>::iterator it = STDmap.begin(); it != STDmap.end(); it++) {
      std::cout << "[" << it->first << "]"
                << "=";
      std::cout << it->second << " ";
    }
  }

  std::cout << "\n";

  std::cout << "\n===========[ SET ]===========\n";
  {
    ft::set<char> FTset;
    std::set<char> STDset;

    FTset.insert('a');
    FTset.insert('b');
    FTset.insert('c');
    FTset.insert('d');

    STDset.insert('a');
    STDset.insert('b');
    STDset.insert('c');
    STDset.insert('d');

    for (ft::set<char>::iterator it = FTset.begin(); it != FTset.end(); it++) {
      std::cout << "[" << *it << "]"
                << "   ";
    }

    std::cout << "\n";

    for (std::set<char>::iterator it = STDset.begin(); it != STDset.end(); it++) {
      std::cout << "[" << *it << "]"
                << "   ";
    }
  }

  std::cout << "\n";

  return (0);
}
