//
//  Particle.hpp
//  wk2_hw02
//
//  Created by Zhong Yuxin on 13/09/2018.
//

#ifndef Particle_hpp
#define Particle_hpp

#include <stdio.h>

#include "ofMain.h"


class Particle{
    
public:
    Particle();
    
    void setAttractPoints( vector<ofPoint> * attract );
    
    void reset();
    void update();
    void draw();
    
    
    ofPoint pos;
    ofPoint vel;
    ofPoint frc;
    
    float drag;
    float uniqueVal;
    float scale;

    
    vector <ofPoint> * attractPoints;
    
};

#endif /* Particle_hpp */
