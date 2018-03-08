#include "timer.h"

void timer::setTimer(float value) {
    this->monoTimer = value;
}

float timer::getTimer() {
    return this->monoTimer;
}

void timer::updateTimer() {
    this->prevTime = this->currentTime;
    this->currentTime = SDL_GetTicks();
    this->deltaTime = (this->currentTime - this->prevTime) / 1000.0f;
    this->monoTimer = this->monoTimer+this->deltaTime;
}

timer::timer() {
    this->monoTimer = 0;
    this->deltaTime = 0;
    this->prevTime = 0;
    this->currentTime = 0;
}
