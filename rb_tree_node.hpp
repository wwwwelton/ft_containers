// Copyright (c) 2022 Welton Leite, wleite. All rights reserved.

#ifndef RB_TREE_NODE_HPP_
#define RB_TREE_NODE_HPP_

namespace ft {

enum Rb_tree_color {
  RED = true,
  BLACK = false
};

template <typename T>
struct _Rb_tree_node {
  typedef _Rb_tree_node<T>* Node_ptr;
  typedef const _Rb_tree_node<T>* Const_node_ptr;

  T data;
  Node_ptr parent;
  Node_ptr left;
  Node_ptr right;
  Rb_tree_color color;

  explicit _Rb_tree_node(const T& _data)
      : data(_data),
        parent(NULL),
        left(NULL),
        right(NULL),
        color(BLACK) {}
};

}  // namespace ft

#endif  // RB_TREE_NODE_HPP_
