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
  _size = 0;
  _comp = comp;
}

template <RB_TREE_TEMPLATE>
RB_TREE_CLASS::Rb_tree(const Rb_tree& src) {
  _alloc = src._alloc;
  TNULL = _alloc.allocate(1);
  _alloc.construct(TNULL, create_node(value_type(), BLACK));
  root = TNULL;
  copy_rb_tree(src.root);
  _size = src._size;
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
    _size = rhs._size;
    _comp = rhs._comp;
  }
  return (*this);
}

template <RB_TREE_TEMPLATE>
RB_TREE_CLASS::~Rb_tree(void) {
  destructor_helper(root);
  _alloc.destroy(TNULL);
  _alloc.deallocate(TNULL, 1);
  _size = 0;
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
  return (_size == 0);
}

template <RB_TREE_TEMPLATE>
typename RB_TREE_CLASS::size_type RB_TREE_CLASS::size(void) const {
  return (_size);
}

template <RB_TREE_TEMPLATE>
typename RB_TREE_CLASS::size_type RB_TREE_CLASS::max_size(void) const {
  return (_alloc.max_size());
}

template <RB_TREE_TEMPLATE>
void RB_TREE_CLASS::swap(Rb_tree& x) {
  allocator_type tmp_alloc = x._alloc;
  Node_ptr tmp_root = x.root;
  Node_ptr tmp_TNULL = x.TNULL;
  size_type tmp_size = x._size;
  key_compare tmp_comp = x._comp;

  x._alloc = _alloc;
  x.root = root;
  x.TNULL = TNULL;
  x._size = _size;
  x._comp = _comp;

  _alloc = tmp_alloc;
  root = tmp_root;
  TNULL = tmp_TNULL;
  _size = tmp_size;
  _comp = tmp_comp;
}

template <RB_TREE_TEMPLATE>
void RB_TREE_CLASS::clear(void) {
  destructor_helper(root);
  root = TNULL;
  _size = 0;
}

// red–black tree functions

template <RB_TREE_TEMPLATE>
typename RB_TREE_CLASS::Node_ptr RB_TREE_CLASS::search(Key k) {
  return (search_helper(root, k));
}

template <RB_TREE_TEMPLATE>
typename RB_TREE_CLASS::Node_ptr RB_TREE_CLASS::minimum(Node_ptr node) const {
  return (Rb_tree_node::minimum(node));
}

template <RB_TREE_TEMPLATE>
typename RB_TREE_CLASS::Node_ptr RB_TREE_CLASS::maximum(Node_ptr node) const {
  return (Rb_tree_node::maximum(node));
}

template <RB_TREE_TEMPLATE>
typename RB_TREE_CLASS::Node_ptr RB_TREE_CLASS::successor(Node_ptr x) const {
  return (Rb_tree_node::successor(x));
}

template <RB_TREE_TEMPLATE>
typename RB_TREE_CLASS::Node_ptr RB_TREE_CLASS::predecessor(Node_ptr x) const {
  return (Rb_tree_node::predecessor(x));
}

template <RB_TREE_TEMPLATE>
void RB_TREE_CLASS::insert(value_type data) {
  Node_ptr z = search(KeyOfValue()(data));
  if (z != TNULL) {
    erase_node_helper(z);
  }
  insert_node_helper(data);
}

template <RB_TREE_TEMPLATE>
void RB_TREE_CLASS::erase(Key key) {
  Node_ptr z = search(key);
  if (z == TNULL) {
    return;
  }
  erase_node_helper(z);
}

template <RB_TREE_TEMPLATE>
typename RB_TREE_CLASS::Node_ptr RB_TREE_CLASS::get_root(void) {
  return (root);
}

}  // namespace ft

#endif  // RB_TREE_TPP_
