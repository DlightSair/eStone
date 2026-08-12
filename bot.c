#include <stdio.h>
#include "type.h"
#include "util.h"
#include "game.h"


int MAX(int x, int y) {return (x > y? x: y);}
int MIN(int x, int y) {return (x < y? x: y);}



void getBotInput(gameState *currentGame, int isFirstPlayer)
{
    int max_i=0, max_j=0, max=-2, val;
    gameState cg = *currentGame;

    for(int i=0; i<currentGame->boardSize; i++){
        for(int j=0; j<currentGame->boardSize; j++){

            if(!cg.board[i][j]){

                cg.board[i][j] = cg.currentPlayer;
                cg.movesPlayed++;
                setNextPlayer(&cg);

                val = minmax(&cg, isFirstPlayer);
                if(val > max){
                    max = val;
                    max_i = i;
                    max_j = j;
                }

                cg.board[i][j] = 0;
                cg.movesPlayed--;
                setNextPlayer(&cg);
            }
        }
    }

    currentGame->board[max_i][max_j] = currentGame->currentPlayer;
}



int minmax(gameState *currentGame, int isFirstPlayer)
{
    int value;
    int turnMax = ((currentGame->currentPlayer == 1) && isFirstPlayer) || ((currentGame->currentPlayer == 2) && !isFirstPlayer);


    int finalState = hasGameEnded(currentGame); // 0: Not ended 

    if(finalState){

        if( (finalState == 1 && isFirstPlayer) || (finalState == 2 && !isFirstPlayer) ){
            return 1;
        }else if( (finalState == 2 && isFirstPlayer) || (finalState == 1 && !isFirstPlayer) ){
            return -1;
        }else if(finalState == 3){
            return 0;
        }
    }

    if(turnMax)
    {

        value = -2;
        for(int i=0; i<currentGame->boardSize; i++){
            for(int j=0; j<currentGame->boardSize; j++){

                if(!currentGame->board[i][j]){
                    

                    currentGame->board[i][j] = currentGame->currentPlayer;
                    currentGame->movesPlayed++;
                    setNextPlayer(currentGame);
                    
                    value = MAX(value, minmax(currentGame, isFirstPlayer));

                    currentGame->board[i][j] = 0;
                    currentGame->movesPlayed--;
                    setNextPlayer(currentGame);

                }
            }
        }

    }else{

        value = 2;
        for(int i=0; i<currentGame->boardSize; i++){
            for(int j=0; j<currentGame->boardSize; j++){

                if(!currentGame->board[i][j]){

                    currentGame->board[i][j] = currentGame->currentPlayer;
                    currentGame->movesPlayed++;
                    setNextPlayer(currentGame);

                    value = MIN(value, minmax(currentGame, isFirstPlayer));

                    currentGame->board[i][j] = 0;
                    currentGame->movesPlayed--;
                    setNextPlayer(currentGame);

                }
            }
        }
    }

    return value;

}