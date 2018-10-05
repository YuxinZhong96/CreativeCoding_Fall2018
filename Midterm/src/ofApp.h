#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "Particle.hpp"


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
    
        float getVal(int x, int y);
        void sim();
        void ripple();
    
        int w;
        int h;
        int pixels;
        int bg;
    
    
        ofImage image;
        ofImage updatedImage;
    
        vector <float> oData;
        vector <float> nData;
        vector <float> tData;
    
        float eps = 10.0;

    
    
        vector <Particle> particles;
    
        ofxPanel gui;
        ofxFloatSlider ripples;
		
};
