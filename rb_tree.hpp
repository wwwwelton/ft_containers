// Copyright (c) 2022 Welton Leite, wleite. All rights reserved.

#ifndef RB_TREE_HPP_
#define RB_TREE_HPP_

#include "./rb_tree_node.hpp"

namespace ft {

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
    while (node->left != TNULL) {
      node = node->left;
    }
    return (node);
  }

  Node_ptr maximum(Node_ptr node) {
    while (node->right != TNULL) {
      node = node->right;
    }
    return (node);
  }

  Node_ptr successor(Node_ptr x) {
    if (x->right != TNULL) {
      return (minimum(x->right));
    }
    Node_ptr y = x->parent;
    while (y != TNULL && x == y->right) {
      x = y;
      y = y->parent;
    }
    return (y);
  }

  Node_ptr predecessor(Node_ptr x) {
    if (x->left != TNULL) {
      return (maximum(x->left));
    }
    Node_ptr y = x->parent;
    while (y != TNULL && x == y->left) {
      x = y;
      y = y->parent;
    }
    return (y);
  }

  void left_rotate(Node_ptr x) {
    Node_ptr y;

    y = x->right;
    x->right = y->left;
    // If y has a left subtree,
    // assign x as the parent of the left subtree of y.
    if (y->left != TNULL) {
      y->left->parent = x;
    }
    y->parent = x->parent;
    // If the parent of x is TNULL, make y as the root of the tree.
    if (x->parent == TNULL) {
      root = y;
      // Else if x is the left child of p,
      // make y as the left child of p.
    } else if (x == x->parent->left) {
      x->parent->left = y;
      // Else assign y as the right child of p.
    } else {
      x->parent->right = y;
    }
    y->left = x;
    // Make y as the parent of x.
    x->parent = y;
  }

  void right_rotate(Node_ptr x) {
    Node_ptr y;

    y = x->left;
    x->left = y->right;
    // If y has a right subtree,
    // assign x as the parent of the right subtree of y.
    if (y->right != TNULL) {
      y->right->parent = x;
    }
    y->parent = x->parent;
    // If the parent of x is TNULL, make y as the root of the tree.
    if (x->parent == TNULL) {
      root = y;
      // Else if x is the right child of its parent p,
      // make y as the right child of p.
    } else if (x == x->parent->right) {
      x->parent->right = y;
      // Else assign y as the left child of p.
    } else {
      x->parent->left = y;
    }
    y->right = x;
    // Make y as the parent of x.
    x->parent = y;
  }

  void insert(int key) {
    Node_ptr x = root;
    Node_ptr y = TNULL;
    Node_ptr z = new Rb_tree_node(key, TNULL, TNULL, TNULL, RED);

    while (x != TNULL) {
      y = x;
      if (z->data < x->data) {
        x = x->left;
      } else {
        x = x->right;
      }
    }

    z->parent = y;

    if (y == TNULL) {
      root = z;
    } else if (z->data < y->data) {
      y->left = z;
    } else {
      y->right = z;
      z->left = TNULL;
      z->right = TNULL;
      z->color = RED;
    }

    insert_fix(z);
  }

  void delete_node(int key) {
    Node_ptr z = search(key);
    if (z == TNULL) {
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
      destructor_helper(node->left);
      destructor_helper(node->right);
      delete (node);
    }
  }

  Node_ptr search_helper(Node_ptr node, int key) {
    if (node == TNULL || key == node->data) {
      return (node);
    }
    if (key < node->data) {
      return (search_helper(node->left, key));
    } else {
      return (search_helper(node->right, key));
    }
  }

  void delete_fix(Node_ptr x) {
    Node_ptr w;

    while (x != root && x->color == BLACK) {
      if (x == x->parent->left) {
        w = x->parent->right;

        if (w->color == RED) {
          w->color = BLACK;
          x->parent->color = RED;
          left_rotate(x->parent);
          w = x->parent->right;
        }
        if (w->left->color == BLACK && w->right->color == BLACK) {
          w->color = RED;
          x = x->parent;
        } else {
          if (w->right->color == BLACK) {
            w->left->color = BLACK;
            w->color = RED;
            right_rotate(w);
            w = x->parent->right;
          }
          w->color = x->parent->color;
          x->parent->color = BLACK;
          w->right->color = BLACK;
          left_rotate(x->parent);
          x = root;
        }
      } else {
        w = x->parent->left;

        if (w->color == RED) {
          w->color = BLACK;
          x->parent->color = RED;
          right_rotate(x->parent);
          w = x->parent->left;
        }
        if (w->right->color == BLACK && w->left->color == BLACK) {
          w->color = RED;
          x = x->parent;
        } else {
          if (w->left->color == BLACK) {
            w->right->color = BLACK;
            w->color = RED;
            left_rotate(w);
            w = x->parent->left;
          }
          w->color = x->parent->color;
          x->parent->color = BLACK;
          w->left->color = BLACK;
          right_rotate(x->parent);
          x = root;
        }
      }
    }
    x->color = BLACK;
  }

  void transplant(Node_ptr u, Node_ptr v) {
    if (u->parent == TNULL) {
      root = v;
    } else if (u == u->parent->left) {
      u->parent->left = v;
    } else {
      u->parent->right = v;
    }
    v->parent = u->parent;
  }

  void delete_node_helper(Node_ptr z) {
    Node_ptr x, y;
    Rb_tree_color y_original_color;

    y = z;
    y_original_color = y->color;
    if (z->left == TNULL) {
      x = z->right;
      transplant(z, z->right);
    } else if (z->right == TNULL) {
      x = z->left;
      transplant(z, z->left);
    } else {
      y = minimum(z->right);
      y_original_color = y->color;
      x = y->right;
      if (z != z->right) {
        transplant(y, y->right);
        y->right = z->right;
        y->right->parent = y;
      } else {
        x->parent = y;
      }
      transplant(z, y);
      y->left = z->left;
      y->left->parent = y;
      y->color = z->color;
    }

    delete z;

    if (y_original_color == BLACK) {
      delete_fix(x);
    }
  }

  void insert_fix(Node_ptr z) {
    Node_ptr y;

    while (z->parent->color == RED) {
      if (z->parent == z->parent->parent->left) {
        y = z->parent->parent->right;
        if (y->color == RED) {
          z->parent->color = BLACK;
          y->color = BLACK;
          z->parent->parent->color = RED;
          z = z->parent->parent;
        } else {
          if (z == z->parent->right) {
            z = z->parent;
            left_rotate(z);
          }
          z->parent->color = BLACK;
          z->parent->parent->color = RED;
          right_rotate(z->parent->parent);
        }
      } else {
        y = z->parent->parent->left;
        if (y->color == RED) {
          z->parent->color = BLACK;
          y->color = BLACK;
          z->parent->parent->color = RED;
          z = z->parent->parent;
        } else {
          if (z == z->parent->left) {
            z = z->parent;
            right_rotate(z);
          }
          z->parent->color = BLACK;
          z->parent->parent->color = RED;
          left_rotate(z->parent->parent);
        }
      }
    }
    root->color = BLACK;
  }
};

}  // namespace ft

#endif  // RB_TREE_HPP_
