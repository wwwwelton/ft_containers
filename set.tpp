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

}  // namespace ft

#endif  // SET_TPP_
