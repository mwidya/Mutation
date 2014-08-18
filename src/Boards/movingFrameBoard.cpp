//
//  movingFrameBoard.cpp
//  Mutation
//
//  Created by Martin Widyanata on 18.08.14.
//
//

#include "movingFrameBoard.h"

movingFrameBoard::movingFrameBoard(){
    
}

void movingFrameBoard::play(ofFbo *fbo){
    float f4_fadeAmnt = 1.5;
    
    ofSetColor(150, 150, 150, f4_fadeAmnt);
    ofRect(0, 0, fbo->getWidth(), fbo->getHeight());
    
    int shiftX   = (ofGetElapsedTimeMillis() / 8 ) % (int)fbo->getWidth();
    
    ofSetColor(255,255,0);
    ofRect(shiftX, 0, 150*0.1, 150*0.1);
}