// Copyright (c) 2022 Welton Leite, wleite. All rights reserved.

#ifndef ALLOCATOR_HPP_
#define ALLOCATOR_HPP_

#include <cstddef>

namespace ft {

template <typename T>
class allocator;

/// allocator<void> specialization.
template <>
class allocator<void> {
 public:
  typedef void value_type;
  typedef void* pointer;
  typedef const void* const_pointer;
  typedef size_t size_type;
  typedef ptrdiff_t difference_type;

  // rebind is for allocating memory for a type that differs
  // from the element type of the container being implemented.
  template <typename U>
  struct rebind {
    typedef allocator<U> other;
  };
};

template <typename T>
class allocator {
 public:
  typedef T value_type;
  typedef T* pointer;
  typedef const T* const_pointer;
  typedef T& reference;
  typedef const T& const_reference;
  typedef size_t size_type;
  typedef ptrdiff_t difference_type;

  // rebind is for allocating memory for a type that differs
  // from the element type of the container being implemented.
  template <typename U>
  struct rebind {
    typedef allocator<U> other;
  };

  // Constructs the default allocator.
  // Since the default allocator is stateless,
  // the constructors have no visible effect.
  allocator(void) {}

  allocator(const allocator& other) {}

  template <typename U>
  allocator(const allocator<U>& other) {}

  ~allocator(void) {}

  // Return the actual address of x.
  pointer address(reference x) const {
    return (&x);
  }

  // Return the actual address of x.
  const_pointer address(const_reference x) const {
    return (&x);
  }

  pointer allocate(size_type n,
                   typename std::allocator<void>::const_pointer = 0) {
    return (reinterpret_cast<pointer>(::operator new(n * sizeof(value_type))));
  }

  void deallocate(pointer p, size_type n) {
    (void)n;
    ::operator delete(p);
  }

  size_type max_size(void) const {
    return (size_t(__PTRDIFF_MAX__) / sizeof(value_type));
  }

  void construct(pointer p, const_reference val) {
    new (p) T(val);
  }

  void destroy(pointer p) {
    p->~T();
  }
};

template <typename T1, typename T2>
inline bool operator==(const allocator<T1>& lhs, const allocator<T2>& rhs) {
  return (true);
}

template <typename T1, typename T2>
inline bool operator!=(const allocator<T1>& lhs, const allocator<T2>& rhs) {
  return (false);
}

}  // namespace ft

#endif  // ALLOCATOR_HPP_
