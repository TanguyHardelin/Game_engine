#include "ParticuleStiffSpring.h"

ParticuleStiffSpring::ParticuleStiffSpring(Vector3D anchor,double K,double damping):_anchor(anchor),_K(K),_damping(damping){

}
void ParticuleStiffSpring::updateForce(Particule *p,float delta_t){
    //Implement
}