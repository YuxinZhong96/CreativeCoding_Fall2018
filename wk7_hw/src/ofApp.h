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
    
    
        ofCamera cam;
        vector <ofVec3f> boxPos;
        ofLight light;
        ofFbo fbo;
    
    
        void audioIn(ofSoundBuffer & input);
    
    
        vector <float> left;
        vector <float> right;
        vector <float> volume;
    
        float smoothedVol;
        float scaledVol;
    
        int bufferCounter;
        bool count;
        int lookAtMe;
        float pct;
    
        float rotateXDeg;
        float rotateYDeg;
        float rotateZDeg;
    
    
        ofVec3f desPos;
        ofVec3f cameraPos;
        ofVec3f followPos;
    
    
        ofSoundStream soundStream;
    
		
};
