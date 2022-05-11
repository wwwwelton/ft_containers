// Copyright (c) 2022 Welton Leite, wleite. All rights reserved.

#ifndef RB_TREE_TPP_
#define RB_TREE_TPP_

#include "rb_tree.hpp"

namespace ft {

template <RB_TREE_TEMPLATE>
RB_TREE_CLASS::Rb_tree(const key_compare& comp,
                       const allocator_type& alloc) {
  _alloc = alloc;
  TNULL = _alloc.allocate(1);
  _alloc.construct(TNULL, create_node(value_type(), BLACK));
  root = TNULL;
  _comp = comp;
}

template <RB_TREE_TEMPLATE>
RB_TREE_CLASS::Rb_tree(const Rb_tree& src) {
  _alloc = src._alloc;
  TNULL = _alloc.allocate(1);
  _alloc.construct(TNULL, create_node(value_type(), BLACK));
  root = TNULL;
  copy_rb_tree(src.root);
  _comp = src._comp;
}

template <RB_TREE_TEMPLATE>
RB_TREE_CLASS& RB_TREE_CLASS::operator=(const Rb_tree& rhs) {
  if (this != &rhs) {
    this->~Rb_tree();
    _alloc = rhs._alloc;
    TNULL = _alloc.allocate(1);
    _alloc.construct(TNULL, create_node(value_type(), BLACK));
    root = TNULL;
    copy_rb_tree(rhs.root);
    _comp = rhs._comp;
  }
  return (*this);
}

template <RB_TREE_TEMPLATE>
RB_TREE_CLASS::~Rb_tree(void) {
  destructor_helper(root);
  _alloc.destroy(TNULL);
  _alloc.deallocate(TNULL, 1);
}

template <RB_TREE_TEMPLATE>
typename RB_TREE_CLASS::iterator RB_TREE_CLASS::begin(void) {
  return (iterator(minimum(root)));
}

template <RB_TREE_TEMPLATE>
typename RB_TREE_CLASS::const_iterator RB_TREE_CLASS::begin(void) const {
  return (const_iterator(minimum(root)));
}

template <RB_TREE_TEMPLATE>
typename RB_TREE_CLASS::iterator RB_TREE_CLASS::end(void) {
  return (iterator(TNULL));
}

template <RB_TREE_TEMPLATE>
typename RB_TREE_CLASS::const_iterator RB_TREE_CLASS::end(void) const {
  return (const_iterator(TNULL));
}

template <RB_TREE_TEMPLATE>
typename RB_TREE_CLASS::reverse_iterator RB_TREE_CLASS::rbegin(void) {
  return (reverse_iterator(end()));
}

template <RB_TREE_TEMPLATE>
typename RB_TREE_CLASS::const_reverse_iterator RB_TREE_CLASS::rbegin(void) const {
  return (const_reverse_iterator(end()));
}

template <RB_TREE_TEMPLATE>
typename RB_TREE_CLASS::reverse_iterator RB_TREE_CLASS::rend(void) {
  return (reverse_iterator(begin()));
}

template <RB_TREE_TEMPLATE>
typename RB_TREE_CLASS::const_reverse_iterator RB_TREE_CLASS::rend(void) const {
  return (const_reverse_iterator(begin()));
}

template <RB_TREE_TEMPLATE>
bool RB_TREE_CLASS::empty(void) const {
  return (root == TNULL);
}

}  // namespace ft

#endif  // RB_TREE_TPP_
