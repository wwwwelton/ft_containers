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
  typedef Alloc allocator_type;
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

 public:
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

  ft::pair<iterator, bool> insert(const value_type& val);

  iterator insert(iterator position, const value_type& val);

  template <class InputIterator>
  void insert(InputIterator first, InputIterator last);

  void clear(void);

  iterator find(const key_type& k);

  const_iterator find(const key_type& k) const;

 private:
  Rb_tree_type _rb_tree;
  key_compare _comp;
  allocator_type _alloc;
};

}  // namespace ft

#include "map.tpp"

#endif  // MAP_HPP_
