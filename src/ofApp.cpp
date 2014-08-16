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

void ofApp::playBoards(ofFbo *fbo){
    if (boardsArray[0]==true) {
        chessboard1(fbo);
    }else if (boardsArray[1]==true) {
        movingFrames(fbo);
    }else if (boardsArray[2]==true) {
        testBoard(fbo);
    }else if (boardsArray[3]==true) {
        oneColor(fbo);
    }
    
}

// ------------------------------------ Boards ------------------------------------

void ofApp::chessboard1(ofFbo *fbo){
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

void ofApp::movingFrames(ofFbo *fbo){
    
    float width = fbo->getWidth();
    float height = fbo->getHeight();
    
    f4_fadeAmnt = 3;
    
    ofSetColor(150, 150, 150, f4_fadeAmnt);
    ofRect(0, 0, width, height);
    
    int speed = 8;
    
    int shiftX   = (ofGetElapsedTimeMillis() / speed ) % (int)width;
    
    ofSetColor(0,255,0);
    ofRect(shiftX, 0, 150*factor, 150*factor);
    
}

void ofApp::testBoard(ofFbo *fbo){
    float _x = ofGetElapsedTimeMillis()/8 % (int)fbo->getWidth();
    
    ofSetColor(50, 50, 50);
    ofRect(0, 0, fbo->getWidth(), fbo->getHeight());
    ofSetColor(ofColor::yellow);
    ofCircle(_x, fbo->getHeight()*.5, 50.0);

}

void ofApp::oneColor(ofFbo *fbo){
    ofSetColor(ofColor::gray);
    ofRect(0, 0, fbo->getWidth(), fbo->getHeight());
    
}

// ------------------------------------ Syphon Servers ------------------------------------

void ofApp::updateMutBoard0(ofxSyphonServer *syphonServer, ofTexture *texture, ofFbo *fbo){
    if (serverArray[0]) {
        playBoards(fbo);
    }else{
        ofClear(0, 0, 0);
    }
}

void ofApp::updateMutBoard1(ofxSyphonServer *syphonServer, ofTexture *texture, ofFbo *fbo){
    if (serverArray[1]) {
        playBoards(fbo);
    }else{
        ofClear(0, 0, 0);
    }
}

void ofApp::updateMutBoard2(ofxSyphonServer *syphonServer, ofTexture *texture, ofFbo *fbo){
    if (serverArray[2]) {
        playBoards(fbo);
    }else{
        ofClear(0, 0, 0);
    }
}

void ofApp::updateMutBoard3(ofxSyphonServer *syphonServer, ofTexture *texture, ofFbo *fbo){
    if (serverArray[3]) {
        playBoards(fbo);
    }else{
        ofClear(0, 0, 0);
    }
}

void ofApp::updateMutBoard4(ofxSyphonServer *syphonServer, ofTexture *texture, ofFbo *fbo){
    if (serverArray[4]) {
        playBoards(fbo);
    }else{
        ofClear(0, 0, 0);
    }
}

void ofApp::updateMutBoard5(ofxSyphonServer *syphonServer, ofTexture *texture, ofFbo *fbo){
    if (serverArray[5]) {
        playBoards(fbo);
    }else{
        ofClear(0, 0, 0);
    }
    
}

void ofApp::updateMutBoard6(ofxSyphonServer *syphonServer, ofTexture *texture, ofFbo *fbo){
    if (serverArray[6]) {
        playBoards(fbo);
    }else{
        ofClear(0, 0, 0);
    }
}

void ofApp::updateMutBoard7(ofxSyphonServer *syphonServer, ofTexture *texture, ofFbo *fbo){
    if (serverArray[7]) {
        playBoards(fbo);
    }else{
        ofClear(0, 0, 0);
    }
}

void ofApp::updateMutBoard8(ofxSyphonServer *syphonServer, ofTexture *texture, ofFbo *fbo){
    if (serverArray[8]) {
        playBoards(fbo);
    }else{
        ofClear(0, 0, 0);
    }
}

void ofApp::updateMutBoard9(ofxSyphonServer *syphonServer, ofTexture *texture, ofFbo *fbo){
    if (serverArray[9]) {
        playBoards(fbo);
    }else{
        ofClear(0, 0, 0);
    }
}

// ------------------------------------ Channel controlling ------------------------------------

void ofApp::setBoardsArrayTrueOnlyAtIndex(int index){
    for (int i = 0; i < numberofBoards; i++) {
        if (i==index) {
            boardsArray[index]=true;
        }else{
            boardsArray[i]=false;
        }
    }
}

void ofApp::setServerArrayTrueOnlyAtIndex(int index){
    for (int i = 0; i < numberofServers; i++) {
        if (i==index) {
            serverArray[index]=true;
        }else{
            serverArray[i]=false;
        }
    }
}

void ofApp::setServerArrayTrue(){
    for (int i = 0; i < numberofServers; i++) {
        serverArray[i]=true;
    }
}

void ofApp::setServerArrayFalse(){
    for (int i = 0; i < numberofServers; i++) {
        serverArray[i]=false;
    }
}

// ------------------------------------ of Lifecycle ------------------------------------

void ofApp::setup(){
    
    serverArray = new bool[numberofServers];
    boardsArray = new bool[numberofBoards];
    
    soundPlayer.loadSound("music/testPattern.mp3");
    fftSmoothed = new float[8192];
	for (int i = 0; i < 8192; i++){
		fftSmoothed[i] = 0;
	}
	nBandsToGet = 64;
    
    board0 = new mutBoard(f0Long, f0Short, GL_RGBA32F_ARB, "F0");
    boards.push_back(board0);
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

        board->mTexture.loadScreenData(0, 0, board->mWidth, board->mHeight);
        board->mSyphonServer.publishTexture(&board->mTexture);
        board->mFbo.end();
        
    }
}

void ofApp::draw(){

    ofClear(30, 30, 30);
    
    ofSetColor(255, 255, 255);    // draw fbo without color modulation
    
    for (int i=0; i<boards.size(); i++) {
        mutBoard *board = boards[i];
        
        if (board->mSyphonServerName == "F0") {
//            board->draw(0,0);
        }
    }
    
}

void ofApp::keyPressed(int key){
    if (key=='0') {
        setServerArrayTrueOnlyAtIndex(0);
    }else if(key=='1'){
        setServerArrayTrueOnlyAtIndex(1);
    }else if(key=='2'){
        setServerArrayTrueOnlyAtIndex(2);
    }else if(key=='3'){
        setServerArrayTrueOnlyAtIndex(3);
    }else if(key=='4'){
        setServerArrayTrueOnlyAtIndex(4);
    }else if(key=='5'){
        setServerArrayTrueOnlyAtIndex(5);
    }else if(key=='6'){
        setServerArrayTrueOnlyAtIndex(6);
    }else if(key=='7'){
        setServerArrayTrueOnlyAtIndex(7);
    }else if(key=='8'){
        setServerArrayTrueOnlyAtIndex(8);
    }else if(key=='9'){
        setServerArrayTrueOnlyAtIndex(9);
    }
    
    if (key=='a') {
        setBoardsArrayTrueOnlyAtIndex(0);
    }else if(key=='b'){
        setBoardsArrayTrueOnlyAtIndex(1);
    }else if(key=='c'){
        setBoardsArrayTrueOnlyAtIndex(2);
    }else if(key=='d'){
        setBoardsArrayTrueOnlyAtIndex(3);
    }/*else if(key=='e'){
        setServerArrayTrueOnlyAtIndex(4);
    }else if(key=='f'){
        setServerArrayTrueOnlyAtIndex(5);
    }else if(key=='g'){
        setServerArrayTrueOnlyAtIndex(6);
    }else if(key=='h'){
        setServerArrayTrueOnlyAtIndex(7);
    }else if(key=='i'){
        setServerArrayTrueOnlyAtIndex(8);
    }else if(key=='j'){
        setServerArrayTrueOnlyAtIndex(9);
    }*/
    
    if(key=='q'){
        playAll = !playAll;
        if (playAll) {
            setServerArrayTrue();
        }else{
            setServerArrayFalse();
        }
    }
    
    if (key == 's') {
        if (!soundIsPlaying) {
            soundPlayer.play();
        }else{
            soundPlayer.stop();
        }
        soundIsPlaying = !soundIsPlaying;
    }
    
}





