#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
//    ofLog() << sinValue;
//    ofSetCircleResolution(50);
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    for (int xPos = 0; xPos < ofGetWidth(); xPos +=30){
        for (int yPos = 0; yPos < ofGetHeight(); yPos += 30){
            
            float sinValue = ofMap(sin(ofGetElapsedTimef())+sin(xPos)+sin(yPos),-1,1,1,15);
            float a = 5 + sinValue;
            
            ofDrawRectangle(xPos, yPos, a, a);}}
    

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
