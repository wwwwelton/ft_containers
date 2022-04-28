// Copyright (c) 2022 Welton Leite, wleite. All rights reserved.

#ifndef RB_TREE_HPP_
#define RB_TREE_HPP_

#include <iostream>
#include <string>

namespace ft {

enum Rb_tree_color {
  RED = true,
  BLACK = false
};

struct Rb_tree_node {
  typedef Rb_tree_node* Node_ptr;
  typedef const Rb_tree_node* Const_node_ptr;

  int _data;
  Node_ptr _parent;
  Node_ptr _left;
  Node_ptr _right;
  Rb_tree_color _color;

  Rb_tree_node(int data,
               Node_ptr parent,
               Node_ptr left,
               Node_ptr right,
               Rb_tree_color color)
      : _data(data),
        _parent(parent),
        _left(left),
        _right(right),
        _color(color) {}
};

class Rb_tree {
 protected:
  typedef Rb_tree_node* Node_ptr;
  typedef const Rb_tree_node* Const_node_ptr;

 public:
  Rb_tree(void) {
    TNULL = new Rb_tree_node(0, NULL, NULL, NULL, BLACK);
    root = TNULL;
  }

 private:
  Node_ptr root;
  Node_ptr TNULL;
};

}  // namespace ft

#endif  // RB_TREE_HPP_
