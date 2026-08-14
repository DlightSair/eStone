#include <stdio.h>
#include<stdlib.h>
#include "type.h"
#include "util.h"
#include "window.h"
#include "game.h"


int game(int gameMode, int isFirstPlayer, int isGUI)
{
    int isGameRunning = 1;

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window;
    SDL_Renderer *renderer;

    if(isGUI){
        window = createSDLWindow("Tic Tac Toe", WIDTH, HEIGHT);
        renderer = SDL_CreateRenderer(window, NULL);
    }

    gameState currentGame = {
        .boardSize = BOARD_SIZE,
        .board = {0},
        .currentPlayer = 1,
        .movesPlayed = 0
    };


    while(isGameRunning)
    {

        if(!isGUI)
        {
            system("cls");
            displayBoard(&currentGame);
        }
        else
        {
            GUIdisplay(&currentGame, renderer);
            SDL_RenderPresent(renderer);
        }


        int state = hasGameEnded(&currentGame); // 0: Not Ended | 1: Player 1 Won | 2: Player 2 Won | 3: Draw
        if(state)
        {
            endScreen(renderer, state, isGUI);

            if(isGUI)
            {
                SDL_RenderPresent(renderer);
                waitForCloseInput(&isGameRunning);
            }

            isGameRunning = 0;
            break;
        }


        int isBotTurn = isThisBotTurn(&currentGame, isFirstPlayer, gameMode);

        if(isBotTurn)
        {
            getBotInput(&currentGame, isFirstPlayer);
        }
        else if(isGUI)
        {
            SDL_Event event;
            takeGUIInput(&currentGame, event, renderer, &isGameRunning);
        }
        else
        {
            takeUserInput(&currentGame);
        }


    }

    if(isGUI)
    {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
    }
    SDL_Quit();
    return 0;
}