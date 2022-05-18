// Copyright (c) 2022 Welton Leite, wleite. All rights reserved.

#ifndef SET_TPP_
#define SET_TPP_

#include "./set.hpp"

namespace ft {

template <SET_TEMPLATE>
SET_CLASS::set(const key_compare& comp, const allocator_type& alloc)
    : _rb_tree(comp, alloc) {}

template <SET_TEMPLATE>
template <class InputIterator>
SET_CLASS::set(InputIterator first, InputIterator last,
               const key_compare& comp,
               const allocator_type& alloc)
    : _rb_tree(comp, alloc) {
  while (first != last) {
    insert(*first);
    ++first;
  }
}

template <SET_TEMPLATE>
SET_CLASS::set(const set& x)
    : _rb_tree(x._rb_tree) {}

template <SET_TEMPLATE>
SET_CLASS::~set(void) {
  clear();
}

template <SET_TEMPLATE>
SET_CLASS& SET_CLASS::operator=(const set& x) {
  _rb_tree = x._rb_tree;
  return (*this);
}

template <SET_TEMPLATE>
typename SET_CLASS::iterator SET_CLASS::begin(void) {
  return (_rb_tree.begin());
}

template <SET_TEMPLATE>
typename SET_CLASS::const_iterator SET_CLASS::begin(void) const {
  return (_rb_tree.begin());
}

}  // namespace ft

#endif  // SET_TPP_
