#include "ParticuleContactGenerator.h"

ParticuleContactGenerator::ParticuleContactGenerator(){}

std::vector<ParticuleContact *> ParticuleContactGenerator::getContacts(){
    return _all_contact;
}

std::vector<ParticuleLinkContact *> ParticuleContactGenerator::getLinks(){
    return _all_link;
}

std::vector<ParticuleCableContact *> ParticuleContactGenerator::getCables(){
    return _all_cable;
}

void ParticuleContactGenerator::addContact(ParticuleContact *pc){
    _all_contact.push_back(pc);
}

void ParticuleContactGenerator::addLink(ParticuleLinkContact *pc){
    _all_link.push_back(pc);
}

void ParticuleContactGenerator::addCable(ParticuleCableContact *pc){
    _all_cable.push_back(pc);
}

void ParticuleContactGenerator::clearContacts(){
    for(unsigned i=0;i<_all_contact.size();i++){
        _all_contact.pop_back();
    }
}

void ParticuleContactGenerator::clearLinkAtIndex(int index){
    int size=(int)_all_link.size();
    if(index<size-1){
        delete _all_link[index];
        _all_link.erase(_all_link.begin()+index,_all_link.begin()+index+1);
    }
}

void ParticuleContactGenerator::clearCableAtIndex(int index){
    int size=(int)_all_link.size();
    if(index<size-1){
        delete _all_cable[index];
        _all_cable.erase(_all_cable.begin()+index,_all_cable.begin()+index+1);
    }
}
