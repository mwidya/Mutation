//
//  movingFrameBoard.cpp
//  Mutation
//
//  Created by Martin Widyanata on 18.08.14.
//
//

#include "movingFrameBoard.h"

movingFrameBoard::movingFrameBoard(ofFbo *fbo){
    
    mFbo = fbo;
    
}

void movingFrameBoard::play(){
    float mFadeAmnt = 1.5;
    
    ofSetColor(150, 150, 150, mFadeAmnt);
    ofRect(0, 0, mFbo->getWidth(), mFbo->getHeight());
    
    int mShiftX   = (ofGetElapsedTimeMillis() / 8 ) % (int)mFbo->getWidth();
    
    ofSetColor(255,255,0);
    ofRect(mShiftX, 0, 150*0.1, 150*0.1);
}