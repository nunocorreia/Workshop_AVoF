#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //Environment
    ofBackground(0);
    ofEnableAlphaBlending();
    ofSetRectMode(OF_RECTMODE_CENTER);
    //Variables
    for(int i=0;i<numSquares;i++){
        posX[i]=ofRandomWidth();
        posY[i]=ofRandomHeight();
        blue[i]=ofRandom(255);
        size[i]=100;
    }
    mouseHasMoved=false;
}

//--------------------------------------------------------------
void ofApp::update(){
    float speed = 20;
    if(mouseHasMoved){
        for(int i=0;i<numSquares;i++){
            dist[i]=ofDist(posX[i],posY[i],mouseX,mouseY);
            if(dist[i]>200){
                //atraction to mouse
                //the larger the "speed", the slower the convergence
                posX[i]+=(mouseX-posX[i])/speed;
                posY[i]+=(mouseY-posY[i])/speed;
            }else{
                //repulsion to mouse
                posX[i]-=(mouseX-posX[i])/speed;
                posY[i]-=(mouseY-posY[i])/speed;
            }
            size[i]=20000/dist[i];
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i=0;i<numSquares;i++){
        ofSetColor(0,255,blue[i],100);
        ofDrawRectangle(posX[i], posY[i], size[i], size[i]);
    }
}
//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
    mouseHasMoved=true;
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

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
