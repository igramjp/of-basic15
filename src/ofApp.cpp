#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    ofSetVerticalSync(true);
    ofSetCircleResolution(64);
    ofEnableAlphaBlending();
    
    radius = 0;
    
    // project-folder/bin/data/sound-file
    soundPlayer.load("drum_loop.aif");
    soundPlayer.setLoop(true);
    soundPlayer.play();
}

//--------------------------------------------------------------
void ofApp::update(){
    float *val = ofSoundGetSpectrum(1);
    radius = val[0] * 800.0;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255, 0, 127, 191);
    ofDrawCircle(mouseX, mouseY, radius);
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
    soundPlayer.setPan(x / (float)ofGetWidth() * 2 - 1.0f);
    soundPlayer.setSpeed(0.5f + ((float)(ofGetHeight() - y) / (float)ofGetHeight()) * 1.0f);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    soundPlayer.setPan(x / (float)ofGetWidth() * 2 - 1.0f);
    soundPlayer.setSpeed(0.5f + ((float)(ofGetHeight() - y) / (float)ofGetHeight()) * 1.0f);
    soundPlayer.play();
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    soundPlayer.stop();
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
