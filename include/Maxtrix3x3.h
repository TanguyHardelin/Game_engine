#ifndef MATRIX3X3_H
#define MATRIX3X3_H

class Matrix3x3{
    public:
        //Constructor:
        Matrix3x3(float a,float b,float c,float d,float e,float f,float g,float h,float i);

        //Setter:
        void setValues(float a,float b,float c,float d,float e,float f,float g,float h,float i);
        //Getter:
        Matrix3x3 getValues(Matrix3x3 & result);

        //Mathematical method:
        Matrix3x3 inverse();

        double& operator[] (int index);
        void operator=(Vector3D a);
        void operator=(double value);

        void operator+=(Vector3D const& a);
        void operator-=(Vector3D const& a);
        void operator*=(Vector3D const& a);
        void operator/=(Vector3D const& a);

        void operator+=(double a);
        void operator-=(double a);
        void operator*=(double a);
        void operator/=(double a);

        //Other:
        void display() const;
    protected:
        float _a,_b,_c,_d,_e,_f,_g,_h,_i;

};


bool operator==(Matrix3x3 const& a, Matrix3x3 const& b);
bool operator!=(Matrix3x3 const&a, Matrix3x3 const&b);

Matrix3x3 operator+(Matrix3x3  const&a, Matrix3x3 const&b);
Matrix3x3 operator-(Matrix3x3  const&a, Matrix3x3 const&b);
Matrix3x3 operator*(Matrix3x3  const&a, Matrix3x3 const&b);
Matrix3x3 operator/(Matrix3x3  const&a, Matrix3x3 const&b);
Matrix3x3 operator+(Matrix3x3  const&a, double k);
Matrix3x3 operator-(Matrix3x3  const&a, double k);
Matrix3x3 operator/(Matrix3x3  const&a, double k);
Matrix3x3 operator*(Matrix3x3  const&a, double k);

#endif