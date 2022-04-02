// Copyright (c) 2022 Welton Leite, wleite. All rights reserved.

#ifndef VECTOR_ITERATORS_TPP_
#define VECTOR_ITERATORS_TPP_

#include "vector_iterators.hpp"

namespace ft {

template <typename T, class Category, typename Distance, typename Pointer, typename Reference>
iterator_type::vector_iterator(void) {
  std::cout << "Vector_iterator default constructor called." << std::endl;
  this->_current = NULL;
}

template <typename T, class Category, typename Distance, typename Pointer, typename Reference>
iterator_type::vector_iterator(const pointer elem) {
  std::cout << "Vector_iterator parametric constructor called." << std::endl;
  this->_current = elem;
}

template <typename T, class Category, typename Distance, typename Pointer, typename Reference>
iterator_type::vector_iterator(const iterator& x) {
  std::cout << "Vector_iterator copy constructor called." << std::endl;
  this = *x;
}

template <typename T, class Category, typename Distance, typename Pointer, typename Reference>
iterator_type::~vector_iterator(void) {
  std::cout << "Vector_iterator default destructor called." << std::endl;
}

}  // namespace ft

#endif  // VECTOR_ITERATORS_TPP_
