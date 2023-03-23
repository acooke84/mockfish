#ifndef INCLUDED_TYPES
#define INCLUDED_TYPES

#include <cassert>
#include <cstdint>

namespace mockfish {

using Bitboard = std::uint64_t;

enum Color : int {
  WHITE, BLACK, COLOR_END = 2
};


// Move:
//   bits 0-5   : start_square
//   bits 6-11  : destination_square
//   bits 12-13 : promotion_type (00 knight, 01 bishop, 10 rook, 11 queen)
//   bits 14-15 : special_move (00 normal 01 en passant 10 promotion 11 castle)
enum Move : int {
  MOVE_NONE = 0,
};

enum PieceType : int {
  NO_PIECE_TYPE, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING,
  ALL_PIECES = 0,
  PIECE_TYPE_END = 8
};

enum Piece : int {
  NO_PIECE,
  W_PAWN = PAWN, W_KNIGHT, W_BISHOP, W_ROOK, W_QUEEN, W_KING,
  B_PAWN = W_PAWN + 8, B_KNIGHT, B_BISHOP, B_ROOK, B_QUEEN, B_KING,
  PIECE_END = 16
};

enum Square : int {
  SQ_A1, SQ_B1, SQ_C1, SQ_D1, SQ_E1, SQ_F1, SQ_G1, SQ_H1,
  SQ_A2, SQ_B2, SQ_C2, SQ_D2, SQ_E2, SQ_F2, SQ_G2, SQ_H2,
  SQ_A3, SQ_B3, SQ_C3, SQ_D3, SQ_E3, SQ_F3, SQ_G3, SQ_H3,
  SQ_A4, SQ_B4, SQ_C4, SQ_D4, SQ_E4, SQ_F4, SQ_G4, SQ_H4,
  SQ_A5, SQ_B5, SQ_C5, SQ_D5, SQ_E5, SQ_F5, SQ_G5, SQ_H5,
  SQ_A6, SQ_B6, SQ_C6, SQ_D6, SQ_E6, SQ_F6, SQ_G6, SQ_H6,
  SQ_A7, SQ_B7, SQ_C7, SQ_D7, SQ_E7, SQ_F7, SQ_G7, SQ_H7,
  SQ_A8, SQ_B8, SQ_C8, SQ_D8, SQ_E8, SQ_F8, SQ_G8, SQ_H8,
  SQ_END = 64,
  SQ_ZERO = 0,
};

enum Rank : int {
  RANK_1, RANK_2, RANK_3, RANK_4, RANK_5, RANK_6, RANK_7, RANK_8
};

enum File : int {
  FILE_A, FILE_B, FILE_C, FILE_D, FILE_E, FILE_F, FILE_G, FILE_H
};

enum Direction : int {
  NORTH = 8,
  EAST = 1,
  SOUTH = -8,
  WEST = -1,
  NORTHEAST = NORTH + EAST,
  NORTHWEST = NORTH + WEST,
  SOUTHEAST = SOUTH + EAST,
  SOUTHWEST = SOUTH + WEST,
};

#define ENABLE_BASE_OPERATORS_ON(T)                             \
constexpr T operator+(T a, int b) { return T(int(a) + b); }     \
constexpr T operator-(T a, int b) { return T(int(a) - b); }     \
constexpr T operator-(T a) { return T(-int(a)); }               \
inline T& operator+=(T& a, int b) { return a = T(int(a) + b); } \
inline T& operator-=(T& a, int b) { return a = T(int(a) - b); }

#define ENABLE_INCR_OPERATORS_ON(T)                      \
inline T& operator++(T& a) { return a = T(int(a) + 1); } \
inline T& operator--(T& a) { return a = T(int(a) - 1); }

ENABLE_INCR_OPERATORS_ON(Square);
ENABLE_INCR_OPERATORS_ON(Rank);
ENABLE_INCR_OPERATORS_ON(File);

#undef ENABLE_BASE_OPERATORS_ON
#undef ENABLE_INCR_OPERATORS_ON

inline Square make_square(File f, Rank r) {
  return Square((r << 3) + f);
}

inline bool is_ok(Square s) {
  return s >= SQ_A1 && s <= SQ_H8;
}

inline Square start_square(Move m) {
  return Square(m & 0x3F);
}

inline Square end_square(Move m) {
  return Square((m >> 6) & 0x3F);
}

inline Piece make_piece(Color c, PieceType pt) {
  return Piece((c << 3) + pt);
}

inline Color color_of(Piece p) {
  assert(p != NO_PIECE);
  return Color(p >> 3);
}

inline PieceType type_of(Piece p) {
  return PieceType(p & 7);
}

}   // namespace mockfish

#endif
