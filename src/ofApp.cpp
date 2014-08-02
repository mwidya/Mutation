#include "ofApp.h"

float factor = 0.1f;
// 1.0 = 1 meter
float levelDistance = 3000*factor;
float f0f1Distance = 2150*factor;
float f3f4Distance = 8600*factor;
float f4f5Distance = 4300*factor;
float f5f6Distance = 11100*factor;
float f8f9Distance = 6000*factor;
float f0Long = 4300*factor;
float f0Short = 1700*factor;
float f1Long = 3000*factor;
float f1Short = 1700*factor;
float f2Long = 3950*factor;
float f2Short = 3000*factor;
float f3Long = 3000*factor;
float f3Short = 1700*factor;
float f4Long = 3000*factor;
float f4Short = 1700*factor;
float f5Long = 3000*factor;
float f5Short = 1700*factor;
float f6Long = 4300*factor;
float f6Short = 1700*factor;
float f7Long = 4300*factor;
float f7Short = 3950*factor;
float f8Long = 4300*factor;
float f8Short = 1700*factor;
float f9Long = 4300*factor;
float f9Short = 1700*factor;

float _x;
float _dx = 1;

void updateMutBoard2(int *width, int *height, ofxSyphonServer *syphonServer, ofTexture *texture, ofFbo *fbo){
    _x += _dx;
    
    if ((_x > *width) | (_x < 0)) {
        _dx *= -1;
    }
    
    fbo->begin();
    ofClear(255);
    ofSetColor(ofColor::red);
    ofRect(0, 0, *width, *height);
    ofSetColor(ofColor::yellow);
    ofCircle(_x, *height*.5, 50.0);
    texture->loadScreenData(0, 0, *width, *height);
    syphonServer->publishTexture(texture);
    fbo->end();
    
}

void updateMutBoard7(int *width, int *height, ofxSyphonServer *syphonServer, ofTexture *texture, ofFbo *fbo){
    _x += _dx;
    
    if ((_x > *width) | (_x < 0)) {
        _dx *= -1;
    }
    
    fbo->begin();
    
    ofClear(255);
    ofSetColor(ofColor::chocolate);
    ofRect(0, 0, *width,  *height);
    ofSetColor(ofColor::burlyWood);
    ofCircle(_x, *height*.5, 50.0);
    texture->loadScreenData(0, 0, *width, *height);
    syphonServer->publishTexture(texture);
    
    fbo->end();

}

//--------------------------------------------------------------
void ofApp::setup(){
    
    mutBoard *board2 = new mutBoard(f2Long, f2Short, GL_RGBA, "F2");
    mutBoard *board7 = new mutBoard(f7Long, f7Short, GL_RGBA, "F7");
    
    boards.push_back(board2);
    boards.push_back(board7);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    for (int i=0; i<boards.size(); i++) {
        mutBoard *board = boards[i];
        if (board->mSyphonServerName == "F2") {
            updateMutBoard2(&board->mWidth, &board->mHeight, &board->mSyphonServer, &board->mTexture, &board->mFbo);
        }
        if (board->mSyphonServerName == "F7") {
            updateMutBoard7(&board->mWidth, &board->mHeight, &board->mSyphonServer, &board->mTexture, &board->mFbo);
        }
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i=0; i<boards.size(); i++) {
        mutBoard *board = boards[i];
        if (board->mSyphonServerName == "F2") {
            board->draw(0,0);
        }
        else if (board->mSyphonServerName == "F7") {
            board->draw(512,0);
        }
    }
}







