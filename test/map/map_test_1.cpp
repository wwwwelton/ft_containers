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
void print_map(T& map) {
  for (typename T::iterator it = map.begin(); it != map.end(); it++) {
    std::cout << "[" << it->first << "]"
              << "(" << it->second << ")"
              << " ";
  }
  std::cout << std::endl;
}

template <typename T, typename U>
bool pred(T x, U y) {
  return ((x.first == y.first) && (x.second == y.second));
}

// NEWLINE
// print_map<FT_PRINT>(FTmap);
// print_map<OR_PRINT>(ORmap);

#define KO "\033[1;31mKO\033[0m"
#define OK "\033[1;32mOK\033[0m"

#define NEWLINE std::cout << "\n";

#define KEY std::string
#define VALUE int
#define FT_TYPE ft::pair<KEY, VALUE>
#define OR_TYPE std::pair<KEY, VALUE>

#define MAP_T KEY, VALUE

#define FT_PRINT ft::map<MAP_T>
#define OR_PRINT std::map<MAP_T>

#include <map>

#include "../../algorithm.hpp"
#include "../../map.hpp"

int main(void) {
  std::cout << "\n===========[ CONSTRUCTORS ]===========\n";
  {
    std::cout << "\n[ CONSTRUCTOR VOID ]\n";
    ft::map<MAP_T> FTmap;

    ft::map<MAP_T>::iterator FTit = FTmap.begin();
    ft::map<MAP_T>::iterator FTite = FTmap.end();

    if ((FTit->first == "") && (FTite->first == "") && (FTit == FTite))
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }
  {
    std::cout << "\n[ CONSTRUCTOR RANGE ]\n";
    ft::map<MAP_T> FTmap_copy;

    FTmap_copy.insert(FT_TYPE("a", 8));
    FTmap_copy.insert(FT_TYPE("b", 18));
    FTmap_copy.insert(FT_TYPE("c", 5));
    FTmap_copy.insert(FT_TYPE("d", 15));

    ft::map<MAP_T> FTmap(FTmap_copy.begin(), FTmap_copy.end());

    if (ft::equal(FTmap.begin(), FTmap.end(), FTmap_copy.begin(),
                  pred<FT_TYPE, FT_TYPE>))
      std::cout << OK " ";
    else
      std::cout << KO " ";

    FTmap.insert(FT_TYPE("e", 17));

    if (!ft::equal(FTmap.begin(), FTmap.end(), FTmap_copy.begin(),
                   pred<FT_TYPE, FT_TYPE>))
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }
  {
    std::cout << "\n[ CONSTRUCTOR COPY ]\n";
    ft::map<MAP_T> FTmap_copy;

    FTmap_copy.insert(FT_TYPE("a", 8));
    FTmap_copy.insert(FT_TYPE("b", 18));
    FTmap_copy.insert(FT_TYPE("c", 5));
    FTmap_copy.insert(FT_TYPE("d", 15));

    ft::map<MAP_T> FTmap(FTmap_copy);

    if (ft::equal(FTmap.begin(), FTmap.end(), FTmap_copy.begin(),
                  pred<FT_TYPE, FT_TYPE>))
      std::cout << OK " ";
    else
      std::cout << KO " ";

    FTmap.insert(FT_TYPE("e", 17));

    if (!ft::equal(FTmap.begin(), FTmap.end(), FTmap_copy.begin(),
                   pred<FT_TYPE, FT_TYPE>))
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }
  {
    std::cout << "\n[ ASSIGNMENT OPERATOR (=) ]\n";
    ft::map<MAP_T> FTmap_copy;

    FTmap_copy.insert(FT_TYPE("a", 8));
    FTmap_copy.insert(FT_TYPE("b", 18));
    FTmap_copy.insert(FT_TYPE("c", 5));
    FTmap_copy.insert(FT_TYPE("d", 15));

    ft::map<MAP_T> FTmap = FTmap_copy;

    if (ft::equal(FTmap.begin(), FTmap.end(), FTmap_copy.begin(),
                  pred<FT_TYPE, FT_TYPE>))
      std::cout << OK " ";
    else
      std::cout << KO " ";

    FTmap.insert(FT_TYPE("e", 17));

    if (!ft::equal(FTmap.begin(), FTmap.end(), FTmap_copy.begin(),
                   pred<FT_TYPE, FT_TYPE>))
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }

  std::cout << "\n\n===========[ ITERATORS ]===========\n";
  {
    std::cout << "\n[ BEGIN ]\n";
    ft::map<MAP_T> FTmap;
    std::map<MAP_T> ORmap;

    FTmap.insert(FT_TYPE("a", 8)), ORmap.insert(OR_TYPE("a", 8));
    FTmap.insert(FT_TYPE("b", 18)), ORmap.insert(OR_TYPE("b", 18));
    FTmap.insert(FT_TYPE("c", 5)), ORmap.insert(OR_TYPE("c", 5));
    FTmap.insert(FT_TYPE("d", 15)), ORmap.insert(OR_TYPE("d", 15));

    ft::map<MAP_T>::iterator FTit = FTmap.begin();
    std::map<MAP_T>::iterator ORit = ORmap.begin();
    ft::map<MAP_T>::const_iterator FTitC = FTmap.begin();
    std::map<MAP_T>::const_iterator ORitC = ORmap.begin();

    if ((FTit->first == ORit->first) && (FTit->second == ORit->second))
      std::cout << OK " ";
    else
      std::cout << KO " ";

    if ((FTitC->first == ORitC->first) && (FTitC->second == ORitC->second))
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }
  {
    std::cout << "\n[ END ]\n";
    ft::map<MAP_T> FTmap;
    std::map<MAP_T> ORmap;

    FTmap.insert(FT_TYPE("a", 8)), ORmap.insert(OR_TYPE("a", 8));
    FTmap.insert(FT_TYPE("b", 18)), ORmap.insert(OR_TYPE("b", 18));
    FTmap.insert(FT_TYPE("c", 5)), ORmap.insert(OR_TYPE("c", 5));
    FTmap.insert(FT_TYPE("d", 15)), ORmap.insert(OR_TYPE("d", 15));

    ft::map<MAP_T>::iterator FTit = --FTmap.end();
    std::map<MAP_T>::iterator ORit = --ORmap.end();
    ft::map<MAP_T>::const_iterator FTitC = --FTmap.end();
    std::map<MAP_T>::const_iterator ORitC = --ORmap.end();

    if ((FTit->first == ORit->first) && (FTit->second == ORit->second))
      std::cout << OK " ";
    else
      std::cout << KO " ";

    if ((FTitC->first == ORitC->first) && (FTitC->second == ORitC->second))
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }
  {
    std::cout << "\n[ RBEGIN ]\n";
    ft::map<MAP_T> FTmap;
    std::map<MAP_T> ORmap;

    FTmap.insert(FT_TYPE("a", 8)), ORmap.insert(OR_TYPE("a", 8));
    FTmap.insert(FT_TYPE("b", 18)), ORmap.insert(OR_TYPE("b", 18));
    FTmap.insert(FT_TYPE("c", 5)), ORmap.insert(OR_TYPE("c", 5));
    FTmap.insert(FT_TYPE("d", 15)), ORmap.insert(OR_TYPE("d", 15));

    ft::map<MAP_T>::reverse_iterator FTitR = FTmap.rbegin();
    std::map<MAP_T>::reverse_iterator ORitR = ORmap.rbegin();
    ft::map<MAP_T>::const_reverse_iterator FTitCR = FTmap.rbegin();
    std::map<MAP_T>::const_reverse_iterator ORitCR = ORmap.rbegin();

    if ((FTitR->first == ORitR->first) && (FTitR->second == ORitR->second))
      std::cout << OK " ";
    else
      std::cout << KO " ";

    if ((FTitCR->first == ORitCR->first) && (FTitCR->second == ORitCR->second))
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }
  {
    std::cout << "\n[ REND ]\n";
    ft::map<MAP_T> FTmap;
    std::map<MAP_T> ORmap;

    FTmap.insert(FT_TYPE("a", 8)), ORmap.insert(OR_TYPE("a", 8));
    FTmap.insert(FT_TYPE("b", 18)), ORmap.insert(OR_TYPE("b", 18));
    FTmap.insert(FT_TYPE("c", 5)), ORmap.insert(OR_TYPE("c", 5));
    FTmap.insert(FT_TYPE("d", 15)), ORmap.insert(OR_TYPE("d", 15));

    ft::map<MAP_T>::reverse_iterator FTitR = --FTmap.rend();
    std::map<MAP_T>::reverse_iterator ORitR = --ORmap.rend();
    ft::map<MAP_T>::const_reverse_iterator FTitCR = --FTmap.rend();
    std::map<MAP_T>::const_reverse_iterator ORitCR = --ORmap.rend();

    if ((FTitR->first == ORitR->first) && (FTitR->second == ORitR->second))
      std::cout << OK " ";
    else
      std::cout << KO " ";

    if ((FTitCR->first == ORitCR->first) && (FTitCR->second == ORitCR->second))
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }

  std::cout << "\n\n===========[ CAPACITY ]===========\n";
  {
    std::cout << "\n[ EMPTY ]\n";
    ft::map<MAP_T> FTmap;
    std::map<MAP_T> ORmap;

    if (FTmap.empty() == ORmap.empty())
      std::cout << OK " ";
    else
      std::cout << KO " ";

    FTmap.insert(FT_TYPE("a", 8)), ORmap.insert(OR_TYPE("a", 8));
    FTmap.insert(FT_TYPE("b", 18)), ORmap.insert(OR_TYPE("b", 18));
    FTmap.insert(FT_TYPE("c", 5)), ORmap.insert(OR_TYPE("c", 5));
    FTmap.insert(FT_TYPE("d", 15)), ORmap.insert(OR_TYPE("d", 15));

    if (FTmap.empty() == ORmap.empty())
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }
  {
    std::cout << "\n[ SIZE ]\n";
    ft::map<MAP_T> FTmap;
    std::map<MAP_T> ORmap;

    if (FTmap.size() == ORmap.size())
      std::cout << OK " ";
    else
      std::cout << KO " ";

    FTmap.insert(FT_TYPE("a", 8)), ORmap.insert(OR_TYPE("a", 8));
    FTmap.insert(FT_TYPE("b", 18)), ORmap.insert(OR_TYPE("b", 18));
    FTmap.insert(FT_TYPE("c", 5)), ORmap.insert(OR_TYPE("c", 5));
    FTmap.insert(FT_TYPE("d", 15)), ORmap.insert(OR_TYPE("d", 15));

    if (FTmap.size() == ORmap.size())
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }
  {
    std::cout << "\n[ MAX_SIZE ]\n";
    ft::map<MAP_T> FTmap;

    if (FTmap.max_size())
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }

  std::cout << "\n\n===========[ MAP MODIFIERS ]===========\n";
  {
    std::cout << "\n[ INSERT VAL ]\n";
    ft::map<MAP_T> FTmap;
    std::map<MAP_T> ORmap;

    ft::pair<ft::map<MAP_T>::iterator, bool> FTit;
    std::pair<std::map<MAP_T>::iterator, bool> ORit;

    FTit = FTmap.insert(FT_TYPE("a", 8));
    ORit = ORmap.insert(OR_TYPE("a", 8));

    if ((FTit.first->first == ORit.first->first) &&
        (FTit.first->second == ORit.first->second) &&
        (FTit.second == ORit.second))
      std::cout << OK " ";
    else
      std::cout << KO " ";

    FTit = FTmap.insert(FT_TYPE("a", 8));
    ORit = ORmap.insert(OR_TYPE("a", 8));

    if ((FTit.first->first == ORit.first->first) &&
        (FTit.first->second == ORit.first->second) &&
        (FTit.second == ORit.second))
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }
  {
    std::cout << "\n[ INSERT POS ]\n";
    ft::map<MAP_T> FTmap;
    std::map<MAP_T> ORmap;

    ft::map<MAP_T>::iterator FTit;
    std::map<MAP_T>::iterator ORit;

    FTit = FTmap.insert(FTmap.begin(), FT_TYPE("a", 8));
    ORit = ORmap.insert(ORmap.begin(), OR_TYPE("a", 8));

    if ((FTit->first == ORit->first) && (FTit->second == ORit->second))
      std::cout << OK " ";
    else
      std::cout << KO " ";

    FTit = FTmap.insert(FTmap.end(), FT_TYPE("b", 18));
    ORit = ORmap.insert(ORmap.end(), OR_TYPE("b", 18));

    if ((FTit->first == ORit->first) && (FTit->second == ORit->second))
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }
  {
    std::cout << "\n[ INSERT RANGE ]\n";
    ft::map<MAP_T> FTmap_copy;
    ft::map<MAP_T> FTmap;

    FTmap_copy.insert(FT_TYPE("a", 8));
    FTmap_copy.insert(FT_TYPE("b", 18));
    FTmap_copy.insert(FT_TYPE("c", 5));
    FTmap_copy.insert(FT_TYPE("d", 15));

    FTmap.insert(FTmap_copy.begin(), FTmap_copy.end());

    if (ft::equal(FTmap.begin(), FTmap.end(), FTmap_copy.begin(),
                  pred<FT_TYPE, FT_TYPE>))
      std::cout << OK " ";
    else
      std::cout << KO " ";

    FTmap.insert(FT_TYPE("e", 17));

    if (!ft::equal(FTmap.begin(), FTmap.end(), FTmap_copy.begin(),
                   pred<FT_TYPE, FT_TYPE>))
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }

  {
    std::cout << "\n[ CLEAR ]\n";
    ft::map<MAP_T> FTmap;

    FTmap.insert(FT_TYPE("a", 8));
    FTmap.insert(FT_TYPE("b", 18));
    FTmap.insert(FT_TYPE("c", 5));
    FTmap.insert(FT_TYPE("d", 15));

    FTmap.clear();

    if (FTmap.begin() == FTmap.end())
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }

  NEWLINE

  return (0);
}
