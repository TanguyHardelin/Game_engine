#ifndef PARTICULE_LINK
#define PARTICULE_LINK

#include "ParticuleContactGenerator.h"

class ParticuleLink: public ParticuleContactGenerator{
    public:
        ParticuleLink();

        inline double getCurrentLength(){return _length;};

    protected:
        double _length;
};


#endif