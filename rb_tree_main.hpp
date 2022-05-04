// Copyright (c) 2022 Welton Leite, wleite. All rights reserved.

#ifndef RB_TREE_MAIN_HPP_
#define RB_TREE_MAIN_HPP_

#include <iostream>
#include <string>

#include "./rb_tree.hpp"
#include "./utility.hpp"

// #define KEY std::string
#define KEY std::string
#define VALUE int
#define TYPE ft::pair<KEY, VALUE>
#define NEWLINE std::cout << "\n";
#define PRINT_EMPTY ""
#define KOV _KeyOfValue
#define VOV _ValueOfValue

template <typename T>
struct _KeyOfValue {
  KEY operator()(T& x) const {
    return (x.first);
  }
};

template <typename T>
struct _ValueOfValue {
  VALUE operator()(T& x) const {
    return (x.second);
  }
};

#endif  // RB_TREE_MAIN_HPP_
