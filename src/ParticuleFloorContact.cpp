#include "ParticuleFloorContact.h"

using namespace std;

ParticuleFloorContact::ParticuleFloorContact(std::vector<Particule *> p,double restitution):ParticuleContact(p,restitution){

}
ParticuleFloorContact::ParticuleFloorContact(std::vector<Particule *> p):ParticuleContact(p){
}

Vector3D ParticuleFloorContact::calculateVs(){
        _n=(_p[0]->getSpeed()).normalize();
        return ((_p[0]->getSpeed())*_n)*(-1.0f);
}
void ParticuleFloorContact::resolveVelocity(double time){
        
        Vector3D vs=calculateVs()*_restitution*-1.0f;
        _p[0]->setSpeed(vs);
}
void ParticuleFloorContact::resolveInterpenetration(){
        Vector3D pos=_p[0]->getPosition();
        if(pos[1]<_p[0]->getRadius()){
                pos[1]=_p[0]->getRadius();
        }
        _p[0]->setPosition(pos);
}