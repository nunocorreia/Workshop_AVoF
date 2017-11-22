#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //Environment
    ofBackground(0);
    ofSetCircleResolution(100);
    //Variables
    //setup(int outChannels, int inChannels, int sampleRate, int bufferSize, int nBuffers)
    mySoundStream.setup(this,0,2, 44100,256,4);
    left=new float[256];
    right=new float[256];
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i=0; i<mySoundStream.getBufferSize(); i++){
        ofSetColor(i,0,255);
        float leftX=ofMap(i,0,255,0,ofGetWidth()/2);
        ofDrawCircle(leftX, ofGetHeight()/2, left[i]*ofGetHeight()/2);
        ofSetColor(255,i,0);
        float rightX=ofMap(i,0,255,ofGetWidth()/2,ofGetWidth());
        ofDrawCircle(rightX, ofGetHeight()/2, right[i]*ofGetHeight()/2);
    }
}

//--------------------------------------------------------------
void ofApp::audioIn(float *input, int buffersize, int nChannels){
    for(int i=0; i<buffersize; i++){//buffersize is 256
        left[i]=input[i*nChannels];//nChannels is 2
        right[i]=input[i*nChannels+1];
    }
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
