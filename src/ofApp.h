#pragma once

#include "ofMain.h"
//#include "ofxSyphon.h"
#include "channel.h"
#include "movingFrameBoard.h"

class ofApp : public ofBaseApp{

public:
    
    void playBoards(ofFbo *fbo);
    
    // ------------------------------------ Boards ------------------------------------
    
    void chessboard1(ofFbo *fbo);
    void movingFrames(ofFbo *fbo);
    void testBoard(ofFbo *fbo);
    void oneColor(ofFbo *fbo);
    
    movingFrameBoard mMovingFrameBoard;
    
    // ------------------------------------ Channels ------------------------------------
    
    void updateChannel(channel *channel, int index);
    
    // ------------------------------------ Channel controlling ------------------------------------
    
    void setBoardsArrayTrueOnlyAtIndex(int index);
    void setChannelsArrayTrueOnlyAtIndex(int index);
    void setChannelsArrayTrue();
    void setChannelsArrayFalse();
    
    // ------------------------------------ Setups & Configurations ------------------------------------
    
    void setupArrays();
    void setupChannels();
    
    // ------------------------------------ of Lifecycle ------------------------------------
    
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    
    // ------------------------------------ Global Variables ------------------------------------
    
    vector<channel*> channels;
    channel *channel0;
    channel *channel1;
    channel *channel2;
    channel *channel3;
    channel *channel4;
    channel *channel5;
    channel *channel6;
    channel *channel7;
    channel *channel8;
    channel *channel9;
    
    int numberofChannels = 10;
    bool *channelsArray;
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
