#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetBackgroundColor(0);
    ofEnableAlphaBlending();
    
    for(int i = 0; i<200; i++){
        Particle p;
        particles.push_back(p);
        particles[i].setup(ofPoint(
                         ofRandom(ofGetWidth()),
                         ofRandom(ofGetHeight())
                        ));
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
    ofPoint mouse = ofPoint(mouseX, mouseY);
    
    
    for(int i = 0; i < particles.size(); i++){
//      particles[i].addForce(ofPoint(0, 0.01));
        
        particles[i].addAttractionForce(mouse, 100, 0.01);
        particles[i].update();
    }
    
    
    for(int i = 0; i < particles.size(); i++){
        for (int j = 0; j < i; j ++){
            particles[i].addRepulsionForce(particles[j].pos, 35, 0.1);
            particles[j].addRepulsionForce(particles[i].pos, 35, 0.1);
        }
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
//    ofSetColor(255, 255, 255);
//
//    ofFill();
//
//    for(int i = 0; i < particles.size(); i++){
//        particles[i].draw();
//    }
//
//
//    ofNoFill();
//    ofDrawCircle(mouseX, mouseY, 100);
    
    
    // lines between particles
    
    float maxDist = 80;
    
    for (int i = 0; i < particles.size(); i++){
        for (int j = 0; j < particles.size(); j++){
            float dist = (particles[i].pos - particles[j].pos).length();
            if(dist < maxDist){
                
                float alpha = ofMap(dist, 0, maxDist, 255, 0);
                ofSetColor(255, alpha);
                ofDrawLine(particles[i].pos, particles[j].pos);
            }
        }
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    for(int i = 0; i < particles.size(); i++){
        particles[i].addForce(ofPoint(ofRandom(-4,4), ofRandom(-4,4)));
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
