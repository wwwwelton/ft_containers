// Copyright (c) 2022 Welton Leite, wleite. All rights reserved.

#ifndef RB_TREE_HPP_
#define RB_TREE_HPP_

#include <memory>

#include "./rb_tree_iterator.hpp"
#include "./rb_tree_node.hpp"
#include "./utility.hpp"

namespace ft {

template <typename Key,
          typename Val,
          typename KeyOfValue,
          typename Compare,
          typename Alloc = std::allocator<Val> >
class Rb_tree {
  typedef typename Alloc::template rebind<_Rb_tree_node<Val> >::other
      Node_allocator;

 protected:
  typedef _Rb_tree_node<Val> Rb_tree_node;
  typedef Rb_tree_node* Node_ptr;
  typedef const Rb_tree_node* Const_node_ptr;

 public:
  typedef Key key_type;
  typedef Val value_type;
  typedef Compare key_compare;
  typedef value_type* pointer;
  typedef const value_type* const_pointer;
  typedef value_type& reference;
  typedef const value_type& const_reference;
  typedef size_t size_type;
  typedef ptrdiff_t difference_type;
  //   typedef Alloc allocator_type;
  typedef Node_allocator allocator_type;
  typedef ft::rb_tree_iterator<pointer> iterator;
  typedef ft::rb_tree_iterator<const_pointer> const_iterator;

 public:
  explicit Rb_tree(const key_compare& comp = key_compare(),
                   const allocator_type& alloc = allocator_type()) {
    _alloc = alloc;
    TNULL = _alloc.allocate(1);
    _alloc.construct(TNULL, create_node(value_type(), BLACK));
    root = TNULL;
    _comp = comp;
  }

  Rb_tree(const Rb_tree& src) {
    _alloc = src._alloc;
    TNULL = _alloc.allocate(1);
    _alloc.construct(TNULL, create_node(value_type(), BLACK));
    root = TNULL;
    copy_rb_tree(src.root);
    _comp = src._comp;
  }

  Rb_tree& operator=(const Rb_tree& rhs) {
    if (this != &rhs) {
      this->~Rb_tree();
      _alloc = rhs._alloc;
      TNULL = _alloc.allocate(1);
      _alloc.construct(TNULL, create_node(value_type(), BLACK));
      root = TNULL;
      copy_rb_tree(rhs.root);
      _comp = rhs._comp;
    }
    return (*this);
  }

  ~Rb_tree(void) {
    destructor_helper(root);
    _alloc.destroy(TNULL);
    _alloc.deallocate(TNULL, 1);
  }

  Node_ptr search(Key k) {
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

  void right_rotate(Node_ptr x) {
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

  void insert(value_type data) {
    Node_ptr z = search(KeyOfValue()(data));
    if (z != TNULL) {
      delete_node_helper(z);
    }
    insert_node_helper(data);
  }

  void delete_node(Key key) {
    Node_ptr z = search(key);
    if (z == TNULL) {
      return;
    }
    delete_node_helper(z);
  }

  Node_ptr get_root(void) {
    return (root);
  }

  Const_node_ptr get_root(void) const {
    return (root);
  }

  iterator begin(void) {
    return (iterator(minimum(root)));
  }

  const_iterator begin(void) const {
    return (const_iterator(minimum(root)));
  }

  iterator end(void) {
    return (iterator(root->leaf));
  }

  const_iterator end(void) const {
    return (const_iterator(root->leaf));
  }

 private:
  allocator_type _alloc;
  Node_ptr root;
  Node_ptr TNULL;
  key_compare _comp;

  void destructor_helper(Node_ptr node) {
    if (node != TNULL) {
      destructor_helper(node->left);
      destructor_helper(node->right);
      _alloc.destroy(node);
      _alloc.deallocate(node, 1);
    }
  }

  Node_ptr search_helper(Node_ptr node, Key key) {
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

  void insert_node_helper(value_type data) {
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

    _alloc.destroy(z);
    _alloc.deallocate(z, 1);

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

  void copy_rb_tree(Node_ptr node) {
    if (node != node->leaf) {
      insert(node->data);
      copy_rb_tree(node->left);
      copy_rb_tree(node->right);
    }
  }

  Rb_tree_node create_node(value_type data, Rb_tree_color color) {
    return (Rb_tree_node(data, root, TNULL, TNULL, TNULL, TNULL, color));
  }
};

}  // namespace ft

#endif  // RB_TREE_HPP_
