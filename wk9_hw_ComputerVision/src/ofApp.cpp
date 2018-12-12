#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    
    int w = 640;
    int h = 480;
    
    count = 0;
    
    
    camera.initGrabber(w, h);
    camera.setDeviceID(0);
    camera.setDesiredFrameRate(60);
    
    ofSetBackgroundColor(0);
    
    ofSetWindowShape(640, 480);
    
    
    
    // allocating the images
    colorImg.allocate(w, h);
    grayImage.allocate(w, h);
    grayBg.allocate(w, h);
    grayDiff.allocate(w, h);
    
    
    captureBackground = true;
    
    
    
    bHasVerts = false;
    
    box2d.init();
    box2d.setGravity(0, 10);
    box2d.createBounds();
    box2d.setFPS(60.0);
    box2d.registerGrabbing();

}

//--------------------------------------------------------------
void ofApp::update(){
    
    bool bNewFrame = false;
    camera.update();
    box2d.update();
    
    bNewFrame = camera.isFrameNew();
    
    if(bNewFrame){
        
        // work with the new camera/video information
        
        
        
        // copy the video image into the color image object
        
        colorImg.setFromPixels(camera.getPixels());
        
        // convert and store in grayscale image;
        grayImage = colorImg;
        
        
        if(captureBackground){
            
            // copy the current image to a background image
            grayBg = grayImage;
            captureBackground = false;
            
        }
        
        // abs differences and thresholding
        
        
        grayDiff.absDiff(grayImage, grayBg);
        grayDiff.threshold(120);
        
        // contour finder
        
        contourFinder.findContours(grayDiff, 500, (320 * 240)/40, 50, true, true); // find holes
        
    }
    
    
    
    
    // update the edge shape with the vertices of the largest bulb
    
    if(contourFinder.nBlobs > 0){
        
        // if we already have previous vertices, clear them
        if(bHasVerts){
            
            shape.clear();
            
        }
        
        
        // add all the vertices of the contour
        
        float scale = 1;
        
        for(int i = 0; i < contourFinder.blobs[0].pts.size(); i++){
            
            shape.addVertex(contourFinder.blobs[0].pts[i].x * scale, contourFinder.blobs[0].pts[i].y * scale);
            
        }
        
        shape.create(box2d.getWorld());
        bHasVerts = true;
        ifDraw = true;
        
        
        
        
    }
    
    
    if(ifDraw && count < 3){
        
        auto poly = std::make_shared<ofxBox2dPolygon>();
        
        
        for(int i = 0; i < contourFinder.blobs[0].pts.size(); i++){
            
            poly->addVertex(contourFinder.blobs[0].pts[i].x + mouseX, contourFinder.blobs[0].pts[i].y + mouseY);
            
        }
        
        
        //        poly->addVertices(contourFinder.blobs[0].pts);
        poly->setPhysics(1.0, 0.3, 0.3);
        poly->triangulatePoly();
        poly->create(box2d.getWorld());
        PolyShapes.push_back(poly);
        
        ifDraw = false;
        count += 1;
        
    } else
        count = 0;


}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    ofSetColor(255);
    shape.draw();
    
//    camera.draw(0, 0);
//    grayDiff.draw(0, 0);
//    contourFinder.draw(0, 0);
    
    // draw the center point on the largest blob
    
    if(contourFinder.nBlobs > 0){
        
        int x = contourFinder.blobs[0].boundingRect.getCenter().x;
        int y = contourFinder.blobs[0].boundingRect.getCenter().y;
        
        
        ofSetColor(255, 0, 0);
        ofDrawCircle(x, y, 4);
        
        
        ofPoint center = contourFinder.blobs[0].centroid;
        
        ofSetColor(0, 255, 0);
        ofDrawCircle(center, 4);
        
        
    }
    
    for(int i=0; i<circles.size(); i++) {
        ofFill();
        ofSetHexColor(0xf6c738);
        circles[i].get()->draw();
    }
    
    
    for(int i=0; i<PolyShapes.size(); i++) {
        
        PolyShapes[i]->draw();
        ofDrawCircle(PolyShapes[i]->getPosition(), 3);
    }



}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(key == 'b'){
        
        captureBackground = true;
        
    }
    
    
    if(key == 'c') {
        float r = ofRandom(4, 20);
        circles.push_back(shared_ptr<ofxBox2dCircle>(new ofxBox2dCircle));
        circles.back().get()->setPhysics(3.0, 0.53, 0.1);
        circles.back().get()->setup(box2d.getWorld(), mouseX, mouseY, r);
    }
    
    
    
//    else if(key == 's' && contourFinder.nBlobs > 0){
//
//        auto poly = std::make_shared<ofxBox2dPolygon>();
//
//
//        for(int i = 0; i < contourFinder.blobs[0].pts.size(); i++){
//
//            poly->addVertex(contourFinder.blobs[0].pts[i].x + mouseX, contourFinder.blobs[0].pts[i].y + mouseY);
//
//        }
//
//
//        //        poly->addVertices(contourFinder.blobs[0].pts);
//        poly->setPhysics(1.0, 0.3, 0.3);
//        poly->triangulatePoly();
//        poly->create(box2d.getWorld());
//        PolyShapes.push_back(poly);
//
//
//    }

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
