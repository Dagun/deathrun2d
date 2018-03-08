#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "timer.h"

#include "SDL.h"
#include "SDL_image.h"

using namespace std;

SDL_Texture *LoadTexture(char *filePath, SDL_Renderer *renderTarget) {
  SDL_Texture *texture = NULL;
  SDL_Surface *surface = IMG_Load(filePath);
  if (surface == NULL) {
    printf("Unable to load image: %s\n", SDL_GetError());
    return NULL;
  }
  texture = SDL_CreateTextureFromSurface(renderTarget, surface);
  if (texture == NULL) {
    printf("Unable to create texture from surface: %s\n", SDL_GetError());
    SDL_FreeSurface(surface);
    return NULL;
  }
  SDL_FreeSurface(surface);
  return texture;
}


int main(int argc, char *argv[])
{
    bool running = true;
    timer time;
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
        printf("Unable to initialize SDL: %s\n", SDL_GetError()); running = false;
    }
    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        printf("Unable to initialize SDL Image: %s\n", IMG_GetError()); running = false;
    }

    SDL_Window *Window= SDL_CreateWindow("DeathRun2D", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1980, 1080,SDL_WINDOW_SHOWN);
    SDL_Renderer *Render = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_Event Event;

    while(running) {
        time.updateTimer();
        const Uint8 *state = SDL_GetKeyboardState(NULL);

        SDL_RenderClear(Render);


    while( SDL_PollEvent( &Event ) ){
        if(Event.type==SDL_QUIT||state[SDL_SCANCODE_ESCAPE]){
            running=false;
        } else if(state[SDL_SCANCODE_UP]) {

        }
    }

        SDL_RenderPresent(Render);
        cout << time.getTimer() << endl;
        if(time.getTimer() > 5) {
            time.setTimer(0);
        }
    }

    SDL_DestroyRenderer(Render);
    SDL_DestroyWindow(Window);

    Render = nullptr;
    Window = nullptr;
    IMG_Quit();
    SDL_Quit();
    return 0;
}
