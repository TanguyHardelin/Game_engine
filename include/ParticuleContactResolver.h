#ifndef PARTICULE_CONTACT_RESOLVER
#define PARTICULE_CONTACT_RESOLVER

#include "ParticuleContact.h"

class ParticuleContactResolver{
    public:
        ParticuleContactResolver(long nb_particules,long current_iteration);
        void resolve_contact();

        friend class ParticuleContact;
    
    protected: 
        long _nb_particules;
        long _current_iteration;

};

#endif