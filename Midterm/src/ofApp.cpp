#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    image.load("bg1.jpeg");
    
    bg = 1;
    
    
    w = image.getWidth();
    h = image.getHeight();
    pixels = w * h;
    updatedImage.allocate(w, h, OF_IMAGE_COLOR);
    
    ofSetFullscreen(true);
    
    
    
    tData.resize(pixels);
    oData.resize(pixels);
    nData.resize(pixels);
    
    
    
    for (int i = 0; i < pixels; i++){
        tData[i] = 0.0;
        oData[i] = 0.0;
        nData[i] = 0.0;
        
    }
    
    gui.setup();
    gui.add(ripples.setup("ripple", 60, 20, 100));
    

    
    ofEnableAlphaBlending();
    ofSetVerticalSync(true);
    
    
    for(int i = 0; i< 300; i++){
        Particle p;
        particles.push_back(p);
        particles[i].setup(ofPoint(
                                   ofRandom(ofGetWidth()),
                                   ofRandom(ofGetHeight())
                                   ));
    }


}

//--------------------------------------------------------------
void ofApp::update(){
    
    ofLog() << "update sim";
    sim();
    
    ofLog() << "update pixels";
    for(int i = 0; i < pixels; i++){
        int x = i % w;
        int y = i / w;
        

        
        ofVec3f n = ofVec3f(getVal(x - eps, y) - getVal(x + eps, y), getVal(x, y - eps) - getVal(x, y + eps), eps * 2.0);
        
        n.normalize();

        ofColor c = image.getColor(x + n.x * ripples, y + n.y * ripples);
        c.r = ofClamp(c.r, 0, 255);
        c.g = ofClamp(c.g, 0, 255);
        c.b = ofClamp(c.b, 0, 255);
        updatedImage.setColor(x, y, c);
        
    }
    
    updatedImage.update();
    
    ofLog() << "update particles";
    ofPoint mouse = ofPoint(mouseX, mouseY);
    
    
    for(int i = 0; i < particles.size(); i++){
        
        particles[i].addAttractionForce(mouse, 100, 0.01);
        particles[i].update();
    }
    
    
    for(int i = 0; i < particles.size(); i++){
        for (int j = 0; j < i; j ++){
            particles[i].addRepulsionForce(particles[j].pos, 35, 0.1);
            particles[j].addRepulsionForce(particles[i].pos, 35, 0.1);
        }
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    updatedImage.draw(0,0);
    
    if(ofRandom(1) < 0.3)
    ripple();

    
    
    for(int i = 0; i < particles.size(); i++){
        
        int pixelIndex =particles[i].pos.y * w + particles[i].pos.x;
        if(pixelIndex < w*h-1 && pixelIndex >= 0){
            ofColor c = image.getColor(particles[i].pos.x, particles[i].pos.y);
            ofSetColor(c,100);
            particles[i].draw();
        }
    }

    
    float maxDist = 50;
    float alpha = 255;
    ofSetColor(255, alpha);
//    for (int i = 0; i < particles.size(); i++){
//        for (int j = 0; j < particles.size(); j++){
//            float dist = (particles[i].pos - particles[j].pos).length();
//            if(dist < maxDist){
//
//                alpha = ofMap(dist, 0, maxDist, 255, 0);
//                ofSetColor(255, alpha);
//            }
//        }
//    }
//    ofLog()<<alpha;
    gui.draw();


}

void ofApp::ripple(){
    
//        int rx = ofGetMouseX() + 5;
//        int ry = ofGetMouseY() + 5;
    
        int rx = (int)ofRandom(0, w) + 5;
        int ry = (int)ofRandom(0, h) + 5;
    
        for (int x = -5; x < 5; x++){
            for (int y = -5; y < 5; y++){
                int targetPix = (rx + x) + (w * (ry + y));
                oData[targetPix] = 100;
            }
        }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    for(int i = 0; i < particles.size(); i++){
        particles[i].addForce(ofPoint(ofRandom(-4,4), ofRandom(-4,4)));
    }

}


float ofApp::getVal(int x, int y){
    
    if(x < 1 || y < 1 ||x >= w - 1 || y >= h - 1){
        return 0;
    }
    
    float a = oData[x + y * w];
    return a;
    
}


void ofApp::sim(){
    

    
    for(int i = 0; i < pixels; i++){
        tData[i] = oData[i];
    }
    
    for(int i = 0; i < pixels; i++){
        oData[i] = nData[i];
    }
    
    for(int i = 0; i < pixels; i++){
        nData[i] = tData[i];
    }
    

    
    for(int i = 0; i < pixels; i++){
        
        int x = i % w;
        int y = i / w;
        if (x > 1 && y > 1 && x <= w - 1 && y <= h - 1){
            float val = (oData[(x-1)+y*w] + oData[(x+1)+y*w] + oData[x+(y-1)*w] + oData[x+(y+1)*w]) / 2;
            val = val - nData[x+y*w];
            nData[x+y*w] = val;
        }
    }
    
    
    
    
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
    
    bg *= -1;
    
    if(bg == 1)
        image.load("bg1.jpeg");
    
    else
        image.load("bg2.jpeg");

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
