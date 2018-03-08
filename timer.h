#pragma once
#include "SDL.h"

class timer {
    private:
        float prevTime;
        float currentTime;
        float deltaTime;
        float monoTimer;
    public:
        timer();
        void setTimer(float value);
        float getTimer();
        void updateTimer();
};
