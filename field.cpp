#include "field.h"

Field::Field() {
    this->height = 1080;
    this->width = 1980;
    this->sizeSqr = 100;
    this->widthSqr = 10;
    this->heightSqr = 10;
}

void Field::setHeight(int value) {
    this->height = value;
}

void Field::setWidth(int value) {
    this->width = value;
}

int Field::getHeight(){
    return this->height;
}

int Field::getWidth(){
    return this->width;
}

void Field::show(){

}

void Field::showTexture(int heightSqr, int widthSqr, int texture){

}

Field::~Field() {

}
