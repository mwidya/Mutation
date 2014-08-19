#pragma once

#include "ofMain.h"
#include "channel.h"
#include "movingFrameBoard.h"
#include "chessBoard1.h"
#include "testBoard.h"
#include "oneColorBoard.h"

class ofApp : public ofBaseApp{

public:
    
    // ------------------------------------ Channels ------------------------------------
    
    void updateSound();
    void updateChannel(channel *channel, int index);
    
    // ------------------------------------ Channel controlling ------------------------------------
    
    void setBoardsArrayTrueOnlyAtIndex(int index);
    void setChannelsArrayTrueOnlyAtIndex(int index);
    void setChannelsArrayTrue();
    void setChannelsArrayFalse();
    
    // ------------------------------------ Setups & Configurations ------------------------------------
    
    void setupArrays();
    void setupSound();
    
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
    
    vector<movingFrameBoard*> movingFrameBoards;
    vector<chessBoard1*> chessBoard1s;
    vector<testBoard*> testBoards;
    vector<oneColorBoard*> oneColorBoards;
    
    // ------------------------------------ Sound Player ------------------------------------
    
    ofSoundPlayer soundPlayer;
    bool soundIsPlaying;
    float *fftSmoothed;
    int nBandsToGet;
    
};
