#ifndef _PIECE_
#define _PIECE_

class Piece {
    public:
        Piece();
        ~Piece();
        SDL_Rect rect;
        char *red_path = "../assets/red_piece.png";
        char *blue_path = "../assets/blue_piece.png";
};

#endif