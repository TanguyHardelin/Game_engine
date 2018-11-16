#ifndef MATRIX4X4_H
#define MATRIX4X4_H

#include <iostream>
#include "Vector3D.h"
#include "Quaternion.h"
#include "Matrix3x3.h"


class Matrix4x4{
    public:
        //Constructor:
        Matrix4x4(double a,double b,double c,double d,double e,double f,double g,double h,double i,double j,double k,double l);
        Matrix4x4(Matrix4x4 const & a);
        
        inline double get(int index) const{return _values[index];}

        //Mathematical method:
        Matrix4x4 inverse();
        
        double Det();       //Calcule le déterminant de la matrice

        static Matrix4x4 setOrientation(Quaternion & q);

        double& operator[] (int index);
        void operator=(Matrix4x4 a);
        void operator=(double value);

        void operator+=(Matrix4x4 & a);
        void operator-=(Matrix4x4 & a);
        void operator*=(Matrix4x4 & a);

        void operator+=(double a);
        void operator-=(double a);
        void operator*=(double a);


        

        //Other:
        void display();
    protected:
        double _values[16];

};


bool operator==(Matrix4x4 & a, Matrix4x4 & b);
bool operator!=(Matrix4x4 &a, Matrix4x4 &b);

Matrix4x4 operator+(Matrix4x4  &a, Matrix4x4 &b);
Matrix4x4 operator-(Matrix4x4  &a, Matrix4x4 &b);
Matrix4x4 operator*(Matrix4x4  &a, Matrix4x4 &b);
Matrix4x4 operator+(Matrix4x4  &a, double k);
Matrix4x4 operator-(Matrix4x4  &a, double k);
Matrix4x4 operator*(Matrix4x4  &a, double k);

Vector3D operator*(Matrix4x4  &a,Vector3D v);

#endif