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

  void swap(set& x);

  void clear(void);

  key_compare key_comp(void) const;

  value_compare value_comp(void) const;

  iterator find(const value_type& val);

  size_type count(const value_type& val) const;

  iterator lower_bound(const value_type& val);

  iterator upper_bound(const value_type& val);

  ft::pair<iterator, iterator> equal_range(const value_type& val) const;

  allocator_type get_allocator(void) const;

  template <typename K1, typename C1, typename A1>
  friend bool
  operator==(const set<K1, C1, A1>&,
             const set<K1, C1, A1>&);

  template <typename K1, typename C1, typename A1>
  friend bool
  operator<(const set<K1, C1, A1>&,
            const set<K1, C1, A1>&);
};

template <class Key, class Compare, class Alloc>
bool operator==(const set<Key, Compare, Alloc>& lhs,
                const set<Key, Compare, Alloc>& rhs) {
  return (lhs._rb_tree == rhs._rb_tree);
}

template <class Key, class Compare, class Alloc>
bool operator!=(const set<Key, Compare, Alloc>& lhs,
                const set<Key, Compare, Alloc>& rhs) {
  return (!(lhs == rhs));
}

template <class Key, class Compare, class Alloc>
bool operator<(const set<Key, Compare, Alloc>& lhs,
               const set<Key, Compare, Alloc>& rhs) {
  return (lhs._rb_tree < rhs._rb_tree);
}

}  // namespace ft

#include "set.tpp"

#endif  // SET_HPP_
