#include <stdio.h>
#include "type.h"


void displayBoard(gameState *currentGame)
{
    printf("\n");
    for(int i=0; i<currentGame->boardSize; i++)
    {
        for(int j=0; j<currentGame->boardSize; j++)
        {
            if(currentGame->board[i][j] == 1){
                printf(" x ");
            }else if(currentGame->board[i][j] == 2){
                printf(" O ");
            }else if(currentGame->board[i][j] == 0){
                printf("   ");
            }

            if(j!=currentGame->boardSize-1) printf("|");
        }
        if(i!=currentGame->boardSize-1) printf("\n-----------\n");
    }
    printf("\n");
}



void takeInput(gameState *currentGame)
{
    int row, column;
    int isMoveLegal = 0;
    int isPositioninBoard = 0;

    while(!isMoveLegal && !isPositioninBoard)
    {
        row = 0; column = 0;
        printf("\nPlayer %d Enter Your Move <row> <column>: ", currentGame->currentPlayer);

        if(!scanf("%d %d", &row, &column)){
            printf("\nInvalid Input!");
            int c;

            while( (c=getchar()) != '\n' && c != EOF);
        }else{
            isPositioninBoard = (row > 0 && row < (currentGame->boardSize+1) && column > 0 && column < (currentGame->boardSize+1));
        }

        if(!isPositioninBoard)
        {
            printf("\nEnter Position Inside The Board.");
        } else {
            isMoveLegal = !(currentGame->board[row-1][column-1]);
            if(!isMoveLegal) printf("\nPosition Already Occupied.");
        }
    }

    currentGame->board[row-1][column-1] = currentGame->currentPlayer;
    currentGame->movesPlayed++;

    if(currentGame->currentPlayer == 1) {
        currentGame->currentPlayer = 2;
    }else if(currentGame->currentPlayer == 2){
        currentGame->currentPlayer = 1;
    }
}


int checkLines(gameState *currentGame, int x)
{
    int same = 1;
    for(int i=0; i<currentGame->boardSize; i++){
        for(int j=0; j<currentGame->boardSize; j++){
            same &= (currentGame->board[i][j] == x);
        }
        if(same) return 1;
        same = 1;
    }

    for(int j=0; j<currentGame->boardSize; j++){
        for(int i=0; i<currentGame->boardSize; i++){
            same &= (currentGame->board[i][j] == x);
        }
        if(same) return 1;
        same = 1;
    }

    return 0;
}

int checkDiagonal(gameState *currentGame, int x)
{
    int same1 = 1;
    int same2 = 1;

    for(int i=0; i<currentGame->boardSize; i++){
        same1 &= (currentGame->board[i][i] == x);
        same2 &= (currentGame->board[i][(currentGame->boardSize)-i-1] == x);
    }

    if( same1 || same2 ) return 1;
    return 0;
}

int checkDraw(gameState *currentGame)
{
    if(currentGame->movesPlayed == (currentGame->boardSize)*(currentGame->boardSize)) return 1;
    return 0;
}

int hasGameEnded(gameState *currrentGame)
{
    if( checkLines(currrentGame, 1) || checkDiagonal(currrentGame, 1) ){
        return 1;
    }else if( checkLines(currrentGame, 2) || checkDiagonal(currrentGame, 2) ){
        return 2;
    }else if( checkDraw(currrentGame) ){
        return 3;
    }else{
        return 0;
    }
}

void endScreen(int state)
{
    if(state == 1){
        printf("\nPlayer 1 has won!");
    }else if( state == 2 ){
        printf("\nPlayer 2 has won!");
    }else if( state == 3){
        printf("\nDraw!");
    }

}