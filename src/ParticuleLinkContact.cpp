#include "ParticuleLinkContact.h"

using namespace std;

ParticuleLinkContact::ParticuleLinkContact(std::vector<Particule *> p,double restitution):ParticuleContact(p,restitution),_length(Vector3D(_p[0]->getPosition()-_p[1]->getPosition())){
}

ParticuleLinkContact::ParticuleLinkContact(std::vector<Particule *> p):ParticuleContact(p),_length(Vector3D(_p[0]->getPosition()-_p[1]->getPosition())){
}

Vector3D ParticuleLinkContact::calculateVs(){
    Vector3D diff_pos=_p[0]->getPosition()-_p[1]->getPosition();
    _n=diff_pos.normalize();
    return (_n*norm(diff_pos-_length)*-1);

}
void ParticuleLinkContact::resolveVelocity(double time){
    Vector3D diff_pos=_p[0]->getPosition()-_p[1]->getPosition();
    if(norm(diff_pos)>norm(_length)+norm(_length)/100.0f*10.0f || norm(diff_pos)<norm(_length)-norm(_length)/100.0f*10.0f){
        Vector3D vs=calculateVs()*_restitution;
        //vs.display();
        Vector3D new_speed=(vs+_p[0]->getSpeed());
        //Vector3D impulsion=vs*_p[0]->getMass();
        //Vector3D new_speed=(_p[0]->getSpeed()+impulsion*1.0f/_p[0]->getMass());
        _p[0]->setSpeed(new_speed);
        //_p[1]->setSpeed(vs+_p[1]->getSpeed()*-1);
        //cout<<"New speed: ";new_speed.display();cout<<endl;
        //impulsion.display();
    }
}
void ParticuleLinkContact::resolveInterpenetration(){
    Vector3D diff_pos=_p[0]->getPosition()-_p[1]->getPosition();
    /*
    if(norm(diff_pos)!=norm(_length)){
        _p[0]->setPosition(_p[1]->getPosition()+_length);
    }
    */
    
    if(norm(diff_pos)>norm(_length)+norm(_length)/100.0f*10.0f){
        _p[0]->setPosition(_p[1]->getPosition()+_length.normalize()*(norm(_length)+norm(_length)/100.0f*10.0f));
        _p[0]->setSpeed(_p[0]->getSpeed()*-1);
    }
    if(norm(diff_pos)<norm(_length)-norm(_length)/100.0f*10.0f){
        _p[0]->setPosition(_p[1]->getPosition()+_length.normalize()*(norm(_length)-norm(_length)/100.0f*10.0f));
        _p[0]->setSpeed(_p[0]->getSpeed()*-1);
    }
    
}