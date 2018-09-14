#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    gui.setup();
    gui.add(freqSlider.setup("Sin Freq", 1, 0.25, 10));

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    float targetAngle = atan2(mouseY - ofGetHeight()/2, mouseX - ofGetWidth()/2);
    
    ofPushMatrix();
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
        ofRotateZRad(targetAngle);
        ofDrawRectangle(0, 0, 50, 50);
    ofPopMatrix();
    
    
    for(int i = 0; i < 360; i += 30){
        float angle = ofDegToRad(i);
        float x = ofGetWidth()/2 + (i * 0.5) * cos(angle);
        float y = ofGetHeight()/2 + (i * 0.5) * sin(angle);

        ofDrawCircle(x, y, 20);
    }
    
    
    
    
    
    for (int xPos = 0; xPos < ofGetWidth(); xPos +=30){
        for (int yPos = 0; yPos < ofGetHeight(); yPos += 30){

            float sinValue = ofMap(sin(ofGetElapsedTimef()) * yPos * freqSlider * 0.01,-1,1,1,15);
            float a = 5 + sinValue;

            ofDrawRectangle(xPos, yPos, a, a);}}


    gui.draw();
    
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
