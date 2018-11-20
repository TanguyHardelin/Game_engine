#ifndef GRAVITY_FORCE_H
#define GRAVITY_FORCE_H

#include "RigidBodyForceGenerator.h"
#include "Vector3D.h"


class RessortRigidBodyForce:public RigidBodyForceGenerator{
    public:
        RessortRigidBodyForce(RigidBody * other_rigidBody,double K);
        virtual void updateForce(RigidBody *p,float delta_t);

    protected:
        RigidBody * _other_rigidBody;
        double _K;
};

#endif