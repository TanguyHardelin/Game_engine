#ifndef GRAVITY_FORCE_H
#define GRAVITY_FORCE_H

#include "ParticuleForceGenerator.h"
#include "Vector3D.h"

#define G 10

class GravityForce:public ParticuleForceGenerator{
    public:
        GravityForce(double g);
        virtual void updateForce(Particule *p,float delta_t);

    protected:
        double _gravity;
};

#endif