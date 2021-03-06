#include "ofApp.h"
#include "constants.h"

// ------------------------------------ Setups & Configurations ------------------------------------

void ofApp::setupArrays(){
    
    channelsArray = new bool[numberofChannels];
    setChannelsArrayTrue();
    boardsArray = new bool[numberofBoards];
    setBoardsArrayTrueOnlyAtIndex(1);
    
}

void ofApp::setupSound(){
    
//    soundPlayer.loadSound("music/02 Blood Stevia Sex Magik.mp3");
    soundPlayer.loadSound("music/Cmin_geschisse_v3.wav");
//    soundPlayer.loadSound("music/St_able_v1.wav");
    
    fftSmoothed = new float[8192];
    for (int i = 0; i < 8192; i++){
        fftSmoothed[i] = 0;
    }
    
    nBandsToGet = 64;
    
}

void ofApp::setupChannels(){
    
    channel0 = new channel(f0Long, f0Short, GL_RGBA32F_ARB, "F0");
    channels.push_back(channel0);
    channel1 = new channel(f1Long, f1Short, GL_RGBA32F_ARB, "F1");
    channels.push_back(channel1);
    channel2 = new channel(f2Long, f2Short, GL_RGBA32F_ARB, "F2");
    channels.push_back(channel2);
    channel3 = new channel(f3Long, f3Short, GL_RGBA32F_ARB, "F3");
    channels.push_back(channel3);
    channel4 = new channel(f4Long, f4Short, GL_RGBA32F_ARB, "F4");
    channels.push_back(channel4);
    channel5 = new channel(f5Long, f5Short, GL_RGBA32F_ARB, "F5");
    channels.push_back(channel5);
    channel6 = new channel(f6Long, f6Short, GL_RGBA32F_ARB, "F6");
    channels.push_back(channel6);
    channel7 = new channel(f7Long, f7Short, GL_RGBA32F_ARB, "F7");
    channels.push_back(channel7);
    channel8 = new channel(f8Long, f8Short, GL_RGBA32F_ARB, "F8");
    channels.push_back(channel8);
    channel9 = new channel(f9Long, f9Short, GL_RGBA32F_ARB, "F9");
    channels.push_back(channel9);

}

void ofApp::setupTcpServer(){
    
    tcpConnected = tcpServer.setup(PORT);
    tcpServer.setMessageDelimiter("\n");
	
}

void ofApp::setup(){
    
    setupTcpServer();
    setupArrays();
    setupSound();
    setupChannels();
    
    for (int i = 0; i < channels.size(); i++) {
        channel *channel = channels[i];
        
        movingFrameBoard *mfb = new movingFrameBoard(&channel->mFbo);
        movingFrameBoards.push_back(mfb);
        
        chessBoard1 *cb1 = new chessBoard1(&channel->mFbo);
        chessBoard1s.push_back(cb1);
        
        testBoard *tb = new testBoard(&channel->mFbo);
        testBoards.push_back(tb);
        
        oneColorBoard *ocb = new oneColorBoard(&channel->mFbo);
        oneColorBoards.push_back(ocb);
        
        chessBoard2 *cb2 = new chessBoard2(&channel->mFbo);
        chessBoard2s.push_back(cb2);
    }
    
    
}

// ------------------------------------ Updates ------------------------------------

void ofApp::updateSound(){
    ofSoundUpdate();
    
    float * val = ofSoundGetSpectrum(nBandsToGet);
    
    for (int i = 0;i < nBandsToGet; i++){
        
        fftSmoothed[i] *= 0.96f;
        if (fftSmoothed[i] < val[i]) fftSmoothed[i] = val[i];
        
    }
}

void ofApp::updateChannel(channel *channel, int index){
    
    channel->mFbo.begin();
    
    if (channelsArray[index]) {
        
        if (boardsArray[0]==true) {
            chessBoard1s[index]->update(fftSmoothed);
        }else if (boardsArray[1]==true) {
            movingFrameBoards[index]->update();
        }else if (boardsArray[2]==true) {
            testBoards[index]->update();
        }else if (boardsArray[3]==true) {
            oneColorBoards[index]->update();
        }else if (boardsArray[4]==true) {
            chessBoard2s[index]->update();
        }
        
    }else{
        ofClear(0, 0, 0);
    }
    channel->mTexture.loadScreenData(0, 0, channel->mWidth, channel->mHeight);
    channel->mSyphonServer.publishTexture(&channel->mTexture);
    
    channel->mFbo.end();
    
}

void ofApp::updateTcpServer(){
    
    for(unsigned int i = 0; i <  (unsigned int)tcpServer.getLastID(); i++){
        
        if( !tcpServer.isClientConnected(i) ) {
            continue;
        }
        
        string msgRx = tcpServer.receive(i);
        if (msgRx.length() > 0) {
//            parseJSONString(msgRx);
//            tiggerAtPoint(screenPoint.x, screenPoint.y, event);
            
        }
    }
}

void ofApp::update(){
    
    updateSound();
    updateTcpServer();
    
    for (int i=0; i<channels.size(); i++) {

        channel *channel = channels[i];
        updateChannel(channel, i);
        
    }
}

// ------------------------------------ of Lifecycle ------------------------------------

void ofApp::draw(){

    ofClear(30, 30, 30);
    
    ofSetColor(255, 255, 255);    // draw fbo without color modulation
    
    for (int i=0; i<channels.size(); i++) {
        channel *channel = channels[i];
        
        if (channel->mSyphonServerName == "F4") {
            channel->draw(0,0);
        }
    }
    
    if (tcpConnected) {
        string str = "TCP server with IP " + ofToString(IP)  + " is online at port: " + ofToString(tcpServer.getPort()) + ", clients: " + ofToString(tcpServer.getNumClients());
        ofSetColor(0, 255, 0);
        ofDrawBitmapString(str, 10, ofGetHeight()-15);
        
        for(unsigned int i = 0; i <  (unsigned int)tcpServer.getLastID(); i++){
            if( !tcpServer.isClientConnected(i) ) {
                continue;
            }else{
                string str = "TCP client with IP " + ofToString(tcpServer.getClientIP(i))+" is connected.";
                ofSetColor(0, 255, 0);
                ofDrawBitmapString(str, 10, ofGetHeight()-(15*(i+2)));
            }
        }
    }
}

void ofApp::keyPressed(int key){
    if (key=='0') {
        setChannelsArrayTrueOnlyAtIndex(0);
    }else if(key=='1'){
        setChannelsArrayTrueOnlyAtIndex(1);
    }else if(key=='2'){
        setChannelsArrayTrueOnlyAtIndex(2);
    }else if(key=='3'){
        setChannelsArrayTrueOnlyAtIndex(3);
    }else if(key=='4'){
        setChannelsArrayTrueOnlyAtIndex(4);
    }else if(key=='5'){
        setChannelsArrayTrueOnlyAtIndex(5);
    }else if(key=='6'){
        setChannelsArrayTrueOnlyAtIndex(6);
    }else if(key=='7'){
        setChannelsArrayTrueOnlyAtIndex(7);
    }else if(key=='8'){
        setChannelsArrayTrueOnlyAtIndex(8);
    }else if(key=='9'){
        setChannelsArrayTrueOnlyAtIndex(9);
    }
    
    if (key=='a') {
        setBoardsArrayTrueOnlyAtIndex(0);
    }else if(key=='b'){
        setBoardsArrayTrueOnlyAtIndex(1);
    }else if(key=='c'){
        setBoardsArrayTrueOnlyAtIndex(2);
    }else if(key=='d'){
        setBoardsArrayTrueOnlyAtIndex(3);
    }
    else if(key=='e'){
        setBoardsArrayTrueOnlyAtIndex(4);
    }/*else if(key=='f'){
        setBoardsArrayTrueOnlyAtIndex(5);
    }else if(key=='g'){
        setBoardsArrayTrueOnlyAtIndex(6);
    }else if(key=='h'){
        setBoardsArrayTrueOnlyAtIndex(7);
    }else if(key=='i'){
        setBoardsArrayTrueOnlyAtIndex(8);
    }else if(key=='j'){
        setBoardsArrayTrueOnlyAtIndex(9);
    }*/
    
    if(key=='q'){
        playAll = !playAll;
        if (playAll) {
            setChannelsArrayTrue();
        }else{
            setChannelsArrayFalse();
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

void ofApp::mousePressed(int x, int y, int button){
    
    for (int i=0; i<channels.size(); i++) {
        channel *channel = channels[i];
        
        if (channel->mSyphonServerName == "F4") {
            chessBoard2s[4]->tiggerAtPoint(x, y, "press");
        }
    }
    
    
}

void ofApp::mouseReleased(int x, int y, int button){
    
    for (int i=0; i<channels.size(); i++) {
        channel *channel = channels[i];
        
        if (channel->mSyphonServerName == "F4") {
            chessBoard2s[4]->tiggerAtPoint(x, y, "release");
        }
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

void ofApp::setChannelsArrayTrueOnlyAtIndex(int index){
    for (int i = 0; i < numberofChannels; i++) {
        if (i==index) {
            channelsArray[index]=true;
        }else{
            channelsArray[i]=false;
        }
    }
}

void ofApp::setChannelsArrayTrue(){
    for (int i = 0; i < numberofChannels; i++) {
        channelsArray[i]=true;
    }
}

void ofApp::setChannelsArrayFalse(){
    for (int i = 0; i < numberofChannels; i++) {
        channelsArray[i]=false;
    }
}

