// Copyright (c) 2022 Welton Leite, wleite. All rights reserved.

#ifndef RB_TREE_BASE_HELPER_TPP_
#define RB_TREE_BASE_HELPER_TPP_

#include "rb_tree.hpp"

namespace ft {

template <RB_TREE_TEMPLATE>
void RB_TREE_CLASS::destructor_helper(Node_ptr node) {
  if (node != TNULL) {
    destructor_helper(node->left);
    destructor_helper(node->right);
    _alloc.destroy(node);
    _alloc.deallocate(node, 1);
  }
}

template <RB_TREE_TEMPLATE>
typename RB_TREE_CLASS::Node_ptr RB_TREE_CLASS::search_helper(Node_ptr node, Key key) {
  if (node == TNULL || (!_comp(key, KeyOfValue()(node->data)) &&
                        !_comp(KeyOfValue()(node->data), key))) {
    return (node);
  }
  if (_comp(key, KeyOfValue()(node->data))) {
    return (search_helper(node->left, key));
  } else {
    return (search_helper(node->right, key));
  }
}

template <RB_TREE_TEMPLATE>
void RB_TREE_CLASS::insert_node_helper(value_type data) {
  Node_ptr x = root;
  Node_ptr y = TNULL;
  Node_ptr z = _alloc.allocate(1);
  _alloc.construct(z, create_node(data, RED));

  while (x != TNULL) {
    y = x;
    if (_comp(KeyOfValue()(z->data), KeyOfValue()(x->data))) {
      x = x->left;
    } else {
      x = x->right;
    }
  }

  z->parent = y;

  if (y == TNULL) {
    root = z;
  } else if (_comp(KeyOfValue()(z->data), KeyOfValue()(y->data))) {
    y->left = z;
  } else {
    y->right = z;
    z->left = TNULL;
    z->right = TNULL;
    z->color = RED;
  }

  insert_fix(z);
  TNULL->root = root;
  _size++;
}

template <RB_TREE_TEMPLATE>
void RB_TREE_CLASS::erase_fix(Node_ptr x) {
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

template <RB_TREE_TEMPLATE>
void RB_TREE_CLASS::transplant(Node_ptr u, Node_ptr v) {
  if (u->parent == TNULL) {
    root = v;
  } else if (u == u->parent->left) {
    u->parent->left = v;
  } else {
    u->parent->right = v;
  }
  v->parent = u->parent;
}

template <RB_TREE_TEMPLATE>
void RB_TREE_CLASS::erase_node_helper(Node_ptr z) {
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

  _alloc.destroy(z);
  _alloc.deallocate(z, 1);

  if (y_original_color == BLACK) {
    erase_fix(x);
  }
  TNULL->root = root;
  _size--;
}

template <RB_TREE_TEMPLATE>
void RB_TREE_CLASS::insert_fix(Node_ptr z) {
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

template <RB_TREE_TEMPLATE>
void RB_TREE_CLASS::copy_rb_tree(Node_ptr node) {
  if (node != node->leaf) {
    insert(node->data);
    copy_rb_tree(node->left);
    copy_rb_tree(node->right);
  }
}

template <RB_TREE_TEMPLATE>
typename RB_TREE_CLASS::Rb_tree_node RB_TREE_CLASS::create_node(value_type data, Rb_tree_color color) {
  return (Rb_tree_node(data, root, TNULL, TNULL, TNULL, TNULL, color));
}

}  // namespace ft

#endif  // RB_TREE_BASE_HELPER_TPP_
