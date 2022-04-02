// Copyright (c) 2022 Welton Leite, wleite. All rights reserved.

#ifndef VECTOR_ITERATORS_TPP_
#define VECTOR_ITERATORS_TPP_

#include "vector_iterators.hpp"

namespace ft {

template <vector_iterator_typenames>
vector_iterator_class::vector_iterator(void) {
  std::cout << "Vector_iterator default constructor called." << std::endl;
  this->_current = NULL;
}

template <vector_iterator_typenames>
vector_iterator_class::vector_iterator(const pointer current) {
  std::cout << "Vector_iterator parametric constructor called." << std::endl;
  this->_current = current;
}

template <vector_iterator_typenames>
vector_iterator_class::vector_iterator(const iterator& src) {
  std::cout << "Vector_iterator copy constructor called." << std::endl;
  this = *src;
}

template <vector_iterator_typenames>
vector_iterator_class::~vector_iterator(void) {
  std::cout << "Vector_iterator default destructor called." << std::endl;
}

template <vector_iterator_typenames>
vector_iterator_class& vector_iterator_class::operator=(const iterator& rhs) {
  if (this != &rhs) {
    this->_current = const_cast<pointer>(rhs._current);
  }
  return (*this);
}

template <vector_iterator_typenames>
bool vector_iterator_class::operator>(const iterator& rhs) {
	return(this->_current > rhs._current);
}

template <vector_iterator_typenames>
bool vector_iterator_class::operator<(const iterator& rhs) {
	return(this->_current < rhs._current);
}

template <vector_iterator_typenames>
bool vector_iterator_class::operator>=(const iterator& rhs) {
	return(this->_current >= rhs._current);
}

template <vector_iterator_typenames>
bool vector_iterator_class::operator<=(const iterator& rhs) {
	return(this->_current <= rhs._current);
}

template <vector_iterator_typenames>
bool vector_iterator_class::operator==(const iterator& rhs) {
	return(this->_current == rhs._current);
}

template <vector_iterator_typenames>
bool vector_iterator_class::operator!=(const iterator& rhs) {
	return(this->_current != rhs._current);
}

}  // namespace ft

#endif  // VECTOR_ITERATORS_TPP_
