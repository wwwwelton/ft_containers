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
    // If the parent of x is NULL, make y as the root of the tree.
    if (x->parent == NULL) {
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
    // If the parent of x is NULL, make y as the root of the tree.
    if (x->parent == NULL) {
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
    Node_ptr newNode = new Rb_tree_node(key, NULL, TNULL, TNULL, RED);

    // Let y be the leaf (ie. TNULL) and x be the root of the tree.
    Node_ptr y = NULL;
    Node_ptr x = root;

    // Check if the tree is empty (ie. whether x is TNULL).
    // If yes, insert newNode as a root node and color it BLACK.
    if (x == TNULL) {
      root = newNode;
      newNode->color = BLACK;
      return;
    }

    // Repeat steps following steps until leaf (TNULL) is reached.
    while (x != TNULL) {
      // When loop ends, y will be the last leaf on the way
      y = x;
      // Compare newNode key (newKey) with rootKey (x).
      // If newKey is smaller than rootKey, traverse through the left subtree.
      if (newNode->data < x->data) {
        x = x->left;
        // Else traverse through the right subtree.
      } else {
        x = x->right;
      }
    }

    // Assign the parent of the leaf as a parent of newNode.
    newNode->parent = y;

    // If newNode key is smaller than leaf key, make newNode as left child.
    if (newNode->data < y->data) {
      y->left = newNode;
      // Else, make newNode as rifht child.
    } else {
      y->right = newNode;
    }

    // If newNode is the root paint it BLACK
    if (newNode->parent == NULL) {
      newNode->color = BLACK;
      return;
    }

    // If newNode is in the first level, dont need fix the tree
    if (newNode->parent->parent == NULL) {
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
    Node_ptr s;

    // Do the following until the x is not the root of the tree
    // and the color of x is BLACK
    while (x != root && x->color == BLACK) {
      // If x is the left child of its parent then,
      if (x == x->parent->left) {
        // Assign s to the sibling of x.
        s = x->parent->right;
        // If the sibling of x is RED,
        // Case-I: x's brother s is red
        if (s->color == RED) {
          // Set the color of the right child of the parent of x as BLACK.
          s->color = BLACK;
          // Set the color of the parent of x as RED.
          x->parent->color = RED;
          // Left-Rotate the parent of x.
          left_rotate(x->parent);
          // Assign the rightChild of the parent of x to s.
          s = x->parent->right;
        }

        // If the color of both the right and the leftChild of s is BLACK,
        // Case-II: x's brother s is black and s's children are black
        if (s->left->color == BLACK && s->right->color == BLACK) {
          // Set the color of s as RED
          s->color = RED;
          // Assign the parent of x to x.
          x = x->parent;
          // Else if the color of the rightChild of s is BLACK
          // Case-III: the sibbling x s is black, the son on the left of
          // s is red and the son on the right of s is black
        } else {
          if (s->right->color == BLACK) {
            // Set the color of the leftChild of s as BLACK
            s->left->color = BLACK;
            // Set the color of s as RED
            s->color = RED;
            // Right-Rotate s.
            right_rotate(s);
            // Assign the rightChild of the parent of x to s.
            s = x->parent->right;
          }

          // If any of the above cases do not occur, then do the following.
          // Case-IV: x's sibling s is black and s's right child is red

          // Set the color of s as the color of the parent of x.
          s->color = x->parent->color;
          // Set the color of the parent of parent of x as BLACK.
          x->parent->color = BLACK;
          // Set the color of the right child of s as BLACK.
          s->right->color = BLACK;
          // Left-Rotate the parent of x.
          left_rotate(x->parent);
          // Set x as the root of the tree.
          x = root;
        }
      } else {
        s = x->parent->left;
        if (s->color == RED) {
          s->color = BLACK;
          x->parent->color = RED;
          right_rotate(x->parent);
          s = x->parent->left;
        }

        if (s->right->color == BLACK && s->left->color == BLACK) {
          s->color = RED;
          x = x->parent;
        } else {
          if (s->left->color == BLACK) {
            s->right->color = BLACK;
            s->color = RED;
            left_rotate(s);
            s = x->parent->left;
          }

          s->color = x->parent->color;
          x->parent->color = BLACK;
          s->left->color = BLACK;
          right_rotate(x->parent);
          x = root;
        }
      }
    }
    // Set the color of x as BLACK.
    x->color = BLACK;
  }

  /* In order to move subtrees around within the binary search tree,
  we define a subroutine TRANSPLANT, which replaces one subtree as a child of
  its parent with another subtree. When TRANSPLANT replaces the subtree rooted
  at node u with the subtree rooted at node v, node u's parent becomes node v’s
  parent, and u's parent ends up having as its appropriate child. */
  void transplant(Node_ptr u, Node_ptr v) {
    // if u doesn't have a parent => u is the root
    if (u->parent == NULL) {
      // then v must replace u as the root of the tree T
      root = v;
      // if u is a left subtree of its parent
    } else if (u == u->parent->left) {
      // then v must replace u as the left subtree of u's parent
      u->parent->left = v;
      // else, u is a right subtree
    } else {
      // (as the tree is binary) and v must replace u as the right subtre
      //  of u's parent
      u->parent->right = v;
    }
    // v must have the same parent as u
    v->parent = u->parent;
  }

  void delete_node_helper(Node_ptr z) {
    Node_ptr x, y;
    Rb_tree_color y_original_color;

    // makes y point to node z when z has fewer than two children
    // and is therefore removed.
    y = z;
    // Save the color of nodeToBeDeleted
    y_original_color = y->color;
    // If the left child of nodeToBeDeleted is TNULL
    if (z->left == TNULL) {
      // Assign the right child of nodeToBeDeleted to x.
      x = z->right;
      // Transplant nodeToBeDeleted with x.
      transplant(z, z->right);
      // Else if the right child of nodeToBeDeleted is TNULL
    } else if (z->right == TNULL) {
      // Assign the left child of nodeToBeDeleted into x.
      x = z->left;
      // Transplant nodeToBeDeleted with x.
      transplant(z, z->left);
    } else {
      // Assign the minimum of right subtree of noteToBeDeleted into y.
      y = minimum(z->right);
      // Save the color of y in originalColor.
      y_original_color = y->color;
      // Assign the rightChild of y into x.
      x = y->right;
      // If y is a child of nodeToBeDeleted, then set the parent of x as y.
      if (y->parent == z) {
        x->parent = y;
        // Else, transplant y with rightChild of y.
      } else {
        // Transplant nodeToBeDeleted with y.
        transplant(y, y->right);
        y->right = z->right;
        y->right->parent = y;
      }

      transplant(z, y);
      y->left = z->left;
      y->left->parent = y;
      y->color = z->color;
    }
    delete (z);
    if (y_original_color == BLACK) {
      delete_fix(x);
    }
  }

  void insert_fix(Node_ptr newNode) {
    Node_ptr u;

    // Do the following while the parent of newNode p is RED.
    while (newNode->parent->color == RED) {
      // If p is the right child of grandParent gP of newNode, do the following
      if (newNode->parent == newNode->parent->parent->right) {
        // Create uncle, left child gP of newNode
        u = newNode->parent->parent->left;
        // If the color of the left child of gP (uncle) of newNode is RED
        if (u->color == RED) {
          // Set the color of both the children of gP as BLACK
          u->color = BLACK;
          newNode->parent->color = BLACK;
          // and the color of gP as RED.
          newNode->parent->parent->color = RED;
          // Assign gP to newNode.
          newNode = newNode->parent->parent;
        } else {
          // Else if newNode is the left child of p
          if (newNode == newNode->parent->left) {
            // assign p to newNode
            newNode = newNode->parent;
            // Right-Rotate newNode.
            right_rotate(newNode);
          }
          // Set color of p as BLACK and color of gP as RED.
          newNode->parent->color = BLACK;
          // Set color of gP as RED.
          newNode->parent->parent->color = RED;
          // Left-Rotate gP.
          left_rotate(newNode->parent->parent);
        }
        // If p is the left child of grandParent gP of newNode, do the following
      } else {
        // Create uncle, right child gP of newNode
        u = newNode->parent->parent->right;
        // If the color of the right child of gP (uncle) of newNode is RED
        if (u->color == RED) {
          // Set the color of both the children of gP as BLACK
          u->color = BLACK;
          newNode->parent->color = BLACK;
          // and the color of gP as RED.
          newNode->parent->parent->color = RED;
          // Assign gP to newNode.
          newNode = newNode->parent->parent;
        } else {
          // Else if newNode is the right child of p
          if (newNode == newNode->parent->right) {
            // assign p to newNode
            newNode = newNode->parent;
            // Left-Rotate newNode.
            left_rotate(newNode);
          }
          // Set color of p as BLACK and color of gP as RED.
          newNode->parent->color = BLACK;
          // Set color of gP as RED.
          newNode->parent->parent->color = RED;
          // Right-Rotate gP.
          right_rotate(newNode->parent->parent);
        }
      }
      // Set the root of the tree as BLACK.
      if (newNode == root) {
        break;
      }
    }
    root->color = BLACK;
  }
};

}  // namespace ft

#endif  // RB_TREE_HPP_
