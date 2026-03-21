#include "board.hpp"
#include "types.hpp"
#include <vector>
#include <bit>
#include <iostream>
//The get bitboards represent piece positions
bitboard pos[Colors_num][PieceTypes_num] = {
    //White Pieces
    {
        0xFFFFFFFFFFFF0000, //Non whites
        0x000000000000FF00, //White pawns
        0x0000000000000042, //White knights
        0x0000000000000024, //White bishops
        0x0000000000000081, //White rooks
        0x0000000000000008, //White queen
        0x0000000000000010, //White king
        0x000000000000FFFF, //All whites
    },
    //Black Pieces
    {
        0x0000FFFFFFFFFFFF, //Non blacks
        0x00FF000000000000, //Black pawns
        0x4200000000000000, //Black knight
        0x2400000000000000, //Black bishops
        0x8100000000000000, //Black rooks
        0x0800000000000000, //Black queen
        0x1000000000000000, //Black king
        0xFFFF000000000000, //All blacks
    }
};
bitboard pos_[Piece_num] = {
    //Whites
        0xFFFFFFFFFFFF0000, //Non whites
        0x000000000000FF00, //White pawns
        0x0000000000000042, //White knights
        0x0000000000000024, //White bishops
        0x0000000000000081, //White rooks
        0x0000000000000008, //White queen
        0x0000000000000010, //White king
        0x000000000000FFFF, //All whites
    //Blacks
        0x0000FFFFFFFFFFFF, //Non blacks
        0x00FF000000000000, //Black pawns
        0x4200000000000000, //Black knight
        0x2400000000000000, //Black bishops
        0x8100000000000000, //Black rooks
        0x0800000000000000, //Black queen
        0x1000000000000000, //Black king
        0xFFFF000000000000, //All blacks
};
bitboard all_pieces = pos_[B_piece] | pos_[W_piece];
bitboard no_pieces = ~all_pieces;

//The attack bitboards represent attacked squares
bitboard attack[Colors_num][PieceTypes_num] = {
    //White attacks
    {
        0x7EFFFF0000000000, //Non white attacks
        0x0000000000FF0000, //White pawn attacks
        0x0000000000A51800, //White knight attacks
        0x0000000000005A00, //White bishop attacks
        0x0000000000008142, //White rook attacks
        0x0000000000001C14, //White queen attacks
        0x0000000000003828, //White king attacks
        0x0000000000FFFF7E, //All white attacks
    },
    //Black attacks
    {
        0x0000000000FFFF7E, //Non black attacks
        0x0000FF0000000000, //Black pawn attacks
        0x0018A50000000000, //Black knight attacks
        0x005A000000000000, //Black bishop attacks
        0x4281000000000000, //Black rook attacks
        0x141C000000000000, //Black queen attacks
        0x2838000000000000, //Black king attacks
        0x7EFFFF0000000000, //All black attacks
    }
};
bitboard attacks[Piece_num] = {
    //White attacks
        0x7EFFFF0000000000, //Non white attacks
        0x0000000000FF0000, //White pawn attacks
        0x0000000000A51800, //White knight attacks
        0x0000000000005A00, //White bishop attacks
        0x0000000000008142, //White rook attacks
        0x0000000000001C14, //White queen attacks
        0x0000000000003828, //White king attacks
        0x0000000000FFFF7E, //All white attacks
    //Black attacks
        0x0000000000FFFF7E, //Non black attacks
        0x0000FF0000000000, //Black pawn attacks
        0x0018A50000000000, //Black knight attacks
        0x005A000000000000, //Black bishop attacks
        0x4281000000000000, //Black rook attacks
        0x141C000000000000, //Black queen attacks
        0x2838000000000000, //Black king attacks
        0x7EFFFF0000000000, //All black attacks
};
bitboard all_attacks = attacks[W_piece] | attacks[B_piece];
bitboard no_attacks = ~all_attacks;

//The move bitboards represent legal moves
bitboard move[Colors_num][PieceTypes_num] = {
    //White moves
    {
        0x0000FFFF00000000, //Non white moves
        0x00000000FFFF0000, //White pawn moves
        0x0000000000A50000, //White knight moves
        0x0000000000000000, //White bishop moves
        0x0000000000000000, //White rook moves
        0x0000000000000000, //White queen moves
        0x0000000000000000, //White king moves
        0x00000000FFFF0000, //All white moves
    },
    //Black moves
    {
        0x00000000FFFF0000, //Non black moves
        0x0000FFFF00000000, //Black pawn moves
        0x0000A50000000000, //Black knight moves
        0x0000000000000000, //Black bishop moves
        0x0000000000000000, //Black rook moves
        0x0000000000000000, //Black queen moves
        0x0000000000000000, //Black king moves
        0x0000FFFF00000000, //All black moves
    }
};
bitboard moves[Piece_num] = {
    //White moves
        0x0000FFFF00000000, //Non white moves
        0x00000000FFFF0000, //White pawn moves
        0x0000000000A50000, //White knight moves
        0x0000000000000000, //White bishop moves
        0x0000000000000000, //White rook moves
        0x0000000000000000, //White queen moves
        0x0000000000000000, //White king moves
        0x00000000FFFF0000, //All white moves
    //Black moves
        0x00000000FFFF0000, //Non black moves
        0x0000FFFF00000000, //Black pawn moves
        0x0000A50000000000, //Black knight moves
        0x0000000000000000, //Black bishop moves
        0x0000000000000000, //Black rook moves
        0x0000000000000000, //Black queen moves
        0x0000000000000000, //Black king moves
        0x0000FFFF00000000, //All black moves
};
bitboard all_moves = moves[W_piece] | moves[B_piece];
bitboard no_moves = ~all_moves;

value castling_right = (Black_Kingside | Black_Queenside) | (White_Kingside | White_Queenside);
Square en_passant = No_SQ; //At the start there is no enpassant squares
fast_number half_turns = 0; //No half moves at the start
Color turn = White; //White starts first
std::vector<uint32_t> his; //Move history
//checks if it is a draw
inline bool is_draw() {
    if(half_turns >= 50) {return true;} //50 move rule
    if(move[turn][AnyPiece] == 0) {return true;} //Stalemate
    if(his[his.size()-1] == his[his.size()-2] && his[his.size()-2] == his[his.size()-3]) {return true;}
    return false; //No draw
}
void remove_rights(castling_rights cr) {
    castling_right&=(~cr); //removes rights 
}
bool is_there(bitboard b, Square s) {
    return (b>>s)&1; //shifts bits to get the s-th bit and checks if its on
}
value how_many(bitboard b) {
    return std::__popcount(b); //return on bits
}