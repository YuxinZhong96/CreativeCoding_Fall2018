//
//  Particle.cpp
//  wk3_inClass
//
//  Created by Zhong Yuxin on 14/09/2018.
//

#include "Particle.hpp"

Particle::Particle(){
    
    //default initialization is constructor
    
    pos.set(0,0,0);
    vel.set(0,0,0);
    acc.set(0,0,0);
    
    damp = 0.9;
    counter = 0;
    
}



void Particle::setup(ofPoint _pos){
    
//    pos.x = ofRandom(0, ofGetWidth());
//    pos.y = ofRandom(0, ofGetHeight());
    
    pos = _pos;
    
    vel.set(ofRandom(-1,1), ofRandom(-1,1));
    
    noiseRandomOffset.set(ofRandom(10), ofRandom(10), ofRandom(10));
    
}

void Particle::addAttractionForce(ofPoint pos_, float rad_, float scale){
    // 1. calculate difference between my position and attractor position
    
    ofPoint diff = pos_ - pos;
    
    // 2. Test if we are close enough to recieve attraction force
    
    if(diff.length() < rad_){
        ofLog() << "ATTRACT";
        
        // first scale from 1 to 0 by dividing by the radius
        // then 1.0 - this valus so that closer distance have a greater force
        
        diff *= 1.0 - (diff.length()/ rad_);
        addForce(diff * scale);
       }
    
}


void Particle::addRepulsionForce(ofPoint pos_, float rad_, float scale){

    ofPoint diff = pos_ - pos;
    
    // 2. Test if we are close enough to recieve attraction force
    
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
    counter += 1;
    
    acc += ofSignedNoise(counter, pos.x * 0.001 + pos.y * 0.001);
    
    if ( pos.x < 1 || pos.x > ofGetWidth() || pos.y < 1 || pos.y > ofGetHeight() ){
        
        vel *= -1;
    }
    
    
}

void Particle::addForce(ofPoint force){
    
    acc += force;
    
}



void Particle::draw(){
    ofDrawRectangle(pos.x, pos.y, 10, 10);
}


void Particle::ripple(){
    
}




