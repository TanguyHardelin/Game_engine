#include "Matrix3x3.h"

using namespace std;

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
    double Determinant=Det();
    Matrix3x3 matrix(0,0,0,0,0,0,0,0,0);
    if(Determinant!=0){
        matrix[0]=_e*_i-_f*_h;
        matrix[1]=_c*_h-_b*_i;
        matrix[2]=_b*_f-_c*_e;

        matrix[3]=_f*_g-_d*_i;
        matrix[4]=_a*_i-_c*_g;
        matrix[5]=_c*_d-_a*_f;

        matrix[6]=_d*_h-_e*_g;
        matrix[7]=_b*_g-_a*_h;
        matrix[8]=_a*_e-_b*_d;

        matrix*=1/Determinant;
    }
    

    return matrix;
}
double Matrix3x3::Det(){
    return _a*_e*_i+_d*_h*_c+_g*_b*_f-_a*_h*_f-_g*_e*_c-_d*_b*_i;
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

void Matrix3x3::operator+=(Matrix3x3 & a){
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
void Matrix3x3::operator-=(Matrix3x3 & a){
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
void Matrix3x3::operator*=(Matrix3x3 & a){
    _a=_a*a[0]+_b*a[3]+_c*a[6];
    _b=_a*a[1]+_b*a[4]+_c*a[7];
    _c=_a*a[2]+_b*a[5]+_c*a[8];

    _d=_d*a[0]+_e*a[3]+_f*a[6];
    _e=_d*a[1]+_e*a[4]+_f*a[7];
    _f=_d*a[0]+_e*a[3]+_f*a[6];
    
    _g=_g*a[0]+_h*a[3]+_i*a[6];
    _h=_g*a[1]+_h*a[4]+_i*a[7];
    _i=_g*a[0]+_h*a[3]+_i*a[6];
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
void Matrix3x3::display(){
    Matrix3x3 m=*this;
    cout<<"------------------"<<endl;
    cout<<"( ";

    for(int i=0;i<9;i++){
        if(i!=0 && i%3==0){
            cout << m[i];
            cout<<" )"<<endl;
            cout<<"( ";
        }
        else{
            cout << m[i] <<" ,";
        }
    }
    cout<<" )"<<endl;

    cout<<"------------------"<<endl;
}
bool operator==(Matrix3x3 & a, Matrix3x3 & b){
    for(int i=0;i<9;i++){
        if(a[i]!=b[i]){
            return false;
        }
    }
    return true;
}
bool operator!=(Matrix3x3 &a, Matrix3x3 &b){
    for(int i=0;i<9;i++){
        if(a[i]==b[i]){
            return false;
        }
    }
    return true;
}
Matrix3x3 operator+(Matrix3x3  &a, Matrix3x3 &b){
    Matrix3x3 tmp(a);
    tmp+=b;
    return tmp;
}
Matrix3x3 operator-(Matrix3x3  &a, Matrix3x3 &b){
    Matrix3x3 tmp(a);
    tmp-=b;
    return tmp;
}
Matrix3x3 operator*(Matrix3x3  &a, Matrix3x3 &b){
    Matrix3x3 tmp(a);
    tmp*=b;
    return tmp;
}
Matrix3x3 operator+(Matrix3x3  &a, double k){
    Matrix3x3 tmp(a);
    tmp+=k;
    return tmp;
}
Matrix3x3 operator-(Matrix3x3  &a, double k){
    Matrix3x3 tmp(a);
    tmp-=k;
    return tmp;
}
Matrix3x3 operator*(Matrix3x3  &a, double k){
    Matrix3x3 tmp(a);
    tmp*=k;
    return tmp;
}