//
//  mutBoard.h
//  Mutation
//
//  Created by Martin Widyanata on 01.08.14.
//
//

#ifndef __Mutation__mutBoard__
#define __Mutation__mutBoard__

#include <iostream>
#include "ofMain.h"
#include "ofxSyphon.h"

class mutBoard
{
    ofTexture mTexture;
    ofxSyphonServer mSyphonServer;
    ofFbo mFbo;
    
    int mWidth, mHeight;
    int mGlFormat;
    string mSyphonServerName;
    
public:
    mutBoard(int width, int height, int glFormat, string syphonServerName);
    ~mutBoard();
    
    void update();
    void draw(float x, float y);
};

#endif /* defined(__Mutation__mutBoard__) */
