// Copyright (c) 2022 Welton Leite, wleite. All rights reserved.

#ifndef VECTOR_HPP_
#define VECTOR_HPP_

#include <cstring>
#include <iostream>
#include <memory>

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
  explicit vector(const allocator_type& alloc = allocator_type()) {
    _alloc = alloc;
    _data = NULL;
    _size = 0;
    _capacity = 0;
  }

  explicit vector(size_type n,
                  const value_type& val = value_type(),
                  const allocator_type& alloc = allocator_type()) {
    _alloc = alloc;
    _data = _alloc.allocate(n);
    _capacity = n;
    _size = 0;
    for (size_type i = 0; i < n; i++) {
      _alloc.construct(this->_data + i, val);
      _size++;
    }
  }

  template <class InputIterator>
  vector(InputIterator first, InputIterator last,
         const allocator_type& alloc = allocator_type());

  vector(const vector& x) {
    *this = x;
  }

  ~vector(void) {
    for (size_type i = 0; i < this->_size; i++) {
      this->_alloc.destroy(this->_data + i);
    }
    this->_alloc.deallocate(this->_data, this->_size);
    this->_size = 0;
    this->_capacity = 0;
  }

  iterator begin() {
    return (iterator(_data));
  }

  const_iterator begin() const {
    return (const_iterator(_data));
  }

  iterator end() {
    return (iterator(_data + _size));
  }

  const_iterator end() const {
    return (const_iterator(_data + _size));
  }

  reverse_iterator rbegin() {
    return (reverse_iterator(_data + _size - 1));
  }

  const_reverse_iterator rbegin() const {
    return (const_reverse_iterator(_data + _size - 1));
  }

  reverse_iterator rend() {
    return (reverse_iterator(begin()));
  }

  const_reverse_iterator rend() const {
    return (const_reverse_iterator(begin()));
  }

  size_type size() const {
    return (size_type(end() - begin()));
  }

  size_type max_size() const {
    return size_type(-1) / sizeof(value_type);
  }

  void resize(size_type n, value_type val = value_type());

  size_type capacity() const {
    return (size_type(const_iterator(end()) - begin()));
  }

  bool empty() const {
    return begin() == end();
  }

  void reserve(size_type n);

  reference operator[](size_type n) {
    return (*(begin() + n));
  }

  const_reference operator[](size_type n) const {
    return (*(begin() + n));
  }

  reference at(size_type n);

  const_reference at(size_type n) const {
    if (n < 0 || n >= _size) {
      throw std::out_of_range("The index is out of range");
    }
    return (_data[n]);
  }

  reference front() {
    return (*begin());
  }

  const_reference front() const {
    return (*begin());
  }

  reference back() {
    return (*(end() - 1));
  }

  const_reference back() const {
    return (*(end() - 1));
  }

  template <class InputIterator>
  void assign(InputIterator first, InputIterator last);

  void assign(size_type n, const value_type& val);

  void push_back(const value_type& val);

  void pop_back();

  iterator insert(iterator position, const value_type& val);

  void insert(iterator position, size_type n, const value_type& val);

  template <class InputIterator>
  void insert(iterator position, InputIterator first, InputIterator last);

  iterator erase(iterator position);

  iterator erase(iterator first, iterator last);

  void swap(vector& x);

  void clear();

  allocator_type get_allocator() const;
};

}  // namespace ft

#endif  // VECTOR_HPP_
