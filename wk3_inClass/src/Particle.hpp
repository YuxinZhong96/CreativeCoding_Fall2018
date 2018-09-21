//
//  Particle.hpp
//  wk3_inClass
//
//  Created by Zhong Yuxin on 14/09/2018.
//

#pragma once

#include "ofMain.h"

class Particle{
    
    public:
        Particle(); //constructor
    
        void setup(ofPoint _pos);
        void update();
        void draw();
        void addForce(ofPoint force);
    
        void addAttractionForce(ofPoint pos_, float rad_, float scale);
        void addRepulsionForce(ofPoint pos_, float rad_, float scale);
        // pos_: attractor position
        // rad_: distance drom attractor to apply force
    
    
        ofPoint pos;
        ofPoint vel;
        ofPoint acc;
    
        float damp;
        
    
    
    
};
