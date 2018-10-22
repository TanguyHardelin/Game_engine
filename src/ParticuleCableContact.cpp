#include "ParticuleCableContact.h"

using namespace std;

ParticuleCableContact::ParticuleCableContact(std::vector<Particule *> p,double restitution):ParticuleLinkContact(p,restitution),_length(Vector3D(_p[0]->getPosition()-_p[1]->getPosition())){

}
ParticuleCableContact::ParticuleCableContact(std::vector<Particule *> p):ParticuleLinkContact(p),_length(Vector3D(_p[0]->getPosition()-_p[1]->getPosition())){

}

void ParticuleCableContact::resolveVelocity(double time){
    //Nothing ---> Cable
}
void ParticuleCableContact::resolveInterpenetration(){
    Vector3D diff_pos=_p[0]->getPosition()-_p[1]->getPosition();
    //If length of cable is different from the difference we set it to the reference
    if(norm(diff_pos)!=norm(_length)){
        _p[0]->setPosition(_p[1]->getPosition()+_length);
    }
}