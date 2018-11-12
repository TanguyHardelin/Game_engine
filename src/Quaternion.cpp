#include "Quaternion.h"

Quaternion::Quaternion(double w,double x,double y,double z):_w(w),_x(x),_y(y),_z(z){

}

void Quaternion::normalize(){
    double d=_w*_w+_x*_x+_y*_y+_z*_z;
    if(d!=0){
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
void Quaternion::operator *= (Quaternion & q){
    _w=_w*q.getW()-_x*q.getX()-_y*q.getY()-_z*q.getZ();
    _x=_w*q.getX()+q.getW()*_x+_y*q.getZ()-_z*q.getY();  
    _y=_w*q.getY()+q.getW()*_y+_z*q.getX()-_x*q.getZ();
    _z=_w*q.getZ()+q.getW()*_z+_x*q.getY()-_y*q.getX();
}
void Quaternion::makeRotation(Vector3D v){

}
void Quaternion::updateAngularVelocity(Vector3D v,double dt){

}