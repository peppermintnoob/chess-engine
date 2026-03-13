#ifndef BOARD_HPP
#define BOARD_HPP

#include "types.hpp"
#include <bit>

using bitboard = uint64_t; //Bitboards are 

bitboard get_piece[Colors_num][PieceTypes_num] = {
    {
        0xFFFFFFFFFFFF0000, //This represents non white pieces 
        0x000000000000FF00, //This is the white pawns
        0x0000000000000042, //This is the white knights
        0x0000000000000024, //This is the white bishops
        0x0000000000000081, //This is the white rooks
        0x0000000000000010, //This is the white queen
        0x0000000000000008, //This is the white king
        0x000000000000FFFF, //This represents all white pieces
    },
    {
        0x0000FFFFFFFFFFFF, //This represents non black pieces
        0x00FF000000000000, //This is the black pawns
        0x4200000000000000, //This is the black knights
        0x2400000000000000, //This is the black bishops
        0x8100000000000000, //This is the black rooks
        0x1000000000000000, //This is the black queen
        0x0800000000000000, //This is the black king
        0xFFFF000000000000, //This represents all black pieces
    }
};
bitboard get_pieces[Piece_num] = {
    0xFFFFFFFFFFFF0000, //This represents non white pieces 
    0x000000000000FF00, //This is the white pawns
    0x0000000000000042, //This is the white knights
    0x0000000000000024, //This is the white bishops
    0x0000000000000081, //This is the white rooks
    0x0000000000000010, //This is the white queen
    0x0000000000000008, //This is the white king
    0x000000000000FFFF, //This represents all white pieces
    0x0000FFFFFFFFFFFF, //This represents non black pieces
    0x00FF000000000000, //This is the black pawns
    0x4200000000000000, //This is the black knights
    0x2400000000000000, //This is the black bishops
    0x8100000000000000, //This is the black rooks
    0x1000000000000000, //This is the black queen
    0x0800000000000000, //This is the black king
    0xFFFF000000000000, //This represents all black pieces
};

bitboard no_pieces = 0x0000'FFFF'FFFF'0000;
bitboard all_pieces = 0xFFFF'0000'0000'FFFF;
fast_number half_turns = 0; //Everytime it goes up it 
fast_number turns = 0; // 


constexpr bool[[always_inline]] is_whites_turn(fast_number half_turn) {
    return half_turn&1==0;
}
constexpr bool[[always_inline]] is_blacks_turn(fast_number half_turn) {
    return half_turn&1!=0;
}


#endif //BOARD_HPP