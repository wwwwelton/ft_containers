// Copyright (c) 2022 Welton Leite, wleite. All rights reserved.

#ifndef VECTOR_HPP_
#define VECTOR_HPP_

#include <cstring>
#include <iostream>
#include <memory>

namespace ft {

template <typename T, class Alloc = std::allocator<T> >
class vector {
 public:
  typedef Alloc allocator_type;
  typedef typename Alloc::value_type value_type;
  typedef typename Alloc::pointer pointer;
  typedef typename Alloc::const_pointer const_pointer;
  typedef typename Alloc::reference reference;
  typedef typename Alloc::const_reference const_reference;
  typedef typename Alloc::size_type size_type;
  typedef typename Alloc::difference_type difference_type;

  //   typedef typename Alloc::difference_type iterator;
  //   typedef typename Alloc::difference_type const_iterator;
  //   typedef typename Alloc::difference_type reverse_iterator;
  //   typedef typename Alloc::difference_type const_reverse_iterator;

  explicit vector(const allocator_type& alloc = allocator_type());
  vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
  vector(const vector& x);

  ~vector(void);

  vector& operator=(const vector& rhs);

  reference operator[](size_type n);
  const_reference operator[](size_type n) const;

 protected:
  std::allocator<T> _alloc;
  size_type _size;
  size_type _capacity;
  pointer _data;
};

}  // namespace ft

#include "vector.tpp"
#include "vector_operators.tpp"

#endif  // VECTOR_HPP_
