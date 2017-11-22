#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //Environment
    ofBackground(0);
    //Variables
    mySound.load("BDC_06_60_Feet_Deep.mp3");
    nBands = 16;//maximum is 512
    rectWidth = ofGetWidth()/nBands;
}

//--------------------------------------------------------------
void ofApp::update(){
    spectrum=ofSoundGetSpectrum(nBands);
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i=0; i<nBands; i++){
        int red=ofMap(i,0,nBands,0,255);
        ofSetColor(red, 0, 255);
        //we multiply de spectrum by i to compensate for smaller values from higher frequencies
        float rectHeight=spectrum[i]*(i+1)*(ofGetHeight());
        ofDrawRectangle(rectWidth*i,ofGetHeight(),rectWidth,-rectHeight);
    }
    ofDrawBitmapString("Press Space to play, Backspace to stop sound", 10,20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key==' '){
        mySound.play();
    }
    if(key==OF_KEY_BACKSPACE){
        mySound.stop();
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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
