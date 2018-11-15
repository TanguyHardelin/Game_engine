#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include <iostream>
#include "Vector3D.h"
#include "Matrix3x3.h"
#include "Quaternion.h"

class RigidBody{
    public:
        RigidBody(double inverse_mass,double linear_damping,double angular_damping,Vector3D position,Vector3D linear_velocity,Vector3D linear_acceleration,Vector3D angular_speed,Vector3D angular_acceleration,Quaternion orientation,Matrix3x3 transform_matrix,Matrix3x3 inverse_inertie_tensor);
        

        //Methods:
        int update(double delta_t);              //Integrator
        void addForceAtPoint(const Vector3D & force, const Vector3D & point);
        void addForceAtBodyPoint(const Vector3D & force, const Vector3D & point);
        void clearAccums();

        void CalculateDerivedData();


    protected:
        double _inverse_mass;
        double _linear_damping;
        double _angular_damping;
        Vector3D _position;
        Vector3D _linear_speed;
        Vector3D _linear_scceleration;

        Vector3D _angular_speed;
        Vector3D _angular_acceleration;

        Quaternion _orientation;
        Matrix3x3 _transform_matrix;
        Matrix3x3 _inverse_inertie_tensor;

        Vector3D _linear_accum_forces;
        Vector3D _angulare_accum_forces;

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