#include "AnchorSpring.h"

AnchorSpring::AnchorSpring(double k,double l0,Vector3D anchor):_K(k),_l0(l0),_anchor(anchor){

}
void AnchorSpring::updateForce(Particule *p,float delta_t){
    Vector3D d=_anchor-p->getPosition();
    Vector3D force=d.normalize()*-1.0f*_K*(d.norm()-_l0);
    p->addForce(force);   
}
