#ifndef INPUT_H
#define INPUT_H

#include <vector>

//Define a structure for keys:
typedef struct{
    long name;
    int x;
    int y;
} INPUT_KEY;

//Defines:
#define MOUSE_OFFSET 5000
#define KEYBOARD_OFFSET 0

#define LEFT_CLICK MOUSE_OFFSET + 0 
#define SCROOL_WHEEL_CLICK MOUSE_OFFSET + 1
#define RIGHT_CLICK MOUSE_OFFSET + 2 
#define SCROOL_WHEEL_UP MOUSE_OFFSET + 3 
#define SCROOL_WHEEL_DOWN MOUSE_OFFSET + 4 

class Input{
    public:
        //Getter:
        inline std::vector<INPUT_KEY> getBuffer(){return _buffer;}
        //Setter:
        void clearBuffer();
    
    protected:
        std::vector<INPUT_KEY> _buffer;
};


#endif