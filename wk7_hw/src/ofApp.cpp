#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetBackgroundColor(0);
    
    ofEnableDepthTest();
    ofEnableAlphaBlending();
    ofSetVerticalSync(true);
    
    fbo.allocate(ofGetWidth(), ofGetHeight());
    
    soundStream.printDeviceList();
    
    int bufferSize = 256;

    
    bufferCounter = 0;
    smoothedVol = 0.0;
    scaledVol = 0.0;
    
    
    rotateXDeg = 0.0;
    rotateYDeg = 0.0;
    rotateZDeg = 0.0;
    
    
    ofSoundStreamSettings settings;
    auto devices = soundStream.getMatchingDevices("default");
    if(!devices.empty()){
        settings.setInDevice(devices[0]);
    }
    settings.setInListener(this);
    settings.sampleRate = 44100;
    settings.numOutputChannels = 0;
    settings.numInputChannels = 2;
    settings.bufferSize = bufferSize;
    soundStream.setup(settings);
    
       
    count = false;
    
    cam.setPosition(130, 50, 300);
    cam.tiltDeg(-10);
    followPos.set(cam.getPosition());

    
    light.setPosition(50, 100, 10);
    light.setAmbientColor(ofFloatColor(0.8, 0.8, 0.8));
    light.enable();
    
    
    for (int i = 0; i < 200; i++){
        ofVec3f pos;
        boxPos.push_back(pos);
        boxPos[i].set(ofRandom(0,300), ofRandom(0, 300), ofRandom(0, 300));
        
    }
    
    left.assign(bufferSize, 0.0);
    right.assign(bufferSize, 0.0);
    volume.assign(boxPos.size(), 0.0);

}

//--------------------------------------------------------------
void ofApp::update(){
    
    scaledVol = ofMap(smoothedVol, 0.0, 0.17, 0.0, 1.0, true);
    
//    volume.push_back(scaledVol);
//
//    if(volume.size() >= boxPos.size()){
//
//        volume.erase(volume.begin(), volume.begin() + 1);
//
//    }

    
    if(count == true){
        
        if(pct < 1){
            pct += 0.005;
        }
        
        float inQuadPct = pct * pct;
        
        followPos = (1 - inQuadPct) * followPos + inQuadPct * boxPos[lookAtMe];
        cam.lookAt(followPos);
        
        desPos = boxPos[lookAtMe] + 20;
        cameraPos = (1 - inQuadPct) * cameraPos + inQuadPct * desPos;
        cam.setPosition(cameraPos);
        
    }
    
    rotateXDeg += (scaledVol + 0.1) * 10;
    rotateYDeg += (scaledVol + 0.1) * 10;
    rotateZDeg += (scaledVol + 0.1) * 10;



}

//--------------------------------------------------------------
void ofApp::draw(){
    
    cam.begin();
    
   
   
    
//        ofDrawAxis(100);
//
//        ofPushMatrix();
//            ofRotateZDeg(90);
//            ofDrawGridPlane(100);
//        ofPopMatrix();

    
    for(int i = 0 ; i < boxPos.size(); i++){
        
        float height = scaledVol * 190.0f * ofSignedNoise(boxPos[i].x * 0.01, boxPos[i].z * 0.005);
        
        ofSetColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255));
        ofNoFill();
//        ofPushMatrix();
//        ofRotateXDeg(rotateXDeg);
//        ofRotateYDeg(rotateYDeg);
//        ofRotateZDeg(rotateZDeg);
        ofDrawBox(boxPos[i].x, boxPos[i].y, boxPos[i].z, 10, ofRandom(5, 25) + height, 10);
//        ofPopMatrix();

       


    }
    


    cam.end();
    
}


void ofApp::audioIn(ofSoundBuffer & input){
    
    float curVol = 0.0;
    
    int numCounted = 0;
    
    for(size_t i = 0; i < input.getNumFrames(); i++){
        
        left[i] = input[i * 2] * 0.5;
        right[i] = input[i * 2 + 1] * 0.5;
        
        curVol += left[i] * left[i];
        curVol += right[i] * right[i];
        numCounted += 2;
        
    }
    
    curVol /= (float)numCounted;
    
    curVol = sqrt(curVol);
    
    smoothedVol *= 0.93;
    smoothedVol += 0.07 * curVol;
    
    bufferCounter++;
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    lookAtMe = ofRandom(0, boxPos.size()-1);
    pct = 0.0;
    count = true;
    followPos.set(cam.getPosition());
    
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
