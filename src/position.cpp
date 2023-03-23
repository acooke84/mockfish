#include "position.h"
#include <cctype>
#include <ios>
#include <sstream>
#include <string_view>

namespace mockfish {

namespace {

constexpr std::string_view pieceToChar(" PNBRQK  pnbrqk", 15);

}

// example fen:
// rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1
void Position::from_fen(const std::string& fen) {
  std::istringstream is(fen); 
  is >> std::noskipws;
  unsigned char token;
  Square s = SQ_A8;

  while ((is >> token) && !std::isspace(token)) {

  }
}

std::string Position::to_fen() {
  std::string fen;
  return fen;
}

}
