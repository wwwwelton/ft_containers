// Copyright (c) 2022 Welton Leite, wleite. All rights reserved.

#include <iostream>

#define NEWLINE std::cout << "\n";
#define VALUE std::string

#if STD == 1
#include <set>
namespace ft = std;
#else
#include "../../algorithm.hpp"
#include "../../set.hpp"
#endif

#define SET_T VALUE
#define PRINT ft::set<SET_T>

template <typename T>
void print(const T& x) {
  std::cout << x << " ";
  std::cout << std::endl;
}

template <typename T>
void print_map(T& set) {
  for (typename T::iterator it = set.begin(); it != set.end(); it++) {
    std::cout << "[" << *it << "]"
              << " ";
  }
  std::cout << std::endl;
  std::cout << "size: " << set.size() << std::endl;
}

int main(void) {
  std::cout << "\n===========[ CONSTRUCTORS ]===========\n";
  {
    std::cout << "\n[ CONSTRUCTOR VOID ]\n";
    ft::set<SET_T> FTset;

    print_map<PRINT>(FTset);
  }
  {
    std::cout << "\n[ CONSTRUCTOR RANGE ]\n";
    ft::set<SET_T> FTset_copy;

    FTset_copy.insert("a");
    FTset_copy.insert("b");
    FTset_copy.insert("c");
    FTset_copy.insert("d");

    ft::set<SET_T> FTset(FTset_copy.begin(), FTset_copy.end());

    print_map<PRINT>(FTset);

    FTset.insert("e");

    print_map<PRINT>(FTset);
  }
  {
    std::cout << "\n[ CONSTRUCTOR COPY ]\n";
    ft::set<SET_T> FTset_copy;

    FTset_copy.insert("a");
    FTset_copy.insert("b");
    FTset_copy.insert("c");
    FTset_copy.insert("d");

    ft::set<SET_T> FTset(FTset_copy);

    print_map<PRINT>(FTset);

    FTset.insert("e");

    print_map<PRINT>(FTset);
  }
  {
    std::cout << "\n[ ASSIGNMENT OPERATOR (=) ]\n";
    ft::set<SET_T> FTset_copy;

    FTset_copy.insert("a");
    FTset_copy.insert("b");
    FTset_copy.insert("c");
    FTset_copy.insert("d");

    ft::set<SET_T> FTset = FTset_copy;

    print_map<PRINT>(FTset);

    FTset.insert("e");

    print_map<PRINT>(FTset);
  }

  std::cout << "\n\n===========[ ITERATORS ]===========\n";
  {
    std::cout << "\n[ BEGIN ]\n";
    ft::set<SET_T> FTset;

    FTset.insert("a");
    FTset.insert("b");
    FTset.insert("c");
    FTset.insert("d");

    ft::set<SET_T> const FTsetC(FTset);

    ft::set<SET_T>::iterator FTit = FTset.begin();
    ft::set<SET_T>::const_iterator FTitC = FTsetC.begin();
    ft::set<SET_T>::iterator FTitE = FTset.end();
    ft::set<SET_T>::const_iterator FTitCE = FTsetC.end();

    while (FTit != FTitE) {
      std::cout << "[" << *FTit << "]"
                << " ";
      FTit++;
    }

    while (FTitC != FTitCE) {
      std::cout << "[" << *FTitC << "]"
                << " ";
      FTitC++;
    }
  }
  {
    std::cout << "\n[ END ]\n";
    ft::set<SET_T> FTset;

    FTset.insert("a");
    FTset.insert("b");
    FTset.insert("c");
    FTset.insert("d");

    ft::set<SET_T> const FTsetC(FTset);

    ft::set<SET_T>::iterator FTit = FTset.begin();
    ft::set<SET_T>::const_iterator FTitC = FTsetC.begin();
    ft::set<SET_T>::iterator FTitE = FTset.end();
    ft::set<SET_T>::const_iterator FTitCE = FTsetC.end();

    while (FTit != FTitE) {
      std::cout << "[" << *FTit << "]"
                << " ";
      FTit++;
    }

    while (FTitC != FTitCE) {
      std::cout << "[" << *FTitC << "]"
                << " ";
      FTitC++;
    }
  }
  {
    std::cout << "\n[ RBEGIN ]\n";
    ft::set<SET_T> FTset;

    FTset.insert("a");
    FTset.insert("b");
    FTset.insert("c");
    FTset.insert("d");

    ft::set<SET_T> const FTsetC(FTset);

    ft::set<SET_T>::reverse_iterator FTitR = FTset.rbegin();
    ft::set<SET_T>::const_reverse_iterator FTitCR = FTset.rbegin();
    ft::set<SET_T>::reverse_iterator FTitRE = --FTset.rend();
    ft::set<SET_T>::const_reverse_iterator FTitCRE = --FTset.rend();

    while (FTitRE != FTitR) {
      std::cout << "[" << *FTitRE << "]"
                << " ";
      FTitRE--;
    }

    while (FTitCRE != FTitCR) {
      std::cout << "[" << *FTitCRE << "]"
                << " ";
      FTitCRE--;
    }
  }
  {
    std::cout << "\n[ REND ]\n";
    ft::set<SET_T> FTset;

    FTset.insert("a");
    FTset.insert("b");
    FTset.insert("c");
    FTset.insert("d");

    ft::set<SET_T> const FTsetC(FTset);

    ft::set<SET_T>::reverse_iterator FTitR = FTset.rbegin();
    ft::set<SET_T>::const_reverse_iterator FTitCR = FTset.rbegin();
    ft::set<SET_T>::reverse_iterator FTitRE = --FTset.rend();
    ft::set<SET_T>::const_reverse_iterator FTitCRE = --FTset.rend();

    while (FTitRE != FTitR) {
      std::cout << "[" << *FTitRE << "]"
                << " ";
      FTitRE--;
    }

    while (FTitCRE != FTitCR) {
      std::cout << "[" << *FTitCRE << "]"
                << " ";
      FTitCRE--;
    }
  }

  std::cout << "\n\n===========[ CAPACITY ]===========\n";
  {
    {
      std::cout << "\n[ EMPTY ]\n";
      ft::set<SET_T> FTset;

      print(FTset.empty());

      FTset.insert("a");

      print(FTset.empty());
    }
    {
      std::cout << "\n[ SIZE ]\n";
      ft::set<SET_T> FTset;
      ft::set<SET_T> FTset_copy;

      FTset_copy.insert("a");
      FTset_copy.insert("b");
      FTset_copy.insert("c");
      FTset_copy.insert("d");

      print(FTset.size());
      print(FTset_copy.size());
    }

    std::cout << "\n\n===========[ SET MODIFIERS ]===========\n";
    {
      std::cout << "\n[ INSERT VAL ]\n";
      ft::set<SET_T> FTset;

      FTset.insert("a");
      FTset.insert("b");
      FTset.insert("c");
      FTset.insert("d");

      print_map<PRINT>(FTset);

      FTset.insert("a");

      print_map<PRINT>(FTset);
    }
    {
      std::cout << "\n[ INSERT POS ]\n";
      ft::set<SET_T> FTset;

      FTset.insert("a");
      FTset.insert("b");
      FTset.insert("c");
      FTset.insert("d");

      print_map<PRINT>(FTset);

      FTset.insert(FTset.end(), "b");

      print_map<PRINT>(FTset);
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

      print_map<PRINT>(FTset);
    }
    {
      std::cout << "\n[ ERASE POS ]\n";
      ft::set<SET_T> FTset;

      FTset.insert("a");
      FTset.insert("b");
      FTset.insert("c");
      FTset.insert("d");

      print_map<PRINT>(FTset);

      FTset.erase(FTset.begin());

      print_map<PRINT>(FTset);
    }
    {
      std::cout << "\n[ ERASE VALUE ]\n";
      ft::set<SET_T> FTset;

      FTset.insert("a");
      FTset.insert("b");
      FTset.insert("c");
      FTset.insert("d");

      print_map<PRINT>(FTset);

      FTset.erase("a");

      print_map<PRINT>(FTset);
    }
    {
      std::cout << "\n[ ERASE RANGE ]\n";
      ft::set<SET_T> FTset;

      FTset.insert("a");
      FTset.insert("b");
      FTset.insert("c");
      FTset.insert("d");

      print_map<PRINT>(FTset);

      FTset.erase(++FTset.begin(), FTset.end());

      print_map<PRINT>(FTset);
    }
    {
      std::cout << "\n[ SWAP ]\n";
      ft::set<SET_T> FTset_copy;
      ft::set<SET_T> FTset;

      FTset_copy.insert("a");
      FTset_copy.insert("b");
      FTset_copy.insert("c");
      FTset_copy.insert("d");

      FTset.insert("e");
      FTset.insert("f");
      FTset.insert("g");
      FTset.insert("h");

      print_map<PRINT>(FTset_copy);
      print_map<PRINT>(FTset);

      FTset.swap(FTset_copy);

      print_map<PRINT>(FTset_copy);
      print_map<PRINT>(FTset);
    }
    {
      std::cout << "\n[ CLEAR ]\n";
      ft::set<SET_T> FTset;

      FTset.insert("a");
      FTset.insert("b");
      FTset.insert("c");
      FTset.insert("d");

      print_map<PRINT>(FTset);

      FTset.clear();

      print_map<PRINT>(FTset);
    }

    std::cout << "\n\n===========[ OBSERVERS ]===========\n";
    {
      std::cout << "\n[ KEY COMP ]\n";
      ft::set<SET_T> FTset_copy;
      ft::set<SET_T> FTset;

      ft::set<SET_T>::key_compare FTset_comp = FTset.key_comp();

      FTset.insert("a");
      FTset_copy.insert("b");

      print(FTset_comp(*FTset.begin(), *FTset_copy.begin()));
    }
    {
      std::cout << "\n[ VALUE COMP ]\n";
      ft::set<SET_T> FTset_copy;
      ft::set<SET_T> FTset;

      FTset.insert("a");
      FTset_copy.insert("b");

      print(FTset.value_comp()(*FTset.begin(), *FTset_copy.begin()));
    }

    std::cout << "\n\n===========[ OPERATIONS ]===========\n";
    {
      std::cout << "\n[ FIND ]\n";
      ft::set<SET_T> FTset;

      FTset.insert("a");

      print(FTset.find("a") == FTset.begin());
      print(FTset.find("b") == FTset.end());
    }
    {
      std::cout << "\n[ COUNT ]\n";
      ft::set<SET_T> FTset;

      FTset.insert("a");

      print(FTset.count("a") == 1);
      print(FTset.count("b") == 0);
    }
    {
      std::cout << "\n[ LOWER BOUND ]\n";
      ft::set<SET_T> FTset;

      FTset.insert("a");
      FTset.insert("b");
      FTset.insert("c");
      FTset.insert("d");

      print(*FTset.lower_bound("b"));
    }
    {
      std::cout << "\n[ UPPER BOUND ]\n";
      ft::set<SET_T> FTset;

      FTset.insert("a");
      FTset.insert("b");
      FTset.insert("c");
      FTset.insert("d");

      print(*FTset.lower_bound("c"));
    }
    {
      std::cout << "\n[ EQUAL RANGE ]\n";
      ft::set<SET_T> FTset;

      FTset.insert("a");
      FTset.insert("b");
      FTset.insert("c");
      FTset.insert("d");

      ft::pair<ft::set<SET_T>::iterator, ft::set<SET_T>::iterator> FTPit;

      FTPit = FTset.equal_range("a");

      print(*FTPit.first);
      print(*FTPit.second);

      FTPit = FTset.equal_range("c");

      print(*FTPit.first);
      print(*FTPit.second);
    }

    std::cout << "\n\n===========[ ALLOCATOR ]===========\n";
    {
      std::cout << "\n[ GET_ALLOCATOR ]\n";
      ft::set<SET_T> FTset_copy;

      FTset_copy.insert("a");
      FTset_copy.insert("b");
      FTset_copy.insert("c");
      FTset_copy.insert("d");

      ft::set<SET_T> FTset(FTset_copy.key_comp(), FTset_copy.get_allocator());

      FTset.insert("a");
      FTset.insert("b");
      FTset.insert("c");
      FTset.insert("d");

      print_map<PRINT>(FTset);
    }

    std::cout << "\n\n===========[ RELATIONAL OPERATORS ]===========\n";
    {
      std::cout << "\n[ EQUAL (==) ]\n";
      ft::set<SET_T> FTset_copy;
      ft::set<SET_T> FTset;

      FTset_copy.insert("a"), FTset.insert("a");
      FTset_copy.insert("b"), FTset.insert("b");
      FTset_copy.insert("c"), FTset.insert("c");
      FTset_copy.insert("d"), FTset.insert("d");

      print(FTset == FTset_copy);

      FTset_copy.insert("e"), FTset.insert("f");

      print(FTset == FTset_copy);
    }
    {
      std::cout << "\n[ DIFFERENT (!=) ]\n";
      ft::set<SET_T> FTset_copy;
      ft::set<SET_T> FTset;

      FTset_copy.insert("a"), FTset.insert("a");
      FTset_copy.insert("b"), FTset.insert("b");
      FTset_copy.insert("c"), FTset.insert("c");
      FTset_copy.insert("d"), FTset.insert("e");

      print(FTset == FTset_copy);

      FTset_copy.insert("e"), FTset.insert("d");

      print(FTset == FTset_copy);
    }
    {
      std::cout << "\n[ MINOR (<) ]\n";
      ft::set<SET_T> FTset_copy;
      ft::set<SET_T> FTset;

      FTset_copy.insert("a"), FTset.insert("a");
      FTset_copy.insert("b"), FTset.insert("b");
      FTset_copy.insert("c"), FTset.insert("c");
      FTset_copy.insert("d");

      print(FTset < FTset_copy);

      FTset.insert("d");

      print(FTset < FTset_copy);
    }
    {
      std::cout << "\n[ MINOR OR EQUAL (<=) ]\n";
      ft::set<SET_T> FTset_copy;
      ft::set<SET_T> FTset;

      FTset_copy.insert("a"), FTset.insert("a");
      FTset_copy.insert("b"), FTset.insert("b");
      FTset_copy.insert("c"), FTset.insert("c");
      FTset_copy.insert("d");

      print(FTset <= FTset_copy);

      FTset.insert("e");

      print(FTset <= FTset_copy);
    }
    {
      std::cout << "\n[ GREATER (>) ]\n";
      ft::set<SET_T> FTset_copy;
      ft::set<SET_T> FTset;

      FTset_copy.insert("a"), FTset.insert("a");
      FTset_copy.insert("b"), FTset.insert("b");
      FTset_copy.insert("c"), FTset.insert("c");
      FTset_copy.insert("d");

      print(FTset > FTset_copy);

      FTset.insert("e");

      print(FTset > FTset_copy);
    }
    {
      std::cout << "\n[ GREATER OR EQUAL (>=) ]\n";
      ft::set<SET_T> FTset_copy;
      ft::set<SET_T> FTset;

      FTset_copy.insert("a"), FTset.insert("a");
      FTset_copy.insert("b"), FTset.insert("b");
      FTset_copy.insert("c"), FTset.insert("c");
      FTset_copy.insert("d");

      print(FTset >= FTset_copy);

      FTset.insert("e");

      print(FTset >= FTset_copy);
    }

    NEWLINE

    return (0);
  }
}
