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
    
    

    
//    if (pct < 1){
//        pct += .005;}
//
//    if (pct >= 1){
//        pct = 0;
//    }
    
    
    pct = ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, 1);
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
//    ofSetRectMode(OF_RECTMODE_CENTER);
//    ofDrawRectangle(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth(), ofGetHeight());
    
    
    for (int x = 12; x < ofGetWidth(); x += 50){
        for (int y = 0; y < ofGetHeight(); y += 50){
            
            float inOutCubicPct = inOutCubic(pct);
            
            int StartR = 20;
            int EndR = 100;
            
            R = (1 - inOutCubicPct) * StartR + inOutCubicPct * EndR;
            
            r = (1 - inOutCubicPct) * purpleR + inOutCubicPct * redR;
            g = (1 - inOutCubicPct) * purpleG + inOutCubicPct * redG;
            b = (1 - inOutCubicPct) * purpleB + inOutCubicPct * redB;
            
            ofSetColor(r, g, b);
//            ofSetCircleResolution(50);
//            ofDrawCircle(x, y, R);
            
            ofSetRectMode(OF_RECTMODE_CENTER);
            ofDrawRectangle(x, y, R, R);
            
        }
    
    }

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
