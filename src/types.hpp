/*
    Types is mainly supposed to represent pieces and their values.
    Aditionally it represents squares, colors, ranks, and directions.
    Lastly it provides specific information for other files.
*/
#ifndef TYPES_HPP
#define TYPES_HPP
#include <cstdint> //Required for special types
#include <limits> //Required for finding the maximum to represent kings value


using fast_number = int_fast32_t; //For representing positions and scores.
using value = uint8_t; //General small number for castling rights.

enum PieceType {
    No_Piece_Type, //If there is no piece. Index 0
    Pawn,          //Index 1
    Knight,        //Index 2
    Bishop,        //Index 3
    Rook,          //Index 4
    Queen,         //Index 5
    King,          //Index 6
    AnyPiece, //This serves as a placeholder for any piece which makes it easy for occupancy checking. Index 7
    PieceTypes_num //There is 8 pieces because we must include the No_Piece_Type and AnyPiece type.
};

enum Color {
    White, //Only for white pieces.
    Black, //Only for black Pieces.
    Colors_num, // 2 because theres both Black and White.
};

enum Piece {
    No_W, W_Pawn, W_Knight, W_Bishop, W_Rook, W_Queen, W_King, W_piece, //These represent the White Pieces
    No_B, B_Pawn, B_Knight, B_Bishop, B_Rook, B_Queen, B_King, B_piece, //These represent the Black Pieces
    Piece_num = 16, // theres sixteen
};

constexpr fast_number general_value = 1; //General values are typically unused but still there
constexpr fast_number pawn_value = 10; //A pawn is only worth 10 because of its low mobility
constexpr fast_number knight_value = 30; //A knight is worth 30 points because of its dynamic structure
constexpr fast_number bishop_value = 33; //A bishop is worth 33 points because of its usefulness at end-game
constexpr fast_number rook_value = 52; //A rook is worth 52 points because it has superior mobility to the bishop
constexpr fast_number queen_value = 94; //A queen is worth 94 points because it is very flexible because it has the highest mobility
constexpr fast_number king_value = std::numeric_limits<fast_number>::max(); //A king is worth the maximum amount of points.

//The castling rights will be read into an int to keep track of
constexpr value White_Queenside_Castle = 1; //0001
constexpr value White_Kingside_Castle = 2;  //0010
constexpr value Black_Queenside_Castle = 4; //0100
constexpr value Black_Kingside_Castle = 8;  //1000
//Each bit represents the castling right of that side. Must become 0000 if rights are taken.

//For this black pieces are worth negative so it becomes easier to implement MiniMax
//This is a color + piecetype implementation
constexpr fast_number Val[Colors_num][PieceTypes_num] = {
    {0, pawn_value, knight_value, bishop_value, rook_value, queen_value, king_value, general_value}, 
    {0, -pawn_value, -knight_value, -bishop_value, -rook_value, -queen_value, -king_value, -general_value}
};
//This is for just pieces no colors necessary
constexpr fast_number Eval[Piece_num] {
    0, pawn_value, knight_value, bishop_value, rook_value, queen_value, king_value, general_value,
    0, -pawn_value, -knight_value, -bishop_value, -rook_value, -queen_value, -king_value, -general_value
};

//Files represent columns
enum File {
    A, B, C, D, E, F, G, H
};
//Ranks represent rows
enum Rank {
    R1, R2, R3, R4, R5, R6, R7, R8
};
//Files + Rank to represent the entire Board
enum Squares {
    A1, B1, C1, D1, E1, F1, G1, H1,
    A2, B2, C2, D2, E2, F2, G2, H2,
    A3, B3, C3, D3, E3, F3, G3, H3,
    A4, B4, C4, D4, E4, F4, G4, H4,
    A5, B5, C5, D5, E5, F5, G5, H5,
    A6, B6, C6, D6, E6, F6, G6, H6,
    A7, B7, C7, D7, E7, F7, G7, H7,
    A8, B8, C8, D8, E8, F8, G8, H8,
};
#endif//TYPES_HPP