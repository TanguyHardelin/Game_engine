#ifndef PARTICULE_CONTACT_GENERATOR
#define PARTICULE_CONTACT_GENERATOR

#include <vector>
#include "ParticuleContact.h"

class ParticuleContactGenerator{
    public:
        ParticuleContactGenerator();

        std::vector<ParticuleContact *> getContacts();
        std::vector<ParticuleContact *> getLinks();
        std::vector<ParticuleContact *> getCables();

        void addContact(ParticuleContact *pc);
        void addLink(ParticuleContact *pc);
        void addCable(ParticuleContact *pc);

        void clearContacts();
        void clearLinkAtIndex(int index);
        void clearCableAtIndex(int index);
        
    protected:
        std::vector<ParticuleContact *> _all_contact;
        std::vector<ParticuleContact *> _all_link;
        std::vector<ParticuleContact *> _all_cable;
};  

#endif