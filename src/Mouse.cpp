#include "Mouse.h"

Mouse::Mouse(){}
void Mouse::handleMouse(int button, int state,int x, int y){
    if(state==0){
        INPUT_KEY new_key;
        new_key.name=MOUSE_OFFSET+button;
        new_key.x=x;
        new_key.y=y;

        _buffer.push_back(new_key);
    }
}