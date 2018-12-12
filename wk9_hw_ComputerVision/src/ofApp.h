#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "ofxBox2d.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    
    
        ofVideoGrabber        camera;
    
    
    
        ofxCvColorImage       colorImg;
    
        ofxCvGrayscaleImage     grayImage;
        ofxCvGrayscaleImage     grayBg;
        ofxCvGrayscaleImage     grayDiff;
    
        ofxCvContourFinder     contourFinder;
    
    
        bool captureBackground;
    
        bool ifDraw;
    
        int count;
    
    
    
        ofxBox2d                               box2d;   // the box2d world
        vector   <shared_ptr<ofxBox2dCircle> > circles; // default box2d circles
        vector   <shared_ptr<ofxBox2dCircle> > boxes;
    
        ofxBox2dEdge shape;
        bool bHasVerts;
    
        vector   <shared_ptr<ofxBox2dPolygon> > PolyShapes;
    
		
};
