#include "ForceRegister.h"

//TODO: Add unit test !

void ForceRegister::addForce(Particule *p,ParticuleForceGenerator *fg){
    ForceRecording fr;
    fr.p=p;
    fr.fg=fg;
    _register.push_back(fr);
}
void ForceRegister::deleteForce(Particule *p,ParticuleForceGenerator *fg){
    for(unsigned i=0;i<_register.size();i++){
        if(fg==_register[i].fg&&p==_register[i].p){
            _register.erase(_register.begin() + i);
        }
    }
}
void ForceRegister::updateAllForce(double delta_t){
    for(unsigned i=0;i<_register.size();i++){
        _register[i].fg->updateForce(_register[i].p,delta_t);
    }
}
void ForceRegister::clearAllForce(){
    for(unsigned i=0;i<_register.size();i++){
        _register[i].p->clearAccum();
    }
}