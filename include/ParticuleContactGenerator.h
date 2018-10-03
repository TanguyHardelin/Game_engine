#ifndef PARTICULE_CONTACT_GENERATOR
#define PARTICULE_CONTACT_GENERATOR

#include <vector>
#include "ParticuleContact.h"

class ParticuleContactGenerator{
    public:
        ParticuleContactGenerator();
        inline std::vector<ParticuleContact *> getContacts(){return _all_contact;}
        inline void addContact(ParticuleContact *pc){_all_contact.push_back(pc);}

    protected:
        std::vector<ParticuleContact *> _all_contact;
};  

#endif