//
//  chessField.cpp
//  chessBoard_2
//
//  Created by Martin Widyanata on 31.05.14.
//
//

#include "chessField.h"

chessField::chessField(float x, float y, float size)
{
    this->setX(x);
    this->setY(y);
    this->setWidth(size);
    this->setHeight(size);
}

void chessField::draw()
{
    
    ofSetColor(_red, _green, _blue);
    ofRect(this->getX(), this->getY(), this->getWidth(), this->getHeight());
    
}

void chessField::setColor(int r, int g, int b)
{
    _red = r;
    _green = g;
    _blue = b;
}

void chessField::playSound(int i)
{
    string path = "music/audio_" + ofToString(i) + ".aif";
    _soundPlayer.loadSound(path);
    _soundPlayer.play();
}