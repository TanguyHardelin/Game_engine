#ifndef GRAVITY_FORCE_H
#define GRAVITY_FORCE_H

#include "RigidBodyForceGenerator.h"
#include "Vector3D.h"


class GravityRigidBodyForce:public RigidBodyForceGenerator{
    public:
        GravityRigidBodyForce(double g);
        virtual void updateForce(RigidBody *p,float delta_t);

    protected:
        double _gravity;
};

#endif