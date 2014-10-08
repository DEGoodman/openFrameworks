#include "ofApp.h"

//get times
string dayNight;
int hour;
int minutes;
int sec;

//time strings, for debugging
string sHour;
string sMin;
string sSec;

//--------------------------------------------------------------
void ofApp::setup(){
    // get time
    hour = ofGetHours();
    minutes = ofGetMinutes();
    sec = ofGetSeconds();

    //AM or PM?
    if (hour <= 11){
        dayNight = "AM";
    } else {
        dayNight = "PM";
    }
    
    //convert hours to 12-hour format
    hour = ofGetHours() % 12;
    if(hour == 0)
        hour = 12;
    
    //manually format time, because of string formatting sucks, and the documentation is terrible
    if (hour < 10) {
        sHour = "0";
    }
    sHour += ofToString(hour);
    
    if (minutes < 10) {
        sMin = "0";
    }
    sMin += ofToString(minutes);
    
    if (sec < 10) {
        sSec= "0";
    }
    sSec += ofToString(sec);
}

//--------------------------------------------------------------
void ofApp::update(){
    // update time before every frame
    hour = ofGetHours();
        if(hour == 0)
            hour = 12;
    minutes = ofGetMinutes();
    sec = ofGetSeconds();
    
    //AM or PM?
    if (hour <= 11){
        dayNight = "AM";
    } else {
        dayNight = "PM";
    }
    
    //convert hours to 12-hour format
    hour = ofGetHours() % 12;
    if(hour == 0)
        hour = 12;
    
    //manually format time, because of string formatting sucks, and the documentation is terrible
    //reset time strings
    sHour = "";
    sMin = "";
    sSec = "";
    
    if (hour < 10) {
        sHour = "0";
    }
    sHour += ofToString(hour);
    
    if (minutes < 10) {
        sMin = "0";
    }
    sMin += ofToString(minutes);
    
    if (sec < 10) {
        sSec= "0";
    }
    sSec += ofToString(sec);
    //log time for debugging
    string log = sHour + ":" + sMin + ":" + sSec + " " + dayNight;

    ofLog(OF_LOG_NOTICE, log);
    
    //reset all strings
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    //set background color according to time of day
    /*
     *
     */
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
