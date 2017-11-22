#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //Environment
    ofSetCircleResolution(200);
    ofEnableAlphaBlending();
    ofSetBackgroundAuto(false);
    ofBackground(0);
    //Variables
    mouseHasMoved=false;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    if(mouseHasMoved){
        ofFill();
        ofSetColor(255,20);
        ofDrawCircle(mouseX,mouseY,100);
        ofNoFill();
        ofSetLineWidth(5);
        ofSetColor(255, 0, 0,20);
        ofDrawCircle(mouseX,mouseY,ofRandom(110,150));
    }
    ofDrawBitmapString("Press backspace to erase the background, 'q' to paint it grey", 10,20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key==OF_KEY_BACKSPACE){
        ofBackground(0);
    }
    if(key=='q'){
        ofBackground(100);
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
    mouseHasMoved=true;
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
