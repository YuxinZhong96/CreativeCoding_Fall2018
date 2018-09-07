#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // initial conditions and set initial values

    ofSetBackgroundColor(ofColor::pink);
    xpos = 0.0;
    pct = 0.0;
    
//    mposX = 0.0;
//    mposY = 0.0;
    
    mpos = ofPoint (0,0);
    
// adding some values to the vector
    
    for (int i = 0; i < 10; i++){
        manyPoints.push_back(ofPoint(i*20,i*20));
    }
    
 
    

}

//--------------------------------------------------------------
void ofApp::update(){


    
    if (pct < 1)
        pct +=.005;
    
    
    for(int i = 0; i < manyPoints.size(); i++){
        float mPct = .001 * (i + 1);
        manyPoints[i].x = (1 - mPct) * manyPoints[i].x + mPct * mouseX;
        manyPoints[i].y = (1 - mPct) * manyPoints[i].y + mPct * mouseY;
    }
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    xpos += .25;
    
    ofSetCircleResolution(50);
    ofSetColor(0);
    ofDrawCircle(xpos, ofGetHeight()/2, 40);
    
    float startPos = 100;
    float endPos = 600;
    
    float nPct = pow(pct,2);
    float sPct = inOutSine(pct);
    
    float currentPos = (1 - nPct) * startPos + nPct * endPos;
    ofDrawCircle(currentPos, 200, 40);
    
    float linearPos = (1 - pct) * startPos + pct * endPos;
    ofDrawCircle(linearPos, 300, 40);
    
    float sPos = (1 - sPct) * startPos + sPct * endPos;
    ofDrawCircle(sPos, 400, 40);
    
    
    
    float mPct = .2;
    mpos.x = (1 - mPct) * mpos.x + mPct * ofGetMouseX();
    mpos.y = (1 - mPct) * mpos.y + mPct * ofGetMouseY();
    ofDrawCircle(mpos, 40);
    
    
    for (int i = 0; i < manyPoints.size(); i++){
        ofDrawRectangle(manyPoints[i], 20, 20);
    }
    
    
}

float ofApp::inOutSine(float t){
    return 0.5 * (1 + sin (PI * (t - 0.5)));
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    pct = 0;

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
