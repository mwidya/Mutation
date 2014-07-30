#include "ofApp.h"

float f4Long = 300;
float f4Short = 170;

//--------------------------------------------------------------
void ofApp::setup(){
    
    syphonServer.setName("Texture Output");
    
    texture.allocate(f4Long, f4Short, GL_RGBA);
    
}

float x;
float dx = 1;

//--------------------------------------------------------------
void ofApp::update(){
    
    x += dx;
    
    if ((x > f4Long*.5) | (x < -f4Long*.5)) {
        dx *= -1;
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(ofColor::chocolate);
    ofRect(ofGetWidth()*.5 - f4Long*.5, ofGetHeight()*.5 - f4Short*.5, f4Long, f4Short);
    ofSetColor(ofColor::burlyWood);
    ofCircle(ofGetWidth()*.5 + x, ofGetHeight()*.5, 50.0);
    
    texture.loadScreenData(ofGetWidth()*.5 - f4Long*.5, ofGetHeight()*.5 - f4Short*.5, f4Long, f4Short);
    syphonServer.publishTexture(&texture);
}