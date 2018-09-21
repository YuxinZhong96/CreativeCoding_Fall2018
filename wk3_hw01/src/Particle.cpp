//
//  Particle.cpp
//  wk3_hw01
//
//  Created by Zhong Yuxin on 20/09/2018.
//

#include "Particle.hpp"

Particle::Particle(){
    
    pos.set(0,0,0);
    vel.set(0,0,0);
    acc.set(0,0,0);
    
    damp = 0.9;
    
    
    
}


void Particle::setup(ofPoint _pos){
    
    pos = _pos;
    
    vel.set(ofRandom(-1,1), ofRandom(-1,1));
    
}



void Particle::addAttractionForce(ofPoint pos_, float rad_, float scale){
    
    ofPoint diff = pos_ - pos;
    
    if(diff.length() < rad_){
        ofLog() << "ATTRACT";
        diff *= 1.0 - (diff.length()/ rad_);
        addForce(diff * scale);
        
    }
    
}

void Particle::addRepulsionForce(ofPoint pos_, float rad_, float scale){
    
    ofPoint diff = pos_ - pos;
    
    if(diff.length() < rad_){
        ofLog() << "REPULSE";
        diff *= 1.0 - (diff.length()/ rad_);
        addForce(-diff * scale);
    }
    
}


void Particle::update(){
    
    vel += acc;
    vel *= damp;
    pos += vel;
    acc *= 0.0;
    
}


void Particle::addForce(ofPoint force){
    
    acc += force;
    
}

void Particle::draw(){

    ofDrawRectangle(pos.x, pos.y, 30, 30);
}
