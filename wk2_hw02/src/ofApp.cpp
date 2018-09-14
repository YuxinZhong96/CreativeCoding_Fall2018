#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetVerticalSync(true);
    
    ofSetBackgroundColor(255, 255, 255);
    ofSetVerticalSync(true);
    
    int num = 1000;
    
    p.assign(num, Particle());
    resetParticles();
    

}

void ofApp::resetParticles(){
    
    attractPoints.clear();
    for(int i = 0; i < 1; i++){
        attractPoints.push_back( ofPoint( ofMap(i, 0, 4, 100, ofGetWidth()-100) , ofRandom(100, ofGetHeight()-100) ) );
    }
    
    attractPointsWithMovement = attractPoints;
    
    for(unsigned int i = 0; i < p.size(); i++){
        
        p[i].setAttractPoints(&attractPointsWithMovement);;
        p[i].reset();
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
    for(unsigned int i = 0; i < p.size(); i++){
        
        p[i].update();
        
    }
    
    for(unsigned int i = 0; i < attractPointsWithMovement.size(); i++){
        attractPointsWithMovement[i].x = attractPoints[i].x + ofSignedNoise(i * 10, ofGetElapsedTimef() * 0.7) * 10.0;
        attractPointsWithMovement[i].y = attractPoints[i].y + ofSignedNoise(i * -10, ofGetElapsedTimef() * 0.7) * 10.0;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for(unsigned int i = 0; i < p.size(); i++){
        p[i].draw();
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
