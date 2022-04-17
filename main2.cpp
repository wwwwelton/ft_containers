// Copyright (c) 2022 Welton Leite, wleite. All rights reserved.

#include <iostream>

#define KO "\033[1;31mKO\033[0m"
#define OK "\033[1;32mOK\033[0m"

// #if 1
// #include <vector>
// namespace ft = std;
// #else
// #include "./vector.hpp"
// #endif

#include <vector>

#include "./vector.hpp"

int main(void) {
  std::cout << "\n===========[ CONSTRUCTORS ]===========\n";
  {
    std::cout << "\n[ RANGE CONSTRUCTOR 1 ]\n";
    ft::vector<int> FTvec(10, 20);
    std::vector<int> ORvec(10, 20);
    ft::vector<int>::iterator FTit = FTvec.begin();
    std::vector<int>::iterator ORit = ORvec.begin();
    ft::vector<int>::iterator FTite = FTvec.end() - 1;
    std::vector<int>::iterator ORite = ORvec.end() - 1;
    if ((*FTit == *ORit) && (*FTite == *ORite))
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }

  {
    std::cout << "\n[ RANGE CONSTRUCTOR 2 ]\n";
    int n[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    ft::vector<int> FTvec(n, n + 9);
    std::vector<int> ORvec(n, n + 9);
    ft::vector<int>::iterator FTit = FTvec.begin();
    std::vector<int>::iterator ORit = ORvec.begin();
    ft::vector<int>::iterator FTite = FTvec.end() - 1;
    std::vector<int>::iterator ORite = ORvec.end() - 1;
    if ((*FTit == *ORit) && (*FTite == *ORite))
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }

  std::cout << "\n===========[ VECTOR ITERATORS ]===========\n";
  {
    std::cout << "\n[ BEGIN ITERATOR ]\n";
    ft::vector<int> FTvec(10);
    std::vector<int> ORvec(10);
    for (int i = 0; i < 10; i++) {
      FTvec[i] = i;
      ORvec[i] = i;
    }
    ft::vector<int>::iterator FTit = FTvec.begin();
    std::vector<int>::iterator ORit = ORvec.begin();
    if (*FTit == *ORit)
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }

  {
    std::cout << "\n[ BEGIN CONST ITERATOR ]\n";
    ft::vector<int> FTvec(10);
    std::vector<int> ORvec(10);
    for (int i = 0; i < 10; i++) {
      FTvec[i] = i;
      ORvec[i] = i;
    }
    ft::vector<int>::iterator FTit = FTvec.begin();
    std::vector<int>::iterator ORit = ORvec.begin();
    ft::vector<int>::const_iterator FCit = FTit;
    std::vector<int>::const_iterator ORCit = ORit;
    if ((FTit == FCit) && (ORit == ORCit))
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }

  {
    std::cout << "\n[ END ITERATOR ]\n";
    int size = 10;
    ft::vector<int> FTvec(size);
    std::vector<int> ORvec(size);
    for (int i = 0; i < size; i++) {
      FTvec[i] = i;
      ORvec[i] = i;
    }
    ft::vector<int>::iterator FTit = FTvec.begin() + size;
    std::vector<int>::iterator ORit = ORvec.begin() + size;
    ft::vector<int>::iterator FTite = FTvec.end();
    std::vector<int>::iterator ORite = ORvec.end();
    if ((FTit == FTite) && (ORit == ORite))
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }

  {
    std::cout << "\n[ END CONST ITERATOR ]\n";
    int size = 10;
    ft::vector<int> FTvec(size);
    std::vector<int> ORvec(size);
    for (int i = 0; i < size; i++) {
      FTvec[i] = i;
      ORvec[i] = i;
    }
    ft::vector<int>::const_iterator FTit = FTvec.begin() + size;
    std::vector<int>::const_iterator ORit = ORvec.begin() + size;
    ft::vector<int>::iterator FTite = FTvec.end();
    std::vector<int>::iterator ORite = ORvec.end();
    if ((FTit == FTite) && (ORit == ORite))
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }

  {
    std::cout << "\n[ RBEGIN ITERATOR ]\n";
    int size = 10;
    ft::vector<int> FTvec(size);
    std::vector<int> ORvec(size);
    for (int i = 0; i < size; i++) {
      FTvec[i] = i;
      ORvec[i] = i;
    }
    ft::vector<int>::reverse_iterator FTitrb = FTvec.rbegin();
    std::vector<int>::reverse_iterator ORitrb = ORvec.rbegin();
    if (*FTitrb == *ORitrb)
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }

  {
    std::cout << "\n[ RBEGIN CONST ITERATOR ]\n";
    int size = 10;
    ft::vector<int> FTvec(size);
    std::vector<int> ORvec(size);
    for (int i = 0; i < size; i++) {
      FTvec[i] = i;
      ORvec[i] = i;
    }
    ft::vector<int>::reverse_iterator FTitrb = FTvec.rbegin();
    std::vector<int>::reverse_iterator ORitrb = ORvec.rbegin();
    ft::vector<int>::const_reverse_iterator FTitrbc = FTvec.rbegin();
    std::vector<int>::const_reverse_iterator ORitrbc = ORvec.rbegin();
    if ((FTitrb == FTitrbc) && (ORitrb == ORitrbc))
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }

  {
    std::cout << "\n[ REND ITERATOR ]\n";
    int size = 10;
    ft::vector<int> FTvec(size);
    std::vector<int> ORvec(size);
    for (int i = 0; i < size; i++) {
      FTvec[i] = i;
      ORvec[i] = i;
    }
    ft::vector<int>::reverse_iterator FTitre = FTvec.rend() - 1;
    std::vector<int>::reverse_iterator ORitre = ORvec.rend() - 1;
    if (*FTitre == *ORitre)
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }

  {
    std::cout << "\n[ REND CONST ITERATOR ]\n";
    int size = 10;
    ft::vector<int> FTvec(size);
    std::vector<int> ORvec(size);
    for (int i = 0; i < size; i++) {
      FTvec[i] = i;
      ORvec[i] = i;
    }
    ft::vector<int>::reverse_iterator FTitrb = FTvec.rend();
    std::vector<int>::reverse_iterator ORitrb = ORvec.rend();
    ft::vector<int>::const_reverse_iterator FTitrbc = FTvec.rend();
    std::vector<int>::const_reverse_iterator ORitrbc = ORvec.rend();
    if ((FTitrb == FTitrbc) && (ORitrb == ORitrbc))
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }

  std::cout << "\n\n===========[ VECTOR CAPACITY ]===========\n";

  {
    std::cout << "\n[ SIZE ]\n";
    ft::vector<int> FTvec;
    std::vector<int> ORvec;
    if (FTvec.size() == ORvec.size())
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }
  {
    ft::vector<int> FTvec(10);
    std::vector<int> ORvec(10);
    if (FTvec.size() == ORvec.size())
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }

  {
    std::cout << "\n[ MAX_SIZE ]\n";
    ft::vector<int> FTvec;
    std::vector<int> ORvec;
    if (FTvec.max_size() == ORvec.max_size())
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }
  {
    ft::vector<int> FTvec(10);
    std::vector<int> ORvec(10);
    if (FTvec.max_size() == ORvec.max_size())
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }

  {
    std::cout << "\n[ CAPACITY ]\n";
    ft::vector<int> FTvec;
    std::vector<int> ORvec;
    if (FTvec.capacity() == FTvec.capacity())
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }
  {
    ft::vector<int> FTvec(10);
    std::vector<int> ORvec(10);
    if (FTvec.capacity() == FTvec.capacity())
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }

  {
    std::cout << "\n[ EMPTY ]\n";
    ft::vector<int> FTvec;
    std::vector<int> ORvec;
    if (FTvec.empty() == FTvec.empty())
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }

  {
    std::cout << "\n[ RESERVE ]\n";
    ft::vector<int> FTvec;
    std::vector<int> ORvec;
    FTvec.reserve(10);
    ORvec.reserve(10);
    if ((FTvec.capacity() == ORvec.capacity()) && (FTvec.size() == ORvec.size()))
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }

  std::cout << "\n\n===========[ VECTOR ELEMENT ACCESS ]===========\n";

  {
    std::cout << "\n[ OPERATOR[] ]\n";
    ft::vector<int> FTvec(10);
    std::vector<int> ORvec(10);
    for (int i = 0; i < 10; i++) {
      FTvec[i] = i;
      ORvec[i] = i;
    }
    if (FTvec[5] == ORvec[5])
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }

  {
    std::cout << "\n[ AT ]\n";
    ft::vector<int> FTvec(10);
    std::vector<int> ORvec(10);
    for (int i = 0; i < 10; i++) {
      FTvec[i] = i;
      ORvec[i] = i;
    }
    if (FTvec.at(5) == ORvec.at(5))
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }
  {
    ft::vector<int> FTvec(10);
    for (int i = 0; i < 10; i++) {
      FTvec[i] = i;
    }
    try {
      int FTvecVal = FTvec.at(100);
      (void)FTvecVal;
      std::cout << KO " ";
    } catch (const std::exception& e) {
      std::cout << OK " ";
    }
  }
  {
    ft::vector<int> FTvec(10);
    for (int i = 0; i < 10; i++) {
      FTvec[i] = i;
    }
    try {
      int FTvecVal = FTvec.at(-1);
      (void)FTvecVal;
      std::cout << KO " ";
    } catch (const std::exception& e) {
      std::cout << OK " ";
    }
  }

  {
    std::cout << "\n[ FRONT ]\n";
    ft::vector<int> FTvec(10);
    std::vector<int> ORvec(10);
    for (int i = 0; i < 10; i++) {
      FTvec[i] = i;
      ORvec[i] = i;
    }
    if (FTvec.front() == ORvec.front())
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }

  {
    std::cout << "\n[ BACK ]\n";
    ft::vector<int> FTvec(10);
    std::vector<int> ORvec(10);
    for (int i = 0; i < 10; i++) {
      FTvec[i] = i;
      ORvec[i] = i;
    }
    if (FTvec.back() == ORvec.back())
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }

  std::cout << "\n\n===========[ VECTOR MODIFIERS ]===========\n";
  // ASSIGN
  {
    std::cout << "\n[ ASSIGN 1 ]\n";
    ft::vector<int> FTvec;
    std::vector<int> ORvec;
    FTvec.assign(10, 20);
    ORvec.assign(10, 20);
    ft::vector<int>::iterator FTit = FTvec.begin();
    std::vector<int>::iterator ORit = ORvec.begin();
    ft::vector<int>::iterator FTite = FTvec.end() - 1;
    std::vector<int>::iterator ORite = ORvec.end() - 1;
    if ((*FTit == *ORit) && (*FTite == *ORite))
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }

  {
    std::cout << "\n[ ASSIGN 2 ]\n";
    int n[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    ft::vector<int> FTvec;
    std::vector<int> ORvec;
    FTvec.assign(n, n + 9);
    ORvec.assign(n, n + 9);
    ft::vector<int>::iterator FTit = FTvec.begin();
    std::vector<int>::iterator ORit = ORvec.begin();
    ft::vector<int>::iterator FTite = FTvec.end() - 1;
    std::vector<int>::iterator ORite = ORvec.end() - 1;
    if ((*FTit == *ORit) && (*FTite == *ORite))
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }
  // ASSIGN

  // PUSH_BACK
  {
    std::cout << "\n[ PUSH_BACK ]\n";
    ft::vector<int> FTvec(10);
    std::vector<int> ORvec(10);
    for (int i = 0; i < 10; i++) {
      FTvec[i] = i;
      ORvec[i] = i;
    }
    FTvec.push_back(11);
    FTvec.push_back(22);
    ORvec.push_back(11);
    ORvec.push_back(22);
    ft::vector<int>::iterator FTit = FTvec.end() - 1;
    std::vector<int>::iterator ORit = ORvec.end() - 1;
    if (*FTit == *ORit)
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }
  {
    ft::vector<int> FTvec(10);
    std::vector<int> ORvec(10);
    for (int i = 0; i < 10; i++) {
      FTvec[i] = i;
      ORvec[i] = i;
    }
    FTvec.push_back(11);
    FTvec.push_back(22);
    ORvec.push_back(11);
    ORvec.push_back(22);
    if (FTvec.size() == ORvec.size())
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }
  {
    ft::vector<int> FTvec(10);
    std::vector<int> ORvec(10);
    for (int i = 0; i < 10; i++) {
      FTvec[i] = i;
      ORvec[i] = i;
    }
    FTvec.push_back(11);
    FTvec.push_back(22);
    ORvec.push_back(11);
    ORvec.push_back(22);
    if (FTvec.capacity() == ORvec.capacity())
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }
  // PUSH_BACK

  // POP_BACK
  {
    std::cout << "\n[ POP_BACK ]\n";
    ft::vector<int> FTvec(10);
    std::vector<int> ORvec(10);
    for (int i = 0; i < 10; i++) {
      FTvec[i] = i;
      ORvec[i] = i;
    }
    FTvec.pop_back();
    ORvec.pop_back();
    ft::vector<int>::iterator FTit = FTvec.begin();
    std::vector<int>::iterator ORit = ORvec.begin();
    ft::vector<int>::iterator FTite = FTvec.end() - 1;
    std::vector<int>::iterator ORite = ORvec.end() - 1;
    if ((*FTit == *ORit) && (FTvec.size() == ORvec.size()) && *FTite == *ORite)
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }
  // POP_BACK

  {
    std::cout << "\n[ ERASE ]\n";
    ft::vector<int> FTvec(10);
    std::vector<int> ORvec(10);
    for (int i = 0; i < 10; i++) {
      FTvec[i] = i;
      ORvec[i] = i;
    }
    ft::vector<int>::iterator FTit = FTvec.begin();
    std::vector<int>::iterator ORit = ORvec.begin();
    ft::vector<int>::iterator FTite = FTvec.erase(FTit);
    std::vector<int>::iterator ORite = ORvec.erase(ORit);
    if ((*FTit == *ORit) && (*FTite == *ORite))
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }

  {
    std::cout << "\n[ ERASE ITERATOR ]\n";
    ft::vector<int> FTvec(10);
    std::vector<int> ORvec(10);
    for (int i = 0; i < 10; i++) {
      FTvec[i] = i;
      ORvec[i] = i;
    }
    ft::vector<int>::iterator FTit1 = FTvec.begin();
    std::vector<int>::iterator ORit1 = ORvec.begin();
    ft::vector<int>::iterator FTit2 = FTvec.begin() + 5;
    std::vector<int>::iterator ORit2 = ORvec.begin() + 5;
    ft::vector<int>::iterator FTite = FTvec.erase(FTit1, FTit2);
    std::vector<int>::iterator ORite = ORvec.erase(ORit1, ORit2);
    if ((*FTit1 == *ORit1) && (*FTite == *ORite) &&
        (FTvec.size() == ORvec.size()))
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }

  {
    std::cout << "\n[ SWAP ]\n";
    ft::vector<int> FTveca(10);
    ft::vector<int> FTvec(10);
    std::vector<int> ORvec(10);
    for (int i = 0; i < 10; i++) {
      FTvec[i] = i;
      ORvec[i] = i + 2;
      FTveca[i] = i + 2;
    }
    FTvec.swap(FTveca);
    ft::vector<int>::iterator FTit1 = FTvec.begin();
    std::vector<int>::iterator ORit1 = ORvec.begin();
    if ((*FTit1 == *ORit1) && (FTvec.size() == ORvec.size()))
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }

  {
    std::cout << "\n[ CLEAR ]\n";
    ft::vector<int> FTvec(10);
    std::vector<int> ORvec(10);
    for (int i = 0; i < 10; i++) {
      FTvec[i] = i;
      ORvec[i] = i;
    }
    if ((FTvec.size() == ORvec.size()) && (FTvec.capacity() == ORvec.capacity()))
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }

  {
    std::cout << "\n[ INSERT 1 ]\n";
    ft::vector<int> FTvec(10);
    std::vector<int> ORvec(10);
    for (int i = 0; i < 10; i++) {
      FTvec[i] = i;
      ORvec[i] = i;
    }
    ft::vector<int>::iterator FTiti = FTvec.insert(FTvec.begin() + 9, 5);
    std::vector<int>::iterator ORiti = ORvec.insert(ORvec.begin() + 9, 5);
    ft::vector<int>::iterator FTit = FTvec.begin();
    std::vector<int>::iterator ORit = ORvec.begin();
    if ((FTvec.size() == ORvec.size()) &&
        (FTvec.capacity() == ORvec.capacity()) &&
        (*FTit == *ORit) && (*FTiti == *ORiti))
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }

  {
    std::cout << "\n[ INSERT 2 ]\n";
    ft::vector<int> FTvec(10);
    std::vector<int> ORvec(10);
    for (int i = 0; i < 10; i++) {
      FTvec[i] = i;
      ORvec[i] = i;
    }
    FTvec.insert(FTvec.begin(), 3, 5);
    ORvec.insert(ORvec.begin(), 3, 5);
    ft::vector<int>::iterator FTit = FTvec.begin();
    std::vector<int>::iterator ORit = ORvec.begin();
    if ((FTvec.size() == ORvec.size()) &&
        (FTvec.capacity() == ORvec.capacity()) && (*FTit == *ORit))
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }

  {
    std::cout << "\n[ INSERT 3 ]\n";
    ft::vector<int> FTvec(13);
    std::vector<int> ORvec(13);
    for (int i = 0; i < 13; i++) {
      FTvec[i] = i;
      ORvec[i] = i;
    }
    FTvec.insert(FTvec.begin(), 5, 13);
    ORvec.insert(ORvec.begin(), 5, 13);
    ft::vector<int>::iterator FTit = FTvec.begin();
    std::vector<int>::iterator ORit = ORvec.begin();
    if ((FTvec.size() == ORvec.size()) &&
        (FTvec.capacity() == ORvec.capacity()) && (*FTit == *ORit))
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }

  {
    std::cout << "\n[ INSERT 4 / 1]\n";
    ft::vector<int> FTvec;
    std::vector<int> ORvec;
    int myarray[] = {501, 502, 503};
    FTvec.insert(FTvec.begin() + 0, myarray, myarray + 3);
    ORvec.insert(ORvec.begin() + 0, myarray, myarray + 3);
    ft::vector<int>::iterator FTit = FTvec.begin();
    std::vector<int>::iterator ORit = ORvec.begin();
    if ((FTvec.size() == ORvec.size()) &&
        (FTvec.capacity() == ORvec.capacity()) && (*FTit == *ORit))
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }

  {
    std::cout << "\n[ INSERT 4 / 2 ]\n";
    ft::vector<int> FTvec(13);
    std::vector<int> ORvec(13);
    for (int i = 0; i < 13; i++) {
      FTvec[i] = i;
      ORvec[i] = i;
    }
    int myarray[] = {501, 502, 503};
    FTvec.insert(FTvec.begin() + 0, myarray, myarray + 3);
    ORvec.insert(ORvec.begin() + 0, myarray, myarray + 3);
    ft::vector<int>::iterator FTit = FTvec.begin();
    std::vector<int>::iterator ORit = ORvec.begin();
    if ((FTvec.size() == ORvec.size()) &&
        (FTvec.capacity() == ORvec.capacity()) && (*FTit == *ORit))
      std::cout << OK " ";
    else
      std::cout << KO " ";
  }

  return (0);
}
