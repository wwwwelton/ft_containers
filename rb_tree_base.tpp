// Copyright (c) 2022 Welton Leite, wleite. All rights reserved.

#ifndef RB_TREE_BASE_TPP_
#define RB_TREE_BASE_TPP_

#include "rb_tree.hpp"

namespace ft {

template <RB_TREE_TEMPLATE>
typename RB_TREE_CLASS::Node_ptr RB_TREE_CLASS::search(Key k) {
  return (search_helper(root, k));
}

template <RB_TREE_TEMPLATE>
typename RB_TREE_CLASS::Node_ptr RB_TREE_CLASS::minimum(Node_ptr node) {
  return (Rb_tree_node::minimum(node));
}

template <RB_TREE_TEMPLATE>
typename RB_TREE_CLASS::Node_ptr RB_TREE_CLASS::maximum(Node_ptr node) {
  return (Rb_tree_node::maximum(node));
}

template <RB_TREE_TEMPLATE>
typename RB_TREE_CLASS::Node_ptr RB_TREE_CLASS::successor(Node_ptr x) {
  return (Rb_tree_node::successor(x));
}

template <RB_TREE_TEMPLATE>
typename RB_TREE_CLASS::Node_ptr RB_TREE_CLASS::predecessor(Node_ptr x) {
  return (Rb_tree_node::predecessor(x));
}

template <RB_TREE_TEMPLATE>
void RB_TREE_CLASS::left_rotate(Node_ptr x) {
  Node_ptr y;

  y = x->right;
  x->right = y->left;
  if (y->left != TNULL) {
    y->left->parent = x;
  }

  y->parent = x->parent;
  if (x->parent == TNULL) {
    root = y;
  } else if (x == x->parent->left) {
    x->parent->left = y;
  } else {
    x->parent->right = y;
  }

  y->left = x;
  x->parent = y;
}

template <RB_TREE_TEMPLATE>
void RB_TREE_CLASS::right_rotate(Node_ptr x) {
  Node_ptr y;

  y = x->left;
  x->left = y->right;
  if (y->right != TNULL) {
    y->right->parent = x;
  }

  y->parent = x->parent;
  if (x->parent == TNULL) {
    root = y;
  } else if (x == x->parent->right) {
    x->parent->right = y;
  } else {
    x->parent->left = y;
  }

  y->right = x;
  x->parent = y;
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

#endif  // RB_TREE_BASE_TPP_
