// Copyright (c) 2022 Welton Leite, wleite. All rights reserved.

#ifndef RB_TREE_ITERATOR_REVERSE_HPP_
#define RB_TREE_ITERATOR_REVERSE_HPP_

#include "./iterator_traits.hpp"
#include "./rb_tree_node.hpp"

namespace ft {

template <typename Iterator>
class rb_tree_reverse_iterator
    : public iterator<typename iterator_traits<Iterator>::iterator_category,
                      typename iterator_traits<Iterator>::value_type,
                      typename iterator_traits<Iterator>::difference_type,
                      typename iterator_traits<Iterator>::pointer,
                      typename iterator_traits<Iterator>::reference> {
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
  rb_tree_reverse_iterator(void) : node(NULL) {}

  explicit rb_tree_reverse_iterator(Node_ptr _node) : node(_node) {}

  explicit rb_tree_reverse_iterator(iterator_type x) : node(x.base()) {}

  rb_tree_reverse_iterator(const rb_tree_reverse_iterator& x) : node(x.node) {}

  template <typename Iter>
  rb_tree_reverse_iterator(const rb_tree_reverse_iterator<Iter>& x) : node(x.base()) {}

  ~rb_tree_reverse_iterator(void) {}

  template <typename Iter>
  rb_tree_reverse_iterator& operator=(const rb_tree_reverse_iterator<Iter>& x) {
    node = x.base();
    return (*this);
  }

  const Node_ptr& base(void) const {
    return (node);
  }
};

}  // namespace ft

#endif  // RB_TREE_ITERATOR_REVERSE_HPP_