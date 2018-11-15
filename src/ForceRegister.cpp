#include "ForceRegister.h"

//TODO: Add unit test !

void ForceRegister::addForce(Particule *p,ParticuleForceGenerator *fg){
    ParticuleForceRecording fr;
    fr.p=p;
    fr.fg=fg;
    _particule_register.push_back(fr);
}
void ForceRegister::deleteForce(Particule *p,ParticuleForceGenerator *fg){
    for(unsigned i=0;i<_particule_register.size();i++){
        if(fg==_particule_register[i].fg&&p==_particule_register[i].p){
            _particule_register.erase(_particule_register.begin() + i);
        }
    }
}
void ForceRegister::addForce(RigidBody *p,RigidBodyForceGenerator *fg){
    RigidBodyForceRecording fr;
    fr.p=p;
    fr.fg=fg;
    _rigidBody_register.push_back(fr);
}
void ForceRegister::deleteForce(RigidBody *p,RigidBodyForceGenerator *fg){
    for(unsigned i=0;i<_rigidBody_register.size();i++){
        if(fg==_rigidBody_register[i].fg&&p==_rigidBody_register[i].p){
            _rigidBody_register.erase(_rigidBody_register.begin() + i);
        }
    }
}
void ForceRegister::updateAllForce(double delta_t){
    for(unsigned i=0;i<_particule_register.size();i++){
        _particule_register[i].fg->updateForce(_particule_register[i].p,delta_t);
    }
    for(unsigned i=0;i<_particule_register.size();i++){
        _rigidBody_register[i].fg->updateForce(_rigidBody_register[i].p,delta_t);
    }
}
void ForceRegister::clearAllForce(){
    for(unsigned i=0;i<_particule_register.size();i++){
        _particule_register[i].p->clearAccum();
    }
    for(unsigned i=0;i<_particule_register.size();i++){
        _rigidBody_register[i].p->clearAccums();
    }
}