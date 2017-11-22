#pragma once

#include "ofMain.h"

class MyCircle{
    public:
        void setup(float initialX, float initialY);
        void update();
        void draw();
    
        float x,y;
        float speedX, speedY;
        float counter;
        float minRadius, maxRadius;
        float blue;
};
