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
    movingFrameBoard();
    void play(ofFbo *fbo);
    
private:
    float shiftX, shiftY, f4_fadeAmnt;
    float speed = 0.2;
    int directionX = 1;
    ofFbo *fbo;
    
};

#endif /* defined(__Mutation__movingFrameBoard__) */
