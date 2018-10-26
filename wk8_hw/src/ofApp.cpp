#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofEnableAlphaBlending();
    ofSetVerticalSync(true);
    
    sound0.load("0.mp3");
    sound1.load("1.mp3");
    sound2.load("2.mp3");
    sound3.load("3.mp3");
    sound4.load("4.mp3");
    sound5.load("5.mp3");
    sound6.load("6.mp3");
    sound7.load("7.mp3");
    sound8.load("8.mp3");
    sound9.load("9.mp3");
    sound10.load("10.mp3");
    sound11.load("11.mp3");
    sound12.load("12.mp3");
    sound13.load("13.mp3");
    sound14.load("14.mp3");
//    sound0.setMultiPlay(true);
//    sound1.setMultiPlay(true);
//    sound2.setMultiPlay(true);
//    sound3.setMultiPlay(true);
//    sound4.setMultiPlay(true);
//    sound5.setMultiPlay(true);
//    sound6.setMultiPlay(true);
//    sound7.setMultiPlay(true);
//    sound8.setMultiPlay(true);
//    sound9.setMultiPlay(true);
    
    
    ofBackground(0, 0, 0);
    
    
    for(int i = 0; i < 15; i++){
        
        line l;
        lines.push_back(l);
        lines[i].setup(280 + (i+1)*30);
    
    }


    

}

//--------------------------------------------------------------
void ofApp::update(){
    
    for(int i = 0; i < 15; i++){
        
        lines[i].update();
        
    }
   


}

//--------------------------------------------------------------
void ofApp::draw(){
    
    

    
    for(int i = 0; i < 15; i++){
        
        ofSetColor(255);
        
        lines[i].draw();
        
        if(ofGetMouseX() < lines[0].xPos + 5 && ofGetMouseX() > lines[0].xPos - 5){
            
            sound0.play();
            
        }
        if(ofGetMouseX() < lines[1].xPos + 5 && ofGetMouseX() > lines[1].xPos - 5){
            
            sound1.play();
            
        }
        if(ofGetMouseX() < lines[2].xPos + 5 && ofGetMouseX() > lines[2].xPos - 5){
            
            sound2.play();
            
        }
        if(ofGetMouseX() < lines[3].xPos + 5 && ofGetMouseX() > lines[3].xPos - 5){
            
            sound3.play();
            
        }
        if(ofGetMouseX() < lines[4].xPos + 5 && ofGetMouseX() > lines[4].xPos - 5){
            
            sound4.play();
            
        }
        if(ofGetMouseX() < lines[5].xPos + 5 && ofGetMouseX() > lines[5].xPos - 5){
            
            sound5.play();
            
        }
        
        if(ofGetMouseX() < lines[6].xPos + 5 && ofGetMouseX() > lines[6].xPos - 5){
            
            sound6.play();
            
        }
        if(ofGetMouseX() < lines[7].xPos + 5 && ofGetMouseX() > lines[7].xPos - 5){
            
            sound7.play();
            
        }
        if(ofGetMouseX() < lines[8].xPos + 5 && ofGetMouseX() > lines[8].xPos - 5){
            
            sound8.play();
            
        }
        
        if(ofGetMouseX() < lines[9].xPos + 5 && ofGetMouseX() > lines[9].xPos - 5){
            
            sound9.play();
            
        }
        if(ofGetMouseX() < lines[10].xPos + 5 && ofGetMouseX() > lines[10].xPos - 5){
            
            sound10.play();
            
        }
        if(ofGetMouseX() < lines[11].xPos + 5 && ofGetMouseX() > lines[11].xPos - 5){
            
            sound11.play();
            
        }
        if(ofGetMouseX() < lines[12].xPos + 5 && ofGetMouseX() > lines[12].xPos - 5){
            
            sound12.play();
            
        }
        if(ofGetMouseX() < lines[13].xPos + 5 && ofGetMouseX() > lines[13].xPos - 5){
            
            sound13.play();
            
        }
        if(ofGetMouseX() < lines[14].xPos + 5 && ofGetMouseX() > lines[14].xPos - 5){
            
            sound14.play();
            
        }
        
    }
    


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
