#pragma once

#include "ofMain.h"
#include "line.hpp"

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
    
    
        vector <line> lines;
        
        ofSoundPlayer sound0;
        ofSoundPlayer sound1;
        ofSoundPlayer sound2;
        ofSoundPlayer sound3;
        ofSoundPlayer sound4;
        ofSoundPlayer sound5;
        ofSoundPlayer sound6;
        ofSoundPlayer sound7;
        ofSoundPlayer sound8;
        ofSoundPlayer sound9;
        ofSoundPlayer sound10;
        ofSoundPlayer sound11;
        ofSoundPlayer sound12;
        ofSoundPlayer sound13;
        ofSoundPlayer sound14;
    
        
    

		
};
