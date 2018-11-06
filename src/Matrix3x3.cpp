#include "Matrix3x3.h"

//Constructor:
Matrix3x3::Matrix3x3(double a,double b,double c,double d,double e,double f,double g,double h,double i){
    _a=a;
    _b=b;
    _c=c;
    _d=d;
    _e=e;
    _f=f;
    _g=g;
    _h=h;
    _i=i;
}

//Setter:
void Matrix3x3::setValues(double a,double b,double c,double d,double e,double f,double g,double h,double i){
    _a=a;
    _b=b;
    _c=c;
    _d=d;
    _e=e;
    _f=f;
    _g=g;
    _h=h;
    _i=i;
}

//Mathematical method:
Matrix3x3 Matrix3x3::inverse(){
    return Matrix3x3(0,0,0,0,0,0,0,0,0);
}
double& Matrix3x3::operator[] (int index){
    switch(index){
        case 0:
        return _a;
        break;
        case 1:
        return _b;
        break;
        case 2:
        return _c;

        case 3:
        return _d;
        break;
        case 4:
        return _e;
        break;
        case 5:
        return _f;

        case 6:
        return _g;
        break;
        case 7:
        return _h;
        break;
        case 8:
        return _i;

        default:
        throw std::runtime_error( "Index > 8: Impossible in Matrix 3x3");
    }
}
void Matrix3x3::operator=(Matrix3x3 a){
    _a=a[0];
    _b=a[1];
    _c=a[2];
    _d=a[3];
    _e=a[4];
    _f=a[5];
    _g=a[6];
    _h=a[7];
    _i=a[8];
}
void Matrix3x3::operator=(double value){
    _a=value;
    _b=value;
    _c=value;
    _d=value;
    _e=value;
    _f=value;
    _g=value;
    _h=value;
    _i=value;
}

void Matrix3x3::operator+=(Matrix3x3 const& a){
    _a+=a[0];
    _b+=a[1];
    _c+=a[2];
    _d+=a[3];
    _e+=a[4];
    _f+=a[5];
    _g+=a[6];
    _h+=a[7];
    _i+=a[8];
}
void Matrix3x3::operator-=(Matrix3x3 const& a){
    _a-=a[0];
    _b-=a[1];
    _c-=a[2];
    _d-=a[3];
    _e-=a[4];
    _f-=a[5];
    _g-=a[6];
    _h-=a[7];
    _i-=a[8];
}
void Matrix3x3::operator*=(Matrix3x3 const& a){
    //TODO
    _a=_a*a[0]+_b*a[3]+_c*a[6];
    _b=_a*a[1]+_b*a[4]+_c*a[7];
    _c=_a*a[2]+_b*a[5]+_c*a[8];
    _d=_a*a[0]+_b*a[3]+_c*a[6];
    _e=_a*a[1]+_b*a[4]+_c*a[7];
    _f=_a*a[0]+_b*a[3]+_c*a[6];
    _g=_a*a[0]+_b*a[3]+_c*a[6];
    _h=_a*a[1]+_b*a[4]+_c*a[7];
    _i=_a*a[0]+_b*a[3]+_c*a[6];
}

void Matrix3x3::operator+=(double a){
    _a+=a;
    _b+=a;
    _c+=a;
    _d+=a;
    _e+=a;
    _f+=a;
    _g+=a;
    _h+=a;
    _i+=a;
}
void Matrix3x3::operator-=(double a){
    _a-=a;
    _b-=a;
    _c-=a;
    _d-=a;
    _e-=a;
    _f-=a;
    _g-=a;
    _h-=a;
    _i-=a;
}
void Matrix3x3::operator*=(double a){
    _a*=a;
    _b*=a;
    _c*=a;
    _d*=a;
    _e*=a;
    _f*=a;
    _g*=a;
    _h*=a;
    _i*=a;
}


//Other:
void display() const;