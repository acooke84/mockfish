#ifndef INCLUDED_BITBOARD
#define INCLUDED_BITBOARD

#include <string>
#include "types.h"

namespace mockfish {

namespace bitboard {

std::string pretty_print(Bitboard bb);

}   // namespace bitboard

constexpr Bitboard AllSquares = ~Bitboard(0);
constexpr Bitboard DarkSquares = 0xAA55AA55AA55AA55ULL;
constexpr Bitboard WhiteSquares = ~DarkSquares;

constexpr Bitboard File_ABB = 0x101010101010101ULL;
constexpr Bitboard File_BBB = File_ABB << 1;
constexpr Bitboard File_CBB = File_ABB << 2;
constexpr Bitboard File_DBB = File_ABB << 3;
constexpr Bitboard File_EBB = File_ABB << 4;
constexpr Bitboard File_FBB = File_ABB << 5;
constexpr Bitboard File_GBB = File_ABB << 6;
constexpr Bitboard File_HBB = File_ABB << 7;

constexpr Bitboard Rank_1BB = 0xFFULL;
constexpr Bitboard Rank_2BB = Rank_1BB << 8;
constexpr Bitboard Rank_3BB = Rank_2BB << 8;
constexpr Bitboard Rank_4BB = Rank_3BB << 8;
constexpr Bitboard Rank_5BB = Rank_4BB << 8;
constexpr Bitboard Rank_6BB = Rank_5BB << 8;
constexpr Bitboard Rank_7BB = Rank_6BB << 8;
constexpr Bitboard Rank_8BB = Rank_7BB << 8;

inline Bitboard square_bb(Square s) {
  assert(is_ok(s));
  return (1ULL << s);
}

inline Bitboard  operator&( Bitboard  b, Square s) { return b &  square_bb(s); }
inline Bitboard  operator|( Bitboard  b, Square s) { return b |  square_bb(s); }
inline Bitboard  operator^( Bitboard  b, Square s) { return b ^  square_bb(s); }
inline Bitboard& operator|=(Bitboard& b, Square s) { return b |= square_bb(s); }
inline Bitboard& operator^=(Bitboard& b, Square s) { return b ^= square_bb(s); }

}   // namespace mockfish

#endif
