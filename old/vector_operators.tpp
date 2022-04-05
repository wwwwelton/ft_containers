// Copyright (c) 2022 Welton Leite, wleite. All rights reserved.

#ifndef VECTOR_OPERATORS_TPP_
#define VECTOR_OPERATORS_TPP_

#include "vector.hpp"

namespace ft {

template <typename T, class Alloc>
vector<T, Alloc>& vector<T, Alloc>::operator=(const vector<T, Alloc>& rhs) {
  std::cout << "Operator  = called." << std::endl;
  if (this != &rhs) {
    this->_alloc = rhs._alloc;
    this->_size = rhs._capacity;
    this->_capacity = rhs._capacity;
    this->_data = this->_alloc.allocate(this->_size);
    for (size_type i = 0; i < rhs._size; i++) {
      this->_alloc.construct(this->_data + i, rhs._data[i]);
    }
  }
  return (*this);
}

template <typename T, class Alloc>
typename vector<T, Alloc>::reference vector<T, Alloc>::operator[](size_type n) {
  return (this->_data[n]);
}

template <typename T, class Alloc>
typename vector<T, Alloc>::const_reference vector<T, Alloc>::operator[](size_type n) const {
  return (this->_data[n]);
}

}  // namespace ft

#endif  // VECTOR_OPERATORS_TPP_
