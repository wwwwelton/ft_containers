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
  {
    std::cout << "\n[ MAX_SIZE ]\n";
    ft::set<SET_T> FTset;

    if (FTset.max_size())
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }
  std::cout << "\n\n===========[ SET MODIFIERS ]===========\n";
  {
    std::cout << "\n[ INSERT VAL ]\n";
    ft::set<SET_T> FTset;
    std::set<SET_T> ORset;

    ft::pair<ft::set<SET_T>::iterator, bool> FTit;
    std::pair<std::set<SET_T>::iterator, bool> ORit;

    FTit = FTset.insert("a");
    ORit = ORset.insert("a");

    if ((*FTit.first == *ORit.first) && (FTit.second == ORit.second))
      std::cout << OK " ";
    else
      std::cout << KO " ";

    FTit = FTset.insert("a");
    ORit = ORset.insert("a");

    if ((*FTit.first == *ORit.first) && (FTit.second == ORit.second))
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }
  {
    std::cout << "\n[ INSERT POS ]\n";
    ft::set<SET_T> FTset;
    std::set<SET_T> ORset;

    ft::set<SET_T>::iterator FTit;
    std::set<SET_T>::iterator ORit;

    FTit = FTset.insert(FTset.begin(), "a");
    ORit = ORset.insert(ORset.begin(), "a");

    if (*FTit == *ORit)
      std::cout << OK " ";
    else
      std::cout << KO " ";

    FTit = FTset.insert(FTset.end(), "b");
    ORit = ORset.insert(ORset.end(), "b");

    if (*FTit == *ORit)
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }
  {
    std::cout << "\n[ INSERT RANGE ]\n";
    ft::set<SET_T> FTset_copy;
    ft::set<SET_T> FTset;

    FTset_copy.insert("a");
    FTset_copy.insert("b");
    FTset_copy.insert("c");
    FTset_copy.insert("d");

    FTset.insert(FTset_copy.begin(), FTset_copy.end());

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
    std::cout << "\n[ ERASE POS ]\n";
    ft::set<SET_T> FTset;
    std::set<SET_T> ORset;

    FTset.insert("a"), ORset.insert("a");
    FTset.insert("b"), ORset.insert("b");
    FTset.insert("c"), ORset.insert("c");
    FTset.insert("d"), ORset.insert("d");

    FTset.erase(FTset.begin());
    ORset.erase(ORset.begin());

    if (ft::equal(FTset.begin(), FTset.end(), ORset.begin()))
      std::cout << OK " ";
    else
      std::cout << KO " ";

    FTset.erase(FTset.begin());

    if (!ft::equal(FTset.begin(), FTset.end(), ORset.begin()))
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }
  {
    std::cout << "\n[ ERASE VALUE ]\n";
    ft::set<SET_T> FTset;
    std::set<SET_T> ORset;

    FTset.insert("a"), ORset.insert("a");
    FTset.insert("b"), ORset.insert("b");
    FTset.insert("c"), ORset.insert("c");
    FTset.insert("d"), ORset.insert("d");

    // print_set<FT_PRINT>(FTset);

    FTset.erase("a");
    ORset.erase("a");

    if (ft::equal(FTset.begin(), FTset.end(), ORset.begin()))
      std::cout << OK " ";
    else
      std::cout << KO " ";

    FTset.erase("b");
    ORset.erase("d");

    if (!ft::equal(FTset.begin(), FTset.end(), ORset.begin()))
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }
  {
    std::cout << "\n[ ERASE RANGE ]\n";
    ft::set<SET_T> FTset;
    std::set<SET_T> ORset;

    FTset.insert("a"), ORset.insert("a");
    FTset.insert("b"), ORset.insert("b");
    FTset.insert("c"), ORset.insert("c");
    FTset.insert("d"), ORset.insert("d");

    FTset.erase(++FTset.begin(), FTset.end());
    ORset.erase(++ORset.begin(), ORset.end());

    if (ft::equal(FTset.begin(), FTset.end(), ORset.begin()))
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }
  {
    std::cout << "\n[ SWAP ]\n";
    ft::set<SET_T> FTset_copy;
    std::set<SET_T> ORset_copy;
    ft::set<SET_T> FTset;
    std::set<SET_T> ORset;

    FTset_copy.insert("a"), ORset_copy.insert("a");
    FTset_copy.insert("b"), ORset_copy.insert("b");
    FTset_copy.insert("c"), ORset_copy.insert("c");
    FTset_copy.insert("d"), ORset_copy.insert("d");

    FTset.insert("e"), ORset.insert("e");
    FTset.insert("f"), ORset.insert("f");
    FTset.insert("g"), ORset.insert("g");
    FTset.insert("h"), ORset.insert("h");

    FTset.swap(FTset_copy);
    ORset.swap(ORset_copy);

    if (ft::equal(FTset_copy.begin(), FTset_copy.end(), ORset_copy.begin()))
      std::cout << OK " ";
    else
      std::cout << KO " ";

    if (ft::equal(FTset.begin(), FTset.end(), ORset.begin()))
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }
  {
    std::cout << "\n[ CLEAR ]\n";
    ft::set<SET_T> FTset;

    FTset.insert("a");
    FTset.insert("b");
    FTset.insert("c");
    FTset.insert("d");

    FTset.clear();

    if (FTset.begin() == FTset.end())
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }

  std::cout << "\n\n===========[ OBSERVERS ]===========\n";
  {
    std::cout << "\n[ KEY COMP ]\n";
    ft::set<SET_T> FTset_copy;
    ft::set<SET_T> FTset;

    ft::set<SET_T>::key_compare FTset_comp = FTset.key_comp();

    FTset.insert("a");
    FTset_copy.insert("b");

    if (FTset_comp(*FTset.begin(), *FTset_copy.begin()))
      std::cout << OK " ";
    else
      std::cout << KO " ";

    if (!FTset_comp(*FTset_copy.begin(), *FTset.begin()))
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }
  {
    std::cout << "\n[ VALUE COMP ]\n";
    ft::set<SET_T> FTset_copy;
    ft::set<SET_T> FTset;

    FTset.insert("a");
    FTset_copy.insert("b");

    if (FTset.value_comp()(*FTset.begin(), *FTset_copy.begin()))
      std::cout << OK " ";
    else
      std::cout << KO " ";

    if (!FTset.value_comp()(*FTset_copy.begin(), *FTset.begin()))
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }

  std::cout << "\n\n===========[ OPERATIONS ]===========\n";
  {
    std::cout << "\n[ FIND ]\n";
    ft::set<SET_T> FTset;

    FTset.insert("a");

    if (FTset.find("a") == FTset.begin())
      std::cout << OK " ";
    else
      std::cout << KO " ";

    if (FTset.find("b") == FTset.end())
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }
  {
    std::cout << "\n[ COUNT ]\n";
    ft::set<SET_T> FTset;

    FTset.insert("a");

    if (FTset.count("a") == 1)
      std::cout << OK " ";
    else
      std::cout << KO " ";

    if (FTset.count("b") == 0)
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }
  {
    std::cout << "\n[ LOWER BOUND ]\n";
    ft::set<SET_T> FTset;
    std::set<SET_T> ORset;

    FTset.insert("a"), ORset.insert("a");
    FTset.insert("b"), ORset.insert("b");
    FTset.insert("c"), ORset.insert("c");
    FTset.insert("d"), ORset.insert("d");

    ft::set<SET_T>::iterator FTit = FTset.lower_bound("b");
    std::set<SET_T>::iterator ORit = ORset.lower_bound("b");

    if (*FTit == *ORit)
      std::cout << OK " ";
    else
      std::cout << KO " ";

    FTit = FTset.lower_bound("z");
    ORit = ORset.lower_bound("z");

    if ((FTit == FTset.end()) && (ORit == ORset.end()))
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }
  {
    std::cout << "\n[ UPPER BOUND ]\n";
    ft::set<SET_T> FTset;
    std::set<SET_T> ORset;

    FTset.insert("a"), ORset.insert("a");
    FTset.insert("b"), ORset.insert("b");
    FTset.insert("c"), ORset.insert("c");
    FTset.insert("d"), ORset.insert("d");

    ft::set<SET_T>::iterator FTit = FTset.upper_bound("a");
    std::set<SET_T>::iterator ORit = ORset.upper_bound("a");

    if (*FTit == *ORit)
      std::cout << OK " ";
    else
      std::cout << KO " ";

    FTit = FTset.upper_bound("c");
    ORit = ORset.upper_bound("c");

    if (*FTit == *ORit)
      std::cout << OK " ";
    else
      std::cout << KO " ";

    FTit = FTset.upper_bound("z");
    ORit = ORset.upper_bound("z");

    if ((FTit == FTset.end()) && (ORit == ORset.end()))
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }
  {
    std::cout << "\n[ EQUAL RANGE ]\n";
    ft::set<SET_T> FTset;
    std::set<SET_T> ORset;

    FTset.insert("a"), ORset.insert("a");
    FTset.insert("b"), ORset.insert("b");
    FTset.insert("c"), ORset.insert("c");
    FTset.insert("d"), ORset.insert("d");

    ft::pair<ft::set<SET_T>::iterator, ft::set<SET_T>::iterator> FTPit;
    std::pair<std::set<SET_T>::iterator, std::set<SET_T>::iterator> ORPit;

    FTPit = FTset.equal_range("a");
    ORPit = ORset.equal_range("a");

    if ((*FTPit.first == *ORPit.first) && (*FTPit.second == *ORPit.second))
      std::cout << OK " ";
    else
      std::cout << KO " ";

    FTPit = FTset.equal_range("c");
    ORPit = ORset.equal_range("c");

    if ((*FTPit.first == *ORPit.first) && (*FTPit.second == *ORPit.second))
      std::cout << OK " ";
    else
      std::cout << KO " ";

    FTPit = FTset.equal_range("z");
    ORPit = ORset.equal_range("z");

    if ((*FTPit.first == *ORPit.first) && (*FTPit.second == *ORPit.second))
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }

  NEWLINE

  return (0);
}
