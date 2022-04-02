// Copyright (c) 2022 Welton Leite, wleite. All rights reserved.

#ifndef VECTOR_TPP_
#define VECTOR_TPP_

#include "vector.hpp"

namespace ft {

template <typename T, class Alloc>
vector<T, Alloc>::vector(const allocator_type& alloc) {
  std::cout << "Vector default constructor called." << std::endl;
  this->_alloc = alloc;
  this->_size = 0;
  this->_capacity = 0;
  this->_data = this->_alloc.allocate(this->_size);
}

template <typename T, class Alloc>
vector<T, Alloc>::vector(size_type n,
                         const value_type& val,
                         const allocator_type& alloc) {
  std::cout << "Vector parametric constructor called." << std::endl;
  this->_alloc = alloc;
  this->_size = n;
  this->_capacity = n;
  this->_data = this->_alloc.allocate(this->_size);
  for (size_type i = 0; i < n; i++) {
    this->_alloc.construct(this->_data + i, val);
  }
}

template <typename T, class Alloc>
vector<T, Alloc>::vector(const vector& x) {
  std::cout << "Vector copy constructor called." << std::endl;
  *this = x;
}

template <typename T, class Alloc>
vector<T, Alloc>::~vector(void) {
  std::cout << "Vector default destructor called." << std::endl;
  for (size_type i = 0; i < this->_size; i++) {
    this->_alloc.destroy(this->_data + i);
  }
  this->_alloc.deallocate(this->_data, this->_size);
  this->_size = 0;
  this->_capacity = 0;
}

}  // namespace ft

#endif  // VECTOR_TPP_

// std::cout << "Capacity: " << this->_capacity << std::endl;
// std::cout << "this->_size: " << this->_size << std::endl;
// std::cout << "Max size: " << this->_alloc.max_size() << std::endl;
// std::cout << "this->_data: " << this->_data[1] << std::endl;
