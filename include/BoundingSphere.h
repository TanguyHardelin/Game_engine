#ifndef BOUNDING_SPHERE
#define BOUNDING_SPHERE 1

#include "Vector3D.h"

class BoundingSphere{
    public:
        BoundingSphere(Vector3D center,float radius);
        inline Vector3D getCenter() const{return _center;}
        inline float getRadius() const{return _radius;}

    protected:
        Vector3D _center;
        float _radius;
};

#endif