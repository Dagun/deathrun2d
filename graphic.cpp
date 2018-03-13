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
Graphic::~Graphic()
{
    delete[]getImageName();
    SDL_DestroyTexture(getTexture());
}
SDL_Rect* Graphic::createTextureDest(int x, int y, int w, int h)
{
    SDL_Rect *tmp = new SDL_Rect;
    tmp->x= x;
    tmp->y = y;
    tmp->w = w;
    tmp->h = h;

    return tmp;
}

SDL_Surface* Graphic::getImage()
{
    return this->image;
}
SDL_Texture* Graphic::getTexture()
{
    return this->texture;
}
SDL_Rect* Graphic::getTextureDestination()
{
    return this->texture_destination;
}
char* Graphic::getImageName()
{
    return this->imageName;
}

void Graphic::setTextureDest( int x, int y, int w, int h)
{
    this->texture_destination = createTextureDest(x, y, w, h);
}
int Graphic::getTextureDestX()
{
    return this->texture_destination->x;
}
void Graphic::setTextureDestX( int x)
{
    this->texture_destination->x = x;
}
void Graphic::setTextureDestY( int y)
{
    this->texture_destination->y = y;
}
void Graphic::setTextureDestW(int w)
{
    this->texture_destination->w = w;
}
void Graphic::setTextureDestH(int h)
{
    this->texture_destination->h = h;
}
void Graphic::copyTextureDest(SDL_Rect *  textDest)
{
    this->texture_destination = textDest;
}
int Graphic::getTextureDestY()
{
    return this->texture_destination->y;
}

