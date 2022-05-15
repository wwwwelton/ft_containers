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

  std::cout << "\n\n===========[ ELEMENT ACCESS ]===========\n";
  {
    std::cout << "\n[ OPERATOR [] ]\n";
    ft::map<MAP_T> FTmap;
    std::map<MAP_T> ORmap;

    FTmap.insert(FT_TYPE("a", 8)), ORmap.insert(OR_TYPE("a", 8));
    FTmap.insert(FT_TYPE("b", 18)), ORmap.insert(OR_TYPE("b", 18));
    FTmap.insert(FT_TYPE("c", 5)), ORmap.insert(OR_TYPE("c", 5));
    FTmap.insert(FT_TYPE("d", 15)), ORmap.insert(OR_TYPE("d", 15));

    FTmap["z"] = 42;
    ORmap["z"] = 42;

    ft::map<MAP_T>::iterator FTit = FTmap.begin();
    std::map<MAP_T>::iterator ORit = ORmap.begin();

    if ((FTit->first == ORit->first) && (FTit->second == ORit->second))
      std::cout << OK " ";
    else
      std::cout << KO " ";

    if ((FTmap["z"] == ORmap["z"]) && (FTmap["y"] == ORmap["y"]))
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
    std::cout << "\n[ ERASE POS ]\n";
    ft::map<MAP_T> FTmap;
    std::map<MAP_T> ORmap;

    FTmap.insert(FT_TYPE("a", 8)), ORmap.insert(OR_TYPE("a", 8));
    FTmap.insert(FT_TYPE("b", 18)), ORmap.insert(OR_TYPE("b", 18));
    FTmap.insert(FT_TYPE("c", 5)), ORmap.insert(OR_TYPE("c", 5));
    FTmap.insert(FT_TYPE("d", 15)), ORmap.insert(OR_TYPE("d", 15));

    FTmap.erase(FTmap.begin());
    ORmap.erase(ORmap.begin());

    if (ft::equal(FTmap.begin(), FTmap.end(), ORmap.begin(),
                  pred<FT_TYPE, OR_TYPE>))
      std::cout << OK " ";
    else
      std::cout << KO " ";

    FTmap.erase(FTmap.begin());

    if (!ft::equal(FTmap.begin(), FTmap.end(), ORmap.begin(),
                   pred<FT_TYPE, OR_TYPE>))
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }
  {
    std::cout << "\n[ ERASE KEY ]\n";
    ft::map<MAP_T> FTmap;
    std::map<MAP_T> ORmap;

    FTmap.insert(FT_TYPE("a", 8)), ORmap.insert(OR_TYPE("a", 8));
    FTmap.insert(FT_TYPE("b", 18)), ORmap.insert(OR_TYPE("b", 18));
    FTmap.insert(FT_TYPE("c", 5)), ORmap.insert(OR_TYPE("c", 5));
    FTmap.insert(FT_TYPE("d", 15)), ORmap.insert(OR_TYPE("d", 15));

    FTmap.erase("a");
    ORmap.erase("a");

    if (ft::equal(FTmap.begin(), FTmap.end(), ORmap.begin(),
                  pred<FT_TYPE, OR_TYPE>))
      std::cout << OK " ";
    else
      std::cout << KO " ";

    FTmap.erase("b");
    ORmap.erase("d");

    if (!ft::equal(FTmap.begin(), FTmap.end(), ORmap.begin(),
                   pred<FT_TYPE, OR_TYPE>))
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }
  {
    std::cout << "\n[ ERASE RANGE ]\n";
    ft::map<MAP_T> FTmap;
    std::map<MAP_T> ORmap;

    FTmap.insert(FT_TYPE("a", 8)), ORmap.insert(OR_TYPE("a", 8));
    FTmap.insert(FT_TYPE("b", 18)), ORmap.insert(OR_TYPE("b", 18));
    FTmap.insert(FT_TYPE("c", 5)), ORmap.insert(OR_TYPE("c", 5));
    FTmap.insert(FT_TYPE("d", 15)), ORmap.insert(OR_TYPE("d", 15));

    FTmap.erase(++FTmap.begin(), FTmap.end());
    ORmap.erase(++ORmap.begin(), ORmap.end());

    if (ft::equal(FTmap.begin(), FTmap.end(), ORmap.begin(),
                  pred<FT_TYPE, OR_TYPE>))
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }
  {
    std::cout << "\n[ SWAP ]\n";
    ft::map<MAP_T> FTmap_copy;
    std::map<MAP_T> ORmap_copy;
    ft::map<MAP_T> FTmap;
    std::map<MAP_T> ORmap;

    FTmap_copy.insert(FT_TYPE("a", 8)), ORmap_copy.insert(OR_TYPE("a", 8));
    FTmap_copy.insert(FT_TYPE("b", 18)), ORmap_copy.insert(OR_TYPE("b", 18));
    FTmap_copy.insert(FT_TYPE("c", 5)), ORmap_copy.insert(OR_TYPE("c", 5));
    FTmap_copy.insert(FT_TYPE("d", 15)), ORmap_copy.insert(OR_TYPE("d", 15));

    FTmap.insert(FT_TYPE("e", 17)), ORmap.insert(OR_TYPE("e", 17));
    FTmap.insert(FT_TYPE("f", 25)), ORmap.insert(OR_TYPE("f", 25));
    FTmap.insert(FT_TYPE("g", 40)), ORmap.insert(OR_TYPE("g", 40));
    FTmap.insert(FT_TYPE("h", 80)), ORmap.insert(OR_TYPE("h", 80));

    FTmap.swap(FTmap_copy);
    ORmap.swap(ORmap_copy);

    if (ft::equal(FTmap_copy.begin(), FTmap_copy.end(), ORmap_copy.begin(),
                  pred<FT_TYPE, OR_TYPE>))
      std::cout << OK " ";
    else
      std::cout << KO " ";

    if (ft::equal(FTmap.begin(), FTmap.end(), ORmap.begin(),
                  pred<FT_TYPE, OR_TYPE>))
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

  std::cout << "\n\n===========[ OBSERVERS ]===========\n";
  {
    std::cout << "\n[ KEY COMP ]\n";
    ft::map<MAP_T> FTmap_copy;
    ft::map<MAP_T> FTmap;

    ft::map<MAP_T>::key_compare FTmap_comp = FTmap.key_comp();

    FTmap.insert(FT_TYPE("a", 8));
    FTmap_copy.insert(FT_TYPE("b", 18));

    if (FTmap_comp(FTmap.begin()->first, FTmap_copy.begin()->first))
      std::cout << OK " ";
    else
      std::cout << KO " ";

    if (!FTmap_comp(FTmap_copy.begin()->first, FTmap.begin()->first))
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }
  {
    std::cout << "\n[ VALUE COMP ]\n";
    ft::map<MAP_T> FTmap_copy;
    ft::map<MAP_T> FTmap;

    FTmap.insert(FT_TYPE("a", 8));
    FTmap_copy.insert(FT_TYPE("b", 18));

    if (FTmap.value_comp()(*FTmap.begin(), *FTmap_copy.begin()))
      std::cout << OK " ";
    else
      std::cout << KO " ";

    if (!FTmap.value_comp()(*FTmap_copy.begin(), *FTmap.begin()))
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }

  std::cout << "\n\n===========[ OPERATIONS ]===========\n";
  {
    std::cout << "\n[ FIND ]\n";
    ft::map<MAP_T> FTmap;

    FTmap.insert(FT_TYPE("a", 8));

    if (FTmap.find("a") == FTmap.begin())
      std::cout << OK " ";
    else
      std::cout << KO " ";

    if (FTmap.find("b") == FTmap.end())
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }
  {
    std::cout << "\n[ COUNT ]\n";
    ft::map<MAP_T> FTmap;

    FTmap.insert(FT_TYPE("a", 8));

    if (FTmap.count("a") == 1)
      std::cout << OK " ";
    else
      std::cout << KO " ";

    if (FTmap.count("b") == 0)
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }
  {
    std::cout << "\n[ LOWER BOUND ]\n";
    ft::map<MAP_T> FTmap;
    std::map<MAP_T> ORmap;

    FTmap.insert(FT_TYPE("a", 8)), ORmap.insert(OR_TYPE("a", 8));
    FTmap.insert(FT_TYPE("b", 18)), ORmap.insert(OR_TYPE("b", 18));
    FTmap.insert(FT_TYPE("c", 5)), ORmap.insert(OR_TYPE("c", 5));
    FTmap.insert(FT_TYPE("d", 15)), ORmap.insert(OR_TYPE("d", 15));

    ft::map<MAP_T>::iterator FTit = FTmap.lower_bound("b");
    std::map<MAP_T>::iterator ORit = ORmap.lower_bound("b");

    if ((FTit->first == ORit->first) && (FTit->second == ORit->second))
      std::cout << OK " ";
    else
      std::cout << KO " ";

    FTit = FTmap.lower_bound("z");
    ORit = ORmap.lower_bound("z");

    if ((FTit == FTmap.end()) && (ORit == ORmap.end()))
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }
  {
    std::cout << "\n[ UPPER BOUND ]\n";
    ft::map<MAP_T> FTmap;
    std::map<MAP_T> ORmap;

    FTmap.insert(FT_TYPE("a", 8)), ORmap.insert(OR_TYPE("a", 8));
    FTmap.insert(FT_TYPE("b", 18)), ORmap.insert(OR_TYPE("b", 18));
    FTmap.insert(FT_TYPE("c", 5)), ORmap.insert(OR_TYPE("c", 5));
    FTmap.insert(FT_TYPE("d", 15)), ORmap.insert(OR_TYPE("d", 15));

    ft::map<MAP_T>::iterator FTit = FTmap.upper_bound("a");
    std::map<MAP_T>::iterator ORit = ORmap.upper_bound("a");

    if ((FTit->first == ORit->first) && (FTit->second == ORit->second))
      std::cout << OK " ";
    else
      std::cout << KO " ";

    FTit = FTmap.upper_bound("c");
    ORit = ORmap.upper_bound("c");

    if ((FTit->first == ORit->first) && (FTit->second == ORit->second))
      std::cout << OK " ";
    else
      std::cout << KO " ";

    FTit = FTmap.upper_bound("z");
    ORit = ORmap.upper_bound("z");

    if ((FTit == FTmap.end()) && (ORit == ORmap.end()))
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }
  {
    std::cout << "\n[ EQUAL RANGE ]\n";
    ft::map<MAP_T> FTmap;
    std::map<MAP_T> ORmap;

    FTmap.insert(FT_TYPE("a", 8)), ORmap.insert(OR_TYPE("a", 8));
    FTmap.insert(FT_TYPE("b", 18)), ORmap.insert(OR_TYPE("b", 18));
    FTmap.insert(FT_TYPE("c", 5)), ORmap.insert(OR_TYPE("c", 5));
    FTmap.insert(FT_TYPE("d", 15)), ORmap.insert(OR_TYPE("d", 15));

    ft::pair<ft::map<MAP_T>::iterator, ft::map<MAP_T>::iterator> FTPit;
    std::pair<std::map<MAP_T>::iterator, std::map<MAP_T>::iterator> ORPit;

    FTPit = FTmap.equal_range("a");
    ORPit = ORmap.equal_range("a");

    if ((FTPit.first->first == ORPit.first->first) &&
        (FTPit.first->second == ORPit.first->second) &&
        (FTPit.second->first == ORPit.second->first) &&
        (FTPit.second->second == ORPit.second->second))
      std::cout << OK " ";
    else
      std::cout << KO " ";

    FTPit = FTmap.equal_range("c");
    ORPit = ORmap.equal_range("c");

    if ((FTPit.first->first == ORPit.first->first) &&
        (FTPit.first->second == ORPit.first->second) &&
        (FTPit.second->first == ORPit.second->first) &&
        (FTPit.second->second == ORPit.second->second))
      std::cout << OK " ";
    else
      std::cout << KO " ";

    FTPit = FTmap.equal_range("z");
    ORPit = ORmap.equal_range("z");

    if ((FTPit.first == FTmap.end()) && (ORPit.first == ORmap.end()) &&
        (FTPit.second == FTmap.end()) && (ORPit.second == ORmap.end()))
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }

  std::cout << "\n\n===========[ ALLOCATOR ]===========\n";
  {
    std::cout << "\n[ GET_ALLOCATOR ]\n";
    ft::map<MAP_T> FTmap_copy;

    FTmap_copy.insert(FT_TYPE("a", 8));
    FTmap_copy.insert(FT_TYPE("b", 18));
    FTmap_copy.insert(FT_TYPE("c", 5));
    FTmap_copy.insert(FT_TYPE("d", 15));

    ft::map<MAP_T> FTmap(FTmap_copy.key_comp(), FTmap_copy.get_allocator());

    FTmap.insert(FT_TYPE("a", 8));
    FTmap.insert(FT_TYPE("b", 18));
    FTmap.insert(FT_TYPE("c", 5));
    FTmap.insert(FT_TYPE("d", 15));

    if (ft::equal(FTmap.begin(), FTmap.end(), FTmap_copy.begin(),
                  pred<FT_TYPE, FT_TYPE>))
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }

  std::cout << "\n\n===========[ RELATIONAL OPERATORS ]===========\n";
  {
    std::cout << "\n[ EQUAL (==) ]\n";
    ft::map<MAP_T> FTmap_copy;
    ft::map<MAP_T> FTmap;

    FTmap_copy.insert(FT_TYPE("a", 8)), FTmap.insert(FT_TYPE("a", 8));
    FTmap_copy.insert(FT_TYPE("b", 18)), FTmap.insert(FT_TYPE("b", 18));
    FTmap_copy.insert(FT_TYPE("c", 5)), FTmap.insert(FT_TYPE("c", 5));
    FTmap_copy.insert(FT_TYPE("d", 15)), FTmap.insert(FT_TYPE("d", 15));

    if (FTmap == FTmap_copy)
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }
  {
    std::cout << "\n[ DIFFERENT (!=) ]\n";
    ft::map<MAP_T> FTmap_copy;
    ft::map<MAP_T> FTmap;

    FTmap_copy.insert(FT_TYPE("a", 8)), FTmap.insert(FT_TYPE("a", 8));
    FTmap_copy.insert(FT_TYPE("b", 18)), FTmap.insert(FT_TYPE("b", 18));
    FTmap_copy.insert(FT_TYPE("c", 5)), FTmap.insert(FT_TYPE("c", 5));
    FTmap_copy.insert(FT_TYPE("d", 15)), FTmap.insert(FT_TYPE("e", 17));

    if (FTmap != FTmap_copy)
      std::cout << OK " ";
    else
      std::cout << KO " ";

    FTmap_copy.insert(FT_TYPE("e", 17)), FTmap.insert(FT_TYPE("d", 1));

    if (FTmap != FTmap_copy)
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }
  {
    std::cout << "\n[ MINOR (<) ]\n";
    ft::map<MAP_T> FTmap_copy;
    ft::map<MAP_T> FTmap;

    FTmap_copy.insert(FT_TYPE("a", 8)), FTmap.insert(FT_TYPE("a", 8));
    FTmap_copy.insert(FT_TYPE("b", 18)), FTmap.insert(FT_TYPE("b", 18));
    FTmap_copy.insert(FT_TYPE("c", 5)), FTmap.insert(FT_TYPE("c", 5));
    FTmap_copy.insert(FT_TYPE("d", 15));

    if (FTmap < FTmap_copy)
      std::cout << OK " ";
    else
      std::cout << KO " ";

    FTmap.insert(FT_TYPE("d", 17));

    if (FTmap_copy < FTmap)
      std::cout
          << OK " ";
    else
      std::cout << KO " ";
  }

  NEWLINE

  return (0);
}
