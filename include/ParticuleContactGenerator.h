#ifndef PARTICULE_CONTACT_GENERATOR
#define PARTICULE_CONTACT_GENERATOR

#include <vector>
#include "ParticuleContact.h"
#include "ParticuleLinkContact.h"
#include "ParticuleCableContact.h"

class ParticuleContactGenerator{
    public:
        ParticuleContactGenerator();

        std::vector<ParticuleContact *> getContacts();
        std::vector<ParticuleLinkContact *> getLinks();
        std::vector<ParticuleCableContact *> getCables();

        void addContact(ParticuleContact *pc);
        void addLink(ParticuleLinkContact *pc);
        void addCable(ParticuleCableContact *pc);

        void clearContacts();
        void clearLinkAtIndex(int index);
        void clearCableAtIndex(int index);
        
    protected:
        std::vector<ParticuleContact *> _all_contact;
        std::vector<ParticuleLinkContact *> _all_link;
        std::vector<ParticuleCableContact *> _all_cable;
};  

#endif