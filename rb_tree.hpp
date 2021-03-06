// Copyright (c) 2022 Welton Leite, wleite. All rights reserved.

#ifndef RB_TREE_HPP_
#define RB_TREE_HPP_

#define RB_TREE_TEMPLATE typename Key,        \
                         typename Val,        \
                         typename KeyOfValue, \
                         typename Compare,    \
                         typename Alloc

#define RB_TREE_CLASS Rb_tree<Key, Val, KeyOfValue, Compare, Alloc>

#include <memory>

#include "./algorithm.hpp"
#include "./rb_tree_iterator.hpp"
#include "./rb_tree_iterator_reverse.hpp"
#include "./rb_tree_node.hpp"

namespace ft {

template <typename Key,
          typename Val,
          typename KeyOfValue,
          typename Compare,
          typename Alloc = std::allocator<Val> >
class Rb_tree {
  typedef typename Alloc::template rebind<_Rb_tree_node<Val> >::other
      Node_allocator;

 public:
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
  typedef ft::rb_tree_reverse_iterator<iterator> reverse_iterator;
  typedef ft::rb_tree_reverse_iterator<const_iterator> const_reverse_iterator;

 public:
  explicit Rb_tree(const key_compare& comp = key_compare(),
                   const allocator_type& alloc = allocator_type());

  Rb_tree(const Rb_tree& src);

  Rb_tree& operator=(const Rb_tree& rhs);

  ~Rb_tree(void);

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

  void swap(Rb_tree& x);

  void clear(void);

  key_compare key_comp(void) const;

  iterator lower_bound(const key_type& k);

  const_iterator lower_bound(const key_type& k) const;

  iterator upper_bound(const key_type& k);

  const_iterator upper_bound(const key_type& k) const;

  allocator_type get_allocator(void) const;

  // red???black tree functions

  Node_ptr search(Key k) const;

  Node_ptr search(Key k, Node_ptr _root) const;

  Node_ptr minimum(Node_ptr node) const;

  Node_ptr maximum(Node_ptr node) const;

  Node_ptr successor(Node_ptr x) const;

  Node_ptr predecessor(Node_ptr x) const;

  void insert(value_type data);

  void insert(value_type data, Node_ptr _root);

  iterator insert_unique(value_type data);

  void erase(Key key);

  Node_ptr get_root(void);

 private:
  allocator_type _alloc;
  Node_ptr root;
  Node_ptr TNULL;
  size_type _size;
  key_compare _comp;

  // red???black tree helper functions

  void left_rotate(Node_ptr x);

  void right_rotate(Node_ptr x);

  void destructor_helper(Node_ptr node);

  Node_ptr search_helper(Node_ptr node, Key key) const;

  iterator insert_node_helper(value_type data);

  void erase_fix(Node_ptr x);

  void transplant(Node_ptr u, Node_ptr v);

  void erase_node_helper(Node_ptr z);

  void insert_fix(Node_ptr z);

  void copy_rb_tree(Node_ptr node);

  Rb_tree_node create_node(value_type data, Rb_tree_color color);
};

template <RB_TREE_TEMPLATE>
inline bool operator==(const RB_TREE_CLASS& x, const RB_TREE_CLASS& y) {
  return (x.size() == y.size() &&
          ft::equal(x.begin(), x.end(), y.begin()));
}

template <RB_TREE_TEMPLATE>
inline bool operator!=(const RB_TREE_CLASS& x, const RB_TREE_CLASS& y) {
  return (!(x == y));
}

template <RB_TREE_TEMPLATE>
inline bool operator<(const RB_TREE_CLASS& x, const RB_TREE_CLASS& y) {
  return (ft::lexicographical_compare(x.begin(), x.end(),
                                      y.begin(), y.end()));
}

template <RB_TREE_TEMPLATE>
inline bool operator<=(const RB_TREE_CLASS& x, const RB_TREE_CLASS& y) {
  return (!(y < x));
}

template <RB_TREE_TEMPLATE>
inline bool operator>(const RB_TREE_CLASS& x, const RB_TREE_CLASS& y) {
  return (y < x);
}

template <RB_TREE_TEMPLATE>
inline bool operator>=(const RB_TREE_CLASS& x,
                       const RB_TREE_CLASS& y) {
  return (!(x < y));
}

}  // namespace ft

#include "rb_tree.tpp"
#include "rb_tree_private.tpp"

#endif  // RB_TREE_HPP_
