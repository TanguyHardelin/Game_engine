#include "ParticuleContact.h"

ParticuleContact::ParticuleContact(std::vector<Particule *> p,double restitution):_p(p),_restitution(restitution),_n(0,0,0),_d(0,0,0){

}
ParticuleContact::ParticuleContact(std::vector<Particule *> p):_p(p),_restitution(DEFAULT_RESTITUTION),_n(0,0,0),_d(0,0,0){
    
}

void ParticuleContact::resolve(double time){

}
double ParticuleContact::calculateVs(){

}
void ParticuleContact::resolveVelocity(){

}
void ParticuleContact::resolveInterpenetration(){

}