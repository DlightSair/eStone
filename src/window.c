#include <stdio.h>
#include "type.h"
#include "util.h"
#include "window.h"



SDL_Window *createSDLWindow(char *name, int width, int height)
{
    SDL_Window *window = SDL_CreateWindow(name, width, height, SDL_WINDOW_RESIZABLE);

    if(!window) {
        printf("Couldn't Initialize Window.\n");
        return NULL;
    }

    SDL_SetWindowMinimumSize(window, BOARD_SIZE * 30, BOARD_SIZE * 30);

    return window;

}


void waitForCloseInput(int *isGameRunning)
{
    int waiting = 1;

    while(waiting)
    {
        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_EVENT_QUIT)
            {
                *isGameRunning = 0;
                waiting = 0;
                break;
            }

            if(event.type == SDL_EVENT_MOUSE_BUTTON_DOWN)
            {
                waiting = 0;
                break;
            }
        }
    }
}

void takeGUIInput(gameState *currentGame, SDL_Event event, SDL_Renderer *renderer, int *isGameRunning)
{
    int currentMoves = currentGame->movesPlayed;

    while(currentMoves == currentGame->movesPlayed)
    {
        while(SDL_PollEvent(&event))
        {

            switch (event.type)
            {

            case SDL_EVENT_QUIT:
                *isGameRunning = 0;
                return;
                break;
            
            case SDL_EVENT_WINDOW_RESIZED:
                WIDTH = event.window.data1;
                HEIGHT = event.window.data2;
                break;

            case SDL_EVENT_MOUSE_BUTTON_DOWN:
                if(event.button.button == SDL_BUTTON_LEFT){
                    int x = event.button.x/(WIDTH/currentGame->boardSize);
                    int y = event.button.y/(HEIGHT/currentGame->boardSize);

                    int isInBounds = (x >= 0 && x < currentGame->boardSize && y >= 0 && y < currentGame->boardSize);

                    if(isInBounds && !currentGame->board[x][y]){
                        currentGame->board[x][y] = currentGame->currentPlayer;
                        currentGame->movesPlayed++;
                        setNextPlayer(currentGame);
                    }
                }
                break;

            default:
                break;
            }

        }

        GUIdisplay(currentGame, renderer);
        SDL_RenderPresent(renderer);
    }
}




void GUIdisplay(gameState *currentGame, SDL_Renderer *renderer)
{
    SDL_RenderClear(renderer);

    SDL_FRect rect = {
        .x = 0,
        .y = 0,
        .w = WIDTH,
        .h = HEIGHT
    };

    SDL_SetRenderDrawColor(renderer, 20, 20, 20, 255);
    SDL_RenderFillRect(renderer, &rect);


    for(int i=0; i<currentGame->boardSize; i++)
    {
        for(int j=0; j<currentGame->boardSize; j++)
        {
            SDL_FRect cellRect = {
                .x = i * WIDTH/currentGame->boardSize,
                .y = j * HEIGHT/currentGame->boardSize,
                .w = WIDTH/currentGame->boardSize,
                .h = HEIGHT/currentGame->boardSize
            };

            if(currentGame->board[i][j] == 1){
                SDL_SetRenderDrawColor(renderer, 231, 76, 60, 255);
                SDL_RenderFillRect(renderer, &cellRect);

            }else if(currentGame->board[i][j] == 2){
                SDL_SetRenderDrawColor(renderer, 52, 152, 219, 255);
                SDL_RenderFillRect(renderer, &cellRect);
            }
        }
    }



    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    SDL_RenderLine(renderer, WIDTH/3, 0, WIDTH/3, HEIGHT);
    SDL_RenderLine(renderer, 2* WIDTH/3, 0, 2* WIDTH/3, HEIGHT);
    SDL_RenderLine(renderer, 0, HEIGHT/3, WIDTH, HEIGHT/3);
    SDL_RenderLine(renderer, 0, 2* HEIGHT/3, WIDTH,2* HEIGHT/3);

}