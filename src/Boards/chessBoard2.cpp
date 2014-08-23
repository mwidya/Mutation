//
//  chessBoard2.cpp
//  Mutation
//
//  Created by Martin Widyanata on 23.08.14.
//
//

#include "chessBoard2.h"

chessBoard2::chessBoard2(ofFbo *fbo){
    
    mFbo = fbo;
    
}

void chessBoard2::update(){
    ofSetColor(20,60,150);
    ofRect(0,0,mFbo->getWidth(),mFbo->getHeight());
}