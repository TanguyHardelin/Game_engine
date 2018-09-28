#ifndef ANCHOR_SPRING_H
#define ANCHOR_SPRING_H

#include "ParticuleForceGenerator.h"
#include "Vector3D.h"

class AnchorSpring: public ParticuleForceGenerator{
    public:
        AnchorSpring(double k,double l0,Vector3D anchor);
        virtual void updateForce(Particule *p,float delta_t);

    protected:
        double _K;
        double _l0;
        Vector3D _anchor;
};

#endif