//
//  Particle.hpp
//  wk3_hw01
//
//  Created by Zhong Yuxin on 20/09/2018.
//

#pragma once

#include "ofMain.h"

class Particle{
    
    public:
        Particle();
    
        void setup(ofPoint _pos);
        void update();
        void draw();
        void addForce(ofPoint force);
    
    void addAttractionForce(ofPoint pos_, float rad_, float scale);
    void addRepulsionForce(ofPoint pos_, float rad_, float scale);
    
    
    ofPoint pos;
    ofPoint vel;
    ofPoint acc;
    
    float damp;
    
    
    
    
    
    
    
    
};
