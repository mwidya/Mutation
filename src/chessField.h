//
//  chessField.h
//  chessBoard_2
//
//  Created by Martin Widyanata on 31.05.14.
//
//

#ifndef __chessBoard_2__chessField__
#define __chessBoard_2__chessField__

#include <iostream>
#import "ofMain.h"

class chessField : ofRectangle{
    
public:
    chessField(float x, float y, float size);
    
    void update();
    void draw();
    void setColor(int r, int g, int b);
    void playSound(int i);
    
private:
    int _red;
    int _green;
    int _blue;
    
    ofSoundPlayer _soundPlayer;
    
};

#endif /* defined(__chessBoard_2__chessField__) */
