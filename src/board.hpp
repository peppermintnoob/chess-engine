#ifndef BOARD_HPP
#define BOARD_HPP

#include "types.hpp"
#include <bit>

using bitboard = uint64_t; 

extern bitboard get_piece[Colors_num][PieceTypes_num];
extern bitboard get_pieces[Piece_num];

extern bitboard attack[Colors_num][PieceTypes_num];
extern bitboard attacks[Piece_num];

extern bitboard move[Colors_num][PieceTypes_num];
extern bitboard moves[Piece_num];
extern bitboard no_pieces;
extern bitboard all_pieces; 
extern fast_number half_turns; 

constexpr value how_many(Piece);
constexpr value how_many(Color, PieceType);
constexpr void remove_rights(value remove);
bool[[always_inline]] is_draw(); 

#endif //BOARD_HPP