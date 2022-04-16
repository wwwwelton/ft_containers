// Copyright (c) 2022 Welton Leite, wleite. All rights reserved.

#ifndef VECTOR_HPP_
#define VECTOR_HPP_

#include <memory>
#include <stdexcept>

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
    _data = NULL;
    _size = 0;
    _capacity = 0;
    if (n > max_size()) {
      throw std::length_error("length_error");
    }
    _data = _alloc.allocate(n);
    if (_data == NULL) {
      throw std::bad_alloc();
    }
    for (size_t i = 0; i < n; i++) {
      _alloc.construct(_data + i, val);
      _size++;
    }
    _capacity = n;
  }

  template <class InputIterator>
  vector(InputIterator first, InputIterator last,
         const allocator_type& alloc = allocator_type()) {
    _alloc = alloc;
    _data = NULL;
    _size = 0;
    _capacity = 0;
    typedef typename ft::is_integral<InputIterator>::type Integral;
    initialize_dispatch(first, last, Integral());
  }

  template <typename Integer>
  void initialize_dispatch(Integer n, Integer value, true_type) {
    _data = _alloc.allocate(n);
    if (_data == NULL) {
      throw std::bad_alloc();
    }
    for (Integer i = 0; i < n; i++) {
      _alloc.construct(_data + i, value);
      _size++;
    }
    _capacity = n;
  }

  template <typename InputIterator>
  void initialize_dispatch(InputIterator first, InputIterator last, false_type) {
    _size = ft::distance(first, last);
    _capacity = _size;
    _data = _alloc.allocate(_size);
    if (_data == NULL) {
      throw std::bad_alloc();
    }
    std::uninitialized_copy(first, last, _data);
  }

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
    return (reverse_iterator(end()));
  }

  const_reverse_iterator rbegin() const {
    return (const_reverse_iterator(end()));
  }

  reverse_iterator rend() {
    return (reverse_iterator(begin()));
  }

  const_reverse_iterator rend() const {
    return (const_reverse_iterator(begin()));
  }

  size_type size() const {
    return (_size);
  }

  size_type max_size() const {
    return (_alloc.max_size());
  }

  void resize(size_type n, value_type val = value_type());

  size_type capacity() const {
    return (_capacity);
  }

  bool empty() const {
    return (begin() == end());
  }

  void reserve(size_type n) {
    if (n > _capacity) {
      if (n > max_size()) {
        throw std::length_error("length_error");
      }
      pointer tmp = _alloc.allocate(n);
      if (tmp == NULL) {
        throw std::bad_alloc();
      }
      for (size_t i = 0; i < _size; i++) {
        _alloc.construct(tmp + i, _data[i]);
      }
      for (size_t i = 0; i < _size; i++) {
        _alloc.destroy(_data + i);
      }
      _alloc.deallocate(_data, _capacity);
      _data = tmp;
      _capacity = n;
    }
  }

  reference operator[](size_type n) {
    return (*(begin() + n));
  }

  const_reference operator[](size_type n) const {
    return (*(begin() + n));
  }

  reference at(size_type n) {
    if (n < 0 || n >= _size) {
      throw std::out_of_range("out_of_range");
    }
    return (*(begin() + n));
  }

  const_reference at(size_type n) const {
    if (n < 0 || n >= _size) {
      throw std::out_of_range("out_of_range");
    }
    return (*(begin() + n));
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
  void assign(InputIterator first, InputIterator last) {
    typedef typename ft::is_integral<InputIterator>::type Integral;
    assign_dispatch(first, last, Integral());
  }

  template <typename Integer>
  void assign_dispatch(Integer n, Integer val, true_type) {
    for (size_t i = 0; i < _size; i++) {
      _alloc.destroy(&_data[i]);
    }
    _alloc.deallocate(_data, _capacity);
    if (static_cast<size_type>(n) > _capacity) {
      _capacity = n;
    }
    _data = _alloc.allocate(n);
    if (_data == NULL) {
      throw std::bad_alloc();
    }
    _size = n;
    for (size_t i = 0; i < _size; i++) {
      _alloc.construct(&_data[i], val);
    }
  }

  template <typename InputIterator>
  void assign_dispatch(InputIterator first, InputIterator last, false_type) {
    for (size_t i = 0; i < _size; i++) {
      _alloc.destroy(&_data[i]);
    }
    _alloc.deallocate(_data, _capacity);
    if (static_cast<size_type>(ft::distance(first, last)) > _capacity) {
      _capacity = ft::distance(first, last);
    }
    _data = _alloc.allocate(_capacity);
    if (_data == NULL) {
      throw std::bad_alloc();
    }
    _size = ft::distance(first, last);
    std::uninitialized_copy(first, last, _data);
  }

  void push_back(const value_type& val) {
    if (_size + 1 > _capacity) {
      _capacity ? _capacity *= 2 : 1;
      pointer tmp = _alloc.allocate(_capacity);
      if (tmp == NULL) {
        throw std::bad_alloc();
      }
      for (size_t i = 0; i < _size; i++) {
        _alloc.construct(tmp + i, _data[i]);
      }
      for (size_t i = 0; i < _size; i++) {
        _alloc.destroy(_data + i);
      }
      _alloc.deallocate(_data, _capacity);
      _data = tmp;
    }
    _alloc.construct(_data + _size, val);
    _size++;
  }

  void pop_back() {
    if (_size) {
      _alloc.destroy(_data + _size - 1);
      _size--;
    }
  }

  iterator insert(iterator position, const value_type& val) {
    std::cout << "insert 1\n";
    size_type distance = ft::distance(begin(), position);
    _size++;
    if (_capacity == 0) {
      reserve(1);
      _alloc.construct(&_data[distance], val);
      return (iterator(&_data[distance]));
    } else if (_size > _capacity) {
      reserve(_capacity * 2);
    }
    for (size_t i = _size; i > distance; i--) {
      _alloc.construct(&_data[i], _data[i - 1]);
    }
    _alloc.construct(&_data[distance], val);
    return (iterator(&_data[distance]));
  }

//   void insert(iterator position, size_type n, const value_type& val) {
//     std::cout << "insert 2\n";
//     size_type distance = ft::distance(begin(), position);
//     if (_capacity == 0) {
//       reserve(n);
//       _size = n;
//       for (size_t i = 0; i < n; i++) {
//         _alloc.construct(&_data[n + i], val);
//       }
//       return;
//     } else if (n > _size) {
//       reserve(_size + n);
//     } else {
//       reserve(_capacity * 2);
//     }
//     for (size_t i = _size; i > distance - 1; i--) {
//       _alloc.construct(&_data[i + n], _data[i]);
//     }
//     for (size_t i = 0; i < n; i++) {
//       _alloc.construct(&_data[i + distance], val);
//     }
//     _size += n;
//   }

//   template <class InputIterator>
//   void insert(iterator position, InputIterator first, InputIterator last) {
//     typedef typename ft::is_integral<InputIterator>::type Integral;
//     insert_dispatch(position, first, last, Integral());
//   }

//   template <class InputIterator>
//   void insert_dispatch(iterator position, size_type n, const value_type& val, true_type) {
//     std::cout << "insert 3\n";
//     size_type distance = ft::distance(begin(), position);
//     if (_capacity == 0) {
//       reserve(n);
//       _size = n;
//       for (size_t i = 0; i < n; i++) {
//         _alloc.construct(&_data[n + i], val);
//       }
//       return;
//     } else if (n > _size) {
//       reserve(_size + n);
//     } else {
//       reserve(_capacity * 2);
//     }
//     for (size_t i = _size; i > distance - 1; i--) {
//       _alloc.construct(&_data[i + n], _data[i]);
//     }
//     for (size_t i = 0; i < n; i++) {
//       _alloc.construct(&_data[i + distance], val);
//     }
//     _size += n;
//   }

//   template <class InputIterator>
//   void insert_dispatch(iterator position, InputIterator first, InputIterator last, false_type) {
//     std::cout << "insert 4\n";
//     size_type distance = ft::distance(begin(), position);
//     size_type n = last - first;
//     if (_capacity == 0) {
//       reserve(n);
//       _size = n;
//       for (size_t i = 0; i < n; i++)
//         _alloc.construct(&_data[distance + i], *first);
//       first++;
//       return;
//     } else if (n > _size)
//       reserve(_size + n);
//     else
//       reserve(_capacity * 2);
//     for (size_t i = _size; i > distance - 1; i--)
//       _alloc.construct(&_data[i + n], _data[i]);
//     for (size_t i = 0; i < n; i++) {
//       _alloc.construct(&_data[i + distance], *first);
//       first++;
//     }
//     _size += n;
//   }

  iterator erase(iterator position) {
    iterator it(position);
    while (position != (end() - 1)) {
      *position = *(position + 1);
      position++;
    }
    --_size;
    _alloc.destroy(_data + _size);
    return (it);
  }

  iterator erase(iterator first, iterator last) {
    iterator it(first);
    while (last != end()) {
      *first = *last;
      ++first;
      ++last;
    }
    _size -= ft::distance(first, last);
    for (size_t i = ft::distance(first, last); i > _size; i--) {
      _alloc.destroy(_data + i);
    }
    return (it);
  }

  void swap(vector& x) {
    pointer tmp_data = x._data;
    size_type tmp_capacity = x._capacity;
    size_type tmp_size = x._size;

    x._data = _data;
    x._capacity = _capacity;
    x._size = _size;

    _data = tmp_data;
    _capacity = tmp_capacity;
    _size = tmp_size;
  }

  void clear() {
    erase(begin(), end());
  }

  allocator_type get_allocator() const {
    return (_alloc);
  }
};

template <class T, class Alloc>
void swap(vector<T, Alloc>& x, vector<T, Alloc>& y) {
  x.swap(y);
}

}  // namespace ft

#endif  // VECTOR_HPP_
