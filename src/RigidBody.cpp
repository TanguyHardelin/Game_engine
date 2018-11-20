#include "RigidBody.h"

using namespace std;

RigidBody::RigidBody(double mass,double linear_damping,double angular_damping,
        Vector3D center_of_gravity,Vector3D position,Vector3D linear_speed,Vector3D linear_acceleration,Vector3D angular_speed,
        Vector3D angular_acceleration,Quaternion orientation,Matrix3x3 transform_matrix,Matrix3x3 inverse_inertie_tensor,Vector3D size):_inverse_mass(1/mass),_linear_damping(linear_damping),_angular_damping(angular_damping),_center_of_gravity(center_of_gravity),_position(position),_linear_speed(linear_speed),_linear_acceleration(linear_acceleration),_angular_speed(angular_speed),_angular_acceleration(angular_acceleration),_orientation(orientation),_transform_matrix(transform_matrix),_inverse_inertie_tensor(inverse_inertie_tensor),_size(size),_linear_accum_forces(0,0,0),_angular_accum_forces(0,0,0){

        //On rajoute la position de manière a bien mettre le centre de gravité dans l'objet
        _center_of_gravity=_center_of_gravity+_position;
}
int RigidBody::update(double delta_t){
    //Mise à jour des accélérations:
    updateLinearAcceleration(delta_t);
    updateAngularAcceleration(delta_t);

    //Mise à jour des vitesses:
    updateLinearSpeed(delta_t);
    updateAngularSpeed(delta_t);

    //Ajout du damping:
    applyDamping();

    //Mise à jour de la position et de l'orientation:
    updatePosition(delta_t);
    updateOrientation(delta_t);

    //Calcul des derived data:
    CalculateDerivedData();

    //Vidage des accumulateurs:
    clearAccums();
    return 0;
}
void RigidBody::addForce(const Vector3D & force){
    _linear_accum_forces+=force;
}

void RigidBody::addForceAtPoint(const Vector3D & force, const Vector3D & point){
    Vector3D p=_center_of_gravity-point;
    _linear_accum_forces+=force;
    _angular_accum_forces+=p.vectorProduct(force);
    
}
void RigidBody::addForceAtBodyPoint(const Vector3D & force, const Vector3D & point){
    Vector3D p=point+_center_of_gravity;
    p=RigidBody::localToWorld(point,_transform_matrix);
    addForceAtPoint(force,p);
}


void RigidBody::clearAccums(){
    _linear_accum_forces=0;
    _angular_accum_forces=0;
}
void RigidBody::CalculateDerivedData(){
    Matrix3x3 new_rotation=Matrix3x3::setOrientation(_orientation);
    _transform_matrix*=new_rotation;
    _inverse_inertie_tensor=_transform_matrix*_inverse_inertie_tensor*_transform_matrix.inverse();
}


void RigidBody::updatePosition(double delta_t){
    _position+=_linear_speed*delta_t;
}

void RigidBody::updateLinearSpeed(double delta_t){
    _linear_speed=_linear_speed+_linear_acceleration*delta_t;
}
void RigidBody::updateLinearAcceleration(double delta_t){
    _linear_acceleration=_linear_accum_forces*1/_inverse_mass;
}



void RigidBody::updateOrientation(double delta_t){
    _orientation.updateAngularVelocity(_angular_speed,delta_t);
    _orientation.normalize();
}
void RigidBody::updateAngularSpeed(double delta_t){
    _angular_speed=_angular_speed+_angular_acceleration*delta_t;
}
void RigidBody::updateAngularAcceleration(double delta_t){
    _angular_acceleration=_inverse_inertie_tensor*_angular_accum_forces;  
}

void RigidBody::applyDamping(){
    _linear_speed*=_linear_damping;
    _angular_speed*=_angular_damping;
}

Vector3D RigidBody::localToWorld(Vector3D v,Matrix3x3 transform_matrix){
    Vector3D r=transform_matrix*v*transform_matrix.inverse();
    return r;
}
Vector3D RigidBody::worldToLocal(Vector3D v,Matrix3x3 transform_matrix){
    return transform_matrix.inverse()*v*transform_matrix;
}
