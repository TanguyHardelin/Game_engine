#ifndef PARTICULE_STIFF_SPRING_H
#define PARTICULE_STIFF_SPRING_H

#include "Vector3D.h"
#include "Particule.h"

class ParticuleStiffSpring{
    public:
        ParticuleStiffSpring(Vector3D anchor,double K,double damping);
        virtual void updateForce(Particule *p,float delta_t);
        
    protected:
        Vector3D _anchor;
        double _K;
        double _damping;
};

#endif