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

    insert_fix(newNode);
  }

  void delete_node(int key) {
    Node_ptr z = search(key);
    if (z == TNULL || z == NULL) {
      return;
    }
    delete_node_helper(z);
  }

  Node_ptr get_root(void) {
    return (root);
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

  void delete_fix(Node_ptr x) {
    Node_ptr s;

    // Do the following until the x is not the root of the tree
    // and the color of x is BLACK
    while (x != root && x->_color == BLACK) {
      // If x is the left child of its parent then,
      if (x == x->_parent->_left) {
        // Assign s to the sibling of x.
        s = x->_parent->_right;
        // If the sibling of x is RED,
        // Case-I: x's brother s is red
        if (s->_color == RED) {
          // Set the color of the right child of the parent of x as BLACK.
          s->_color = BLACK;
          // Set the color of the parent of x as RED.
          x->_parent->_color = RED;
          // Left-Rotate the parent of x.
          left_rotate(x->_parent);
          // Assign the rightChild of the parent of x to s.
          s = x->_parent->_right;
        }

        // If the color of both the right and the leftChild of s is BLACK,
        // Case-II: x's brother s is black and s's children are black
        if (s->_left->_color == BLACK && s->_right->_color == BLACK) {
          // Set the color of s as RED
          s->_color = RED;
          // Assign the parent of x to x.
          x = x->_parent;
          // Else if the color of the rightChild of s is BLACK
          // Case-III: the sibbling x s is black, the son on the left of
          // s is red and the son on the right of s is black
        } else {
          if (s->_right->_color == BLACK) {
            // Set the color of the leftChild of s as BLACK
            s->_left->_color = BLACK;
            // Set the color of s as RED
            s->_color = RED;
            // Right-Rotate s.
            right_rotate(s);
            // Assign the rightChild of the parent of x to s.
            s = x->_parent->_right;
          }

          // If any of the above cases do not occur, then do the following.
          // Case-IV: x's sibling s is black and s's right child is red

          // Set the color of s as the color of the parent of x.
          s->_color = x->_parent->_color;
          // Set the color of the parent of parent of x as BLACK.
          x->_parent->_color = BLACK;
          // Set the color of the right child of s as BLACK.
          s->_right->_color = BLACK;
          // Left-Rotate the parent of x.
          left_rotate(x->_parent);
          // Set x as the root of the tree.
          x = root;
        }
      } else {
        s = x->_parent->_left;
        if (s->_color == RED) {
          s->_color = BLACK;
          x->_parent->_color = RED;
          right_rotate(x->_parent);
          s = x->_parent->_left;
        }

        if (s->_right->_color == BLACK && s->_left->_color == BLACK) {
          s->_color = RED;
          x = x->_parent;
        } else {
          if (s->_left->_color == BLACK) {
            s->_right->_color = BLACK;
            s->_color = RED;
            left_rotate(s);
            s = x->_parent->_left;
          }

          s->_color = x->_parent->_color;
          x->_parent->_color = BLACK;
          s->_left->_color = BLACK;
          right_rotate(x->_parent);
          x = root;
        }
      }
    }
    // Set the color of x as BLACK.
    x->_color = BLACK;
  }

  /* In order to move subtrees around within the binary search tree,
  we define a subroutine TRANSPLANT, which replaces one subtree as a child of
  its parent with another subtree. When TRANSPLANT replaces the subtree rooted
  at node u with the subtree rooted at node v, node u's parent becomes node v’s
  parent, and u's parent ends up having as its appropriate child. */
  void transplant(Node_ptr u, Node_ptr v) {
    // if u doesn't have a parent => u is the root
    if (u->_parent == NULL) {
      // then v must replace u as the root of the tree T
      root = v;
      // if u is a left subtree of its parent
    } else if (u == u->_parent->_left) {
      // then v must replace u as the left subtree of u's parent
      u->_parent->_left = v;
      // else, u is a right subtree
    } else {
      // (as the tree is binary) and v must replace u as the right subtre
      //  of u's parent
      u->_parent->_right = v;
    }
    // v must have the same parent as u
    v->_parent = u->_parent;
  }

  void delete_node_helper(Node_ptr z) {
    Node_ptr x, y;
    Rb_tree_color y_original_color;

    // makes y point to node z when z has fewer than two children
    // and is therefore removed.
    y = z;
    // Save the color of nodeToBeDeleted
    y_original_color = y->_color;
    // If the left child of nodeToBeDeleted is TNULL
    if (z->_left == TNULL) {
      // Assign the right child of nodeToBeDeleted to x.
      x = z->_right;
      // Transplant nodeToBeDeleted with x.
      transplant(z, z->_right);
      // Else if the right child of nodeToBeDeleted is TNULL
    } else if (z->_right == TNULL) {
      // Assign the left child of nodeToBeDeleted into x.
      x = z->_left;
      // Transplant nodeToBeDeleted with x.
      transplant(z, z->_left);
    } else {
      // Assign the minimum of right subtree of noteToBeDeleted into y.
      y = minimum(z->_right);
      // Save the color of y in originalColor.
      y_original_color = y->_color;
      // Assign the rightChild of y into x.
      x = y->_right;
      // If y is a child of nodeToBeDeleted, then set the parent of x as y.
      if (y->_parent == z) {
        x->_parent = y;
        // Else, transplant y with rightChild of y.
      } else {
        // Transplant nodeToBeDeleted with y.
        transplant(y, y->_right);
        y->_right = z->_right;
        y->_right->_parent = y;
      }

      transplant(z, y);
      y->_left = z->_left;
      y->_left->_parent = y;
      y->_color = z->_color;
    }
    delete (z);
    if (y_original_color == BLACK) {
      delete_fix(x);
    }
  }

  void insert_fix(Node_ptr newNode) {
    Node_ptr u;

    // Do the following while the parent of newNode p is RED.
    while (newNode->_parent->_color == RED) {
      // If p is the right child of grandParent gP of newNode, do the following
      if (newNode->_parent == newNode->_parent->_parent->_right) {
        // Create uncle, left child gP of newNode
        u = newNode->_parent->_parent->_left;
        // If the color of the left child of gP (uncle) of newNode is RED
        if (u->_color == RED) {
          // Set the color of both the children of gP as BLACK
          u->_color = BLACK;
          newNode->_parent->_color = BLACK;
          // and the color of gP as RED.
          newNode->_parent->_parent->_color = RED;
          // Assign gP to newNode.
          newNode = newNode->_parent->_parent;
        } else {
          // Else if newNode is the left child of p
          if (newNode == newNode->_parent->_left) {
            // assign p to newNode
            newNode = newNode->_parent;
            // Right-Rotate newNode.
            right_rotate(newNode);
          }
          // Set color of p as BLACK and color of gP as RED.
          newNode->_parent->_color = BLACK;
          // Set color of gP as RED.
          newNode->_parent->_parent->_color = RED;
          // Left-Rotate gP.
          left_rotate(newNode->_parent->_parent);
        }
        // If p is the left child of grandParent gP of newNode, do the following
      } else {
        // Create uncle, right child gP of newNode
        u = newNode->_parent->_parent->_right;
        // If the color of the right child of gP (uncle) of newNode is RED
        if (u->_color == RED) {
          // Set the color of both the children of gP as BLACK
          u->_color = BLACK;
          newNode->_parent->_color = BLACK;
          // and the color of gP as RED.
          newNode->_parent->_parent->_color = RED;
          // Assign gP to newNode.
          newNode = newNode->_parent->_parent;
        } else {
          // Else if newNode is the right child of p
          if (newNode == newNode->_parent->_right) {
            // assign p to newNode
            newNode = newNode->_parent;
            // Left-Rotate newNode.
            left_rotate(newNode);
          }
          // Set color of p as BLACK and color of gP as RED.
          newNode->_parent->_color = BLACK;
          // Set color of gP as RED.
          newNode->_parent->_parent->_color = RED;
          // Right-Rotate gP.
          right_rotate(newNode->_parent->_parent);
        }
      }
      // Set the root of the tree as BLACK.
      if (newNode == root) {
        break;
      }
    }
    root->_color = BLACK;
  }
};

}  // namespace ft

#endif  // RB_TREE_HPP_
