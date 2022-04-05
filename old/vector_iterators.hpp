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
  typedef Category iterator_category;
  typedef T value_type;
  typedef ptrdiff_t difference_type;
  typedef size_t size_type;
  typedef Pointer pointer;
  typedef Reference reference;

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

  vector_iterator_class operator+(difference_type n) const;
  vector_iterator_class operator-(difference_type n) const;

  vector_iterator_class& operator+=(difference_type n);
  vector_iterator_class& operator-=(difference_type n);

  vector_iterator_class& operator++(void);  // Prefix increment operator.
  vector_iterator_class operator++(int);    // Postfix increment operator.
  vector_iterator_class& operator--(void);  // Prefix decrement operator.
  vector_iterator_class operator--(int);    // Postfix decrement operator.

  reference operator*(void);
  pointer operator->(void);
  reference operator[](difference_type n);

  pointer _current;
};

}  // namespace ft

#include "vector_iterators.tpp"

#endif  // VECTOR_ITERATORS_HPP_
