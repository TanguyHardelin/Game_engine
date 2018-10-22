#include "ParticuleContactResolver.h"
#include "ParticuleContact.h"
#include "ParticuleContactGenerator.h"

using namespace std;

ParticuleContactResolver::ParticuleContactResolver():_nb_particules(0),_current_iteration(0){
}
void ParticuleContactResolver::resolve(vector <ParticuleContact*> all_contacts, double dt){
    for(unsigned i=0;i<all_contacts.size();i++){
        all_contacts[i]->resolve(dt);
    }
}
