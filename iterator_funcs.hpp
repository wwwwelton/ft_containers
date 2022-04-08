// Copyright (c) 2022 Welton Leite, wleite. All rights reserved.

#ifndef ITERATOR_FUNCS_HPP_
#define ITERATOR_FUNCS_HPP_

#include "iterator_traits.hpp"

namespace ft {

template <class InputIt>
typename ft::iterator_traits<InputIt>::difference_type distance(InputIt first, InputIt last) {
  typename ft::iterator_traits<InputIt>::difference_type result = 0;
  while (first != last) {
    ++first;
    ++result;
  }
  return (result);
}

template <class InputIt, class Distance>
void advance(InputIt& it, Distance n) {
  while (n > 0) {
    --n;
    ++it;
  }
}

}  // namespace ft

#endif  // ITERATOR_FUNCS_HPP_
