#pragma once

#include "ofMain.h"

//to define a constant in .h you use the following syntax
#define numSquares 100

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    //Create arrays with a fixed size (numSquares)
    float posX[numSquares];
    float posY[numSquares];
    float dist[numSquares];
    float size[numSquares];
    float blue[numSquares];
    bool mouseHasMoved;
};
