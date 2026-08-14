#ifndef WINDOW_H
#define WINDOW_H

#include "type.h"

SDL_Window *createSDLWindow(char *name, int width, int height);
void takeGUIInput(gameState *currentGame, SDL_Event event, SDL_Renderer *renderer, int *isGameRunning);
void GUIdisplay(gameState *currentGame, SDL_Renderer *renderer);
void waitForCloseInput(int *isGameRunning);


#endif