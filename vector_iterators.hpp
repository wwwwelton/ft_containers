// Copyright (c) 2022 Welton Leite, wleite. All rights reserved.

#ifndef VECTOR_ITERATORS_HPP_
#define VECTOR_ITERATORS_HPP_

#include <cstddef>
#include <memory>

namespace ft {

template <
    typename T,
    class Category = std::random_access_iterator_tag,
    typename Distance = std::ptrdiff_t,
    typename Pointer = T*,
    typename Reference = T&>
class vector_iterator {
 public:
  typedef vector_iterator<T, Category, Distance, T*, T&> iterator_type;
  typedef vector_iterator<T, T*, T&> iterator;
  typedef vector_iterator<T, const T*, const T&> const_iterator;
  typedef T value_type;
  typedef Pointer pointer;
  typedef Reference reference;
  typedef size_t size_type;
  typedef ptrdiff_t difference_type;
  typedef Category iterator_category;

  vector_iterator(void);
  explicit vector_iterator(const pointer elem);
  explicit vector_iterator(const iterator& x);
  ~vector_iterator(void);

 private:
  pointer _current;
};

}  // namespace ft

#endif  // VECTOR_ITERATORS_HPP_
