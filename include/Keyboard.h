#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "Input.h"

class Keyboard:public Input{
    public:
        Keyboard();
        void handleKeyboard(unsigned char key, int x, int y);

};

#endif