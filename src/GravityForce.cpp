#include "GravityForce.h"
#include <iostream>

using namespace std;

GravityForce::GravityForce(double g):_gravity(g){

}
void GravityForce::updateForce(Particule *p,float delta_t){
    if(p->getMass()>0){
        Vector3D gravity(0,-1*_gravity,0);
        //cout<<"Gravity: ";gravity.display();
        p->addForce(gravity);
    }
}