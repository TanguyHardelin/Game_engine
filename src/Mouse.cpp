#include "Mouse.h"

Mouse::Mouse(){}
void Mouse::handleMouse(int button, int state,int x, int y){
    INPUT_KEY new_key;
    new_key.name=5000+button;
    new_key.x=x;
    new_key.y=y;

    _buffer.push_back(new_key);
}