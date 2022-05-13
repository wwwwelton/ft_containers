// Copyright (c) 2022 Welton Leite, wleite. All rights reserved.

#ifndef MAP_TPP_
#define MAP_TPP_

#include "./map.hpp"

namespace ft {

template <MAP_TEMPLATE>
MAP_CLASS::map(const key_compare& comp, const allocator_type& alloc)
    : _rb_tree(), _comp(comp), _alloc(alloc) {}

template <MAP_TEMPLATE>
typename MAP_CLASS::iterator MAP_CLASS::begin(void) {
  return (_rb_tree.begin());
}

template <MAP_TEMPLATE>
typename MAP_CLASS::const_iterator MAP_CLASS::begin(void) const {
  return (_rb_tree.begin());
}

template <MAP_TEMPLATE>
typename MAP_CLASS::iterator MAP_CLASS::end(void) {
  return (_rb_tree.end());
}

template <MAP_TEMPLATE>
typename MAP_CLASS::const_iterator MAP_CLASS::end(void) const {
  return (_rb_tree.end());
}

template <MAP_TEMPLATE>
ft::pair<typename MAP_CLASS::iterator, bool> MAP_CLASS::insert(const value_type& val) {
  iterator x = find(val.first);
  if (x != end()) {
    return (ft::make_pair(x, false));
  } else {
    _rb_tree.insert(val);
    iterator y = find(val.first);
    return (ft::make_pair(y, true));
  }
}

template <MAP_TEMPLATE>
typename MAP_CLASS::iterator MAP_CLASS::find(const key_type& k) {
  iterator it(_rb_tree.search(k));
  return (it);
}

template <MAP_TEMPLATE>
typename MAP_CLASS::const_iterator MAP_CLASS::find(const key_type& k) const {
  const_iterator it(_rb_tree.search(k));
  return (it);
}

}  // namespace ft

#endif  // MAP_TPP_
