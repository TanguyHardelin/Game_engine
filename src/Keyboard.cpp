#include "Keyboard.h"

Keyboard::Keyboard(){}
void Keyboard::handleKeyboard(unsigned char key, int x, int y){
    INPUT_KEY new_key;
    new_key.name=key;
    new_key.x=x;
    new_key.y=y;

    _buffer.push_back(new_key);
}