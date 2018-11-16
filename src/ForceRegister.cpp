#include "ForceRegister.h"

using namespace std;

void ForceRegister::addForce(Particule *p,ParticuleForceGenerator *fg){
    //cout<<"Add force particule"<<endl;
    ParticuleForceRecording fr;
    fr.p=p;
    fr.fg=fg;
    _particule_register.push_back(fr);
}
void ForceRegister::deleteForce(Particule *p,ParticuleForceGenerator *fg){
    //cout<<"Delete force particule"<<endl;
    for(unsigned i=0;i<_particule_register.size();i++){
        if(fg==_particule_register[i].fg&&p==_particule_register[i].p){
            _particule_register.erase(_particule_register.begin() + i);
        }
    }
}
void ForceRegister::addForce(RigidBody *p,RigidBodyForceGenerator *fg){
    //cout<<"Add force rigidbody"<<endl;
    RigidBodyForceRecording fr;
    fr.p=p;
    fr.fg=fg;
    _rigidBody_register.push_back(fr);
}
void ForceRegister::deleteForce(RigidBody *p,RigidBodyForceGenerator *fg){
    //cout<<"Delete force rigidbody"<<endl;
    for(unsigned i=0;i<_rigidBody_register.size();i++){
        if(fg==_rigidBody_register[i].fg&&p==_rigidBody_register[i].p){
            _rigidBody_register.erase(_rigidBody_register.begin() + i);
        }
    }
}
void ForceRegister::updateAllForce(double delta_t){
    //cout<<"Update force"<<endl;
    for(unsigned i=0;i<_particule_register.size();i++){
        _particule_register[i].fg->updateForce(_particule_register[i].p,delta_t);
    }
    //cout<<"OK"<<endl;
    for(unsigned i=0;i<_rigidBody_register.size();i++){
        _rigidBody_register[i].fg->updateForce(_rigidBody_register[i].p,delta_t);
    }
    //cout<<"END Update force"<<endl;
}
void ForceRegister::clearAllForce(){
    //cout<<"Clear force"<<endl;
    for(unsigned i=0;i<_particule_register.size();i++){
        _particule_register[i].p->clearAccum();
    }
    for(unsigned i=0;i<_rigidBody_register.size();i++){
        _rigidBody_register[i].p->clearAccums();
    }
    //cout<<"END Clear force"<<endl;
}