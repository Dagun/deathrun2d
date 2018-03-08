#include <string.h>
#include "timer.h"

#include "SDL.h"
#include "SDL_image.h"

#include "graphic.h"

Graphic::Graphic()
{
    imageName = new char[0];
    texture_destination = NULL;
    texture = NULL;
    image = NULL;
}
Graphic::Graphic(SDL_Renderer *renderer, char* imageName)
{
    this->imageName = new char[strlen(imageName)+1];
    strcpy(this->imageName, imageName);

    image = IMG_Load(this->imageName);
    texture = SDL_CreateTextureFromSurface(renderer, image);



}
