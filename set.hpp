// Copyright (c) 2022 Welton Leite, wleite. All rights reserved.

#ifndef SET_HPP_
#define SET_HPP_

#define SET_TEMPLATE typename Key,     \
                     typename Compare, \
                     typename Alloc

#define SET_CLASS set<Key, Compare, Alloc>

#include <functional>
#include <memory>

#include "./rb_tree.hpp"
#include "./utility.hpp"

namespace ft {

template <class Key,
          class Compare = std::less<Key>,
          class Alloc = std::allocator<Key> >
class set {
  template <typename P>
  struct _Identity {
    Key operator()(const P& x) const {
      return (x);
    }
  };

 public:
  typedef Key key_type;
  typedef Key value_type;
  typedef Compare key_compare;
  typedef Compare value_compare;
  typedef typename Alloc::reference reference;
  typedef typename Alloc::const_reference const_reference;
  typedef typename Alloc::pointer pointer;
  typedef typename Alloc::const_pointer const_pointer;

 private:
  typedef Rb_tree<key_type, value_type,
                  _Identity<value_type>, key_compare, Alloc>
      Rb_tree_type;

  Rb_tree_type _rb_tree;

 public:
  typedef typename Rb_tree_type::allocator_type allocator_type;
  typedef typename Rb_tree_type::iterator iterator;
  typedef typename Rb_tree_type::const_iterator const_iterator;
  typedef typename Rb_tree_type::reverse_iterator reverse_iterator;
  typedef typename Rb_tree_type::const_reverse_iterator const_reverse_iterator;
  typedef typename Rb_tree_type::size_type size_type;
  typedef typename Rb_tree_type::difference_type difference_type;
};

}  // namespace ft

#include "set.tpp"

#endif  // SET_HPP_
