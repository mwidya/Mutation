#pragma once

#include "ofMain.h"
//#include "ofxSyphon.h"
#include "mutBoard.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    
    void updateMutBoards(ofxSyphonServer *syphonServer, ofTexture *texture, ofFbo *fbo);
    void updateMutBoard0(ofxSyphonServer *syphonServer, ofTexture *texture, ofFbo *fbo);
    void updateMutBoard1(ofxSyphonServer *syphonServer, ofTexture *texture, ofFbo *fbo);
    void updateMutBoard2(ofxSyphonServer *syphonServer, ofTexture *texture, ofFbo *fbo);
    void updateMutBoard3(ofxSyphonServer *syphonServer, ofTexture *texture, ofFbo *fbo);
    void updateMutBoard4(ofxSyphonServer *syphonServer, ofTexture *texture, ofFbo *fbo);
    void updateMutBoard5(ofxSyphonServer *syphonServer, ofTexture *texture, ofFbo *fbo);
    void updateMutBoard6(ofxSyphonServer *syphonServer, ofTexture *texture, ofFbo *fbo);
    void updateMutBoard7(ofxSyphonServer *syphonServer, ofTexture *texture, ofFbo *fbo);
    void updateMutBoard8(ofxSyphonServer *syphonServer, ofTexture *texture, ofFbo *fbo);
    void updateMutBoard9(ofxSyphonServer *syphonServer, ofTexture *texture, ofFbo *fbo);
//    ofTrueTypeFont mFont;
    
    vector<mutBoard*> boards;
	
    // ------------------ all boards ----------------
    
    bool playAll;
	float f4_fadeAmnt;
    
    // ------------------ f0 ------------------
    
    float rectSize = 5;
    float rectSizeMin = 5;
    float whiteMax = 255;
    int gray;
    
    float stroke = 20;
    float lengthFactor = 130;
    ofSoundPlayer soundPlayer;
    bool soundIsPlaying;
    float *fftSmoothed;
    int nBandsToGet;
    
};
