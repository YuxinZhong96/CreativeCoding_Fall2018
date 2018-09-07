#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetBackgroundColor(255, 255, 255);
    
    redR = 204;
    redG = 43;
    redB = 94;
    
    purpleR = 117;
    purpleG = 58;
    purpleB = 136;
    

}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    float inOutCubicPct = inOutCubic(pct);
    
    int StartR = 50;
    int EndR = 200;
    
    if (pct < 1){
        pct += .005;}

    
    
    R = (1 - inOutCubicPct) * StartR + inOutCubicPct * EndR;
    
    r = (1 - inOutCubicPct) * purpleR + inOutCubicPct * redR;
    g = (1 - inOutCubicPct) * purpleG + inOutCubicPct * redG;
    b = (1 - inOutCubicPct) * purpleB + inOutCubicPct * redB;
    
    
    if (pct >= 1){
        pct = 0;
        
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
//    ofSetRectMode(OF_RECTMODE_CENTER);
//    ofDrawRectangle(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth(), ofGetHeight());
    
    ofSetColor(r, g, b);
    ofSetCircleResolution(50);
    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, R);
}

float ofApp::inOutCubic(float t){
    return t < .5 ? 4 * t * t * t : (t - 1) * (2 * t - 2) * (2 * t - 2) + 1;
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
