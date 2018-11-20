#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include <iostream>
#include "Vector3D.h"
#include "Matrix3x3.h"
#include "Quaternion.h"

class RigidBody{
    public:
        RigidBody(double mass,double linear_damping,double angular_damping,
        Vector3D center_of_gravity,Vector3D position,Vector3D linear_speed,Vector3D linear_acceleration,Vector3D angular_speed,
        Vector3D angular_acceleration,Quaternion orientation,Matrix3x3 transform_matrix,Matrix3x3 inverse_inertie_tensor,Vector3D size);
        
        //Getter:
        inline double getInverseMass() const{return _inverse_mass;}
        inline double getMass() const{return 1/_inverse_mass;}
        inline double getLinearDamping() const{return _linear_damping;}
        inline double getAngularDamping() const{return _angular_damping;}

        inline Vector3D getCenterOfGravity() const{return _center_of_gravity;}
        inline Vector3D getPosition() const{return _position;}
        inline Vector3D getLinearSpeed() const{return _linear_speed;}
        inline Vector3D getLinearAcceleration() const{return _linear_acceleration;}

        inline Vector3D getAngularSpeed() const{return _angular_speed;}
        inline Vector3D getAngularAcceleration() const{return _angular_acceleration;}


        inline Quaternion getOrientation() const{return _orientation;}
        inline Matrix3x3 getTransformMatrix() const{return _transform_matrix;}
        inline Matrix3x3 getInverseInertieTensor() const{return _inverse_inertie_tensor;}

        inline Vector3D getSize(){return _size;}

        //Methods:
        int update(double delta_t);              //Integrator
        void addForce(const Vector3D & force);
        void addForceAtPoint(const Vector3D & force, const Vector3D & point);
        void addForceAtBodyPoint(const Vector3D & force, const Vector3D & point);
        void clearAccums();

        void CalculateDerivedData();

        //Utils:
        static Vector3D localToWorld(Vector3D v,Matrix3x3 transform_matrix);
        static Vector3D worldToLocal(Vector3D v,Matrix3x3 transform_matrix);



    protected:
        double _inverse_mass;
        double _linear_damping;
        double _angular_damping;
        Vector3D _center_of_gravity;
        Vector3D _position;
        Vector3D _linear_speed;
        Vector3D _linear_acceleration;

        Vector3D _angular_speed;
        Vector3D _angular_acceleration;

        Quaternion _orientation;
        Matrix3x3 _transform_matrix;
        Matrix3x3 _inverse_inertie_tensor;

        Vector3D _size;

        Vector3D _linear_accum_forces;
        Vector3D _angular_accum_forces;

        //Protected methods:
        void updatePosition(double delta_t);
        void updateOrientation(double delta_t);
        void updateLinearSpeed(double delta_t);
        void updateLinearAcceleration(double delta_t);
        void updateAngularSpeed(double delta_t);
        void updateAngularAcceleration(double delta_t);
        void applyDamping();
};

#endif