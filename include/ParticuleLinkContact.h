#ifndef PARTICULE_LINK_CONTACT_H
#define PARTICULE_LINK_CONTACT_H

#include "ParticuleContact.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

class ParticuleLinkContact:public ParticuleContact{
    public:
        ParticuleLinkContact(std::vector<Particule *> p,double restitution);
        ParticuleLinkContact(std::vector<Particule *> p);

        virtual Vector3D calculateVs();
        virtual void resolveVelocity(double time);
        virtual void resolveInterpenetration();
    
    protected:
        Vector3D _length;

};

#endif