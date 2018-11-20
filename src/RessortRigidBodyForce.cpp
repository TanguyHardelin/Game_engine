#include "RessortRigidBodyForce.h"
#include <iostream>

using namespace std;

RessortRigidBodyForce::RessortRigidBodyForce(RigidBody * other_rigidBody,double K):_other_rigidBody(other_rigidBody),_K(K){

}
void RessortRigidBodyForce::updateForce(RigidBody *r,float delta_t){
    
    Vector3D p1=RigidBody::worldToLocal(r->getPosition(),r->getTransformMatrix());
    Vector3D p2=RigidBody::worldToLocal(_other_rigidBody->getPosition(),_other_rigidBody->getTransformMatrix());
    Vector3D result =p1-p2;

    Vector3D force=result.normalize()*_K*result;
    r->addForceAtPoint(force,p1);
  
}