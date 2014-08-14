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

void ofApp::updateChessboard1(ofFbo *fbo){
    ofSoundUpdate();
    float * val = ofSoundGetSpectrum(nBandsToGet);
    for (int i = 0;i < nBandsToGet; i++){
        fftSmoothed[i] *= 0.96f;
        if (fftSmoothed[i] < val[i]) fftSmoothed[i] = val[i];
        
    }
    
    float band0 = fftSmoothed[1]*fbo->getWidth()/25.0;
    if (band0 > rectSizeMin) {
        rectSize = (int)band0;
    }
    
    for (int i = 0; i < fbo->getWidth() / rectSize; i++) {
        for (int j = 0; j < fbo->getHeight() / rectSize; j++) {
            ofSetColor(ofRandom(0, whiteMax));
            ofRect(rectSize * i, rectSize * j, rectSize, rectSize);
        }
    }
    
    float band12 = fftSmoothed[12] * lengthFactor * 5;
    float band38 = fftSmoothed[38] * lengthFactor;
    
    ofSetColor(255, 0, 0, 100);
    ofRect(0, stroke, band12, stroke);
    
    ofSetColor(0, 0, 255, 100);
    ofRect(fbo->getWidth()-band38, fbo->getHeight() - stroke * 2, band38, stroke);
    
}

void ofApp::updateAllMutBoards(ofxSyphonServer *syphonServer, ofTexture *texture, ofFbo *fbo){
    if (playAll==true) {
    
        float width = fbo->getWidth();
        float height = fbo->getHeight();
        
        f4_fadeAmnt = 3;
        
        ofSetColor(150, 150, 150, f4_fadeAmnt);
        ofRect(0, 0, width, height);
        
        int speed = 8;
        
        int shiftX   = (ofGetElapsedTimeMillis() / speed ) % (int)width;
        
        ofSetColor(0,255,0);
        ofRect(shiftX, 0, 150*factor, 150*factor);
    }else{
//        ofBackground(0, 0, 0);
    }
}

void ofApp::updateMutBoard0(ofxSyphonServer *syphonServer, ofTexture *texture, ofFbo *fbo){
    if (playArray[0]) {
        updateChessboard1(fbo);
    }else{
        ofClear(0, 0, 0);
    }
}

void ofApp::updateMutBoard1(ofxSyphonServer *syphonServer, ofTexture *texture, ofFbo *fbo){
    if (playArray[1]) {
        updateChessboard1(fbo);
    }else{
        ofClear(0, 0, 0);
    }
    
//    float _x = ofGetElapsedTimeMillis()/8 % *width;
//    
//    ofSetColor(50, 50, 50);
//    ofRect(0, 0, *width, *height);
//    ofSetColor(ofColor::yellow);
//    ofCircle(_x, *height*.5, 50.0);

}

void ofApp::updateMutBoard2(ofxSyphonServer *syphonServer, ofTexture *texture, ofFbo *fbo){
    if (playArray[2]) {
        updateChessboard1(fbo);
    }else{
        ofClear(0, 0, 0);
    }
//    float _x = ofGetElapsedTimeMillis()/8 % *width;
//    
//    ofSetColor(50, 50, 50);
//    ofRect(0, 0, *width,  *height);
//    ofSetColor(ofColor::blue);
//    ofCircle(_x, *height*.5, 50.0);
    
}

void ofApp::updateMutBoard3(ofxSyphonServer *syphonServer, ofTexture *texture, ofFbo *fbo){
    if (playArray[3]) {
        updateChessboard1(fbo);
    }else{
        ofClear(0, 0, 0);
    }
    
//    float _x = ofGetElapsedTimeMillis()/8 % *width;
//    
//    ofSetColor(50, 50, 50);
//    ofRect(0, 0, *width,  *height);
//    ofSetColor(ofColor::blue);
//    ofCircle(_x, *height*.5, 50.0);
    
}

void ofApp::updateMutBoard4(ofxSyphonServer *syphonServer, ofTexture *texture, ofFbo *fbo){
    if (playArray[4]) {
        updateChessboard1(fbo);
    }else{
        ofClear(0, 0, 0);
    }
    
    //    ofSetColor(ofColor::gray);
    //    ofRect(0, 0, *width, *height);
    
}

void ofApp::updateMutBoard5(ofxSyphonServer *syphonServer, ofTexture *texture, ofFbo *fbo){
    if (playArray[5]) {
        updateChessboard1(fbo);
    }else{
        ofClear(0, 0, 0);
    }
    
//    ofSetColor(ofColor::gray);
//    ofRect(0, 0, *width, *height);
    
}

void ofApp::updateMutBoard6(ofxSyphonServer *syphonServer, ofTexture *texture, ofFbo *fbo){
    if (playArray[6]) {
        updateChessboard1(fbo);
    }else{
        ofClear(0, 0, 0);
    }
    
//    ofSetColor(ofColor::seaGreen);
//    ofRect(0, 0, *width, *height);
    
}

void ofApp::updateMutBoard7(ofxSyphonServer *syphonServer, ofTexture *texture, ofFbo *fbo){
    if (playArray[7]) {
        updateChessboard1(fbo);
    }else{
        ofClear(0, 0, 0);
    }
    
//    ofSetColor(ofColor::tomato);
//    ofRect(0, 0, *width, *height);
    
}

void ofApp::updateMutBoard8(ofxSyphonServer *syphonServer, ofTexture *texture, ofFbo *fbo){
    if (playArray[8]) {
        updateChessboard1(fbo);
    }else{
        ofClear(0, 0, 0);
    }
    
//    ofSetColor(ofColor::cyan);
//    ofRect(0, 0, *width, *height);
    
}

void ofApp::updateMutBoard9(ofxSyphonServer *syphonServer, ofTexture *texture, ofFbo *fbo){
    if (playArray[9]) {
        updateChessboard1(fbo);
    }else{
        ofClear(0, 0, 0);
    }
    
//    ofSetColor(ofColor::magenta);
//    ofRect(0, 0, *width, *height);

}

//--------------------------------------------------------------
void ofApp::setup(){
    
    playArray = new bool[numberofBoards];
    
//    mFont.loadFont("vag.ttf", 50);
    
    // ------------------ f0 ------------------
    
    board0 = new mutBoard(f0Long, f0Short, GL_RGBA32F_ARB, "F0");
    boards.push_back(board0);
    
    rectSize = rectSizeMin;
    gray = whiteMax;
    
    soundPlayer.loadSound("music/testPattern.mp3");
    fftSmoothed = new float[8192];
	for (int i = 0; i < 8192; i++){
		fftSmoothed[i] = 0;
	}
	
	nBandsToGet = 64;
    
    // ------------------ f1 ------------------
    
    board1 = new mutBoard(f1Long, f1Short, GL_RGBA32F_ARB, "F1");
    boards.push_back(board1);
    board2 = new mutBoard(f2Long, f2Short, GL_RGBA32F_ARB, "F2");
    boards.push_back(board2);
    board3 = new mutBoard(f3Long, f3Short, GL_RGBA32F_ARB, "F3");
    boards.push_back(board3);
    board4 = new mutBoard(f4Long, f4Short, GL_RGBA32F_ARB, "F4");
    boards.push_back(board4);
    board5 = new mutBoard(f5Long, f5Short, GL_RGBA32F_ARB, "F5");
    boards.push_back(board5);
    board6 = new mutBoard(f6Long, f6Short, GL_RGBA32F_ARB, "F6");
    boards.push_back(board6);
    board7 = new mutBoard(f7Long, f7Short, GL_RGBA32F_ARB, "F7");
    boards.push_back(board7);
    board8 = new mutBoard(f8Long, f8Short, GL_RGBA32F_ARB, "F8");
    boards.push_back(board8);
    board9 = new mutBoard(f9Long, f9Short, GL_RGBA32F_ARB, "F9");
    boards.push_back(board9);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    for (int i=0; i<boards.size(); i++) {
        mutBoard *board = boards[i];
        
        board->mFbo.begin();
        
        if (board->mSyphonServerName == "F0") {
            updateMutBoard0(&board->mSyphonServer, &board->mTexture, &board->mFbo);
        }
        else if (board->mSyphonServerName == "F1") {
            updateMutBoard1(&board->mSyphonServer, &board->mTexture, &board->mFbo);
        }
        else if (board->mSyphonServerName == "F2") {
            updateMutBoard2(&board->mSyphonServer, &board->mTexture, &board->mFbo);
        }
        else if (board->mSyphonServerName == "F3") {
            updateMutBoard3(&board->mSyphonServer, &board->mTexture, &board->mFbo);
        }
        else if (board->mSyphonServerName == "F4") {
            updateMutBoard4(&board->mSyphonServer, &board->mTexture, &board->mFbo);
        }
        else if (board->mSyphonServerName == "F5") {
            updateMutBoard5(&board->mSyphonServer, &board->mTexture, &board->mFbo);
        }
        else if (board->mSyphonServerName == "F6") {
            updateMutBoard6(&board->mSyphonServer, &board->mTexture, &board->mFbo);
        }
        else if (board->mSyphonServerName == "F7") {
            updateMutBoard7(&board->mSyphonServer, &board->mTexture, &board->mFbo);
        }
        else if (board->mSyphonServerName == "F8") {
            updateMutBoard8(&board->mSyphonServer, &board->mTexture, &board->mFbo);
        }
        else if (board->mSyphonServerName == "F9") {
            updateMutBoard9(&board->mSyphonServer, &board->mTexture, &board->mFbo);
        }
        
//        updateAllMutBoards(&board->mSyphonServer, &board->mTexture, &board->mFbo);

        board->mTexture.loadScreenData(0, 0, board->mWidth, board->mHeight);
        board->mSyphonServer.publishTexture(&board->mTexture);
        board->mFbo.end();
        
    }
}

void ofApp::draw(){
    
    
    ofClear(30, 30, 30);
    
    // draw fbo without color modulation
    ofSetColor(255, 255, 255);
    
    for (int i=0; i<boards.size(); i++) {
        mutBoard *board = boards[i];
        
        if (board->mSyphonServerName == "F0") {
            board->draw(0,0);
        }

    }
    
}

void ofApp::setArrayTrueOnlyAtIndex(int index){
    for (int i = 0; i < numberofBoards; i++) {
        if (i==index) {
            playArray[index]=true;
        }else{
            playArray[i]=false;
        }
    }
}

void ofApp::setArrayTrue(){
    for (int i = 0; i < numberofBoards; i++) {
        playArray[i]=true;
    }
}

void ofApp::setArrayFalse(){
    for (int i = 0; i < numberofBoards; i++) {
        playArray[i]=false;
    }
}

void ofApp::keyPressed(int key){
    if (key=='0') {
        setArrayTrueOnlyAtIndex(0);
    }else if(key=='1'){
        setArrayTrueOnlyAtIndex(1);
    }else if(key=='2'){
        setArrayTrueOnlyAtIndex(2);
    }else if(key=='3'){
        setArrayTrueOnlyAtIndex(3);
    }else if(key=='4'){
        setArrayTrueOnlyAtIndex(4);
    }else if(key=='5'){
        setArrayTrueOnlyAtIndex(5);
    }else if(key=='6'){
        setArrayTrueOnlyAtIndex(6);
    }else if(key=='7'){
        setArrayTrueOnlyAtIndex(7);
    }else if(key=='8'){
        setArrayTrueOnlyAtIndex(8);
    }else if(key=='9'){
        setArrayTrueOnlyAtIndex(9);
    }
    
    if(key=='a'){
        playAll = !playAll;
        if (playAll) {
            setArrayTrue();
        }else{
            setArrayFalse();
        }
    }
    
    if (key == ' ') {
        if (!soundIsPlaying) {
            soundPlayer.play();
        }else{
            soundPlayer.stop();
        }
        soundIsPlaying = !soundIsPlaying;
    }
    
}





