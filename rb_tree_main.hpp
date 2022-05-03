// Copyright (c) 2022 Welton Leite, wleite. All rights reserved.

#ifndef RB_TREE_MAIN_HPP_
#define RB_TREE_MAIN_HPP_

#include <iostream>
#include <string>

#include "./rb_tree.hpp"
#include "./utility.hpp"

// #define KEY std::string
#define KEY int
#define VALUE int
#define TYPE ft::pair<KEY, VALUE>
#define NEWLINE std::cout << "\n";
#define PRINT_EMPTY 0
#define KOV _KeyOfValue

template <typename _Tp>
struct _KeyOfValue {
  KEY operator()(_Tp& x) const {
    return (x.first);
  }
};

#endif  // RB_TREE_MAIN_HPP_
