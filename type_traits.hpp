// Copyright (c) 2022 Welton Leite, wleite. All rights reserved.

#ifndef TYPE_TRAITS_HPP_
#define TYPE_TRAITS_HPP_

namespace ft {

template <typename, bool>
struct enable_if {};

template <typename T>
struct enable_if<T, true> {
  typedef T type;
};

template <typename T>
struct is_integral {
  enum { value = 0 };
};

template <>
struct is_integral<bool> {
  enum { value = 1 };
};

template <>
struct is_integral<char> {
  enum { value = 1 };
};

template <>
struct is_integral<signed char> {
  enum { value = 1 };
};

template <>
struct is_integral<unsigned char> {
  enum { value = 1 };
};

template <>
struct is_integral<wchar_t> {
  enum { value = 1 };
};

template <>
struct is_integral<short> {
  enum { value = 1 };
};

template <>
struct is_integral<unsigned short> {
  enum { value = 1 };
};

template <>
struct is_integral<int> {
  enum { value = 1 };
};

template <>
struct is_integral<unsigned int> {
  enum { value = 1 };
};

template <>
struct is_integral<long> {
  enum { value = 1 };
};

template <>
struct is_integral<unsigned long> {
  enum { value = 1 };
};

template <>
struct is_integral<long long> {
  enum { value = 1 };
};

template <>
struct is_integral<unsigned long long> {
  enum { value = 1 };
};

}  // namespace ft

#endif  // TYPE_TRAITS_HPP_
