#include "MyCircle.h"

//--------------------------------------------------------------
void MyCircle::setup(float initialX, float initialY){
    x=initialX;
    y=initialY;
    speedX=ofRandom(-10,10);
    speedY=ofRandom(-10,10);
    blue=ofRandom(255);
    counter =0;
    minRadius =50;
    maxRadius =70;
}

//--------------------------------------------------------------
void MyCircle::update(){
    x+=speedX;
    y+=speedY;
    if(x<0||x>ofGetWidth()){
        speedX*=-1;
    }
    if(y<0||y>ofGetHeight()){
        speedY*=-1;
    }
    counter+=0.05;
}

//--------------------------------------------------------------
void MyCircle::draw(){
    ofSetColor(127,100);
    ofDrawCircle(x,y,maxRadius+sin(counter)*(maxRadius-minRadius));
    ofSetColor(255,0,blue,120);
    ofDrawCircle(x,y,minRadius);
}
