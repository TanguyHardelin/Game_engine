#include "ParticuleContact.h"

using namespace std;

ParticuleContact::ParticuleContact(std::vector<Particule *> p,double restitution):_p(p),_restitution(restitution),_n(0,0,0),_d(0,0,0){

}
ParticuleContact::ParticuleContact(std::vector<Particule *> p):_p(p),_restitution(DEFAULT_RESTITUTION),_n(0,0,0),_d(0,0,0){
    
}

void ParticuleContact::resolve(double time){
    resolveInterpenetration();
    resolveVelocity(time);
}
Vector3D ParticuleContact::calculateVs(){
    _n=(_p[0]->getSpeed()-_p[1]->getSpeed()).normalize();
    return ((_p[0]->getSpeed()-_p[1]->getSpeed())*_n);
}
void ParticuleContact::resolveVelocity(double time){
    Vector3D vs=calculateVs()*-1*_restitution;

    Vector3D impulsion_0=vs*_p[0]->getMass();
    Vector3D new_speed_0=(_p[0]->getSpeed()+impulsion_0*1.0f/_p[0]->getMass());
    Vector3D impulsion_1=vs*_p[1]->getMass();
    Vector3D new_speed_1=(_p[1]->getSpeed()+impulsion_1*1.0f/_p[1]->getMass()*-1.0f);
    _p[0]->setSpeed(new_speed_0);
    _p[1]->setSpeed(new_speed_1);
}
void ParticuleContact::resolveInterpenetration(){
    _d=norm(_p[0]->getPosition()-_p[1]->getPosition());
    double ma=1/_p[0]->getMass();
    double mb=1/_p[1]->getMass();
    Vector3D delta_pa=_d*_n*mb/(ma+mb);
    Vector3D delta_pb=_d*_n*-1*ma/(ma+mb);
    _p[0]->setPosition(_p[0]->getPosition()+delta_pa);
    _p[1]->setPosition(_p[1]->getPosition()+delta_pb);
}
ParticuleContact::~ParticuleContact(){
   
}