#include "ParticuleContact.h"

using namespace std;


ParticuleContact::ParticuleContact(std::vector<Particule *> p,double restitution,bool interact_with_floor):_p(p),_restitution(restitution),_n(0,0,0),_d(0,0,0),_interact_with_floor(interact_with_floor){

}

ParticuleContact::ParticuleContact(std::vector<Particule *> p,double restitution):_p(p),_restitution(restitution),_n(0,0,0),_d(0,0,0),_interact_with_floor(false){

}
ParticuleContact::ParticuleContact(std::vector<Particule *> p):_p(p),_restitution(DEFAULT_RESTITUTION),_n(0,0,0),_d(0,0,0),_interact_with_floor(false){
    
}

void ParticuleContact::resolve(double time){
    resolveInterpenetration();
    resolveVelocity(time);
}
Vector3D ParticuleContact::calculateVs(){
    if(_interact_with_floor){
        _n=(_p[0]->getSpeed()).normalize();

        //cout<<"_p[0]->getSpeed() ";_p[0]->getSpeed().display();cout<<endl;
        //cout<<"_p[1]->getPosition() ";_p[1]->getPosition().display();cout<<endl;
        //cout<<"_n ";_n.display();cout<<endl;
        cout<<"((_p[0]->getSpeed())*_n) ";((_p[0]->getSpeed())*_n).display();cout<<endl;

        return ((_p[0]->getSpeed())*_n)*(-1.0f);
    }
    else{
        _n=(_p[0]->getSpeed()-_p[1]->getSpeed()).normalize();
        return ((_p[0]->getSpeed()-_p[1]->getSpeed())*_n);
    }
    
    
    
}
void ParticuleContact::resolveVelocity(double time){
    if(_interact_with_floor){
        Vector3D vs=calculateVs()*_restitution*-1.0f;
        //cout<<"VS"<<endl;
        //vs.display();
        Vector3D impulsion=vs*_p[0]->getMass();
        Vector3D new_speed=(vs);
        _p[0]->setSpeed(new_speed);
        cout<<"New speed: ";new_speed.display();cout<<endl;
    }
    else{
        Vector3D vs=calculateVs()*-1*_restitution;
        //cout<<"VS"<<endl;
        //vs.display();
        Vector3D impulsion=vs*_p[0]->getMass();
        Vector3D new_speed=(_p[0]->getSpeed()+impulsion*1.0f/_p[0]->getMass());
        _p[0]->setSpeed(new_speed);
        //cout<<"New speed: ";new_speed.display();cout<<endl;
        //impulsion.display();
    }
    
}
void ParticuleContact::resolveInterpenetration(){
    if(_interact_with_floor){
        Vector3D pos=_p[0]->getPosition();
        pos[1]=0;
        _p[0]->setPosition(pos);
    }
    else{
        _d=norm(_p[0]->getPosition()-_p[1]->getPosition());
        double ma=1/_p[0]->getMass();
        double mb=1/_p[1]->getMass();
        Vector3D delta_pa=_d*_n*mb/(ma+mb);
        Vector3D delta_pb=_d*_n*-1*ma/(ma+mb);
        _p[0]->setPosition(_p[0]->getPosition()+delta_pa);
        _p[1]->setPosition(_p[1]->getPosition()+delta_pb);
    }
}