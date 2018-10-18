#ifndef PARTICULE_CONTACT_RESOLVER
#define PARTICULE_CONTACT_RESOLVER

#include <vector>
#include "ParticuleContact.h"
#include "Particule.h"

class ParticuleContact;

class ParticuleContactResolver{
    public:
        ParticuleContactResolver(long nb_particules,long current_iteration);
        void resolveContacts(std::vector<ParticuleContact*> all_contacts, double dt);

        friend class ParticuleContact;
    
    protected: 
        long _nb_particules;
        long _current_iteration;

};

#endif