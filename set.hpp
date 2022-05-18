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

  explicit set(const key_compare& comp = key_compare(),
               const allocator_type& alloc = allocator_type());

  template <class InputIterator>
  set(InputIterator first, InputIterator last,
      const key_compare& comp = key_compare(),
      const allocator_type& alloc = allocator_type());

  set(const set& x);

  ~set(void);

  set& operator=(const set& x);

  iterator begin(void);

  const_iterator begin(void) const;

  iterator end(void);

  const_iterator end(void) const;

  reverse_iterator rbegin(void);

  const_reverse_iterator rbegin(void) const;

  reverse_iterator rend(void);

  const_reverse_iterator rend(void) const;

  bool empty(void) const;

  size_type size(void) const;

  size_type max_size(void) const;

  ft::pair<iterator, bool> insert(const value_type& val);

  iterator insert(iterator position, const value_type& val);

  template <class InputIterator>
  void insert(InputIterator first, InputIterator last);

  void erase(iterator position);

  size_type erase(const value_type& val);

  void erase(iterator first, iterator last);
};

}  // namespace ft

#include "set.tpp"

#endif  // SET_HPP_
