#include "Input.h"

void Input::clearBuffer(){
    for(unsigned i=0;i<_buffer.size();i++){
        _buffer.pop_back();
    }
}