// Copyright (c) 2022 Welton Leite, wleite. All rights reserved.

#ifndef MAP_TPP_
#define MAP_TPP_

#include "./map.hpp"

namespace ft {

template <MAP_TEMPLATE>
MAP_CLASS::map(const key_compare& comp, const allocator_type& alloc)
    : _rb_tree(comp), _alloc(alloc) {}

template <MAP_TEMPLATE>
template <class InputIterator>
MAP_CLASS::map(InputIterator first, InputIterator last,
               const key_compare& comp,
               const allocator_type& alloc)
    : _rb_tree(comp), _alloc(alloc) {
  while (first != last) {
    insert(*first);
    ++first;
  }
}

template <MAP_TEMPLATE>
MAP_CLASS::map(const map& x)
    : _rb_tree(x._rb_tree), _alloc(x._alloc) {}

template <MAP_TEMPLATE>
MAP_CLASS::~map(void) {
  clear();
}

template <MAP_TEMPLATE>
MAP_CLASS& MAP_CLASS::operator=(const map& x) {
  _rb_tree = x._rb_tree;
  _alloc = x._alloc;
}

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
typename MAP_CLASS::reverse_iterator MAP_CLASS::rbegin(void) {
  return (_rb_tree.rbegin());
}

template <MAP_TEMPLATE>
typename MAP_CLASS::const_reverse_iterator MAP_CLASS::rbegin(void) const {
  return (_rb_tree.rbegin());
}

template <MAP_TEMPLATE>
typename MAP_CLASS::reverse_iterator MAP_CLASS::rend(void) {
  return (_rb_tree.rend());
}

template <MAP_TEMPLATE>
typename MAP_CLASS::const_reverse_iterator MAP_CLASS::rend(void) const {
  return (_rb_tree.rend());
}

template <MAP_TEMPLATE>
bool MAP_CLASS::empty(void) const {
  return (_rb_tree.empty());
}

template <MAP_TEMPLATE>
typename MAP_CLASS::size_type MAP_CLASS::size(void) const {
  return (_rb_tree.size());
}

template <MAP_TEMPLATE>
typename MAP_CLASS::size_type MAP_CLASS::max_size(void) const {
  return (_rb_tree.max_size());
}

template <MAP_TEMPLATE>
typename MAP_CLASS::mapped_type& MAP_CLASS::operator[](const key_type& k) {
  iterator x = insert(begin(), ft::make_pair(k, mapped_type()));
  return (x->second);
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
typename MAP_CLASS::iterator MAP_CLASS::insert(iterator position, const value_type& val) {
  iterator x = find(val.first);
  if (x != end()) {
    return (x);
  } else {
    _rb_tree.insert(val, position.base());
    iterator y = find(val.first);
    return (y);
  }
}

template <MAP_TEMPLATE>
template <class InputIterator>
void MAP_CLASS::insert(InputIterator first, InputIterator last) {
  while (first != last) {
    insert(*first);
    ++first;
  }
}

template <MAP_TEMPLATE>
void MAP_CLASS::erase(iterator position) {
  _rb_tree.erase(position->first);
}

template <MAP_TEMPLATE>
typename MAP_CLASS::size_type MAP_CLASS::erase(const key_type& k) {
  if (find(k) != end()) {
    _rb_tree.erase(k);
    return (0);
  }
  return (1);
}

template <MAP_TEMPLATE>
void MAP_CLASS::erase(iterator first, iterator last) {
  iterator it;
  while (first != last) {
    it = first;
    ++first;
    _rb_tree.erase(it->first);
  }
}

template <MAP_TEMPLATE>
void MAP_CLASS::swap(map& x) {
  allocator_type tmp_alloc = x._alloc;

  x._alloc = _alloc;
  _alloc = tmp_alloc;

  _rb_tree.swap(x._rb_tree);
}

template <MAP_TEMPLATE>
void MAP_CLASS::clear(void) {
  _rb_tree.clear();
}

template <MAP_TEMPLATE>
typename MAP_CLASS::key_compare MAP_CLASS::key_comp(void) const {
  return (_rb_tree.key_comp());
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

template <MAP_TEMPLATE>
typename MAP_CLASS::allocator_type MAP_CLASS::get_allocator(void) const {
  return (_rb_tree.get_allocator());
}

}  // namespace ft

#endif  // MAP_TPP_
