// Copyright (c) 2022 Welton Leite, wleite. All rights reserved.

#ifndef VECTOR_TPP_
#define VECTOR_TPP_

#include "vector.hpp"

using namespace ft;

template <typename T, class Alloc>
vector<T, Alloc>::vector(const allocator_type& alloc) {
  std::cout << "Constructor 1 called." << std::endl;
  _alloc = alloc;
  _size = 0;
  _capacity = 0;
  _data = _alloc.allocate(_size);
}

template <typename T, class Alloc>
vector<T, Alloc>::vector(size_type n,
                         const value_type& val,
                         const allocator_type& alloc) {
  std::cout << "Constructor 2 called." << std::endl;
  _alloc = alloc;
  _size = n;
  _capacity = n;
  _data = _alloc.allocate(_size);
  for (size_type i = 0; i < n; i++) {
    _alloc.construct(_data + i, val);
  }
  std::cout << "Capacity: " << _capacity << std::endl;
  std::cout << "_size: " << _size << std::endl;
  std::cout << "_data: " << _data[1] << std::endl;
  return;
}

template <typename T, class Alloc>
vector<T, Alloc>::vector(const vector& x) {
  std::cout << "Constructor 3 called." << std::endl;
  return;
}

template <typename T, class Alloc>
vector<T, Alloc>::~vector(void) {
  return;
}

#endif  // VECTOR_TPP_
