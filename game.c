#include <stdio.h>
#include "type.h"
#include "util.h"


int game()
{
    int isGameRunning = 1;

    gameState currentGame = {
        .boardSize = BOARD_SIZE,
        .board = {0},
        .currentPlayer = 1,
        .movesPlayed = 0
    };

    while(isGameRunning){

        displayBoard(&currentGame);

        int state = hasGameEnded(&currentGame);
        if(state) // 0: Not Ended | 1: Player 1 Won | 2: Player 2 Won | 3: Draw
        {
            isGameRunning = 0;
            endScreen(state);
            break;
        }

        takeInput(&currentGame);

    }

    return 0;
}