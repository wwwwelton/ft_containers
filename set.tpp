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

template <SET_TEMPLATE>
typename SET_CLASS::iterator SET_CLASS::end(void) {
  return (_rb_tree.end());
}

template <SET_TEMPLATE>
typename SET_CLASS::const_iterator SET_CLASS::end(void) const {
  return (_rb_tree.end());
}

template <SET_TEMPLATE>
typename SET_CLASS::reverse_iterator SET_CLASS::rbegin(void) {
  return (_rb_tree.rbegin());
}

template <SET_TEMPLATE>
typename SET_CLASS::const_reverse_iterator SET_CLASS::rbegin(void) const {
  return (_rb_tree.rbegin());
}

template <SET_TEMPLATE>
typename SET_CLASS::reverse_iterator SET_CLASS::rend(void) {
  return (_rb_tree.rend());
}

template <SET_TEMPLATE>
typename SET_CLASS::const_reverse_iterator SET_CLASS::rend(void) const {
  return (_rb_tree.rend());
}

template <SET_TEMPLATE>
bool SET_CLASS::empty(void) const {
  return (_rb_tree.empty());
}

template <SET_TEMPLATE>
typename SET_CLASS::size_type SET_CLASS::size(void) const {
  return (_rb_tree.size());
}

template <SET_TEMPLATE>
typename SET_CLASS::size_type SET_CLASS::max_size(void) const {
  return (_rb_tree.max_size());
}

template <SET_TEMPLATE>
ft::pair<typename SET_CLASS::iterator, bool> SET_CLASS::insert(const value_type& val) {
  iterator x = find(val);
  if (x != end()) {
    return (ft::make_pair(x, false));
  } else {
    _rb_tree.insert(val);
    iterator y = find(val);
    return (ft::make_pair(y, true));
  }
}

template <SET_TEMPLATE>
typename SET_CLASS::iterator SET_CLASS::insert(iterator position, const value_type& val) {
  iterator x = find(val);
  if (x != end()) {
    return (x);
  } else {
    _rb_tree.insert(val, position.base());
    iterator y = find(val);
    return (y);
  }
}

template <SET_TEMPLATE>
template <class InputIterator>
void SET_CLASS::insert(InputIterator first, InputIterator last) {
  while (first != last) {
    insert(*first);
    ++first;
  }
}

template <SET_TEMPLATE>
void SET_CLASS::erase(iterator position) {
  _rb_tree.erase(*position);
}

template <SET_TEMPLATE>
typename SET_CLASS::size_type SET_CLASS::erase(const value_type& val) {
  if (find(val) != end()) {
    _rb_tree.erase(val);
    return (1);
  }
  return (0);
}

template <SET_TEMPLATE>
void SET_CLASS::erase(iterator first, iterator last) {
  iterator it;
  while (first != last) {
    it = first;
    ++first;
    _rb_tree.erase(*it);
  }
}

template <SET_TEMPLATE>
void SET_CLASS::swap(set& x) {
  _rb_tree.swap(x._rb_tree);
}

template <SET_TEMPLATE>
void SET_CLASS::clear(void) {
  _rb_tree.clear();
}

template <SET_TEMPLATE>
typename SET_CLASS::key_compare SET_CLASS::key_comp(void) const {
  return (_rb_tree.key_comp());
}

}  // namespace ft

#endif  // SET_TPP_
