#pragma once

#include "ofMain.h"
//#include "ofxSyphon.h"
#include "mutBoard.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();
    
    vector<mutBoard> boards;
    
//    ofFbo fbo6;
//    ofxSyphonServer syphonServer6;
//    ofTexture texture6;
//    
//    ofFbo fbo7;
//    ofxSyphonServer syphonServer7;
//    ofTexture texture7;
		
};
