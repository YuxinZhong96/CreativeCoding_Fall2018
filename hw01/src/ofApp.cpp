#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(0, 0, 0);
    pct =  0.0;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if (pct < 1){
        pct += 0.005;
    }
    
    if (pct >= 1){
        pct = 0;
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    float linearPct = linear(pct);
    float inQuadPct = inQuad(pct);
    float outQuadPct = outQuad(pct);
    float inOutQuadPct = inOutQuad(pct);
    float inCubicPct = inCubic(pct);
    float outCubicPct = outCubic(pct);
    float inOutCubicPct = inOutCubic(pct);
    float inQuartPct = inQuart(pct);
    float outQuartPct = outQuart(pct);
    float inExpoPct = inExpo(pct);
    float outExpoPct = outExpo(pct);
    float inQuintPct = inQuint(pct);
    float outQuintPct = outQuint(pct);
    float inOutQuintPct = inOutQuint(pct);
    
    
    
    
    float startPos = 10;
    float endPos = 990;
    
    float linearPos = (1 - linearPct) * startPos + linearPct * endPos;
    ofDrawRectangle(linearPos, 50, 20, 20);
    
    
    float inQuadPos = (1 - inQuadPct) * startPos + inQuadPct * endPos;
    ofDrawRectangle(inQuadPos, 100, 20, 20);
    
    float outQuadPos = (1 - outQuadPct) * startPos + outQuadPct * endPos;
    ofDrawRectangle(outQuadPos, 150, 20, 20);
    
    float inOutQuadPos = (1 - inOutQuadPct) * startPos + inOutQuadPct * endPos;
    ofDrawRectangle(inOutQuadPos, 200, 20, 20);
    
    float inCubicPos = (1 - inCubicPct) * startPos + inCubicPct * endPos;
    ofDrawRectangle(inCubicPos, 250, 20, 20);
    
    float outCubicPos = (1 - outCubicPct) * startPos + outCubicPct * endPos;
    ofDrawRectangle(outCubicPos, 300, 20, 20);
    
    float inOutCubicPos = (1 - inOutCubicPct) * startPos + inOutCubicPct * endPos;
    ofDrawRectangle(inOutCubicPos, 350, 20, 20);
    
    float inQuartPos = (1 - inQuartPct) * startPos + inQuartPct * endPos;
    ofDrawRectangle(inQuartPos, 400, 20, 20);
    
    float outQuartPos = (1 - outQuartPct) * startPos + outQuartPct * endPos;
    ofDrawRectangle(outQuartPos, 450, 20, 20);
    
    float inExpoPos = (1 - inExpoPct) * startPos + inExpoPct * endPos;
    ofDrawRectangle(inExpoPos, 500, 20, 20);
    
    float outExpoPos = (1 - outExpoPct) * startPos + outExpoPct * endPos;
    ofDrawRectangle(outExpoPos, 550, 20, 20);
    
    float inQuintPos = (1 - inQuintPct) * startPos + inQuintPct * endPos;
    ofDrawRectangle(inQuintPos, 600, 20, 20);
    
    float outQuintPos = (1 - outQuintPct) * startPos + outQuintPct * endPos;
    ofDrawRectangle(outQuintPos, 650, 20, 20);
    
    float inOutQuintPos = (1 - inOutQuintPct) * startPos + inOutQuintPct * endPos;
    ofDrawRectangle(inOutQuintPos, 700, 20, 20);
    
    
    
    
    
    
    
    

    
}


float ofApp::linear(float t){
    return t;
}

float ofApp::inQuad(float t){
    return t * t;
}

float ofApp::outQuad(float t){
    return t * ( 2 - t );
}

float ofApp::inOutQuad(float t){
    return t < .5 ? 2 * t * t : -1 + (4 - 2 * t) * t;
}

float ofApp::inCubic(float t){
    return t * t * t;
}

float ofApp::outCubic(float t){
    return (--t) * t * t + 1;
}

float ofApp::inOutCubic(float t){
    return t < .5 ? 4 * t * t * t : (t - 1) * (2 * t - 2) * (2 * t - 2) + 1;
}

float ofApp::inQuart(float t){
    return t * t * t * t;
}

float ofApp::outQuart(float t){
    return 1 - (--t) * t * t * t;
}

float ofApp::inExpo(float t){
    return (t == 0) ? 0 : pow(2, 10 * (t - 1));
}

float ofApp::outExpo(float t){
    return (t == 1) ? 1 : (pow(2, -10 * t) + 1);
}

float ofApp::inQuint(float t){
    return t * t * t * t * t;
}

float ofApp::outQuint(float t){
    return 1 + (--t) * t * t * t * t;
}

float ofApp::inOutQuint(float t) {
    return t < .5 ? 16 * t * t * t * t * t : 1 + 16 * (--t) * t * t * t * t;
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
