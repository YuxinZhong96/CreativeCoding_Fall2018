#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetBackgroundColor(0, 0, 0);
    counter = 0;
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    counter += 0.05 ;
    
    float time = ofGetElapsedTimef();
    
    for (auto & verts: line.getVertices()){
        
        verts.x += ofSignedNoise(verts.x + time, counter);
        verts.y += ofSignedNoise(counter, verts.y + time);
        
    }
    
 

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(255, 255, 255);
    line.draw();

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
    
    ofPoint point;
    point.set(x, y);
    line.addVertex(point);

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
   line.clear();
    


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
