// Copyright (c) 2022 Welton Leite, wleite. All rights reserved.

#ifndef VECTOR_OPERATORS_TPP_
#define VECTOR_OPERATORS_TPP_

#include "vector.hpp"

using namespace ft;

template <typename T, class Alloc>
vector<T, Alloc>& vector<T, Alloc>::operator=(const vector<T, Alloc>& rhs) {
  std::cout << "Operator = called." << std::endl;
  return (*this);
}

#endif  // VECTOR_OPERATORS_TPP_
