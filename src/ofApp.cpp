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

//--------------------------------------------------------------
void ofApp::setup(){
    
//    mutBoard *board2 = new mutBoard(f2Long, f2Short, GL_RGBA, "F2");
    mutBoard *board6 = new mutBoard(f6Long, f6Short, GL_RGBA, "F6");
    
//    boards.push_back(*board2);
    boards.push_back(*board6);
    
//    syphonServer6.setName("F6");
//    texture6.allocate(f6Long, f6Short, GL_RGBA);
//    fbo6.allocate(f6Long, f6Short, GL_RGBA);
//    
//    syphonServer7.setName("F2");
//    texture7.allocate(f2Long, f2Short, GL_RGBA);
//    fbo7.allocate(f2Long, f2Short, GL_RGBA);
}

float x;
float dx = 1;

//--------------------------------------------------------------
void ofApp::update(){
    
    for (int i=0; i<boards.size(); i++) {
        boards[i].update();
    }

//    x += dx;
//    
//    if ((x > f4Long) | (x < 0)) {
//        dx *= -1;
//    }
//    
//    fbo6.begin();
//    ofClear(255);
//    ofSetColor(ofColor::chocolate);
//    ofRect(0, 0, f6Long, f6Short);
//    ofSetColor(ofColor::burlyWood);
//    ofCircle(x, f6Short*.5, 50.0);
//    texture6.loadScreenData(0, 0, f6Long, f6Short);
//    syphonServer6.publishTexture(&texture6);
//    fbo6.end();
//    
//    fbo7.begin();
//    ofClear(255);
//    ofSetColor(ofColor::red);
//    ofRect(0, 0, f2Long, f2Short);
//    ofSetColor(ofColor::yellow);
//    ofCircle(x, f2Short*.5, 50.0);
//    texture7.loadScreenData(0, 0, f2Long, f2Short);
//    syphonServer7.publishTexture(&texture7);
//    fbo7.end();

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for (int i=0; i<boards.size(); i++) {
        boards[i].draw(512,0);
    }
    
//    fbo6.draw(0,0);
//    fbo7.draw(512, 0);
}







