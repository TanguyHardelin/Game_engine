#ifndef PARTICULE_FLOOR_CONTACT_H
#define PARTICULE_FLOOR_CONTACT_H

#include "ParticuleContact.h"

class ParticuleFloorContact:public ParticuleContact{
    public:
        ParticuleFloorContact(std::vector<Particule *> p,double restitution);
        ParticuleFloorContact(std::vector<Particule *> p);

        virtual Vector3D calculateVs();
        virtual void resolveVelocity(double time);
        virtual void resolveInterpenetration();
};

#endif