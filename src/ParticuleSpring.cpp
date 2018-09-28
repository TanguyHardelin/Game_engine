#include "ParticuleSpring.h"

ParticuleSpring::ParticuleSpring(double k,double l0,Particule *p):_K(k),_l0(l0),_other_particule(p){

}
void ParticuleSpring::updateForce(Particule *p,float delta_t){
    Vector3D d=_other_particule->getPosition()-p->getPosition();
    Vector3D force=d.normalize()*-1.0f*_K*(d.norm()-_l0);
    p->addForce(force);    
}