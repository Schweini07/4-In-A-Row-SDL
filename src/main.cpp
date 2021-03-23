#include <iostream>
#include <SDL2/SDL.h>
#include "game_manager.h"
#include "application.h"
#include "board.h"
#include "piece.h"
#include "ai.h"

void startGame(GM &gm, Application &app, Board &board);

int main()
{
    SDL_Event event;
    GM gm;
    Application app;
    Board board;
    Piece piece;
    AI ai;
    bool quit = false;
    bool in_game = true;

    startGame(gm, app, board);

    while (!quit) {
        while (in_game) {

            SDL_WaitEvent(&event);

            switch (event.type) {
                case SDL_MOUSEBUTTONDOWN:
                    if (event.button.button == SDL_BUTTON_LEFT) {
                        int mouse_pos_x, mouse_pos_y, x, y;
                        bool piece_placed;
                        SDL_GetMouseState(&mouse_pos_x, &mouse_pos_y);
                        piece_placed = gm.placePiece(mouse_pos_x, mouse_pos_y, x, y);
                        if (gm.checkForWin()) {
                            std::cout << "Player " << gm.player_on_turn << " won!" << std::endl;
                            startGame(gm, app, board);
                            continue;
                        }
                        if (piece_placed) {
                            piece.rect.x = x;
                            piece.rect.y = y;
                            app.renderObj(piece.rect, (gm.player_on_turn == 1) ? piece.blue_path : piece.red_path);
                            gm.player_on_turn = (gm.player_on_turn == 1) ? 2 : 1;
                        }
                        int ai_x, ai_y;
                        
                    }
                    break;
                case SDL_QUIT:
                    quit = true;
                    in_game = false;
                    break;
            }
        }
    }

    return 0;
}

void startGame(GM &gm, Application &app, Board &board)
{
    SDL_RenderClear(app.renderer);
    app.renderObj(board.rect, board.path);
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            gm.grid[i][j] = 0;
        }
    }
}