#include <iostream>
#include <stdlib.h>
#include <stdio.h>

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

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
        printf("Unable to initialize SDL: %s\n", SDL_GetError()); running = false;
    }
    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        printf("Unable to initialize SDL Image: %s\n", IMG_GetError()); running = false;
    }

    SDL_Window *Window= SDL_CreateWindow("DeathRun2D", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 1980,SDL_WINDOW_FULLSCREEN);
    SDL_Renderer *Render = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_Event Event;
    SDL_Texture *Background = LoadTexture("test.png",Render);
    SDL_Texture *Background2 = LoadTexture("test2.png",Render);

    float prevTime = 0;
    float currentTime = 0;
    float deltaTime = 0;

    float timer = 0;

    while(running) {
        prevTime = currentTime;
        currentTime = SDL_GetTicks();
        deltaTime = (currentTime - prevTime) / 1000.0f;
        timer = timer + deltaTime;

        SDL_RenderClear(Render);

        if(timer < 2) {
            SDL_RenderCopy(Render,Background,NULL,NULL);
        } else if(timer > 2 && timer < 3) {
            SDL_RenderCopy(Render,Background2,NULL,NULL);
        }else if(timer >3) {
            SDL_RenderCopy(Render,Background2,NULL,NULL);
            timer = 0;
        }
        cout << deltaTime << endl;
        cout << timer << endl;

        SDL_RenderPresent(Render);
    }

    SDL_DestroyRenderer(Render);
    SDL_DestroyWindow(Window);

    Render = nullptr;
    Window = nullptr;
    IMG_Quit();
    SDL_Quit();
    return 0;
}
