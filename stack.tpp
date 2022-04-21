// Copyright (c) 2022 Welton Leite, wleite. All rights reserved.

#ifndef STACK_PP_
#define STACK_PP_

#include "stack.hpp"

namespace ft {

template <class T, class Container>
stack<T, Container>::stack(const Container& c) : _c(c) {}

template <class T, class Container>
stack<T, Container>::~stack(void) {}

template <class T, class Container>
bool stack<T, Container>::empty(void) const {
  return (_c.empty());
}

template <class T, class Container>
typename stack<T, Container>::size_type stack<T, Container>::size(void) const {
  return (_c.size());
}

template <class T, class Container>
typename stack<T, Container>::reference stack<T, Container>::top(void) {
  return (_c.back());
}

template <class T, class Container>
typename stack<T, Container>::const_reference stack<T, Container>::top(void) const {
  return (_c.back());
}

template <class T, class Container>
void stack<T, Container>::push(const value_type& x) {
  _c.push_back(x);
}

template <class T, class Container>
void stack<T, Container>::pop(void) {
  _c.pop_back();
}

}  // namespace ft

#endif  // STACK_PP_
