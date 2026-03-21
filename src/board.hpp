#ifndef BOARD_HPP
#define BOARD_HPP

#include "types.hpp"
#include <vector>

using bitboard = uint64_t; 

extern bitboard pos[Colors_num][PieceTypes_num]; //occupancy squares of pieces
extern bitboard pos_[Piece_num]; //occupancy squares of pieces
extern bitboard all_pieces; //the squares that are occupied
extern bitboard no_pieces; //the squares which arent occupied

extern bitboard attack[Colors_num][PieceTypes_num]; //attacks of specific pieces
extern bitboard attacks[Piece_num]; //attacks of specific pieces
extern bitboard all_attacks; //returns squares that can be attacked
extern bitboard no_attacks; //returns squares that cannot be attacked 

extern bitboard move[Colors_num][PieceTypes_num]; //returns squares that can be moved to
extern bitboard moves[Piece_num]; //returns squares that can be moved to
extern bitboard all_moves; //all squares that can be moved to
extern bitboard no_moves; //inaccessible squares

extern value castling_right;
extern Square en_passant; //which square you can en passant to
extern fast_number half_turns; //resets everytime a pawn is pushed or piece is taken
extern Color turn; //which sides turn is it
extern std::vector<uint32_t> his; //recording moves


bool is_there(bitboard b, Square s);
value how_many(bitboard b);
void remove_rights(castling_rights cr);
bool is_draw(); 
#endif //BOARD_HPP