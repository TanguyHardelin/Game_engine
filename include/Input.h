#ifndef INPUT_H
#define INPUT_H

#include <vector>

typedef struct{
    long name;
    int x;
    int y;
} INPUT_KEY;

class Input{
    public:
        inline std::vector<INPUT_KEY> getBuffer(){return _buffer;}
    
    protected:
        std::vector<INPUT_KEY> _buffer;
};

#endif