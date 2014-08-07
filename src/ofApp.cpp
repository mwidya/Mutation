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

void ofApp::updateMutBoard0(int *width, int *height, ofxSyphonServer *syphonServer, ofTexture *texture, ofFbo *fbo){
    
    float _x = ofGetElapsedTimeMillis()/8 % *width;
    
    ofSetColor(50, 50, 50);
    ofRect(0, 0, *width,  *height);
    ofSetColor(ofColor::blue);
    ofCircle(_x, *height*.5, 50.0);
    
}

void ofApp::updateMutBoard1(int *width, int *height, ofxSyphonServer *syphonServer, ofTexture *texture, ofFbo *fbo){
    
    float _x = ofGetElapsedTimeMillis()/8 % *width;
    
    ofSetColor(50, 50, 50);
    ofRect(0, 0, *width, *height);
    ofSetColor(ofColor::yellow);
    ofCircle(_x, *height*.5, 50.0);

}

void ofApp::updateMutBoard2(int *width, int *height, ofxSyphonServer *syphonServer, ofTexture *texture, ofFbo *fbo){

    float _x = ofGetElapsedTimeMillis()/8 % *width;
    
    ofSetColor(50, 50, 50);
    ofRect(0, 0, *width,  *height);
    ofSetColor(ofColor::blue);
    ofCircle(_x, *height*.5, 50.0);
    
}

void ofApp::updateMutBoard3(int *width, int *height, ofxSyphonServer *syphonServer, ofTexture *texture, ofFbo *fbo){
    
    float _x = ofGetElapsedTimeMillis()/8 % *width;
    
    ofSetColor(50, 50, 50);
    ofRect(0, 0, *width,  *height);
    ofSetColor(ofColor::blue);
    ofCircle(_x, *height*.5, 50.0);
    
}

void ofApp::updateMutBoard4(int *width, int *height, ofxSyphonServer *syphonServer, ofTexture *texture, ofFbo *fbo){
    
    ofSetColor(50, 50, 50);
	ofRect(0,0,*width,*height);
	
    ofSetColor(0,255,0);
	int shiftX   = (ofGetElapsedTimeMillis() / 8 ) % *width;
	ofRect(shiftX, 0, 150*factor, 150*factor);

    
}

void ofApp::updateMutBoard5(int *width, int *height, ofxSyphonServer *syphonServer, ofTexture *texture, ofFbo *fbo){
    
    ofSetColor(ofColor::gray);
    ofRect(0, 0, *width, *height);
    
}

void ofApp::updateMutBoard6(int *width, int *height, ofxSyphonServer *syphonServer, ofTexture *texture, ofFbo *fbo){
    
    ofSetColor(ofColor::seaGreen);
    ofRect(0, 0, *width, *height);
    
}

void ofApp::updateMutBoard7(int *width, int *height, ofxSyphonServer *syphonServer, ofTexture *texture, ofFbo *fbo){
    
    ofSetColor(ofColor::tomato);
    ofRect(0, 0, *width, *height);
    
}

void ofApp::updateMutBoard8(int *width, int *height, ofxSyphonServer *syphonServer, ofTexture *texture, ofFbo *fbo){
    
    ofSetColor(ofColor::cyan);
    ofRect(0, 0, *width, *height);
    
}

void ofApp::updateMutBoard9(int *width, int *height, ofxSyphonServer *syphonServer, ofTexture *texture, ofFbo *fbo){
    
    ofSetColor(ofColor::magenta);
    ofRect(0, 0, *width, *height);

}

//--------------------------------------------------------------
void ofApp::setup(){
    
    mFont.loadFont("vag.ttf", 50);
    
    mutBoard *board0 = new mutBoard(f0Long, f0Short, GL_RGBA32F_ARB, "F0");
    boards.push_back(board0);
    mutBoard *board1 = new mutBoard(f1Long, f1Short, GL_RGBA32F_ARB, "F1");
    boards.push_back(board1);
    mutBoard *board2 = new mutBoard(f2Long, f2Short, GL_RGBA32F_ARB, "F2");
    boards.push_back(board2);
    mutBoard *board3 = new mutBoard(f3Long, f3Short, GL_RGBA32F_ARB, "F3");
    boards.push_back(board3);
    mutBoard *board4 = new mutBoard(f4Long, f4Short, GL_RGBA32F_ARB, "F4");
    boards.push_back(board4);
    mutBoard *board5 = new mutBoard(f5Long, f5Short, GL_RGBA32F_ARB, "F5");
    boards.push_back(board5);
    mutBoard *board6 = new mutBoard(f6Long, f6Short, GL_RGBA32F_ARB, "F6");
    boards.push_back(board6);
    mutBoard *board7 = new mutBoard(f7Long, f7Short, GL_RGBA32F_ARB, "F7");
    boards.push_back(board7);
    mutBoard *board8 = new mutBoard(f8Long, f8Short, GL_RGBA32F_ARB, "F8");
    boards.push_back(board8);
    mutBoard *board9 = new mutBoard(f9Long, f9Short, GL_RGBA32F_ARB, "F9");
    boards.push_back(board9);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    for (int i=0; i<boards.size(); i++) {
        mutBoard *board = boards[i];
        
        board->mFbo.begin();
        
        ofClear(255,255,255, 0);
        
        if (board->mSyphonServerName == "F0") {
            updateMutBoard0(&board->mWidth, &board->mHeight, &board->mSyphonServer, &board->mTexture, &board->mFbo);
        }
        else if (board->mSyphonServerName == "F1") {
            updateMutBoard1(&board->mWidth, &board->mHeight, &board->mSyphonServer, &board->mTexture, &board->mFbo);
        }
        else if (board->mSyphonServerName == "F2") {
            updateMutBoard2(&board->mWidth, &board->mHeight, &board->mSyphonServer, &board->mTexture, &board->mFbo);
        }
        else if (board->mSyphonServerName == "F3") {
            updateMutBoard3(&board->mWidth, &board->mHeight, &board->mSyphonServer, &board->mTexture, &board->mFbo);
        }
        else if (board->mSyphonServerName == "F4") {
            updateMutBoard4(&board->mWidth, &board->mHeight, &board->mSyphonServer, &board->mTexture, &board->mFbo);
        }
        else if (board->mSyphonServerName == "F5") {
            updateMutBoard5(&board->mWidth, &board->mHeight, &board->mSyphonServer, &board->mTexture, &board->mFbo);
        }
        else if (board->mSyphonServerName == "F6") {
            updateMutBoard6(&board->mWidth, &board->mHeight, &board->mSyphonServer, &board->mTexture, &board->mFbo);
        }
        else if (board->mSyphonServerName == "F7") {
            updateMutBoard7(&board->mWidth, &board->mHeight, &board->mSyphonServer, &board->mTexture, &board->mFbo);
        }
        else if (board->mSyphonServerName == "F8") {
            updateMutBoard8(&board->mWidth, &board->mHeight, &board->mSyphonServer, &board->mTexture, &board->mFbo);
        }
        else if (board->mSyphonServerName == "F9") {
            updateMutBoard9(&board->mWidth, &board->mHeight, &board->mSyphonServer, &board->mTexture, &board->mFbo);
        }
        
        ofSetColor(255,122,220);
        mFont.drawString("Bangin !!!", 100, 100);
        
        board->mTexture.loadScreenData(0, 0, board->mWidth, board->mHeight);
        board->mSyphonServer.publishTexture(&board->mTexture);
        board->mFbo.end();
        
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(255, 255, 255);
    
    for (int i=0; i<boards.size(); i++) {
        mutBoard *board = boards[i];
        
        if (board->mSyphonServerName == "F4") {
            board->draw(0,0);
        }

    }
    
}







