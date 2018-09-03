#include <iostream>

#include "Vector3D.h"
#include "UnitTests.h"

using namespace std;
void runTests(){

}
void runVector3DTest(){
    Vector3D v(1,2,3),w(1,4,1);

    Vector3D p=v+w;

    p.display();
}