#include "bitboard.h"
#include <iostream>
#include <string>

namespace mockfish {

std::string bitboard::pretty_print(Bitboard bb) {
  std::string out;
  out += "+---+---+---+---+---+---+---+---+\n";
  for (Rank r = RANK_8; r >= RANK_1; --r) {
    for (File f = FILE_A; f <= FILE_H; ++f) {
      out += (bb & make_square(f, r)) ? "| ■ " : "|   ";
    }
    out += "| " + std::to_string(1 + r) + "\n+---+---+---+---+---+---+---+---+\n";
  }
  out += "  a   b   c   d   e   f   g   h \n";
  return out;
}

}   // namespace mockfish
