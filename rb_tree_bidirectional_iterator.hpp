// Copyright (c) 2022 Welton Leite, wleite. All rights reserved.

#ifndef RB_TREE_BIDIRECTIONAL_ITERATOR_HPP_
#define RB_TREE_BIDIRECTIONAL_ITERATOR_HPP_

#include "./iterator_traits.hpp"
#include "./rb_tree_node.hpp"

namespace ft {

template <typename Iterator>
class rb_tree_bidirectional_iterator : public iterator<bidirectional_iterator_tag,
                                                       Iterator> {
 public:
  typedef Iterator iterator_type;
  typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
  typedef typename iterator_traits<Iterator>::value_type value_type;
  typedef typename iterator_traits<Iterator>::difference_type difference_type;
  typedef typename iterator_traits<Iterator>::pointer pointer;
  typedef typename iterator_traits<Iterator>::reference reference;

  typedef _Rb_tree_node<value_type> Rb_tree_node;
  typedef Rb_tree_node* Node_ptr;
  typedef const Rb_tree_node* Const_node_ptr;

 protected:
  Node_ptr node;

 public:
  rb_tree_bidirectional_iterator(void) : node(NULL) {}

  explicit rb_tree_bidirectional_iterator(Node_ptr _node) : node(_node) {}

  template <typename Iter>
  rb_tree_bidirectional_iterator(const rb_tree_bidirectional_iterator<Iter>& i)
      : node(i.base()) {}

  ~rb_tree_bidirectional_iterator(void) {}

  template <typename Iter>
  rb_tree_bidirectional_iterator&
  operator=(const rb_tree_bidirectional_iterator<Iter>& i) {
    node = i.base();
    return (*this);
  }

  const Node_ptr& base(void) const {
    return (node);
  }

  rb_tree_bidirectional_iterator& operator++(void) {
    node = successor(node);
    return (*this);
  }

  rb_tree_bidirectional_iterator operator++(int) {
    Node_ptr tmp = this->node;
    node = node = successor(node);
    return (rb_tree_bidirectional_iterator(tmp));
  }

  reference operator*(void) const {
    return (node->data);
  }

  pointer operator->(void) const {
    return (&(operator*()));
  }

 private:
  Node_ptr minimum(Node_ptr node) {
    while (node->left != node->left) {
      node = node->left;
    }
    return (node);
  }

  Node_ptr maximum(Node_ptr node) {
    while (node->right != node->left) {
      node = node->right;
    }
    return (node);
  }

  Node_ptr successor(Node_ptr x) {
    if (x->right != x->leaf) {
      return (minimum(x->right));
    }
    Node_ptr y = x->parent;
    while (y != y->leaf && x == y->right) {
      x = y;
      y = y->parent;
    }
    return (y);
  }

  Node_ptr predecessor(Node_ptr x) {
    if (x->left != x->leaf) {
      return (maximum(x->left));
    }
    Node_ptr y = x->parent;
    while (y != y->leaf && x == y->left) {
      x = y;
      y = y->parent;
    }
    return (y);
  }
};

}  // namespace ft

#endif  // RB_TREE_BIDIRECTIONAL_ITERATOR_HPP_
