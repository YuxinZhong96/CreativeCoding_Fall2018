//
//  line.hpp
//  wk8_hw
//
//  Created by Zhong Yuxin on 25/10/2018.
//

#pragma once

#include "ofMain.h"

class line{
    
    public:
    
        line();
    
        void setup(float _xPos);
        void update();
        void draw();
    
    
        float xPos;
    
        ofPolyline SingleLine;
    
    
};
