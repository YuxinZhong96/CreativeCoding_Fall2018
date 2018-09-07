#pragma once

#include "ofMain.h"

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
    
    
        float pct;
    
    
        float linear(float t);
        float inQuad(float t);
        float outQuad(float t);
        float inOutQuad(float t);
        float inCubic(float t);
        float outCubic(float t);
        float inOutCubic(float t);
        float inQuart(float t);
        float outQuart(float t);
        float inExpo(float t);
        float outExpo(float t);
        float inQuint (float t);
        float outQuint (float t);
        float inOutQuint(float t);
    
    
  
    
    
		
};
