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
Matrix3x3 Matrix3x3::transpose(){
    Matrix3x3 matrix(0,0,0,0,0,0,0,0,0);

    matrix[0]=_a;
    matrix[1]=_d;
    matrix[2]=_g;
    matrix[3]=_b;
    matrix[4]=_e;
    matrix[5]=_h;
    matrix[6]=_c;
    matrix[7]=_f;
    matrix[8]=_i;

    return matrix;
}
Matrix3x3 Matrix3x3::setOrientation(Quaternion & q){
    Matrix3x3 matrix(0,0,0,0,0,0,0,0,0);

    matrix[0]= 1-(2*q.getY()*q.getY()+2*q.getZ()*q.getZ());
    matrix[1]= 2*q.getX()*q.getY()+2*q.getZ()*q.getW();
    matrix[2]= 2*q.getX()*q.getZ()-2*q.getY()*q.getW();

    matrix[3]= 2*q.getX()*q.getY()-2*q.getZ()*q.getW();
    matrix[4]= 1-(2*q.getX()*q.getX()+2*q.getZ()*q.getZ());
    matrix[5]= 2*q.getY()*q.getZ()+2*q.getX()*q.getW();

    matrix[6]= 2*q.getX()*q.getZ()+2*q.getY()*q.getW();
    matrix[7]= 2*q.getY()*q.getZ()-2*q.getX()*q.getW();
    matrix[8]= 1-(2*q.getX()*q.getX()+2*q.getY()*q.getY());

    /*
    return Matrix3x3(
        1-(2*q.getY()*q.getY()+2*q.getZ()*q.getZ())     , 2*q.getX()*q.getY()+2*q.getZ()*q.getW()    , 2*q.getX()*q.getZ()-2*q.getY()*q.getW(),
        2*q.getX()*q.getY()-2*q.getZ()*q.getW()         , 1-(2*q.getX()*q.getX()+2*q.getZ()*q.getZ()), 2*q.getY()*q.getZ()-2*q.getX()*q.getW(),
        2*q.getX()*q.getZ()+2*q.getY()*q.getW()         , 2*q.getY()*q.getZ()-2*q.getX()*q.getW()    , 1-(2*q.getX()*q.getX()+2*q.getY()*q.getY())
    );
    */

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

void Matrix3x3::operator+=(Matrix3x3 a){
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
void Matrix3x3::operator-=(Matrix3x3 a){
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
void Matrix3x3::operator*=(Matrix3x3 a){
    Matrix3x3 r(0,0,0,0,0,0,0,0,0);

    r[0]=_a*a[0]+_b*a[3]+_c*a[6];
    r[1]=_a*a[1]+_b*a[4]+_c*a[7];
    r[2]=_a*a[2]+_b*a[5]+_c*a[8];

    r[3]=_d*a[0]+_e*a[3]+_f*a[6];
    r[4]=_d*a[1]+_e*a[4]+_f*a[7];
    r[5]=_d*a[2]+_e*a[5]+_f*a[8];
    
    r[6]=_g*a[0]+_h*a[3]+_i*a[6];
    r[7]=_g*a[1]+_h*a[4]+_i*a[7];
    r[8]=_g*a[2]+_h*a[5]+_i*a[8];

    _a=r[0];
    _b=r[1];
    _c=r[2];
    _d=r[3];
    _e=r[4];
    _f=r[5];
    _g=r[6];
    _h=r[7];
    _i=r[8];
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

Vector3D operator*(Matrix3x3  a,Vector3D v){
    Vector3D r(0,0,0);
    r[0]=a[0]*v[0]+a[1]*v[1]+a[2]*v[2];
    r[1]=a[3]*v[0]+a[4]*v[1]+a[5]*v[2];
    r[2]=a[6]*v[0]+a[7]*v[1]+a[8]*v[2];

    return r;
}
Vector3D operator*(Vector3D v,Matrix3x3  a){
    Vector3D r(0,0,0);
    r[0]=a[0]*v[0]+a[3]*v[1]+a[6]*v[2];
    r[1]=a[1]*v[0]+a[4]*v[1]+a[7]*v[2];
    r[2]=a[2]*v[0]+a[5]*v[1]+a[8]*v[2];

    return r;
}

//Other:
void Matrix3x3::display(){
    Matrix3x3 m=*this;
    cout<<"------------------"<<endl;
    cout<<"( ";

    for(int i=0;i<9;i++){
        if(i!=0 && i%3==0){
            cout<<" )"<<endl;
            cout<<"( ";
            cout << m[i];
        }
        else{
            cout << m[i];
        }
        if((i+1)%3!=0)cout<<" ,";
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
Matrix3x3 operator+(Matrix3x3  a, Matrix3x3 b){
    Matrix3x3 tmp(a);
    tmp+=b;
    return tmp;
}
Matrix3x3 operator-(Matrix3x3  a, Matrix3x3 b){
    Matrix3x3 tmp(a);
    tmp-=b;
    return tmp;
}
Matrix3x3 operator*(Matrix3x3  a, Matrix3x3 b){
    Matrix3x3 tmp(a);
    tmp*=b;
    return tmp;
}
Matrix3x3 operator+(Matrix3x3  a, double k){
    Matrix3x3 tmp(a);
    tmp+=k;
    return tmp;
}
Matrix3x3 operator-(Matrix3x3  a, double k){
    Matrix3x3 tmp(a);
    tmp-=k;
    return tmp;
}
Matrix3x3 operator*(Matrix3x3  a, double k){
    Matrix3x3 tmp(a);
    tmp*=k;
    return tmp;
}