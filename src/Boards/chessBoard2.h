//
//  chessBoard2.h
//  Mutation
//
//  Created by Martin Widyanata on 23.08.14.
//
//

#ifndef __Mutation__chessBoard2__
#define __Mutation__chessBoard2__

#include <iostream>
#include "ofMain.h"
#include "chessField.h"

class chessBoard2{
    
public:
    chessBoard2(ofFbo *fbo);
    void update();
    
private:
    ofFbo *mFbo;
    vector<chessField*> chessFields;
    float fieldSize;
};

#endif /* defined(__Mutation__chessBoard2__) */
