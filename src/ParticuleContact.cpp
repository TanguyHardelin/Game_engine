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
    Vector3D vs=calculateVs();
    Vector3D vc=vs*-1*_restitution;

    for(unsigned i=0;i<_p.size();i++){
        Vector3D impulsion=vc*_p[i]->getMass();
        _p[i]->setSpeed(_p[i]->getSpeed()+impulsion*1/_p[i]->getMass());
    }
    

}
void ParticuleContact::resolveInterpenetration(){
    double ma=1/_p[0]->getMass();
    double mb=1/_p[1]->getMass();
    Vector3D delta_pa=_d*_n*mb/(ma+mb);
    Vector3D delta_pb=_d*_n*-1*ma/(ma+mb);

    _p[0]->setPosition(_p[0]->getPosition()+delta_pa);
    _p[1]->setPosition(_p[1]->getPosition()+delta_pb);
}