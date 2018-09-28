#ifndef FLOATING_PARTICULE_H
#define FLOATING_PARTICULE_H

#include "ParticuleForceGenerator.h"
#include "Vector3D.h"

class FloatingParticule: public ParticuleForceGenerator{
    public:
        FloatingParticule(double depth,double volume,double height_of_water,double density);
        virtual void updateForce(Particule *p,float delta_t);

    protected:
        double _depth;
        double _volume;
        double _height_of_water;
        double _density;

};

#endif