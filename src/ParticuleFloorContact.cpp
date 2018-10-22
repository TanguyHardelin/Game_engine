#include "ParticuleFloorContact.h"

using namespace std;

ParticuleFloorContact::ParticuleFloorContact(std::vector<Particule *> p,double restitution):ParticuleContact(p,restitution){

}
ParticuleFloorContact::ParticuleFloorContact(std::vector<Particule *> p):ParticuleContact(p){


}

Vector3D ParticuleFloorContact::calculateVs(){
        _n=(_p[0]->getSpeed()).normalize();

        //cout<<"_p[0]->getSpeed() ";_p[0]->getSpeed().display();cout<<endl;
        //cout<<"_p[1]->getPosition() ";_p[1]->getPosition().display();cout<<endl;
        //cout<<"_n ";_n.display();cout<<endl;
        //cout<<"((_p[0]->getSpeed())*_n) ";((_p[0]->getSpeed())*_n).display();cout<<endl;

        return ((_p[0]->getSpeed())*_n)*(-1.0f);

}
void ParticuleFloorContact::resolveVelocity(double time){
         Vector3D vs=calculateVs()*_restitution*-1.0f;
        //cout<<"VS"<<endl;
        //vs.display();
        Vector3D new_speed=(vs);
        _p[0]->setSpeed(new_speed);
        //cout<<"New speed: ";new_speed.display();cout<<endl;

}
void ParticuleFloorContact::resolveInterpenetration(){
        Vector3D pos=_p[0]->getPosition();
        pos[1]=0;
        _p[0]->setPosition(pos);
}