//
//  oneColorBoard.h
//  Mutation
//
//  Created by Martin Widyanata on 19.08.14.
//
//

#ifndef __Mutation__oneColorBoard__
#define __Mutation__oneColorBoard__

#include <iostream>
#include "ofMain.h"

class oneColorBoard{
public:
    oneColorBoard(ofFbo *fbo);
    void update();
    
private:
    ofFbo *mFbo;
    ofTrueTypeFont mFont;
};

#endif /* defined(__Mutation__oneColorBoard__) */
