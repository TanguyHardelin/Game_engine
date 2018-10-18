#include "ParticuleContactResolver.h"
#include "ParticuleContact.h"

using namespace std;

ParticuleContactResolver::ParticuleContactResolver(long nb_particules,long current_iteration):_nb_particules(nb_particules),_current_iteration(current_iteration){

}
void ParticuleContactResolver::resolveContacts(vector <ParticuleContact*> all_contacts, double dt){
    for(unsigned i=0;i<all_contacts.size();i++){
        all_contacts[i]->resolve(dt);
    }
}