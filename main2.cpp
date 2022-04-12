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
  std::cout << "\n===========[ VECTOR ]==========\n";
  {
      {std::cout << "\n[ SIZE ]\n";
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
}

{
    {std::cout << "\n[ CAPACITY ]\n";
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
}

{
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
}

return (0);
}
