//
//  Particle.cpp
//  wk2_hw02
//
//  Created by Zhong Yuxin on 13/09/2018.
//

#include "Particle.hpp"

Particle::Particle(){
    attractPoints = NULL;
}

void Particle::setAttractPoints(vector<ofPoint> * attract){
    
    attractPoints = attract;
    
}



void Particle::reset(){
    
    uniqueVal = ofRandom(-10000, 10000);
    
    pos.x = ofRandomWidth();
    pos.y = ofRandomHeight();
    
    vel.x = ofRandom(-2.2, 2);
    vel.y = ofRandom(-2.2, 2);
    
    frc = ofPoint(0, 0, 0);
    
    scale = ofRandom(0.5, 1.0);
    
    drag = ofRandom(0.95, 0.998);
    

    
    
}

void Particle::update(){
    
    ofPoint attractPt(ofGetMouseX(), ofGetMouseY());
    frc = attractPt-pos;
    frc.normalize();
    vel *= drag;
    vel += frc * 0.6;
    
    
    pos += vel;

    
    if( pos.x > ofGetWidth() ){
        pos.x = ofGetWidth();
        vel.x *= -1.0;
    }else if( pos.x < 0 ){
        pos.x = 0;
        vel.x *= -1.0;
    }
    if( pos.y > ofGetHeight() ){
        pos.y = ofGetHeight();
        vel.y *= -1.0;
    }
    else if( pos.y < 0 ){
        pos.y = 0;
        vel.y *= -1.0;
    }
    
}

void Particle::draw(){
    
    ofSetColor(255, 215, 0);
    ofDrawCircle(pos.x, pos.y, scale * 6.0);
    
}
