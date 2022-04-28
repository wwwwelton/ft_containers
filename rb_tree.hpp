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

  ~Rb_tree(void) {
    destructor_helper(root);
    delete (TNULL);
  }

  Node_ptr search(int k) {
    return (search_helper(root, k));
  }

  Node_ptr minimum(Node_ptr node) {
    while (node->_left != TNULL) {
      node = node->_left;
    }
    return (node);
  }

  Node_ptr maximum(Node_ptr node) {
    while (node->_right != TNULL) {
      node = node->_right;
    }
    return (node);
  }

  Node_ptr successor(Node_ptr x) {
    if (x->_right != TNULL) {
      return (minimum(x->_right));
    }
    Node_ptr y = x->_parent;
    while (y != TNULL && x == y->_right) {
      x = y;
      y = y->_parent;
    }
    return (y);
  }

 private:
  Node_ptr root;
  Node_ptr TNULL;

  void destructor_helper(Node_ptr node) {
    if (node != TNULL) {
      destructor_helper(node->_left);
      destructor_helper(node->_right);
      delete (node);
    }
  }

  Node_ptr search_helper(Node_ptr node, int key) {
    if (node == TNULL || key == node->_data) {
      return (node);
    }
    if (key < node->_data) {
      return (search_helper(node->_left, key));
    } else {
      return (search_helper(node->_right, key));
    }
  }
};

}  // namespace ft

#endif  // RB_TREE_HPP_
