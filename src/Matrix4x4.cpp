#include "Matrix4x4.h"

using namespace std;

//Constructor:
Matrix4x4::Matrix4x4(double a,double b,double c,double d,double e,double f,double g,double h,double i,double j,double k,double l){
    _values[0] = a;
    _values[1] = b;
    _values[2] = c;
    _values[3] = d;

    _values[4] = e;
    _values[5] = f;
    _values[6] = g;
    _values[7] = h;

    _values[8] = i;
    _values[9] = j;
    _values[10] = k;
    _values[11] = l;

    _values[12] = 0;
    _values[13] = 0;
    _values[14] = 0;
    _values[15] = 1; 
}

Matrix4x4::Matrix4x4(Matrix4x4 & a){
    for(int i=0;i<16;i++){
        _values[i]=a[i];
    }
}

//Mathematical method:
Matrix4x4 Matrix4x4::inverse(){
    Matrix4x4 r(0,0,0,0,0,0,0,0,0,0,0,0);

    if(Det() != 0){
        r[0] = -1.0f*_values[9]*_values[6]+_values[5]*_values[10];
        r[1] = _values[9]*_values[2]-_values[1]*_values[10];
        r[2] = -1.0f*_values[5]*_values[2]+_values[1]*_values[6];
        r[3] = _values[9]*_values[6]*_values[3]-_values[5]*_values[10]*_values[3]-_values[9]*_values[2]*_values[7]+_values[1]*_values[10]*_values[7]+_values[5]*_values[2]*_values[11]-_values[1]*_values[6]*_values[11];

        r[4] = _values[8]*_values[6]-_values[4]*_values[10];
        r[5] = -1.0f*_values[8]*_values[2]+_values[0]*_values[10];
        r[6] = _values[4]*_values[2]-_values[0]*_values[6];
        r[7] = -1.0f*_values[8]*_values[6]*_values[3]+_values[4]*_values[10]*_values[3]+_values[8]*_values[2]*_values[7]-_values[0]*_values[10]*_values[7]-_values[4]*_values[2]*_values[11]+_values[0]*_values[6]*_values[11];

        r[8] = -1.0f*_values[8]*_values[5]+_values[4]*_values[9];
        r[9] = _values[8]*_values[1]-_values[0]*_values[9];
        r[10] = -1.0f*_values[4]*_values[1]+_values[0]*_values[5];

        //FAUX !
        r[11] = _values[8]*_values[5]*_values[3]-_values[4]*_values[9]*_values[3]-_values[8]*_values[1]*_values[7]+_values[0]*_values[9]*_values[7]+_values[4]*_values[1]*_values[11]-_values[0]*_values[5]*_values[11];

        r[12] = 0;
        r[13] = 0;
        r[14] = 0;
        r[15] = 1;

        r*=(1/Det());
    }
  

    return r;
}

double Matrix4x4::Det(){
    return -1*_values[8]*_values[5]*_values[2]+_values[4]*_values[9]*_values[2]+_values[8]*_values[1]*_values[6]-_values[0]*_values[9]*_values[6]-_values[4]*_values[1]*_values[10]+_values[0]*_values[5]*_values[10];
}

Matrix4x4 Matrix4x4::setOrientation(Quaternion & q){
    Matrix3x3 tmp=Matrix3x3::setOrientation(q);
    Matrix4x4 r(0,0,0,0,0,0,0,0,0,0,0,1);

    r[0]=tmp[0];
    r[1]=tmp[1];
    r[2]=tmp[2];
    r[3]=q.getX();

    r[4]=tmp[3];
    r[5]=tmp[4];
    r[6]=tmp[5];
    r[7]=q.getY();

    r[8]=tmp[6];
    r[9]=tmp[7];
    r[10]=tmp[8];
    r[11]=q.getZ();

    r[12] = 0;
    r[13] = 0;
    r[14] = 0;
    r[15] = 1;

    return r;
}

double& Matrix4x4::operator[] (int index){
    return _values[index];
}
void Matrix4x4::operator=(Matrix4x4 a){
    for(int i=0;i<16;i++){
        _values[i]=a[i];
    }
}
void Matrix4x4::operator=(double value){
    for(int i=0;i<16;i++){
        _values[i]=value;
    }
}
void Matrix4x4::operator+=(Matrix4x4 & a){
    for(int i=0;i<16;i++){
        _values[i]+=a[i];
    }
}
void Matrix4x4::operator-=(Matrix4x4 & a){
    for(int i=0;i<16;i++){
        _values[i]-=a[i];
    }
}
void Matrix4x4::operator*=(Matrix4x4 & a){
    Matrix4x4 r(0,0,0,0,0,0,0,0,0,0,0,0);
    
    r[0]=_values[0]*a[0]+_values[1]*a[4]+_values[2]*a[8];
    r[1]=_values[0]*a[1]+_values[1]*a[5]+_values[2]*a[9];
    r[2]=_values[0]*a[2]+_values[1]*a[6]+_values[2]*a[10];
    r[3]=_values[0]*a[3]+_values[1]*a[7]+_values[2]*a[11]+_values[3]*a[15];

    r[4]=_values[4]*a[0]+_values[5]*a[4]+_values[6]*a[8];
    r[5]=_values[4]*a[1]+_values[5]*a[5]+_values[6]*a[9];
    r[6]=_values[4]*a[2]+_values[5]*a[6]+_values[6]*a[10];
    r[7]=_values[4]*a[3]+_values[5]*a[7]+_values[6]*a[11]+_values[7]*a[15];

    r[8]=_values[8]*a[0]+_values[9]*a[4]+_values[10]*a[8];
    r[9]=_values[8]*a[1]+_values[9]*a[5]+_values[10]*a[9];
    r[10]=_values[8]*a[2]+_values[9]*a[6]+_values[10]*a[10];
    r[11]=_values[8]*a[3]+_values[9]*a[7]+_values[10]*a[11]+_values[11]*a[15];

    r[15]=_values[15]*a[15];

    for(int i=0;i<16;i++){
        _values[i]=r[i];
    }

    
}
void Matrix4x4::operator+=(double a){
    for(int i=0;i<16;i++){
        _values[i]+=a;
    }
}
void Matrix4x4::operator-=(double a){
    for(int i=0;i<16;i++){
        _values[i]-=a;
    }
}
void Matrix4x4::operator*=(double a){
    for(int i=0;i<16;i++){
        _values[i]*=a;
    }
}

//Other:
void Matrix4x4::display(){
    Matrix4x4 m=*this;
    cout<<"------------------"<<endl;
    cout<<"( ";

    for(int i=0;i<16;i++){
        if(i!=0 && i%4==0){
            cout<<" )"<<endl;
            cout<<"( ";
            cout << m[i];
        }
        else{
            cout << m[i];
        }
        if((i+1)%4!=0)cout<<" ,";
    }
    cout<<" )"<<endl;

    cout<<"------------------"<<endl;
}

bool operator==(Matrix4x4 & a, Matrix4x4 & b){
    for(int i=0;i<16;i++){
        if(a[i]!=b[i]){
            return false;
        }
    }
    return true;
}
bool operator!=(Matrix4x4 &a, Matrix4x4 &b){
    for(int i=0;i<16;i++){
        if(a[i]==b[i]){
            return false;
        }
    }
    return true;
}

Matrix4x4 operator+(Matrix4x4  &a, Matrix4x4 &b){
    Matrix4x4 r(a);
    r+=b;
    return r;
}
Matrix4x4 operator-(Matrix4x4  &a, Matrix4x4 &b){
    Matrix4x4 r(a);
    r-=b;
    return r;
}
Matrix4x4 operator*(Matrix4x4  &a, Matrix4x4 &b){
    Matrix4x4 r(a);
    r*=b;
    return r;
}
Matrix4x4 operator+(Matrix4x4  &a, double k){
    Matrix4x4 r(a);
    r+=k;
    return r;
}
Matrix4x4 operator-(Matrix4x4  &a, double k){
    Matrix4x4 r(a);
    r-=k;
    return r;
}
Matrix4x4 operator*(Matrix4x4  &a, double k){
    Matrix4x4 r(a);
    r*=k;
    return r;
}

Vector3D operator*(Matrix4x4  &a,Vector3D v){
    Vector3D r(0,0,0);
    
    r[0]=a[0]*v[0]+a[1]*v[1]+a[2]*v[2];
    r[1]=a[4]*v[0]+a[5]*v[1]+a[6]*v[2];
    r[2]=a[8]*v[0]+a[9]*v[1]+a[10]*v[2];

    return r;
}