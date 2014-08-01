//
//  mutBoard.cpp
//  Mutation
//
//  Created by Martin Widyanata on 01.08.14.
//
//

#include "mutBoard.h"

mutBoard::mutBoard(int width, int height, int glFormat, string syphonServerName){
    
    mWidth = width;
    mHeight = height;
    mGlFormat = glFormat;
    mSyphonServerName = syphonServerName;
    
    // TODO Test if new instance is created when setName is called
    mSyphonServer.setName(mSyphonServerName);
    mTexture.allocate(mWidth, mHeight, mGlFormat);
    mFbo.allocate(mWidth, mHeight, mGlFormat);
    
}

mutBoard::~mutBoard(){
    ofLog(OF_LOG_NOTICE, "Desructor ~mutBoard was called");
}

float _x;
float _dx = 1;

void mutBoard::update(){
    
    _x += _dx;
    
    if ((_x > mWidth) | (_x < 0)) {
        _dx *= -1;
    }

    mFbo.begin();
    
    ofClear(255);
    ofSetColor(ofColor::chocolate);
    ofRect(0, 0, mWidth, mHeight);
    ofSetColor(ofColor::burlyWood);
    ofCircle(_x, mHeight*.5, 50.0);
    mTexture.loadScreenData(0, 0, mWidth, mHeight);
    mSyphonServer.publishTexture(&mTexture);
    
    mFbo.end();
}

void mutBoard::draw(float x, float y){
    mFbo.draw(x, y);
}