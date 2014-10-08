#include "ofApp.h"

//audio
int fs = 44100; //sample rate
long n = 0;
float modI = 1.0;

//waves
const int L = 120;
float delayLine [L];
int ind = 0; // index for memory buffer

//--------------------------------------------------------------
void ofApp::setup(){
    int bufferSize = 512;
    
    // setup audio codecs:  2 output, 0 input, sample rate, bufferSize, numBuffers
    soundStream.setup(this, 2, 0, fs, bufferSize, 4);
    
    //waves
    for (int k = 0; k<L; k++) {
        delayLine[k] = ofRandom(-0.5, 0.5);
    }

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

// frequency modulation, or FM
void ofApp::audioOut(float *output, int bufferSize, int nChannels){
//        //audio
//        float fc = 440.0; //beginning frequency
//        float fm = modI*fc; //in Hertz
//        for (int i = 0; i < bufferSize; i++){
//            //and add decay
//            float env = 0.95*exp(-n/(float)fs);
//            
//            //fm output
//            float TheOut = env*sin(TWO_PI*fc*n/(float)fs +
//                           2*env*sin(TWO_PI*fm*n/(float)fs));
//            output[i*nChannels] = TheOut;
//            output[i*nChannels + 1] = TheOut;
//            n++;
//        }
        //waves
    for (int i = 0; i < bufferSize; i++) {
        //memory buffer
        delayLine[ind] *= 0.99; //decay
        float TheOut = delayLine[ind];
        ind++;
        //at end of index, start back over
        if(ind >=L){
            ind = 0;
        }
        output[i*nChannels] = TheOut;
        output[i*nChannels + 1] = TheOut;
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
    //modI = 3.0*x/(float)ofGetWidth();
    n=0;
    
    //start again with random noise
    for (int i = 0; i < L; i++) {
        //memory buffer
        delayLine[i] = ofRandom(-0.5, 0.5);
    }
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
