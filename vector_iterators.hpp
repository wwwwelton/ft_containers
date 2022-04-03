// Copyright (c) 2022 Welton Leite, wleite. All rights reserved.

#ifndef VECTOR_ITERATORS_HPP_
#define VECTOR_ITERATORS_HPP_

#include <cstddef>
#include <memory>

namespace ft {

#define vector_iterator_class vector_iterator<T, Category, Distance, Pointer, Reference>
#define vector_iterator_typenames typename T, class Category, typename Distance, typename Pointer, typename Reference

template <typename T, class Category = std::random_access_iterator_tag, typename Distance = std::ptrdiff_t, typename Pointer = T*, typename Reference = T&>
class vector_iterator {
 public:
  typedef vector_iterator<T, T*, T&> iterator;
  typedef vector_iterator<T, const T*, const T&> const_iterator;
  typedef T value_type;
  typedef Pointer pointer;
  typedef Reference reference;
  typedef size_t size_type;
  typedef ptrdiff_t difference_type;
  typedef Category iterator_category;

  vector_iterator(void);
  explicit vector_iterator(const pointer current);
  explicit vector_iterator(const iterator& src);
  ~vector_iterator(void);

  vector_iterator_class& operator=(const iterator& rhs);

  bool operator>(const iterator& rhs);
  bool operator<(const iterator& rhs);
  bool operator>=(const iterator& rhs);
  bool operator<=(const iterator& rhs);
  bool operator==(const iterator& rhs);
  bool operator!=(const iterator& rhs);

  iterator operator+(difference_type n);
  iterator operator-(difference_type n);

  iterator& operator++(void);  // Prefix increment operator.
  iterator operator++(int);    // Postfix increment operator.
  iterator& operator--(void);  // Prefix decrement operator.
  iterator operator--(int);    // Postfix decrement operator.

  pointer _current;
};

}  // namespace ft

#include "vector_iterators.tpp"

#endif  // VECTOR_ITERATORS_HPP_
