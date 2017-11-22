#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //Environment
    ofBackground(0);
    ofEnableSmoothing();
    ofSetVerticalSync(true);
    ofSetCircleResolution(100);
    ofEnableAlphaBlending();
    //Variables
    mouseHasPressed=false;
}

//--------------------------------------------------------------
void ofApp::update(){
    if(mouseHasPressed){
        for(int i=0;i<newCircles.size();i++){
            //collision detection
            for(int k=i+1;k<newCircles.size();k++){
                float distance=ofDist(newCircles[i].x, newCircles[i].y,
                                      newCircles[k].x,newCircles[k].y);
                float minDist=newCircles[i].minRadius+newCircles[k].minRadius;
                //there is collision if distance<=minDist
                if(distance<=minDist){
                    newCircles[i].speedX*=-1;
                    newCircles[i].speedY*=-1;
                    newCircles[k].speedX*=-1;
                    newCircles[k].speedY*=-1;
                }
            }
            //end of collision detection
            newCircles[i].update();
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    if(mouseHasPressed){
        for(int i=0;i<newCircles.size();i++){
            if(i>0){
                ofSetColor(255,150);
                ofDrawLine(newCircles[i-1].x,newCircles[i-1].y,
                       newCircles[i].x,newCircles[i].y);
            }
            newCircles[i].draw();
        }
    }
    ofSetColor(255);
    ofDrawBitmapString("click to add circles, press <backspace> to delete", 10,20);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if(key==OF_KEY_BACKSPACE){
        if(newCircles.size()>0){
            newCircles.pop_back();
        }
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    //this is "not": !=
    if(x!=0 && y!=0){
        mouseHasPressed=true;
        MyCircle newCircle;
        newCircle.setup(x, y);
        //with push_back we add a new circle to a vector of circles
        newCircles.push_back(newCircle);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

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
