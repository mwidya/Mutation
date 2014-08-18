//
//  movingFrameBoard.h
//  Mutation
//
//  Created by Martin Widyanata on 18.08.14.
//
//

#ifndef __Mutation__movingFrameBoard__
#define __Mutation__movingFrameBoard__

#include <iostream>
#include "ofMain.h"

class movingFrameBoard{
    
public:
    movingFrameBoard(ofFbo *fbo);
    void play();
    
private:
    float mShiftX, mShiftY, mFadeAmnt;
    float mSpeed = 0.2;
    int mDirectionX = 1;
    ofFbo *mFbo;
    
};

#endif /* defined(__Mutation__movingFrameBoard__) */
