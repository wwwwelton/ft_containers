// Copyright (c) 2022 Welton Leite, wleite. All rights reserved.

#ifndef TEST_RB_TREE_RB_TREE_MAIN_HPP_
#define TEST_RB_TREE_RB_TREE_MAIN_HPP_

#include <functional>
#include <iostream>
#include <string>

#include "../../rb_tree.hpp"
#include "../../rb_tree_iterator.hpp"
#include "../../utility.hpp"

// #define KEY std::string
#define KEY std::string
#define VALUE int
#define TYPE ft::pair<KEY, VALUE>
#define COMPARE std::less<KEY>
#define NEWLINE std::cout << "\n";
#define PRINT_EMPTY ""
#define KOV _KeyOfValue
#define VOV _ValueOfValue

template <typename T>
struct _KeyOfValue {
  KEY operator()(const T& x) const {
    return (x.first);
  }
};

template <typename T>
struct _ValueOfValue {
  VALUE operator()(const T& x) const {
    return (x.second);
  }
};

#endif  // TEST_RB_TREE_RB_TREE_MAIN_HPP_
