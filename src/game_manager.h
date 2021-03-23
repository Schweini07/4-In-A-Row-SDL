#ifndef _GM_
#define _GM_

class GM {
    public:
        GM();
        ~GM();
        bool placePiece(int mouse_pos_x, int mouse_pos_y, int &x, int &y);
        bool checkForWin();
        wchar_t player_on_turn = 1;
        int grid[6][7] = {
            {0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0}
        };
};

#endif