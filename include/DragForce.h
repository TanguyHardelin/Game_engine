#ifndef DRAG_FORCE_H
#define DRAG_FORCE_H

#include "ParticuleForceGenerator.h"
#include "Vector3D.h"

class DragForce:public ParticuleForceGenerator{
    public:
        DragForce(double k1,double k2);
        virtual void updateForce(Particule *p,float delta_t);
    
    protected:
        double _k1,_k2;
};


#endif