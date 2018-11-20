#include "GravityRigidBodyForce.h"
#include <iostream>

using namespace std;

GravityRigidBodyForce::GravityRigidBodyForce(double g):_gravity(g){

}
void GravityRigidBodyForce::updateForce(RigidBody *p,float delta_t){
    if(p->getMass()>0){
        Vector3D gravity(0,-1*_gravity,0);
        p->addForce(gravity);
    }
}