#ifndef RIGIDBODY_FORCE_GENERATOR
#define RIGIDBODY_FORCE_GENERATOR

#include "RigidBody.h"

class RigidBodyForceGenerator{
    public:
        virtual void updateForce(RigidBody *r,float delta_t)=0;
};

#endif