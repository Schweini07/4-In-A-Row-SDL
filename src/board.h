#ifndef _BOARD_
#define _BOARD_

class Board {
    public:
        Board();
        ~Board();
        SDL_Rect rect;
        char *path = "../assets/grid.png";
};

#endif