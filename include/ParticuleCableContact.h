#ifndef PARTICULE_CABLE_CONTACT_H
#define PARTICULE_CABLE_CONTACT_H

#include "ParticuleContact.h"

class ParticuleCableContact:public ParticuleContact{
    public:
        ParticuleCableContact(std::vector<Particule *> p,double restitution);
        ParticuleCableContact(std::vector<Particule *> p);

        virtual void resolveVelocity(double time);
        virtual void resolveInterpenetration();
    protected:
        Vector3D _length;
};

#endif