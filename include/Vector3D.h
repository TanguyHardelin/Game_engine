#ifndef VECTORD_H
#define VECTORD_H

#include <iostream>
#include <cmath>

class Vector3D{
    public:
    //Constructors:
    Vector3D(double x,double y,double z);
    Vector3D(Vector3D & v);

    //Getters:
    inline double getX(){return _x;};
    inline double getY(){return _y;};
    inline double getZ(){return _z;};

    //Setters:
    inline void setX(double x){_x=x;};
    inline void setY(double y){_y=y;};
    inline void setZ(double z){_z=z;};

    //Methods:
    void display();

    double norm();
    double scalarProduct(Vector3D & v);
    Vector3D projectOn(Vector3D & v);
    Vector3D normalize();
    double distanceOf(Vector3D & v);
    Vector3D vectorProduct(Vector3D & v);


    //Operators:
    double& operator[] (int index);

    void operator+=(Vector3D & a);
    void operator-=(Vector3D & a);
    void operator*=(Vector3D & a);
    void operator/=(Vector3D & a);

    void operator+=(double a);
    void operator-=(double a);
    void operator*=(double a);
    void operator/=(double a);

    protected:
    double  _x,_y,_z;
};

//Others operators:
bool operator==(Vector3D & a, Vector3D & b);
bool operator!=(Vector3D &a, Vector3D &b);

Vector3D operator+(Vector3D  &a, Vector3D &b);
Vector3D operator-(Vector3D  &a, Vector3D &b);
Vector3D operator*(Vector3D  &a, Vector3D &b);
Vector3D operator/(Vector3D  &a, Vector3D &b);
Vector3D operator+(Vector3D  &a,double k);
Vector3D operator-(Vector3D  &a,double k);
Vector3D operator/(Vector3D  &a,double k);
Vector3D operator*(Vector3D  &a,double k);

#endif