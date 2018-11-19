#include "Quaternion.h"
#include "Vector3D.h"

using namespace std;

Quaternion::Quaternion(double w,double x,double y,double z):_w(w),_x(x),_y(y),_z(z){

}

void Quaternion::normalize(){
    double d=_w*_w+_x*_x+_y*_y+_z*_z;
    if(d!=0 && d!=1){
        d=1/sqrt(d);
        _w*=d;
        _x*=d;
        _y*=d;
        _z*=d;
    }
    else{
        _w=1;
        _x=_y=_z=0;
    }
}
void Quaternion::operator*= (Quaternion const& q){
    Quaternion result(0,0,0,0);

    result.setW(_w*q.getW()-_x*q.getX()-_y*q.getY()-_z*q.getZ());
    result.setX(_w*q.getX()+q.getW()*_x+_y*q.getZ()-_z*q.getY());  
    result.setY(_w*q.getY()+q.getW()*_y+_z*q.getX()-_x*q.getZ());
    result.setZ(_w*q.getZ()+q.getW()*_z+_x*q.getY()-_y*q.getX());

    _w=result.getW();
    _x=result.getX();
    _y=result.getY();
    _z=result.getZ();
}
void Quaternion::operator+=  (Quaternion const& q){
    _w+=q.getW();
    _x+=q.getX();
    _y+=q.getY();
    _z+=q.getZ();
}
void Quaternion::operator=  (Quaternion const& q){
    _w=q.getW();
    _x=q.getX();
    _y=q.getY();
    _z=q.getZ();
}
void Quaternion::makeRotation(Vector3D v){
    Quaternion q(0,v[0],v[1],v[2]);
    
    Quaternion q0(_w,_x,_y,_z);
    q0*=q;

    _w=q0.getW();
    _x=q0.getX();
    _y=q0.getY();
    _z=q0.getZ();
}
void Quaternion::updateAngularVelocity(Vector3D v,double dt){
    Quaternion O1(_w,_x,_y,_z);
    Quaternion w(1,v[0],v[1],v[2]);
    Quaternion result(0,0,0,0);
    

    result+= w * O1 * (dt/2.0f);
    result.normalize();

/*
    cout<<"result: ";result.display();
    cout<<" w * O1 * (dt/2.0f): ";( w * O1 * (dt/2.0f)).display();
*/

    _w=result.getW();
    _x=result.getX();
    _y=result.getY();
    _z=result.getZ();
}

void Quaternion::operator*= (double a){
    _w*=a;
    _x*=a;
    _y*=a;
    _z*=a;
}

Quaternion operator+ (Quaternion const& q1,Quaternion const&q2){
    Quaternion q(0,0,0,0);
    q+=q2;
    return q;
}



Quaternion operator* (Quaternion const& q1,Quaternion const&q2){
    Quaternion q(q1);
    q*=q2;
    return q;
}

Quaternion operator* (Quaternion const& q1,double a){
    Quaternion q(q1);
    q*=a;
    return q;
}

Quaternion operator* (double a,Quaternion const& q1){
    return q1*a;
}

void Quaternion::display() const{
    cout<<"w: "<<_w<<"\t\t x: "<<_x<<"\t\t y: "<<_y<<"\t\t z: "<<_z<<endl;
}