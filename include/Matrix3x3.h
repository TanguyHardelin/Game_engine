#ifndef MATRIX3X3_H
#define MATRIX3X3_H

#include <iostream>
#include "Vector3D.h"
#include "Quaternion.h"

class Matrix3x3{
    public:
        //Constructor:
        Matrix3x3(double a,double b,double c,double d,double e,double f,double g,double h,double i);

        //Setter:
        void setValues(double a,double b,double c,double d,double e,double f,double g,double h,double i);
        
        //Mathematical method:
        Matrix3x3 inverse();
        Matrix3x3 transpose();
        
        double Det();       //Calcule le déterminant de la matrice

        static Matrix3x3 setOrientation(Quaternion & q);

        double& operator[] (int index);
        void operator=(Matrix3x3 a);
        void operator=(double value);

        void operator+=(Matrix3x3 & a);
        void operator-=(Matrix3x3 & a);
        void operator*=(Matrix3x3 & a);

        void operator+=(double a);
        void operator-=(double a);
        void operator*=(double a);


        

        //Other:
        void display();
    protected:
        double _a,_b,_c,_d,_e,_f,_g,_h,_i;

};


bool operator==(Matrix3x3 a, Matrix3x3 b);
bool operator!=(Matrix3x3 a, Matrix3x3 b);

Matrix3x3 operator+(Matrix3x3  a, Matrix3x3 b);
Matrix3x3 operator-(Matrix3x3  a, Matrix3x3 b);
Matrix3x3 operator*(Matrix3x3  a, Matrix3x3 b);
Matrix3x3 operator+(Matrix3x3  a, double k);
Matrix3x3 operator-(Matrix3x3  a, double k);
Matrix3x3 operator*(Matrix3x3  a, double k);

Vector3D operator*(Matrix3x3  a,Vector3D v);
Vector3D operator*(Vector3D v,Matrix3x3  a);

#endif