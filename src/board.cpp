#include "board.hpp"

bitboard get_piece[Colors_num][PieceTypes_num] = {
    {
        0xFFFFFFFFFFFF0000,
        0x000000000000FF00,
        0x00000000000000
    },
    {}
};
bitboard get_pieces[Piece_num];

bitboard attack[Colors_num][PieceTypes_num];
bitboard attacks[Piece_num];

bitboard move[Colors_num][PieceTypes_num];
bitboard moves[Piece_num];
bitboard no_pieces;
bitboard all_pieces; 
fast_number half_turns; 