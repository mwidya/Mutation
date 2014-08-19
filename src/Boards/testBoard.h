//
//  testBoard.h
//  Mutation
//
//  Created by Martin Widyanata on 19.08.14.
//
//

#ifndef __Mutation__testBoard__
#define __Mutation__testBoard__

#include <iostream>
#include "ofMain.h"

class testBoard{
public:
    testBoard(ofFbo *fbo);
    void update();
    
private:
    ofFbo *mFbo;
    
};

#endif /* defined(__Mutation__testBoard__) */
