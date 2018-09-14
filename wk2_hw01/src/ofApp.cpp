#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    gui.setup();
    gui.add(freqSlider.setup("Sin Freq", 1, 0.25, 5));
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
    pct = ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, 1);

  
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    float targetAngle = atan2(mouseY - ofGetHeight()/3, mouseX - ofGetWidth()/3);
    
    for (int i = 0; i < 360; i += 5){
        for (int j = 5; j < 1500; j += 25){
            
            
            float sinValue = ofMap(sin(ofGetElapsedTimef()) * j * freqSlider * 0.01, -1, 1, -5, 15);
            
            float a = 5 + sinValue;
            
            float angle = ofDegToRad(i);
            
            float posX = ofGetWidth()/2 + j * cos(angle);
            float posY = ofGetHeight()/2 + j * sin(angle);
            
            pct = ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, 1);

            
            int r = (1 - pct) * purpleR + pct * redR;
            int g = (1 - pct) * purpleG + pct * redG;
            int b = (1 - pct) * purpleB + pct * redB;
            
            
            ofPushMatrix();
            
                ofTranslate(ofGetWidth()/3, ofGetHeight()/3);
            
                ofRotateZRad(targetAngle);
            
                ofSetColor(r,g,b);
            
                ofDrawCircle(posX, posY, a);
       
            ofPopMatrix();
            
     
            

        }
    }
    
    
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
