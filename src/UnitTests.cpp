#include <iostream>

#include "Vector3D.h"
#include "Utils.h"
#include "UnitTests.h"
#include "Matrix3x3.h"
#include "Matrix4x4.h"
#include "Quaternion.h"

using namespace std;

void runTests(){
    //runVector3DTest();
    //runMaxtrix3x3Test();
    //runMaxtrix4x4Test();
    runQuaternionTest();
}

void runQuaternionTest(){
    Quaternion t(1,1,2,3);
    Quaternion te(2,5,3,4);

    cout<<"t: ";t.display();
    cout<<"te: ";te.display();
    t*=te;
    cout<<"t*te: ";t.display();

    t.normalize();
    Matrix3x3::setOrientation(t).transpose().display();

    t.normalize();
}

void runMaxtrix3x3Test(){
    log("Matrix 3x3:");
    Matrix3x3 A(1,2,3,4,5,6,7,8,9);

    log("A");
    A.display();

    Matrix3x3 B(11,20,30,7,45,2,13,8,1);

    log("B");
    B.display();

    log("B inverse");
    B.inverse().display();

    log("A inverse");
    A.inverse().display();

    log("B transpose");
    B.transpose().display();

    log("A transpose");
    A.transpose().display();

    log("A*B");
    (A*B).display();

    log("B*A");
    (B*A).display();

    Vector3D v0(4,5,6);
    log("v0");
    v0.display();

    Vector3D v1(11,35,45);
    log("v1");
    v1.display();

    log("A*v0");
    (A*v0).display();

    log("A*v1");
    (A*v1).display();

    log("B*v0");
    (B*v0).display();

    log("B*v1");
    (B*v1).display();
    
}

void runMaxtrix4x4Test(){
    log("Matrix 4x4:");
    Matrix4x4 A(1,2,3,4,5,6,7,8,9,10,11,12);

    log("A");
    A.display();

    Matrix4x4 B(11,20,30,6,7,45,2,5,13,8,1,15);

    log("B");
    B.display();

    log("B inverse");
    B.inverse().display();

    log("A inverse");
    A.inverse().display();


    log("B Det");
    cout<<B.Det()<<endl;

    log("A Det");
    cout<<A.Det()<<endl;



    log("A*B");
    (A*B).display();

    log("B*A");
    (B*A).display();

    Vector3D v0(4,5,6);
    log("v0");
    v0.display();

    Vector3D v1(11,35,45);
    log("v1");
    v1.display();

    log("A*v0");
    (A*v0).display();

    log("A*v1");
    (A*v1).display();

    log("B*v0");
    (B*v0).display();

    log("B*v1");
    (B*v1).display();
    
}
void runVector3DTest(){
    Vector3D v(1,2,3),w(1,4,1);

    //Test of operator +
    Vector3D t(v+w);
    Vector3D t_v(2,6,4);
    log("runVector3DTest",v.toString()+"+"+w.toString()+"="+t.toString(),t==t_v);

    //Test of operator -
    t=Vector3D(v-w);
    t_v=Vector3D(0,-2,2);
    log("runVector3DTest",v.toString()+"-"+w.toString()+"="+t.toString(),t==t_v);

    //Test of operator *
    t=Vector3D(v*w);
    t_v=Vector3D(1,8,3);
    log("runVector3DTest",v.toString()+"*"+w.toString()+"="+t.toString(),t==t_v);

    t=Vector3D(v*5);
    t_v=Vector3D(5,10,15);
    log("runVector3DTest",v.toString()+"*5="+t.toString(),t==t_v);

    t=Vector3D(w*3);
    t_v=Vector3D(3,12,3);
    log("runVector3DTest",w.toString()+"*3="+t.toString(),t==t_v);

    //Test of operator /
    t=Vector3D(v/w);
    t_v=Vector3D(1,0.5,3);
    log("runVector3DTest",v.toString()+"-"+w.toString()+"="+t.toString(),t==t_v);

    //Test of projection 
    t=project(v,w);
    t_v=Vector3D(2/3.0f,8/3.0f,2/3.0f);
    log("runVector3DTest",v.toString()+"->"+w.toString()+"="+t.toString(),t==t_v);
    log("The expected result is  "+t_v.toString());
    log("The calculate result is "+t.toString());

    //Test of normalization
    t=normalize(v);
    t_v=Vector3D(0.267261,0.534522,0.801784);
    log("runVector3DTest","normalize(v)="+t.toString(),t==t_v);
    log("The expected result is  "+t_v.toString());
    log("The calculate result is "+t.toString());

    //Test of vectorial product
    t=vectorProduct(v,w);
    t_v=Vector3D(-10,2,2);
    log("runVector3DTest",v.toString()+"^"+w.toString()+"="+t.toString(),t==t_v);
    log("The expected result is  "+t_v.toString());
    log("The calculate result is "+t.toString());

    //Test of scalar product
    double t_scalarProduct=scalarProduct(v,w);
    double t_scalarProduct_v=12;
    log("runVector3DTest","v.w = 12",t_scalarProduct==t_scalarProduct_v);

    //Test of norm
    double t_norm=norm(v);
    double t_norm_v=3.74166;
    log("runVector3DTest","norm(v)",t_scalarProduct==t_scalarProduct_v);
    log("The expected result is  3.74166");
    ostringstream strs_norm_v;
    strs_norm_v << t_norm;
    string r_norm_v=strs_norm_v.str();
    log("The calculate result is "+r_norm_v);

    t_norm=norm(w);
    t_norm_v=4.24264;
    log("runVector3DTest","norm(w)",t_scalarProduct==t_norm_v);
    log("The expected result is  4.24264");
    ostringstream strs_norm_w;
    strs_norm_w << t_norm;
    string r_norm_w=strs_norm_w.str();
    log("The calculate result is "+r_norm_w);

    //Test of distance
    double t_distance=distance(v,w);
    double t_distance_v=8.60233;
    log("runVector3DTest","distance(v,w)",t_scalarProduct==t_distance_v);
    log("The expected result is  8.60233");
    ostringstream strs_distance;
    strs_distance << t_distance;
    string r_distance=strs_distance.str();
    log("The calculate result is "+r_distance);
    
}