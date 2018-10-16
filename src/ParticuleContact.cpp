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
    cout<<"Normalize ";_n.display();cout<<endl;
    return ((_p[0]->getSpeed()-_p[1]->getSpeed())*_n);
}
void ParticuleContact::resolveVelocity(double time){
    Vector3D vs=calculateVs()*-1*_restitution;
    cout<<"VS"<<endl;
    vs.display();
    Vector3D impulsion=vs*_p[0]->getMass();
    _p[0]->setSpeed(_p[0]->getSpeed()+impulsion*1.0f/_p[0]->getMass());
    _p[0]->getSpeed().display();
}
void ParticuleContact::resolveInterpenetration(){
    _d=norm(_p[0]->getPosition()-_p[1]->getPosition());
    cout<<"D"<<endl;
    _d.display();
    double ma=1/_p[0]->getMass();
    double mb=1/_p[1]->getMass();
    Vector3D delta_pa=_d*_n*mb/(ma+mb);
    Vector3D delta_pb=_d*_n*-1*ma/(ma+mb);

    _p[0]->setPosition(_p[0]->getPosition()+delta_pa);
    _p[1]->setPosition(_p[1]->getPosition()+delta_pb);
}