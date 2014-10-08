#include "ofApp.h"

const int nStar = 1400;
float speed = 0.01;
float angle[nStar];
float radius[nStar];
ofImage TheStar;
//--------------------------------------------------------------
void ofApp::setup(){
    TheStar.loadImage("sprite16.png");
    ofSetWindowShape(800, 600);
    for (int i = 0; i < nStar; i++) {
        angle[i] = ofRandom(0, TWO_PI);
        radius[i] = ofRandom(1,300);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0, 0, 0);
    
    ofSetColor(255,255,192,100);
    float x,y;
    int width = ofGetWidth();
    int height = ofGetHeight();
    ofTranslate(width/2.0, height/2.0);
    for (int i=0; i< nStar; i++){
        angle[i]+=speed;
        x = radius[i]*cos(angle[i]);
        y = ofMap(mouseX,0,width,0.2,5.0)*radius[i]*sin(angle[i]);
        ofPushMatrix();
        
        ofRotate(ofMap(mouseY,0,height,0,4*180)*radius[i]/200.0);
        ofTranslate(x,y);
        TheStar.draw(0,0);
        
        ofPopMatrix();
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
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