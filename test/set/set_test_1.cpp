// Copyright (c) 2022 Welton Leite, wleite. All rights reserved.

#include <iostream>

template <typename T>
void print(const T& x) {
  std::cout << std::endl;
  std::cout << "===============" << std::endl;
  std::cout << x << std::endl;
  std::cout << "===============" << std::endl;
}

template <typename T>
void print_set(T& set) {
  for (typename T::iterator it = set.begin(); it != set.end(); it++) {
    std::cout << "[" << *it << "]"
              << " ";
  }
  std::cout << std::endl;
}

#define KO "\033[1;31mKO\033[0m"
#define OK "\033[1;32mOK\033[0m"

#define NEWLINE std::cout << "\n";

#define KEY_VALUE std::string
#define SET_T KEY_VALUE

#define FT_PRINT ft::set<SET_T>
#define OR_PRINT std::set<SET_T>

#include <set>

#include "../../algorithm.hpp"
#include "../../set.hpp"

int main(void) {
  std::cout << "\n===========[ CONSTRUCTORS ]===========\n";
  {
    std::cout << "\n[ CONSTRUCTOR VOID ]\n";
    ft::set<SET_T> FTset;

    ft::set<SET_T>::iterator FTit = FTset.begin();
    ft::set<SET_T>::iterator FTite = FTset.end();

    if ((*FTit == "") && (*FTite == "") && (FTit == FTite))
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }
  {
    std::cout << "\n[ CONSTRUCTOR RANGE ]\n";
    ft::set<SET_T> FTset_copy;

    FTset_copy.insert("a");
    FTset_copy.insert("b");
    FTset_copy.insert("c");
    FTset_copy.insert("d");

    ft::set<SET_T> FTset(FTset_copy.begin(), FTset_copy.end());

    if (ft::equal(FTset.begin(), FTset.end(), FTset_copy.begin()))
      std::cout << OK " ";
    else
      std::cout << KO " ";

    FTset.insert("e");

    if (!ft::equal(FTset.begin(), FTset.end(), FTset_copy.begin()))
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }
  {
    std::cout << "\n[ CONSTRUCTOR COPY ]\n";
    ft::set<SET_T> FTset_copy;

    FTset_copy.insert("a");
    FTset_copy.insert("b");
    FTset_copy.insert("c");
    FTset_copy.insert("d");

    ft::set<SET_T> FTset(FTset_copy);

    if (ft::equal(FTset.begin(), FTset.end(), FTset_copy.begin()))
      std::cout << OK " ";
    else
      std::cout << KO " ";

    FTset.insert("e");

    if (!ft::equal(FTset.begin(), FTset.end(), FTset_copy.begin()))
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }
  {
    std::cout << "\n[ ASSIGNMENT OPERATOR (=) ]\n";
    ft::set<SET_T> FTset_copy;

    FTset_copy.insert("a");
    FTset_copy.insert("b");
    FTset_copy.insert("c");
    FTset_copy.insert("d");

    ft::set<SET_T> FTset = FTset_copy;

    if (ft::equal(FTset.begin(), FTset.end(), FTset_copy.begin()))
      std::cout << OK " ";
    else
      std::cout << KO " ";

    FTset.insert("e");

    if (!ft::equal(FTset.begin(), FTset.end(), FTset_copy.begin()))
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }

  std::cout << "\n\n===========[ ITERATORS ]===========\n";
  {
    std::cout << "\n[ BEGIN ]\n";
    ft::set<SET_T> FTset;
    std::set<SET_T> ORset;

    FTset.insert("a"), ORset.insert("a");
    FTset.insert("b"), ORset.insert("b");
    FTset.insert("c"), ORset.insert("c");
    FTset.insert("d"), ORset.insert("d");

    ft::set<SET_T>::iterator FTit = FTset.begin();
    std::set<SET_T>::iterator ORit = ORset.begin();
    ft::set<SET_T>::const_iterator FTitC = FTset.begin();
    std::set<SET_T>::const_iterator ORitC = ORset.begin();

    if (*FTit == *ORit)
      std::cout << OK " ";
    else
      std::cout << KO " ";

    if (*FTitC == *ORitC)
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }
  {
    std::cout << "\n[ END ]\n";
    ft::set<SET_T> FTset;
    std::set<SET_T> ORset;

    FTset.insert("a"), ORset.insert("a");
    FTset.insert("b"), ORset.insert("b");
    FTset.insert("c"), ORset.insert("c");
    FTset.insert("d"), ORset.insert("d");

    ft::set<SET_T>::iterator FTit = --FTset.end();
    std::set<SET_T>::iterator ORit = --ORset.end();
    ft::set<SET_T>::const_iterator FTitC = --FTset.end();
    std::set<SET_T>::const_iterator ORitC = --ORset.end();

    if (*FTit == *ORit)
      std::cout << OK " ";
    else
      std::cout << KO " ";

    if (*FTitC == *ORitC)
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }
  {
    std::cout << "\n[ RBEGIN ]\n";
    ft::set<SET_T> FTset;
    std::set<SET_T> ORset;

    FTset.insert("a"), ORset.insert("a");
    FTset.insert("b"), ORset.insert("b");
    FTset.insert("c"), ORset.insert("c");
    FTset.insert("d"), ORset.insert("d");

    ft::set<SET_T>::reverse_iterator FTitR = FTset.rbegin();
    std::set<SET_T>::reverse_iterator ORitR = ORset.rbegin();
    ft::set<SET_T>::const_reverse_iterator FTitCR = FTset.rbegin();
    std::set<SET_T>::const_reverse_iterator ORitCR = ORset.rbegin();

    if (*FTitR == *ORitR)
      std::cout << OK " ";
    else
      std::cout << KO " ";

    if (*FTitCR == *ORitCR)
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }
  {
    std::cout << "\n[ REND ]\n";
    ft::set<SET_T> FTset;
    std::set<SET_T> ORset;

    FTset.insert("a"), ORset.insert("a");
    FTset.insert("b"), ORset.insert("b");
    FTset.insert("c"), ORset.insert("c");
    FTset.insert("d"), ORset.insert("d");

    ft::set<SET_T>::reverse_iterator FTitR = --FTset.rend();
    std::set<SET_T>::reverse_iterator ORitR = --ORset.rend();
    ft::set<SET_T>::const_reverse_iterator FTitCR = --FTset.rend();
    std::set<SET_T>::const_reverse_iterator ORitCR = --ORset.rend();

    if (*FTitR == *ORitR)
      std::cout << OK " ";
    else
      std::cout << KO " ";

    if (*FTitCR == *ORitCR)
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }

  std::cout << "\n\n===========[ CAPACITY ]===========\n";
  {
    std::cout << "\n[ EMPTY ]\n";
    ft::set<SET_T> FTset;
    std::set<SET_T> ORset;

    if (FTset.empty() == ORset.empty())
      std::cout << OK " ";
    else
      std::cout << KO " ";

    FTset.insert("a"), ORset.insert("a");
    FTset.insert("b"), ORset.insert("b");
    FTset.insert("c"), ORset.insert("c");
    FTset.insert("d"), ORset.insert("d");

    if (FTset.empty() == ORset.empty())
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }
  {
    std::cout << "\n[ SIZE ]\n";
    ft::set<SET_T> FTset;
    std::set<SET_T> ORset;

    if (FTset.size() == ORset.size())
      std::cout << OK " ";
    else
      std::cout << KO " ";

    FTset.insert("a"), ORset.insert("a");
    FTset.insert("b"), ORset.insert("b");
    FTset.insert("c"), ORset.insert("c");
    FTset.insert("d"), ORset.insert("d");

    if (FTset.size() == ORset.size())
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }

  NEWLINE

  return (0);
}
