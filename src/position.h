#ifndef INCLUDED_POSITION
#define INCLUDED_POSITION

#include "types.h"
#include <string>

namespace mockfish {

class Position {
public:
  void from_fen(const std::string& fen);
  std::string to_fen();

  void put_piece(Piece p, Square s);
  Piece remove_piece(Square s);
private:
  Piece board[SQ_END];
  Bitboard byPieceTypeBB[PIECE_TYPE_END];
  Bitboard byColorBB[COLOR_END];
  int pieceCount[PIECE_END];
};


inline void Position::put_piece(Piece p, Square s) {
  board[s] = p;
  byPieceTypeBB[type_of(p)] |= s;
  byPieceTypeBB[ALL_PIECES] |= s;
  byColorBB[color_of(p)] |= s;
  pieceCount[p]++;
  pieceCount[make_piece(color_of(p), ALL_PIECES)]++;
}

inline Piece Position::remove_piece(Square s) {
  Piece p = board[s];
  byPieceTypeBB[type_of(p)] ^= s;
  byPieceTypeBB[ALL_PIECES] ^= s;
  byColorBB[color_of(p)] ^= s;
  pieceCount[p]--;
  pieceCount[make_piece(color_of(p), ALL_PIECES)]--;
  return p;
}

} // namespace mockfish

#endif
