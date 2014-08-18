#pragma once

#include "ofMain.h"
//#include "ofxSyphon.h"
#include "mutBoard.h"

class ofApp : public ofBaseApp{

public:
    
    void playBoards(ofFbo *fbo);
    
    // ------------------------------------ Boards ------------------------------------
    
    void chessboard1(ofFbo *fbo);
    void movingFrames(ofFbo *fbo);
    void testBoard(ofFbo *fbo);
    void oneColor(ofFbo *fbo);
    
    // ------------------------------------ Syphon Servers ------------------------------------
    
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
    
    // ------------------------------------ Channel controlling ------------------------------------
    
    void setBoardsArrayTrueOnlyAtIndex(int index);
    void setServerArrayTrueOnlyAtIndex(int index);
    void setServerArrayTrue();
    void setServerArrayFalse();
    
    // ------------------------------------ Setups & Configurations ------------------------------------
    
    void setupArrays();
    void setupServers();
    
    // ------------------------------------ of Lifecycle ------------------------------------
    
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    
    // ------------------------------------ Global Variables ------------------------------------
    
    vector<mutBoard*> boards;
    mutBoard *board0;
    mutBoard *board1;
    mutBoard *board2;
    mutBoard *board3;
    mutBoard *board4;
    mutBoard *board5;
    mutBoard *board6;
    mutBoard *board7;
    mutBoard *board8;
    mutBoard *board9;
    
    int numberofServers = 10;
    bool *serverArray;
    int numberofBoards = 4;
    bool *boardsArray;
    
    bool playAll;
	
    ofTrueTypeFont mFont;
    
    /*// ------------------ moving frames ------------------
    // TODO vars has to be instantiated in an object
	float f4_fadeAmnt;
    float shiftX, shiftY = 0;
    int directionX = 1;
    float speed = 0.2;*/
    
    // ------------------ chessboard1 ------------------
    
    float rectSize = 5;
    float rectSizeMin = 5;
    float whiteMax = 255;
    int gray = 255;
    
    float stroke = 20;
    float lengthFactor = 130;
    ofSoundPlayer soundPlayer;
    bool soundIsPlaying;
    float *fftSmoothed;
    int nBandsToGet;
    
};
