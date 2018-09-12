#ifndef MOUSE_H
#define MOUSE_H

#include "Input.h"

class Mouse: public Input{
    public:
        //Constructor:
        Mouse();
        //Methods:
        void handleMouse(int button, int state,int x, int y);
};

#endif