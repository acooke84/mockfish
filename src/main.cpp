#include <iostream>
#include "bitboard.h"

int main (int argc, char *argv[])
{
  std::cout << mockfish::bitboard::pretty_print(mockfish::Rank_7BB) << std::endl;
  std::cout << mockfish::bitboard::pretty_print(mockfish::File_BBB) << std::endl;
  return 0;
}

