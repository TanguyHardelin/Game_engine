#include "DragForce.h"
#include <iostream>

using namespace std;

DragForce::DragForce(double k1,double k2):_k1(k1),_k2(k2){

}
void DragForce::updateForce(Particule *p,float delta_t){
    if(p->getMass()>0){
        Vector3D speed=p->getSpeed();
        Vector3D drag=speed.normalize()*-1.0*(_k1*speed.norm()+_k2*speed.norm());
        p->addForce(drag);
        //cout<<"drag: ";drag.display();
    }
}