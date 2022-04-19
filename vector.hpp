// Copyright (c) 2022 Welton Leite, wleite. All rights reserved.

#ifndef VECTOR_HPP_
#define VECTOR_HPP_

#include <memory>
#include <stdexcept>

#include "algorithm.hpp"
#include "iterator_funcs.hpp"
#include "iterator_random.hpp"
#include "iterator_reverse.hpp"
#include "iterator_traits.hpp"
#include "type_traits.hpp"

namespace ft {

template <class T, class Alloc = std::allocator<T> >
class vector {
 public:
  typedef T value_type;
  typedef Alloc allocator_type;
  typedef typename Alloc::reference reference;
  typedef typename Alloc::const_reference const_reference;
  typedef typename Alloc::pointer pointer;
  typedef typename Alloc::const_pointer const_pointer;
  typedef ft::random_access_iterator<pointer> iterator;
  typedef ft::random_access_iterator<const_pointer> const_iterator;
  typedef ft::reverse_iterator<iterator> reverse_iterator;
  typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
  typedef ptrdiff_t difference_type;
  typedef size_t size_type;

 protected:
  std::allocator<T> _alloc;
  pointer _data;
  size_type _capacity;
  size_type _size;

 public:
  explicit vector(const allocator_type& alloc = allocator_type());

  explicit vector(size_type n,
                  const value_type& val = value_type(),
                  const allocator_type& alloc = allocator_type());

  template <class InputIterator>
  vector(InputIterator first, InputIterator last,
         const allocator_type& alloc = allocator_type());

  template <typename Integer>
  void initialize_dispatch(Integer n, Integer value, true_type);

  template <typename InputIterator>
  void initialize_dispatch(InputIterator first, InputIterator last, false_type);

  vector(const vector& x);

  ~vector(void);

  iterator begin(void);

  const_iterator begin(void) const;

  iterator end(void);

  const_iterator end(void) const;

  reverse_iterator rbegin(void);

  const_reverse_iterator rbegin(void) const;

  reverse_iterator rend(void);

  const_reverse_iterator rend(void) const;

  size_type size(void) const;

  size_type max_size(void) const;

  void resize(size_type n, value_type val = value_type());

  size_type capacity(void) const;

  bool empty(void) const;

  void reserve(size_type n);

  reference operator[](size_type n);

  const_reference operator[](size_type n) const;

  reference at(size_type n);

  const_reference at(size_type n) const;

  reference front(void);

  const_reference front(void) const;

  reference back(void);

  const_reference back(void) const;

  template <class InputIterator>
  void assign(InputIterator first, InputIterator last);

  template <typename Integer>
  void assign_dispatch(Integer n, Integer val, true_type);

  template <typename InputIterator>
  void assign_dispatch(InputIterator first, InputIterator last, false_type);

  void push_back(const value_type& val);

  void pop_back(void);

  iterator insert(iterator position, const value_type& val);

  void insert(iterator position, size_type n, const value_type& val);

  template <class InputIterator>
  void insert(iterator position, InputIterator first, InputIterator last);

  template <class Integer>
  void insert_dispatch(iterator position,
                       size_type n, const Integer& val, true_type);

  template <class InputIterator>
  void insert_dispatch(iterator position,
                       InputIterator first, InputIterator last, false_type);

  iterator erase(iterator position);

  iterator erase(iterator first, iterator last);

  void swap(vector& x);

  void clear(void);

  allocator_type get_allocator(void) const;
};

template <class T, class Alloc>
inline bool operator==(const vector<T, Alloc>& x, const vector<T, Alloc>& y) {
  return ((x.size() == y.size() && ft::equal(x.begin(), x.end(), y.begin())));
}

template <class T, class Alloc>
inline bool operator!=(const vector<T, Alloc>& x, const vector<T, Alloc>& y) {
  return (!(x == y));
}

template <class T, class Alloc>
inline bool operator<(const vector<T, Alloc>& x, const vector<T, Alloc>& y) {
  return (ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end()));
}

template <class T, class Alloc>
inline bool operator<=(const vector<T, Alloc>& x, const vector<T, Alloc>& y) {
  return (!(y < x));
}

template <class T, class Alloc>
inline bool operator>(const vector<T, Alloc>& x, const vector<T, Alloc>& y) {
  return (y < x);
}

template <class T, class Alloc>
inline bool operator>=(const vector<T, Alloc>& x, const vector<T, Alloc>& y) {
  return (!(x < y));
}

template <class T, class Alloc>
void swap(vector<T, Alloc>& x, vector<T, Alloc>& y) {
  x.swap(y);
}

}  // namespace ft

#include "vector.tpp"

#endif  // VECTOR_HPP_
