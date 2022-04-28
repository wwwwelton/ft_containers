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

  Node_ptr predecessor(Node_ptr x) {
    if (x->_left != TNULL) {
      return (maximum(x->_left));
    }
    Node_ptr y = x->_parent;
    while (y != TNULL && x == y->_left) {
      x = y;
      y = y->_parent;
    }
    return (y);
  }

  void left_rotate(Node_ptr x) {
    Node_ptr y = x->_right;

    x->_right = y->_left;
    // If y has a left subtree,
    // assign x as the parent of the left subtree of y.
    if (y->_left != TNULL) {
      y->_left->_parent = x;
    }
    y->_parent = x->_parent;
    // If the parent of x is NULL, make y as the root of the tree.
    if (x->_parent == NULL) {
      root = y;
      // Else if x is the left child of p,
      // make y as the left child of p.
    } else if (x == x->_parent->_left) {
      x->_parent->_left = y;
      // Else assign y as the right child of p.
    } else {
      x->_parent->_right = y;
    }
    y->_left = x;
    // Make y as the parent of x.
    x->_parent = y;
  }

  void right_rotate(Node_ptr x) {
    Node_ptr y = x->_left;

    x->_left = y->_right;
    // If y has a right subtree,
    // assign x as the parent of the right subtree of y.
    if (y->_right != TNULL) {
      y->_right->_parent = x;
    }
    y->_parent = x->_parent;
    // If the parent of x is NULL, make y as the root of the tree.
    if (x->_parent == NULL) {
      root = y;
      // Else if x is the right child of its parent p,
      // make y as the right child of p.
    } else if (x == x->_parent->_right) {
      x->_parent->_right = y;
      // Else assign y as the left child of p.
    } else {
      x->_parent->_left = y;
    }
    y->_right = x;
    // Make y as the parent of x.
    x->_parent = y;
  }

  void insert(int key) {
    Node_ptr newNode = new Rb_tree_node(key, NULL, TNULL, TNULL, RED);

    // Let y be the leaf (ie. TNULL) and x be the root of the tree.
    Node_ptr y = NULL;
    Node_ptr x = root;

    // Check if the tree is empty (ie. whether x is TNULL).
    // If yes, insert newNode as a root node and color it BLACK.
    if (x == TNULL) {
      root = newNode;
      newNode->_color = BLACK;
      return;
    }

    // Repeat steps following steps until leaf (TNULL) is reached.
    while (x != TNULL) {
      // When loop ends, y will be the last leaf on the way
      y = x;
      // Compare newNode key (newKey) with rootKey (x).
      // If newKey is smaller than rootKey, traverse through the left subtree.
      if (newNode->_data < x->_data) {
        x = x->_left;
        // Else traverse through the right subtree.
      } else {
        x = x->_right;
      }
    }

    // Assign the parent of the leaf as a parent of newNode.
    newNode->_parent = y;

    // If newNode key is smaller than leaf key, make newNode as left child.
    if (newNode->_data < y->_data) {
      y->_left = newNode;
      // Else, make newNode as rifht child.
    } else {
      y->_right = newNode;
    }

    // If newNode is the root paint it BLACK
    if (newNode->_parent == NULL) {
      newNode->_color = BLACK;
      return;
    }

    // If newNode is in the first level, dont need fix the tree
    if (newNode->_parent->_parent == NULL) {
      return;
    }
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
