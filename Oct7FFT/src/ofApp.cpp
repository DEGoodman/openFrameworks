#include "ofApp.h"

//global vars
int fs = 44100; //sampling frequency
const int TheBuffSize = 512; //'const' lets us use it as size of array
float Spectrum[TheBuffSize];
int MaxFreq = 22050; //limit freqs to 'zoom in' for analysis

//--------------------------------------------------------------
void ofApp::setup(){

    
    soundStream.setup(this, 0, 2, fs, TheBuffSize, 4);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(200, 0, 0);  //red!
    
    float TheLimit = TheBuffSize*MaxFreq/(float)fs; // linear proportion between frequencies
    
    //represent ea. freq as rectangular bin
    float binW = 0.9*ofGetWidth()/(float)TheLimit; //devides width of screen, with a little space, by number of elements
    
    for (int k=0; k < TheBuffSize; k++) {
        ofRect(0.05*ofGetWidth() + k*binW, //small margin, new bin
               3*ofGetHeight()/4.0, //not a critical value
               binW, //width of each bin
               -10*Spectrum[k]);
    }
    
}

//-------------------------------------------------------------- //call-back function
void ofApp::audioIn(float * input, int bufferSize, int nChannels){
    
    //OpenCV FFT fxn
    //number of Rows; number of Columns; data type is 32-bit, Floating point values, 2 Channels (it will read data 1-channel at a time)

    cv::Mat AudioBuff(1,TheBuffSize,CV_32FC2);
    Float32 *PointBuff = (Float32*) AudioBuff.data; // defines a pointer to whatever m-x previously defined that has data
    
    //reads whatever is incoming from mic and copy it to OpenCV for processing
    for (int i = 0; i < bufferSize; i++){
        float left, right;
        
        //see line 32
        left = input[i*nChannels]*0.5;
        right = input[i*nChannels]*0.5;
        
        //let's play with data!
        PointBuff[2*i] = (Float32)(left+right); //'real' signals
        PointBuff[2*i + 1] = 0.0; //'imaginary' signals

    }
    
    // does... something
    dft(AudioBuff, AudioBuff);
    
    for (int i = 0; i < bufferSize; i++){

        //see lines 45, 46
        float TheReal = PointBuff[2*i];
        float TheImaginary = PointBuff[2*i + 1];
        
        Spectrum[i] = sqrt(TheReal*TheReal +
                           TheImaginary*TheImaginary);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case OF_KEY_RIGHT:
            MaxFreq+=50;
            break;
            
        case OF_KEY_LEFT:
            MaxFreq-=50;
            break;
            
        default:
            break;
    }
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
