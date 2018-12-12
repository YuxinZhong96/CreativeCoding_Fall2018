//
//  line.cpp
//  wk8_hw
//
//  Created by Zhong Yuxin on 25/10/2018.
//

#include "line.hpp"

line::line(){
    
    xPos = 0.0;
    
}


void line::setup(float _xPos){
    
    xPos = _xPos;
    
    for (int i = 20; i < ofGetHeight()-20; i += 2){
        
        ofPoint pt;
        pt.set(xPos, i);
        SingleLine.addVertex(pt);
        
    }
    
}


void line::update(){
    
    float t = ofGetElapsedTimef();
    
    
    for (auto &vert: SingleLine.getVertices()){
        vert.x = xPos + ofRandom(-1, 1);
    }
    
    
    
    if(ofGetMouseX() < xPos + 5 && ofGetMouseX() > xPos - 5){


        for (auto &vert: SingleLine.getVertices()){

            vert.x = xPos + 20 * sin(t * vert.y / 10) * ofSignedNoise(t * 0.001, vert.y * 0.005, ofGetMouseY() * 0.002, ofGetMouseX() * 0.004);
            

            }

        }
    
    
}



void line::draw(){
    
    SingleLine.draw();
    
    
}
