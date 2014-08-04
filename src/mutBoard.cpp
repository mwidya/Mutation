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

void mutBoard::draw(float x, float y){
    mFbo.draw(x, y);
}