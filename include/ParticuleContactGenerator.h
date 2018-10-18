#ifndef PARTICULE_CONTACT_GENERATOR
#define PARTICULE_CONTACT_GENERATOR

#include <vector>
#include "ParticuleContact.h"

class ParticuleContactGenerator{
    public:
        ParticuleContactGenerator();
        inline std::vector<ParticuleContact *> getContacts(){return _all_contact;}
        inline void addContact(ParticuleContact *pc){_all_contact.push_back(pc);}
        inline void clearContacts(){
            for(unsigned i=0;i<_all_contact.size();i++){
                _all_contact.pop_back();
            }
        }

        
    protected:
        std::vector<ParticuleContact *> _all_contact;
};  

#endif