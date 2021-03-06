// Copyright (c) 2022 Welton Leite, wleite. All rights reserved.

#ifndef MAP_HPP_
#define MAP_HPP_

#define MAP_TEMPLATE typename Key,     \
                     typename T,       \
                     typename Compare, \
                     typename Alloc

#define MAP_CLASS map<Key, T, Compare, Alloc>

#include <functional>
#include <memory>

#include "./rb_tree.hpp"
#include "./utility.hpp"

namespace ft {

template <class Key,
          class T,
          class Compare = std::less<Key>,
          class Alloc = std::allocator<ft::pair<const Key, T> > >
class map {
  template <typename P>
  struct _Select1st {
    Key operator()(const P& x) const {
      return (x.first);
    }
  };

 public:
  typedef Key key_type;
  typedef T mapped_type;
  typedef ft::pair<const Key, T> value_type;
  typedef Compare key_compare;
  typedef typename Alloc::reference reference;
  typedef typename Alloc::const_reference const_reference;
  typedef typename Alloc::pointer pointer;
  typedef typename Alloc::const_pointer const_pointer;

  class value_compare
      : public std::binary_function<value_type, value_type, bool> {
    friend class map<Key, T, Compare, Alloc>;

   protected:
    Compare comp;

    explicit value_compare(Compare c) : comp(c) {}

   public:
    bool operator()(const value_type& x, const value_type& y) const {
      return (comp(x.first, y.first));
    }
  };

 private:
  typedef Rb_tree<key_type, value_type,
                  _Select1st<value_type>, key_compare, Alloc>
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

  explicit map(const key_compare& comp = key_compare(),
               const allocator_type& alloc = allocator_type());

  template <class InputIterator>
  map(InputIterator first, InputIterator last,
      const key_compare& comp = key_compare(),
      const allocator_type& alloc = allocator_type());

  map(const map& x);

  ~map(void);

  map& operator=(const map& x);

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

  mapped_type& operator[](const key_type& k);

  ft::pair<iterator, bool> insert(const value_type& val);

  iterator insert(iterator position, const value_type& val);

  template <class InputIterator>
  void insert(InputIterator first, InputIterator last);

  void erase(iterator position);

  size_type erase(const key_type& k);

  void erase(iterator first, iterator last);

  void swap(map& x);

  void clear(void);

  key_compare key_comp(void) const;

  value_compare value_comp(void) const;

  iterator find(const key_type& k);

  const_iterator find(const key_type& k) const;

  size_type count(const key_type& k) const;

  iterator lower_bound(const key_type& k);

  const_iterator lower_bound(const key_type& k) const;

  iterator upper_bound(const key_type& k);

  const_iterator upper_bound(const key_type& k) const;

  ft::pair<iterator, iterator> equal_range(const key_type& k);

  ft::pair<const_iterator, const_iterator> equal_range(const key_type& k) const;

  allocator_type get_allocator(void) const;

  template <typename K1, typename T1, typename C1, typename A1>
  friend bool
  operator==(const map<K1, T1, C1, A1>&,
             const map<K1, T1, C1, A1>&);

  template <typename K1, typename T1, typename C1, typename A1>
  friend bool
  operator<(const map<K1, T1, C1, A1>&,
            const map<K1, T1, C1, A1>&);
};

template <class Key, class T, class Compare, class Alloc>
bool operator==(const map<Key, T, Compare, Alloc>& lhs,
                const map<Key, T, Compare, Alloc>& rhs) {
  return (lhs._rb_tree == rhs._rb_tree);
}

template <class Key, class T, class Compare, class Alloc>
bool operator!=(const map<Key, T, Compare, Alloc>& lhs,
                const map<Key, T, Compare, Alloc>& rhs) {
  return (!(lhs == rhs));
}

template <class Key, class T, class Compare, class Alloc>
bool operator<(const map<Key, T, Compare, Alloc>& lhs,
               const map<Key, T, Compare, Alloc>& rhs) {
  return (lhs._rb_tree < rhs._rb_tree);
}

template <class Key, class T, class Compare, class Alloc>
bool operator<=(const map<Key, T, Compare, Alloc>& lhs,
                const map<Key, T, Compare, Alloc>& rhs) {
  return (!(rhs < lhs));
}

template <class Key, class T, class Compare, class Alloc>
bool operator>(const map<Key, T, Compare, Alloc>& lhs,
               const map<Key, T, Compare, Alloc>& rhs) {
  return (rhs < lhs);
}

template <class Key, class T, class Compare, class Alloc>
bool operator>=(const map<Key, T, Compare, Alloc>& lhs,
                const map<Key, T, Compare, Alloc>& rhs) {
  return (!(lhs < rhs));
}

}  // namespace ft

#include "map.tpp"

#endif  // MAP_HPP_
