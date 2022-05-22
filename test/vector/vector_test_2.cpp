// Copyright (c) 2022 Welton Leite, wleite. All rights reserved.

#include <iostream>

#if STD == 1
#include <vector>
namespace ft = std;
#else
#include "../../vector.hpp"
#endif

bool pred(int i, int j) {
  return (i == j);
}

template <typename T>
void print_vector(T& vector) {
  for (size_t i = 0; i < vector.size(); i++) {
    std::cout << vector[i] << " ";
  }
  std::cout << "\n";
  std::cout << "size: " << vector.size() << "\n";
  std::cout << "capacity: " << vector.capacity() << "\n";
}

template <typename T>
void print_iterator(T it) {
  std::cout << "iterator: " << *it << "\n";
}

template <typename T>
void fill_vector(T& vector, int size) {
  for (int i = 0; i < size; i++) {
    vector[i] = i;
  }
}

int main(void) {
  std::cout << "\n===========[ CONSTRUCTORS ]===========\n";
  {
    std::cout << "\n[ CONSTRUCTOR 1 ]\n";
    ft::vector<int> FTvec;
    print_vector(FTvec);
  }

  {
    std::cout << "\n[ CONSTRUCTOR 2 ]\n";
    ft::vector<int> FTvec(10, 20);
    print_vector(FTvec);
  }

  {
    std::cout << "\n[ CONSTRUCTOR 3 ]\n";
    int n[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    ft::vector<int> FTvec(n, n + 10);
    print_vector(FTvec);
  }

  std::cout << "\n\n===========[ VECTOR ITERATORS ]===========\n";
  {
    std::cout << "\n[ CONST VS NORMAL ]\n";
    ft::vector<int> FTvec(10);
    for (int i = 0; i < 10; i++) {
      FTvec[i] = i;
    }
    ft::vector<int> FTvecConst(FTvec.begin(), FTvec.end());

    ft::vector<int>::iterator FTit = FTvec.begin();
    ft::vector<int>::const_iterator FTitConst = FTvecConst.begin();

    std::cout << (*FTit == *FTitConst) << "\n";

    ft::vector<int>::iterator FTitEnd = FTvec.end() - 1;
    ft::vector<int>::const_iterator FTitConstEnd = FTvecConst.end() - 1;

    std::cout << (*FTitEnd == *FTitConstEnd) << "\n";
  }

  {
    std::cout << "\n[ BEGIN ITERATOR ]\n";
    ft::vector<int> FTvec(10);
    fill_vector(FTvec, 10);
    ft::vector<int>::iterator FTit = FTvec.begin();
    print_iterator(FTit);
    print_vector(FTvec);
  }

  {
    std::cout << "\n[ BEGIN CONST ITERATOR ]\n";
    ft::vector<int> FTvec(10);
    fill_vector(FTvec, 10);
    ft::vector<int>::const_iterator FCit = FTvec.begin();
    print_iterator(FCit);
    print_vector(FTvec);
  }

  {
    std::cout << "\n[ END ITERATOR ]\n";
    ft::vector<int> FTvec(10);
    fill_vector(FTvec, 10);
    ft::vector<int>::iterator FTit = FTvec.end() - 1;
    print_iterator(FTit);
    print_vector(FTvec);
  }

  {
    std::cout << "\n[ END CONST ITERATOR ]\n";
    ft::vector<int> FTvec(10);
    fill_vector(FTvec, 10);
    ft::vector<int>::const_iterator FTit = FTvec.end() - 1;
    print_iterator(FTit);
    print_vector(FTvec);
  }

  {
    std::cout << "\n[ RBEGIN ITERATOR ]\n";
    ft::vector<int> FTvec(10);
    fill_vector(FTvec, 10);
    ft::vector<int>::reverse_iterator FTit = FTvec.rbegin();
    print_iterator(FTit);
    print_vector(FTvec);
  }

  {
    std::cout << "\n[ RBEGIN CONST ITERATOR ]\n";
    ft::vector<int> FTvec(10);
    fill_vector(FTvec, 10);
    ft::vector<int>::const_reverse_iterator FTit = FTvec.rbegin();
    print_iterator(FTit);
    print_vector(FTvec);
  }

  {
    std::cout << "\n[ REND ITERATOR ]\n";
    ft::vector<int> FTvec(10);
    fill_vector(FTvec, 10);
    ft::vector<int>::reverse_iterator FTit = FTvec.rend() - 1;
    print_iterator(FTit);
    print_vector(FTvec);
  }

  {
    std::cout << "\n[ REND CONST ITERATOR ]\n";
    ft::vector<int> FTvec(10);
    fill_vector(FTvec, 10);
    ft::vector<int>::const_reverse_iterator FTit = FTvec.rend() - 1;
    print_iterator(FTit);
    print_vector(FTvec);
  }

  std::cout << "\n\n===========[ VECTOR CAPACITY ]===========\n";

  {
    std::cout << "\n[ SIZE ]\n";
    ft::vector<int> FTvec;
    print_vector(FTvec);
  }
  {
    std::cout << "\n[ SIZE ]\n";
    ft::vector<int> FTvec(20);
    fill_vector(FTvec, 20);
    print_vector(FTvec);
  }
  {
    std::cout << "\n[ SIZE ]\n";
    ft::vector<int> FTvec(50);
    fill_vector(FTvec, 50);
    print_vector(FTvec);
  }

  {
    std::cout << "\n[ MAX_SIZE ]\n";
    ft::vector<int> FTvec(10);
    fill_vector(FTvec, 10);
    std::cout << "max_size: " << FTvec.max_size() << "\n";
    print_vector(FTvec);
  }

  {
    std::cout << "\n[ RESIZE 1]\n";
    ft::vector<int> FTvec(10);
    fill_vector(FTvec, 10);
    print_vector(FTvec);
    FTvec.resize(5);
    std::cout << "\n";
    print_vector(FTvec);
  }
  {
    std::cout << "\n[ RESIZE 2 ]\n";
    ft::vector<int> FTvec(5);
    fill_vector(FTvec, 5);
    FTvec.resize(5, 10);
    print_vector(FTvec);
  }

  {
    std::cout << "\n[ CAPACITY ]\n";
    ft::vector<int> FTvec;
    print_vector(FTvec);
  }
  {
    std::cout << "\n[ CAPACITY ]\n";
    ft::vector<int> FTvec(20);
    fill_vector(FTvec, 20);
    print_vector(FTvec);
  }
  {
    std::cout << "\n[ CAPACITY ]\n";
    ft::vector<int> FTvec(50);
    fill_vector(FTvec, 50);
    print_vector(FTvec);
  }

  {
    std::cout << "\n[ EMPTY FALSE ]\n";
    ft::vector<int> FTvec(10);
    fill_vector(FTvec, 10);
    print_vector(FTvec);
    std::cout << "is empty? " << FTvec.empty() << "\n";
  }

  {
    std::cout << "\n[ EMPTY TRUE ]\n";
    ft::vector<int> FTvec;
    print_vector(FTvec);
    std::cout << "is empty? " << FTvec.empty() << "\n";
  }

  {
    std::cout << "\n[ RESERVE ]\n";
    ft::vector<int> FTvec;
    print_vector(FTvec);
    FTvec.reserve(10);
  }

  std::cout << "\n\n===========[ VECTOR ELEMENT ACCESS ]===========\n";

  {
    std::cout << "\n[ OPERATOR[] ]\n";
    ft::vector<int> FTvec(10);
    fill_vector(FTvec, 10);
    print_vector(FTvec);
    std::cout << "index [3] = " << FTvec[3] << "\n";
  }

  {
    std::cout << "\n[ AT ]\n";
    ft::vector<int> FTvec(10);
    fill_vector(FTvec, 10);
    print_vector(FTvec);
    std::cout << "at index 3 = " << FTvec.at(3) << "\n";
  }

  {
    std::cout << "\n[ FRONT ]\n";
    ft::vector<int> FTvec(10);
    fill_vector(FTvec, 10);
    print_vector(FTvec);
    std::cout << "front = " << FTvec.front() << "\n";
  }

  {
    std::cout << "\n[ BACK ]\n";
    ft::vector<int> FTvec(10);
    fill_vector(FTvec, 10);
    print_vector(FTvec);
    std::cout << "back = " << FTvec.back() << "\n";
  }

  std::cout << "\n\n===========[ VECTOR MODIFIERS ]===========\n";
  // ASSIGN
  {
    std::cout << "\n[ ASSIGN 1 ]\n";
    ft::vector<int> FTvec;
    FTvec.assign(10, 20);
    print_vector(FTvec);
  }

  {
    std::cout << "\n[ ASSIGN 2 ]\n";
    int n[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    ft::vector<int> FTvec;
    FTvec.assign(n, n + 10);
    print_vector(FTvec);
  }
  // ASSIGN

  // PUSH_BACK
  {
    std::cout << "\n[ PUSH_BACK ]\n";
    ft::vector<int> FTvec(10);
    fill_vector(FTvec, 10);
    print_vector(FTvec);
    FTvec.push_back(11);
    FTvec.push_back(22);
    print_vector(FTvec);
  }
  // PUSH_BACK

  // POP_BACK
  {
    std::cout << "\n[ POP_BACK ]\n";
    ft::vector<int> FTvec(10);
    fill_vector(FTvec, 10);
    print_vector(FTvec);
    FTvec.pop_back();
    print_vector(FTvec);
  }
  // POP_BACK

  {
    std::cout << "\n[ INSERT 1 ]\n";
    ft::vector<int> FTvec(10);
    fill_vector(FTvec, 10);
    print_vector(FTvec);
    FTvec.insert(FTvec.begin() + 9, 5);
    print_vector(FTvec);
  }

  {
    std::cout << "\n[ INSERT 2 ]\n";
    ft::vector<int> FTvec(10);
    fill_vector(FTvec, 10);
    print_vector(FTvec);
    FTvec.insert(FTvec.begin(), 3, 5);
    print_vector(FTvec);
  }

  {
    std::cout << "\n[ INSERT 3 ]\n";
    ft::vector<int> FTvec(13);
    fill_vector(FTvec, 10);
    print_vector(FTvec);
    FTvec.insert(FTvec.begin(), 5, 13);
    print_vector(FTvec);
  }

  {
    std::cout << "\n[ INSERT 4 / 1]\n";
    ft::vector<int> FTvec;
    int myarray[] = {501, 502, 503};
    FTvec.insert(FTvec.begin() + 0, myarray, myarray + 3);
    print_vector(FTvec);
  }

  {
    std::cout << "\n[ INSERT 4 / 2 ]\n";
    ft::vector<int> FTvec(13);
    fill_vector(FTvec, 10);
    int myarray[] = {501, 502, 503};
    print_vector(FTvec);
    FTvec.insert(FTvec.begin() + 0, myarray, myarray + 3);
    print_vector(FTvec);
  }

  {
    std::cout << "\n[ ERASE ]\n";
    ft::vector<int> FTvec(10);
    fill_vector(FTvec, 10);
    print_vector(FTvec);
    ft::vector<int>::iterator FTit = FTvec.begin();
    FTvec.erase(FTit);
    print_vector(FTvec);
  }
  {
    std::cout << "\n[ ERASE ITERATOR ]\n";
    ft::vector<int> FTvec(10);
    fill_vector(FTvec, 10);
    ft::vector<int>::iterator FTit1 = FTvec.begin();
    ft::vector<int>::iterator FTit2 = FTvec.begin() + 5;
    print_vector(FTvec);
    FTvec.erase(FTit1, FTit2);
    print_vector(FTvec);
  }

  {
    std::cout << "\n[ SWAP ]\n";
    ft::vector<int> FTveca(10);
    ft::vector<int> FTvec(10);
    for (int i = 0; i < 10; i++) {
      FTveca[i] = i + 10;
      FTvec[i] = i;
    }
    print_vector(FTvec);
    FTvec.swap(FTveca);
    print_vector(FTvec);
  }

  {
    std::cout << "\n[ CLEAR ]\n";
    ft::vector<int> FTvec(10);
    fill_vector(FTvec, 10);
    print_vector(FTvec);
    FTvec.clear();
    print_vector(FTvec);
  }

  std::cout << "\n===========[ COMPARE ]===========\n";

  {
    std::cout << "\n[ EQUAL ]\n";
    int v1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    ft::vector<int> FTvec(10);
    fill_vector(FTvec, 10);
    std::cout << "is equal? " << ft::equal(FTvec.begin(), FTvec.end(), v1) << "\n";
  }

  {
    std::cout << "\n[ EQUAL PRED ]\n";
    int v1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    ft::vector<int> FTvec(10);
    fill_vector(FTvec, 10);
    std::cout << "is equal? " << ft::equal(FTvec.begin(), FTvec.end(), v1, pred) << "\n";
  }

  {
    std::cout << "\n[ LEXICOGRAPHICAL ]\n";
    ft::vector<int> FTvec1(10);
    ft::vector<int> FTvec2(10);
    fill_vector(FTvec1, 10);
    fill_vector(FTvec2, 10);
    std::cout << "is equal? " << !ft::lexicographical_compare(FTvec1.begin(), FTvec1.end(), FTvec2.begin(), FTvec2.end()) << "\n";
  }

  {
    std::cout << "\n[ LEXICOGRAPHICAL PRED ]\n";
    ft::vector<int> FTvec1(10);
    ft::vector<int> FTvec2(10);
    fill_vector(FTvec1, 10);
    fill_vector(FTvec2, 10);
    std::cout << "is equal? " << ft::lexicographical_compare(FTvec1.begin(), FTvec1.end(), FTvec2.begin(), FTvec2.end(), pred) << "\n";
  }

  std::cout << "\n\n===========[ RELATIONAL OPERATORS ]===========\n";

  {
    std::cout << "\n[ OPERATOR == ]\n";
    ft::vector<int> FTvec1(10);
    ft::vector<int> FTvec2(10);
    fill_vector(FTvec1, 10);
    fill_vector(FTvec2, 10);
    std::cout << "is equal? " << (FTvec1 == FTvec2) << "\n";
  }

  {
    std::cout << "\n[ OPERATOR != ]\n";
    ft::vector<int> FTvec1(10);
    ft::vector<int> FTvec2(10);
    fill_vector(FTvec1, 10);
    fill_vector(FTvec2, 10);
    std::cout << "is different? " << (FTvec1 != FTvec2) << "\n";
  }

  {
    std::cout << "\n[ OPERATOR < ]\n";
    ft::vector<int> FTvec1(9);
    ft::vector<int> FTvec2(10);
    fill_vector(FTvec1, 9);
    fill_vector(FTvec2, 10);
    std::cout << "is minor? " << (FTvec1 < FTvec2) << "\n";
  }

  {
    std::cout << "\n[ OPERATOR <= ]\n";
    ft::vector<int> FTvec1(10);
    ft::vector<int> FTvec2(10);
    fill_vector(FTvec1, 10);
    fill_vector(FTvec2, 10);
    std::cout << "is minor or equal? " << (FTvec1 <= FTvec2) << "\n";
  }

  {
    std::cout << "\n[ OPERATOR > ]\n";
    ft::vector<int> FTvec1(10);
    ft::vector<int> FTvec2(9);
    fill_vector(FTvec1, 10);
    fill_vector(FTvec2, 9);
    std::cout << "is bigger? " << (FTvec1 > FTvec2) << "\n";
  }

  {
    std::cout << "\n[ OPERATOR >= ]\n";
    ft::vector<int> FTvec1(10);
    ft::vector<int> FTvec2(9);
    fill_vector(FTvec1, 10);
    fill_vector(FTvec2, 9);
    std::cout << "is bigger or equal? " << (FTvec1 >= FTvec2) << "\n";
  }

  std::cout << "\n";

  return (0);
}
