#pragma once

#include "graphic.h"

class Field {
    private:
        int height;// 1080
        int width; // 1980
        int sizeSqr; // 100
        int heightSqr;
        int widthSqr;
        Graphic textures[0]; // bsp. 10 texturen POINTER in einem array mit new
    public:
        Field();
        void setHeight(int value);
        void setWidth(int value);
        int getHeight();
        int getWidth();
        void show();
        void showTexture(int heightSqr, int widthSqr, int texture);
        ~Field();
};
