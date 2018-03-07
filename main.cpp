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

    SDL_Window *Window= SDL_CreateWindow("DeathRun2D", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1980, 1080,SDL_WINDOW_SHOWN);
    SDL_Renderer *Render = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_Event Event;
    SDL_Texture *Background = LoadTexture("test.png",Render);
    SDL_Texture *Background2 = LoadTexture("test2.png",Render);

    float prevTime = 0;
    float currentTime = 0;
    float deltaTime = 0;

    float timer = 0;
    int mode =1;
    bool toggle = false;

    while(running) {
        prevTime = currentTime;
        currentTime = SDL_GetTicks();
        deltaTime = (currentTime - prevTime) / 1000.0f;
        const Uint8 *state = SDL_GetKeyboardState(NULL);
        timer = timer + deltaTime;

        SDL_RenderClear(Render);


    while( SDL_PollEvent( &Event ) ){
        if(Event.type==SDL_QUIT||state[SDL_SCANCODE_ESCAPE]){
            running=false;
        } else if(state[SDL_SCANCODE_UP]) {

        } else if(state[SDL_SCANCODE_DOWN]){
            mode=2;
        }else {
            mode=1;
        }
        if(state[SDL_SCANCODE_RETURN]) {
            if(toggle == true) {
                toggle = false;
            } else {
                toggle = true;
            }
        }
      }
        if(mode==1){
            SDL_RenderCopy(Render,Background,NULL,NULL);
        } else if(mode==2){
            SDL_RenderCopy(Render,Background2,NULL,NULL);

        }

        if(toggle == true) {
            if(timer<2) {
                SDL_RenderCopy(Render,Background,NULL,NULL);
            } else if(timer < 3) {
                SDL_RenderCopy(Render,Background2,NULL,NULL);
            } else if(timer < 4) {
                timer = 0;
            }
        }
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
