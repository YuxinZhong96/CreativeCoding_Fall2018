#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    lilies.load("lilies.jpeg");
    
    w = lilies.getWidth();
    h = lilies.getHeight();
    pixel = w * h;
    cout << pixel << endl;
    
    ofSetWindowShape(w, h);
    ofEnableAlphaBlending();
    ofSetVerticalSync(true);
    
    counter = 0;
    


}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    lilies.draw(0, 0, w, h);
    
//    for (int i = 0; i < ofGetWidth(); i += 4){
//        for (int j = 0; j < ofGetHeight(); j += 4){
//            
//            
//            ofSetRectMode(OF_RECTMODE_CENTER);
//            float x = i + ofNoise(counter, 0.05 * i * ofGetElapsedTimef());
//            float y = j + ofNoise(0.05 * j * ofGetElapsedTimef(), counter);
//            ofColor c = lilies.getColor(x, y);
//            ofSetColor(c);
//            ofDrawRectangle(x, y, 3, 3);
//            
//        }
//    }

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
