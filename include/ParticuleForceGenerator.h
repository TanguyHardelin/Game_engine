#ifndef PARTICULE_FORCE_GENERATOR
#define PARTICULE_FORCE_GENERATOR

#include "Particule.h"
#include "RigidBody.h"

class ParticuleForceGenerator{
    public:
    virtual void updateForce(Particule *p,float delta_t)=0;

};

#endif