#include "ParticuleStiffSpring.h"

ParticuleStiffSpring::ParticuleStiffSpring(Vector3D anchor,double K,double damping,Vector3D initial_position,Vector3D initial_velocity):_anchor(anchor),_K(K),_damping(damping),_initial_position(initial_position),_initial_velocity(initial_velocity){

}
void ParticuleStiffSpring::updateForce(Particule *p,float delta_t){
    double phi=0.5f*sqrt(4*_K-_damping*_damping);
    Vector3D c=_initial_position*_damping/(2*phi)+_initial_velocity*(1/phi);
    Vector3D position=(_initial_position*cos(phi*delta_t)+c*sin(phi*delta_t))*exp(-1/2);
    Vector3D new_acceleration=(position-_anchor)*(1/(delta_t*delta_t))-_initial_velocity;
    p->addForce(new_acceleration);
}