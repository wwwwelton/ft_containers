// Copyright (c) 2022 Welton Leite, wleite. All rights reserved.

#include <iostream>

#define NEWLINE std::cout << "\n";
#define KEY std::string
#define VALUE int

#if STD == 1
#include <map>
namespace ft = std;
#else
#include "../../algorithm.hpp"
#include "../../map.hpp"
#endif

#define TYPE ft::pair<KEY, VALUE>
#define MAP_T KEY, VALUE
#define PRINT ft::map<MAP_T>

template <typename T>
void print(const T& x) {
  std::cout << x << " ";
  std::cout << std::endl;
}

template <typename T>
void print_map(T& map) {
  for (typename T::iterator it = map.begin(); it != map.end(); it++) {
    std::cout << "[" << it->first << "]"
              << "(" << it->second << ")"
              << " ";
  }
  std::cout << std::endl;
  std::cout << "size: " << map.size() << std::endl;
}

int main(void) {
  std::cout << "\n===========[ CONSTRUCTORS ]===========\n";
  {
    std::cout << "\n[ CONSTRUCTOR VOID ]\n";
    ft::map<MAP_T> FTmap;

    print_map<PRINT>(FTmap);
  }
  {
    std::cout << "\n[ CONSTRUCTOR RANGE ]\n";
    ft::map<MAP_T> FTmap_copy;

    FTmap_copy.insert(TYPE("a", 8));
    FTmap_copy.insert(TYPE("b", 18));
    FTmap_copy.insert(TYPE("c", 5));
    FTmap_copy.insert(TYPE("d", 15));

    ft::map<MAP_T> FTmap(FTmap_copy.begin(), FTmap_copy.end());

    print_map<PRINT>(FTmap);

    FTmap.insert(TYPE("e", 17));

    print_map<PRINT>(FTmap);
  }
  {
    std::cout << "\n[ CONSTRUCTOR COPY ]\n";
    ft::map<MAP_T> FTmap_copy;

    FTmap_copy.insert(TYPE("a", 8));
    FTmap_copy.insert(TYPE("b", 18));
    FTmap_copy.insert(TYPE("c", 5));
    FTmap_copy.insert(TYPE("d", 15));

    ft::map<MAP_T> FTmap(FTmap_copy);

    print_map<PRINT>(FTmap);

    FTmap.insert(TYPE("e", 17));

    print_map<PRINT>(FTmap);
  }
  {
    std::cout << "\n[ ASSIGNMENT OPERATOR (=) ]\n";
    ft::map<MAP_T> FTmap_copy;

    FTmap_copy.insert(TYPE("a", 8));
    FTmap_copy.insert(TYPE("b", 18));
    FTmap_copy.insert(TYPE("c", 5));
    FTmap_copy.insert(TYPE("d", 15));

    ft::map<MAP_T> FTmap = FTmap_copy;

    print_map<PRINT>(FTmap);

    FTmap.insert(TYPE("e", 17));

    print_map<PRINT>(FTmap);
  }

  std::cout << "\n\n===========[ ITERATORS ]===========\n";
  {
    std::cout << "\n[ BEGIN ]\n";
    ft::map<MAP_T> FTmap;

    FTmap.insert(TYPE("a", 8));
    FTmap.insert(TYPE("b", 18));
    FTmap.insert(TYPE("c", 5));
    FTmap.insert(TYPE("d", 15));

    ft::map<MAP_T> const FTmapC(FTmap);

    ft::map<MAP_T>::iterator FTit = FTmap.begin();
    ft::map<MAP_T>::const_iterator FTitC = FTmapC.begin();
    ft::map<MAP_T>::iterator FTitE = FTmap.end();
    ft::map<MAP_T>::const_iterator FTitCE = FTmapC.end();

    while (FTit != FTitE) {
      std::cout << "[" << FTit->first << "]"
                << "(" << FTit->second << ")"
                << " ";
      FTit++;
    }

    while (FTitC != FTitCE) {
      std::cout << "[" << FTitC->first << "]"
                << "(" << FTitC->second << ")"
                << " ";
      FTitC++;
    }
  }
  {
    std::cout << "\n[ END ]\n";
    ft::map<MAP_T> FTmap;

    FTmap.insert(TYPE("a", 8));
    FTmap.insert(TYPE("b", 18));
    FTmap.insert(TYPE("c", 5));
    FTmap.insert(TYPE("d", 15));

    ft::map<MAP_T> const FTmapC(FTmap);

    ft::map<MAP_T>::iterator FTit = FTmap.begin();
    ft::map<MAP_T>::const_iterator FTitC = FTmapC.begin();
    ft::map<MAP_T>::iterator FTitE = FTmap.end();
    ft::map<MAP_T>::const_iterator FTitCE = FTmapC.end();

    while (FTit != FTitE) {
      std::cout << "[" << FTit->first << "]"
                << "(" << FTit->second << ")"
                << " ";
      FTit++;
    }

    while (FTitC != FTitCE) {
      std::cout << "[" << FTitC->first << "]"
                << "(" << FTitC->second << ")"
                << " ";
      FTitC++;
    }
  }
  {
    std::cout << "\n[ RBEGIN ]\n";
    ft::map<MAP_T> FTmap;

    FTmap.insert(TYPE("a", 8));
    FTmap.insert(TYPE("b", 18));
    FTmap.insert(TYPE("c", 5));
    FTmap.insert(TYPE("d", 15));

    ft::map<MAP_T> const FTmapC(FTmap);

    ft::map<MAP_T>::reverse_iterator FTitR = FTmap.rbegin();
    ft::map<MAP_T>::const_reverse_iterator FTitCR = FTmap.rbegin();
    ft::map<MAP_T>::reverse_iterator FTitRE = --FTmap.rend();
    ft::map<MAP_T>::const_reverse_iterator FTitCRE = --FTmap.rend();

    while (FTitRE != FTitR) {
      std::cout << "[" << FTitRE->first << "]"
                << "(" << FTitRE->second << ")"
                << " ";
      FTitRE--;
    }

    while (FTitCRE != FTitCR) {
      std::cout << "[" << FTitCRE->first << "]"
                << "(" << FTitCRE->second << ")"
                << " ";
      FTitCRE--;
    }
  }
  {
    std::cout << "\n[ REND ]\n";
    ft::map<MAP_T> FTmap;

    FTmap.insert(TYPE("a", 8));
    FTmap.insert(TYPE("b", 18));
    FTmap.insert(TYPE("c", 5));
    FTmap.insert(TYPE("d", 15));

    ft::map<MAP_T> const FTmapC(FTmap);

    ft::map<MAP_T>::reverse_iterator FTitR = FTmap.rbegin();
    ft::map<MAP_T>::const_reverse_iterator FTitCR = FTmap.rbegin();
    ft::map<MAP_T>::reverse_iterator FTitRE = --FTmap.rend();
    ft::map<MAP_T>::const_reverse_iterator FTitCRE = --FTmap.rend();

    while (FTitRE != FTitR) {
      std::cout << "[" << FTitRE->first << "]"
                << "(" << FTitRE->second << ")"
                << " ";
      FTitRE--;
    }

    while (FTitCRE != FTitCR) {
      std::cout << "[" << FTitCRE->first << "]"
                << "(" << FTitCRE->second << ")"
                << " ";
      FTitCRE--;
    }
  }

  std::cout << "\n\n===========[ CAPACITY ]===========\n";
  {
    {
      std::cout << "\n[ EMPTY ]\n";
      ft::map<MAP_T> FTmap;

      print(FTmap.empty());

      FTmap.insert(TYPE("a", 8));

      print(FTmap.empty());
    }
    {
      std::cout << "\n[ SIZE ]\n";
      ft::map<MAP_T> FTmap;

      print(FTmap.size());
    }

    std::cout << "\n\n===========[ ELEMENT ACCESS ]===========\n";
    {
      std::cout << "\n[ OPERATOR [] ]\n";
      ft::map<MAP_T> FTmap;

      FTmap.insert(TYPE("a", 8));
      FTmap.insert(TYPE("b", 18));
      FTmap.insert(TYPE("c", 5));
      FTmap.insert(TYPE("d", 15));

      FTmap["z"] = 42;

      print_map<PRINT>(FTmap);

      print(FTmap["z"]);
      print(FTmap["a"]);
      print(FTmap["y"]);
    }

    std::cout << "\n\n===========[ MAP MODIFIERS ]===========\n";
    {
      std::cout << "\n[ INSERT VAL ]\n";
      ft::map<MAP_T> FTmap;

      FTmap.insert(TYPE("a", 8));
      FTmap.insert(TYPE("b", 18));
      FTmap.insert(TYPE("c", 5));
      FTmap.insert(TYPE("d", 15));

      print_map<PRINT>(FTmap);

      FTmap.insert(TYPE("a", 8));

      print_map<PRINT>(FTmap);
    }
    {
      std::cout << "\n[ INSERT POS ]\n";
      ft::map<MAP_T> FTmap;

      FTmap.insert(FTmap.begin(), TYPE("a", 8));
      FTmap.insert(FTmap.begin(), TYPE("b", 18));
      FTmap.insert(FTmap.begin(), TYPE("c", 5));
      FTmap.insert(FTmap.begin(), TYPE("d", 15));

      print_map<PRINT>(FTmap);

      FTmap.insert(FTmap.end(), TYPE("b", 18));

      print_map<PRINT>(FTmap);
    }
    {
      std::cout << "\n[ INSERT RANGE ]\n";
      ft::map<MAP_T> FTmap_copy;
      ft::map<MAP_T> FTmap;

      FTmap_copy.insert(TYPE("a", 8));
      FTmap_copy.insert(TYPE("b", 18));
      FTmap_copy.insert(TYPE("c", 5));
      FTmap_copy.insert(TYPE("d", 15));

      FTmap.insert(FTmap_copy.begin(), FTmap_copy.end());

      print_map<PRINT>(FTmap);
    }
    {
      std::cout << "\n[ ERASE POS ]\n";
      ft::map<MAP_T> FTmap;

      FTmap.insert(TYPE("a", 8));
      FTmap.insert(TYPE("b", 18));
      FTmap.insert(TYPE("c", 5));
      FTmap.insert(TYPE("d", 15));

      print_map<PRINT>(FTmap);

      FTmap.erase(FTmap.begin());

      print_map<PRINT>(FTmap);
    }
    {
      std::cout << "\n[ ERASE KEY ]\n";
      ft::map<MAP_T> FTmap;

      FTmap.insert(TYPE("a", 8));
      FTmap.insert(TYPE("b", 18));
      FTmap.insert(TYPE("c", 5));
      FTmap.insert(TYPE("d", 15));

      print_map<PRINT>(FTmap);

      FTmap.erase("a");

      print_map<PRINT>(FTmap);
    }
    {
      std::cout << "\n[ ERASE RANGE ]\n";
      ft::map<MAP_T> FTmap;

      FTmap.insert(TYPE("a", 8));
      FTmap.insert(TYPE("b", 18));
      FTmap.insert(TYPE("c", 5));
      FTmap.insert(TYPE("d", 15));

      print_map<PRINT>(FTmap);

      FTmap.erase(++FTmap.begin(), FTmap.end());

      print_map<PRINT>(FTmap);
    }
    {
      std::cout << "\n[ SWAP ]\n";
      ft::map<MAP_T> FTmap_copy;
      ft::map<MAP_T> FTmap;

      FTmap_copy.insert(TYPE("a", 8));
      FTmap_copy.insert(TYPE("b", 18));
      FTmap_copy.insert(TYPE("c", 5));
      FTmap_copy.insert(TYPE("d", 15));

      FTmap.insert(TYPE("e", 17));
      FTmap.insert(TYPE("f", 25));
      FTmap.insert(TYPE("g", 40));
      FTmap.insert(TYPE("h", 80));

      print_map<PRINT>(FTmap_copy);
      print_map<PRINT>(FTmap);

      FTmap.swap(FTmap_copy);

      print_map<PRINT>(FTmap_copy);
      print_map<PRINT>(FTmap);
    }
    {
      std::cout << "\n[ CLEAR ]\n";
      ft::map<MAP_T> FTmap;

      FTmap.insert(TYPE("a", 8));
      FTmap.insert(TYPE("b", 18));
      FTmap.insert(TYPE("c", 5));
      FTmap.insert(TYPE("d", 15));

      print_map<PRINT>(FTmap);

      FTmap.clear();

      print_map<PRINT>(FTmap);
    }

    std::cout << "\n\n===========[ OBSERVERS ]===========\n";
    {
      std::cout << "\n[ KEY COMP ]\n";
      ft::map<MAP_T> FTmap_copy;
      ft::map<MAP_T> FTmap;

      ft::map<MAP_T>::key_compare FTmap_comp = FTmap.key_comp();

      FTmap.insert(TYPE("a", 8));
      FTmap_copy.insert(TYPE("b", 18));

      print(FTmap_comp(FTmap.begin()->first, FTmap_copy.begin()->first));
    }
    {
      std::cout << "\n[ VALUE COMP ]\n";
      ft::map<MAP_T> FTmap_copy;
      ft::map<MAP_T> FTmap;

      FTmap.insert(TYPE("a", 8));
      FTmap_copy.insert(TYPE("b", 18));

      print(FTmap.value_comp()(*FTmap.begin(), *FTmap_copy.begin()));
    }

    std::cout << "\n\n===========[ OPERATIONS ]===========\n";
    {
      std::cout << "\n[ FIND ]\n";
      ft::map<MAP_T> FTmap;

      FTmap.insert(TYPE("a", 8));

      print(FTmap.find("a") == FTmap.begin());
      print(FTmap.find("b") == FTmap.end());
    }
    {
      std::cout << "\n[ COUNT ]\n";
      ft::map<MAP_T> FTmap;

      FTmap.insert(TYPE("a", 8));

      print(FTmap.count("a") == 1);
      print(FTmap.count("b") == 0);
    }
    {
      std::cout << "\n[ LOWER BOUND ]\n";
      ft::map<MAP_T> FTmap;

      FTmap.insert(TYPE("a", 8));
      FTmap.insert(TYPE("b", 18));
      FTmap.insert(TYPE("c", 5));
      FTmap.insert(TYPE("d", 15));

      print(FTmap.lower_bound("b")->first);
      print(FTmap.lower_bound("b")->second);
    }
    {
      std::cout << "\n[ UPPER BOUND ]\n";
      ft::map<MAP_T> FTmap;

      FTmap.insert(TYPE("a", 8));
      FTmap.insert(TYPE("b", 18));
      FTmap.insert(TYPE("c", 5));
      FTmap.insert(TYPE("d", 15));

      print(FTmap.lower_bound("c")->first);
      print(FTmap.lower_bound("c")->second);
    }
    {
      std::cout << "\n[ EQUAL RANGE ]\n";
      ft::map<MAP_T> FTmap;

      FTmap.insert(TYPE("a", 8));
      FTmap.insert(TYPE("b", 18));
      FTmap.insert(TYPE("c", 5));
      FTmap.insert(TYPE("d", 15));

      ft::pair<ft::map<MAP_T>::iterator, ft::map<MAP_T>::iterator> FTPit;

      FTPit = FTmap.equal_range("a");

      print(FTPit.first->first);
      print(FTPit.first->second);
      print(FTPit.second->first);
      print(FTPit.second->second);

      FTPit = FTmap.equal_range("c");

      print(FTPit.first->first);
      print(FTPit.first->second);
      print(FTPit.second->first);
      print(FTPit.second->second);
    }

    std::cout << "\n\n===========[ ALLOCATOR ]===========\n";
    {
      std::cout << "\n[ GET_ALLOCATOR ]\n";
      ft::map<MAP_T> FTmap_copy;

      FTmap_copy.insert(TYPE("a", 8));
      FTmap_copy.insert(TYPE("b", 18));
      FTmap_copy.insert(TYPE("c", 5));
      FTmap_copy.insert(TYPE("d", 15));

      ft::map<MAP_T> FTmap(FTmap_copy.key_comp(), FTmap_copy.get_allocator());

      FTmap.insert(TYPE("a", 8));
      FTmap.insert(TYPE("b", 18));
      FTmap.insert(TYPE("c", 5));
      FTmap.insert(TYPE("d", 15));

      print_map<PRINT>(FTmap);
    }

    std::cout << "\n\n===========[ RELATIONAL OPERATORS ]===========\n";
    {
      std::cout << "\n[ EQUAL (==) ]\n";
      ft::map<MAP_T> FTmap_copy;
      ft::map<MAP_T> FTmap;

      FTmap_copy.insert(TYPE("a", 8)), FTmap.insert(TYPE("a", 8));
      FTmap_copy.insert(TYPE("b", 18)), FTmap.insert(TYPE("b", 18));
      FTmap_copy.insert(TYPE("c", 5)), FTmap.insert(TYPE("c", 5));
      FTmap_copy.insert(TYPE("d", 15)), FTmap.insert(TYPE("d", 15));

      print(FTmap == FTmap_copy);

      FTmap_copy.insert(TYPE("e", 17)), FTmap.insert(TYPE("f", 25));

      print(FTmap == FTmap_copy);
    }
    {
      std::cout << "\n[ DIFFERENT (!=) ]\n";
      ft::map<MAP_T> FTmap_copy;
      ft::map<MAP_T> FTmap;

      FTmap_copy.insert(TYPE("a", 8)), FTmap.insert(TYPE("a", 8));
      FTmap_copy.insert(TYPE("b", 18)), FTmap.insert(TYPE("b", 18));
      FTmap_copy.insert(TYPE("c", 5)), FTmap.insert(TYPE("c", 5));
      FTmap_copy.insert(TYPE("d", 15)), FTmap.insert(TYPE("e", 17));

      print(FTmap != FTmap_copy);

      FTmap_copy.insert(TYPE("e", 17)), FTmap.insert(TYPE("d", 15));

      print(FTmap != FTmap_copy);
    }
    {
      std::cout << "\n[ MINOR (<) ]\n";
      ft::map<MAP_T> FTmap_copy;
      ft::map<MAP_T> FTmap;

      FTmap_copy.insert(TYPE("a", 8)), FTmap.insert(TYPE("a", 8));
      FTmap_copy.insert(TYPE("b", 18)), FTmap.insert(TYPE("b", 18));
      FTmap_copy.insert(TYPE("c", 5)), FTmap.insert(TYPE("c", 5));
      FTmap_copy.insert(TYPE("d", 15));

      print(FTmap < FTmap_copy);

      FTmap.insert(TYPE("d", 17));

      print(FTmap < FTmap_copy);
    }
    {
      std::cout << "\n[ MINOR OR EQUAL (<=) ]\n";
      ft::map<MAP_T> FTmap_copy;
      ft::map<MAP_T> FTmap;

      FTmap_copy.insert(TYPE("a", 8)), FTmap.insert(TYPE("a", 8));
      FTmap_copy.insert(TYPE("b", 18)), FTmap.insert(TYPE("b", 18));
      FTmap_copy.insert(TYPE("c", 5)), FTmap.insert(TYPE("c", 5));
      FTmap_copy.insert(TYPE("d", 15));

      print(FTmap <= FTmap_copy);

      FTmap.insert(TYPE("e", 17));

      print(FTmap <= FTmap_copy);
    }
    {
      std::cout << "\n[ GREATER (>) ]\n";
      ft::map<MAP_T> FTmap_copy;
      ft::map<MAP_T> FTmap;

      FTmap_copy.insert(TYPE("a", 8)), FTmap.insert(TYPE("a", 8));
      FTmap_copy.insert(TYPE("b", 18)), FTmap.insert(TYPE("b", 18));
      FTmap_copy.insert(TYPE("c", 5)), FTmap.insert(TYPE("c", 5));
      FTmap_copy.insert(TYPE("d", 15));

      print(FTmap > FTmap_copy);

      FTmap.insert(TYPE("e", 17));

      print(FTmap > FTmap_copy);
    }
    {
      std::cout << "\n[ GREATER OR EQUAL (>=) ]\n";
      ft::map<MAP_T> FTmap_copy;
      ft::map<MAP_T> FTmap;

      FTmap_copy.insert(TYPE("a", 8)), FTmap.insert(TYPE("a", 8));
      FTmap_copy.insert(TYPE("b", 18)), FTmap.insert(TYPE("b", 18));
      FTmap_copy.insert(TYPE("c", 5)), FTmap.insert(TYPE("c", 5));
      FTmap_copy.insert(TYPE("d", 15));

      print(FTmap >= FTmap_copy);

      FTmap.insert(TYPE("e", 17));

      print(FTmap >= FTmap_copy);
    }

    NEWLINE

    return (0);
  }
}
