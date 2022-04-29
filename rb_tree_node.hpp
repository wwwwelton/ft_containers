// Copyright (c) 2022 Welton Leite, wleite. All rights reserved.

#ifndef RB_TREE_NODE_HPP_
#define RB_TREE_NODE_HPP_

namespace ft {

enum Rb_tree_color {
  RED = true,
  BLACK = false
};

struct Rb_tree_node {
  typedef Rb_tree_node* Node_ptr;
  typedef const Rb_tree_node* Const_node_ptr;

  int data;
  Node_ptr parent;
  Node_ptr left;
  Node_ptr right;
  Rb_tree_color color;

  Rb_tree_node(int _data,
               Node_ptr _parent,
               Node_ptr _left,
               Node_ptr _right,
               Rb_tree_color _color)
      : data(_data),
        parent(_parent),
        left(_left),
        right(_right),
        color(_color) {}
};

}  // namespace ft

#endif  // RB_TREE_NODE_HPP_
