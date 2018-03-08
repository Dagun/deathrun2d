#pragma once
#include "SDL.h"

class Graphic
{
    private:
        char* imageName;
        SDL_Rect *texture_destination;
        SDL_Texture *texture;
        SDL_Surface *image;

    public:
        Graphic();
        Graphic(SDL_Renderer *renderer, char* imageName);
        SDL_Rect* createTextureDestination(int x, int y, int w, int h);
        //get
        SDL_Surface* getImage();
        SDL_Texture* getTexture();
        SDL_Rect* getTextureDestination();
        char* getImageName();
        int getTextureDestX();
        int getTextureDestY();
        //set
        void setTextureDest( int x, int y, int w, int h);
        void setTextureDestX( int x);
        void setTextureDestY(int y);
        void setTextureDestW(int w);
        void setTextureDestH(int h);
        void copyTextureDest(SDL_Rect *  textDest);
        void setImageName( char* newN);

};
