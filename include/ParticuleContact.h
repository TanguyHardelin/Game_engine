#ifndef PARTICULE_CONTACT_H
#define PARTICULE_CONTACT_H

#include <vector>
#include "Particule.h"
#include "Vector3D.h"

#define DEFAULT_RESTITUTION 0.9

class ParticuleContact{
    public:
        ParticuleContact(std::vector<Particule *> p,double restitution);
        ParticuleContact(std::vector<Particule *> p);

        void resolve(double time);
        double calculateVs();
        void resolveVelocity();
        void resolveInterpenetration();

    protected:
        std::vector<Particule *> _p;
        double _restitution;
        Vector3D _n;
        Vector3D _d;

};

#endif