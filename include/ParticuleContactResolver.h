#ifndef PARTICULE_CONTACT_RESOLVER
#define PARTICULE_CONTACT_RESOLVER

#include <vector>
#include "Particule.h"

class ParticuleContact;

class ParticuleContactResolver{
    public:
        ParticuleContactResolver();
        void handleContacts(std::vector<Particule*> all_contacts, double dt);
        void resolve(std::vector<ParticuleContact*> all_contacts, double dt);

        friend class ParticuleContact;
    
    protected: 
        long _nb_particules;
        long _current_iteration;
};

#endif