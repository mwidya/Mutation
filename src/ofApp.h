#pragma once

#include "ofMain.h"
//#include "ofxSyphon.h"
#include "mutBoard.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();
    
    void updateMutBoard0(int *width, int *height, ofxSyphonServer *syphonServer, ofTexture *texture, ofFbo *fbo);
    void updateMutBoard1(int *width, int *height, ofxSyphonServer *syphonServer, ofTexture *texture, ofFbo *fbo);
    void updateMutBoard2(int *width, int *height, ofxSyphonServer *syphonServer, ofTexture *texture, ofFbo *fbo);
    void updateMutBoard3(int *width, int *height, ofxSyphonServer *syphonServer, ofTexture *texture, ofFbo *fbo);
    void updateMutBoard4(int *width, int *height, ofxSyphonServer *syphonServer, ofTexture *texture, ofFbo *fbo);
    void updateMutBoard5(int *width, int *height, ofxSyphonServer *syphonServer, ofTexture *texture, ofFbo *fbo);
    void updateMutBoard6(int *width, int *height, ofxSyphonServer *syphonServer, ofTexture *texture, ofFbo *fbo);
    void updateMutBoard7(int *width, int *height, ofxSyphonServer *syphonServer, ofTexture *texture, ofFbo *fbo);
    void updateMutBoard8(int *width, int *height, ofxSyphonServer *syphonServer, ofTexture *texture, ofFbo *fbo);
    void updateMutBoard9(int *width, int *height, ofxSyphonServer *syphonServer, ofTexture *texture, ofFbo *fbo);
    void updateMutBoards(ofxSyphonServer *syphonServer, ofTexture *texture, ofFbo *fbo);
//    ofTrueTypeFont mFont;
    
    vector<mutBoard*> boards;
	
	float f4_fadeAmnt;
    
};
