#ifndef BUOYANCY_SPRING_H
#define BUOYANCY_SPRING_H

#include "ParticuleForceGenerator.h"
#include "Vector3D.h"

class BuoyancySpring: public ParticuleForceGenerator{
    public:
        BuoyancySpring(double max_depth,double obj_volume,double water_height,double density);
        virtual void updateForce(Particule *p,float delta_t);

    protected:
        double _max_depth;
        double _obj_volume;
        double _water_height;
        double _density;
};

#endif