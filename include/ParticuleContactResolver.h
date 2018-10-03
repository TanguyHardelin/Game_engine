#ifndef PARTICULE_CONTACT_RESOLVER
#define PARTICULE_CONTACT_RESOLVER

class ParticuleContactResolver{
    public:
        ParticuleContactResolver(long nb_particules,long current_iteration);
        void resolve_contact();
    
    protected: 
        long _nb_particules;
        long _current_iteration;

};

#endif