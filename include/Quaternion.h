#ifndef QUATERNION_H
#define QUATERNION_H

#include <iostream>
#include <cmath>
#include "Vector3D.h"

class Quaternion{
    public:
        Quaternion(double w,double x,double y,double z);

        //Getter:
        inline double getW(){return _w;}
        inline double getX(){return _x;}
        inline double getY(){return _y;}
        inline double getZ(){return _z;}

        //Setter:
        inline void setW(double w){_w=w;}
        inline void setX(double x){_x=x;}
        inline void setY(double y){_y=y;}
        inline void setZ(double z){_z=z;}

        //Méthodes:
        void normalize();
        void makeRotation(Vector3D v);
        void updateAngularVelocity(Vector3D v,double dt);

        //Operator:
        void operator*= (Quaternion & q);
        void operator* (double a);
        void operator=  (Quaternion & q);
        
    protected:
        double _w,_x,_y,_z;
};

Quaternion operator* (Quaternion & q1,Quaternion &q2);
Quaternion operator* (Quaternion & q1,double a);

#endif