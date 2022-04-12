// Copyright (c) 2022 Welton Leite, wleite. All rights reserved.

#ifndef ITERATOR_REVERSE_HPP_
#define ITERATOR_REVERSE_HPP_

#include "./iterator_traits.hpp"

namespace ft {

template <typename Iterator>
class reverse_iterator
    : public iterator<typename iterator_traits<Iterator>::iterator_category,
                      typename iterator_traits<Iterator>::value_type,
                      typename iterator_traits<Iterator>::difference_type,
                      typename iterator_traits<Iterator>::pointer,
                      typename iterator_traits<Iterator>::reference> {
 protected:
  Iterator current;

 public:
  typedef Iterator iterator_type;
  typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
  typedef typename iterator_traits<Iterator>::value_type value_type;
  typedef typename iterator_traits<Iterator>::difference_type difference_type;
  typedef typename iterator_traits<Iterator>::pointer pointer;
  typedef typename iterator_traits<Iterator>::reference reference;

 public:
  reverse_iterator() : current() {}
  explicit reverse_iterator(iterator_type x) : current(x) {}
  reverse_iterator(const reverse_iterator& x) : current(x.current) {}
  template <typename Iter>
  reverse_iterator(const reverse_iterator<Iter>& x) : current(x.base()) {}
  ~reverse_iterator() {}

  template <typename Iter>
  reverse_iterator& operator=(const reverse_iterator<Iter>& x) {
    current = x.base();
    return (*this);
  }

  iterator_type base() const {
    return (current);
  }

  reference operator*() const {
    Iterator tmp = current;
    return (*--tmp);
  }

  reverse_iterator operator+(difference_type n) const {
    return (reverse_iterator(current - n));
  }

  reverse_iterator& operator++() {
    --current;
    return (*this);
  }

  reverse_iterator operator++(int) {
    reverse_iterator tmp = *this;
    --current;
    return (tmp);
  }

  reverse_iterator& operator+=(difference_type n) {
    current -= n;
    return (*this);
  }

    reverse_iterator operator-(difference_type n) const {
    return (reverse_iterator(current + n));
  }

  reverse_iterator& operator--() {
    ++current;
    return (*this);
  }

  reverse_iterator operator--(int) {
    reverse_iterator tmp = *this;
    ++current;
    return (tmp);
  }

  reverse_iterator& operator-=(difference_type n) {
    current += n;
    return (*this);
  }

  pointer operator->() const {
    Iterator tmp = current;
    return (&--tmp);
  }

  reference operator[](difference_type n) const {
    return (*(*this + n));
  }
};

template <typename IteratorL, typename IteratorR>
inline bool operator==(const reverse_iterator<IteratorL>& x,
                       const reverse_iterator<IteratorR>& y) {
  return (x.base() == y.base());
}

template <typename Iterator>
inline bool operator==(const reverse_iterator<Iterator>& x,
                       const reverse_iterator<Iterator>& y) {
  return (x.base() == y.base());
}

template <typename IteratorL, typename IteratorR>
inline bool operator!=(const reverse_iterator<IteratorL>& x,
                       const reverse_iterator<IteratorR>& y) {
  return (!(x == y));
}

template <typename Iterator>
inline bool operator!=(const reverse_iterator<Iterator>& x,
                       const reverse_iterator<Iterator>& y) {
  return (!(x == y));
}

template <typename IteratorL, typename IteratorR>
inline bool operator<(const reverse_iterator<IteratorL>& x,
                      const reverse_iterator<IteratorR>& y) {
  return (y.base() < x.base());
}

template <typename Iterator>
inline bool operator<(const reverse_iterator<Iterator>& x,
                      const reverse_iterator<Iterator>& y) {
  return (y.base() < x.base());
}

template <typename IteratorL, typename IteratorR>
inline bool operator<=(const reverse_iterator<IteratorL>& x,
                       const reverse_iterator<IteratorR>& y) {
  return (!(y < x));
}

template <typename Iterator>
inline bool operator<=(const reverse_iterator<Iterator>& x,
                       const reverse_iterator<Iterator>& y) {
  return (!(y < x));
}

template <typename IteratorL, typename IteratorR>
inline bool operator>(const reverse_iterator<IteratorL>& x,
                      const reverse_iterator<IteratorR>& y) {
  return (y < x);
}

template <typename Iterator>
inline bool operator>(const reverse_iterator<Iterator>& x,
                      const reverse_iterator<Iterator>& y) {
  return (y < x);
}

template <typename IteratorL, typename IteratorR>
inline bool operator>=(const reverse_iterator<IteratorL>& x,
                       const reverse_iterator<IteratorR>& y) {
  return (!(x < y));
}

template <typename Iterator>
inline bool operator>=(const reverse_iterator<Iterator>& x,
                       const reverse_iterator<Iterator>& y) {
  return (!(x < y));
}

template <typename Iterator>
inline reverse_iterator<Iterator>
operator+(typename reverse_iterator<Iterator>::difference_type n,
          const reverse_iterator<Iterator>& x) {
  return (reverse_iterator<Iterator>(x.base() - n));
}

template <typename Iterator>
inline typename reverse_iterator<Iterator>::difference_type
operator-(const reverse_iterator<Iterator>& x,
          const reverse_iterator<Iterator>& y) {
  return (y.base() - x.base());
}

}  // namespace ft

#endif  // ITERATOR_REVERSE_HPP_
