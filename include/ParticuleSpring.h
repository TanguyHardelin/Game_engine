#ifndef PARTICULE_SPRING_H
#define PARTICULE_SPRING_H

#include "ParticuleForceGenerator.h"
#include "Vector3D.h"

class ParticuleSpring: public ParticuleForceGenerator{
    public:
        ParticuleSpring(double k,double l0,Particule *p);
        virtual void updateForce(Particule *p,float delta_t);

    protected:
        double _K;
        double _l0;
        Particule *_other_particule;
};

#endif