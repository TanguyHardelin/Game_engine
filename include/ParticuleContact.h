#ifndef PARTICULE_CONTACT_H
#define PARTICULE_CONTACT_H

#include <vector>
#include "Particule.h"
#include "Vector3D.h"
#include "ParticuleContactResolver.h"

#define DEFAULT_RESTITUTION 0.9

class ParticuleContact{
    public:
        //ParticuleContact(std::vector<Particule *> p,double restitution,bool interact_with_floor);
        ParticuleContact(std::vector<Particule *> p,double restitution);
        ParticuleContact(std::vector<Particule *> p);

        void resolve(double time);
        virtual Vector3D calculateVs();
        virtual void resolveVelocity(double time);
        virtual void resolveInterpenetration();

        virtual ~ParticuleContact();
        friend class ParticuleContactResolver;

    protected:
        std::vector<Particule *> _p;
        double _restitution;
        Vector3D _n;
        Vector3D _d;
};

#endif