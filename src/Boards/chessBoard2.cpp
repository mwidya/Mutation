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
    fieldSize = mFbo->getWidth()/6.0;
    
    for (int i = 0; i < mFbo->getWidth() / fieldSize; i++) {
        for (int j = 0; j < mFbo->getHeight() / fieldSize; j++) {
            int randomColor = ofRandom(255);
            chessField *cf = new chessField(i*fieldSize, j*fieldSize, fieldSize);
            cf->setColor(randomColor,randomColor,randomColor);
            chessFields.push_back(cf);
        }
    }
    
    
}

void chessBoard2::update(){
    for (int i=0; i<chessFields.size(); i++) {
        chessFields[i]->draw();
    }
}