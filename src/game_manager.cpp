#include <iostream>
#include "game_manager.h"

GM::GM()
{
    // Couting the grid
    /*
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            std::cout << i << " and " << j << " are: " << grid[i][j] << std::endl;
        }
    }
    */
}

GM::~GM()
{

}

bool GM::placePiece(int mouse_pos_x, int mouse_pos_y, int &x, int &y)
{
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 6; j++) {
            if (mouse_pos_x > i*100 && mouse_pos_x < i*100+100) {
                for (int k = 5; k >= 0; k--) {
                    if (grid[k][i] == 0) {
                        j = k;
                        break;
                    }

                    if (k == 0) {
                        return false;
                    }
                }
                // Couting grid value
                // std::cout << "Grid: " << grid[j][i];
                grid[j][i] = player_on_turn;
                x = i*100;
                y = j*100;
                // Couting: i, j, mouse_pos_x, mouse_pos_y, x and y
                // std::cout << " | i and j: " << i << ", " << j <<" | x and y: " << x << ", " << y << " | Mouse Coords: " << mouse_pos_x << ", " << mouse_pos_y << std::endl;
                return true;
            }
        }
    }
    return false;
}

bool GM::checkForWin()
{
    // Check the horizontal pieces for a win
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            if (grid[i][j] == player_on_turn && grid[i][j+1] == player_on_turn && grid[i][j+1] == player_on_turn && grid[i][j+2] == player_on_turn && grid[i][j+3] == player_on_turn) {
                return true;
            }
        }
    }
    // Check the vertical pieces for a win
    for (int i = 0; i < 7; i++) {
        for (int j = 5; j >= 0; j--) {
            if (grid[j][i] == player_on_turn && grid[j+1][i] == player_on_turn && grid[j+2][i] == player_on_turn && grid[j+3][i] == player_on_turn) 
            {
                return true;
            }
        }
    }
    // Check the right diagonals (/) for a win
    for (int i = 5; i > 3; i--) {
        for (int j = 0; j < 5; j++) {
            if (grid[i][j] == player_on_turn && grid[i-1][j+1] == player_on_turn && grid[i-2][j+2] == player_on_turn && grid[i-3][j+3] == player_on_turn) {
                return true;
            }
        }
    }

    // Check the left diagonals (\) for a win
    for (int i = 5; i > 3; i--) {
        for (int j = 6; j > 2; j--) {
            if (grid[i][j] == player_on_turn && grid[i-1][j-1] == player_on_turn && grid[i-2][j-2] == player_on_turn && grid[i-3][j-3] == player_on_turn) {
                return true;
            }
        }
    }

    return false;
}