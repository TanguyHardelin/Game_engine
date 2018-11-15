#include "RigidBody.h"

RigidBody::RigidBody(double inverse_mass,double linear_damping,double angular_damping,Vector3D position,Vector3D linear_velocity,Vector3D linear_acceleration,Vector3D angular_speed,Vector3D angular_acceleration,Quaternion orientation,Matrix3x3 transform_matrix,Matrix3x3 inverse_inertie_tensor){
    _inverse_mass=inverse_mass;
    _linear_damping=linear_damping;
    _angular_damping=angular_damping;
    _position=position;
    _linear_velocity=linear_velocity;
    _linear_acceleration=linear_acceleration;
    _angular_speed=angular_speed;
    _angular_acceleration=angular_acceleration;
    _transform_matrix=transform_matrix;
    _inverse_inertie_tensor=inverse_inertie_tensor;

    _linear_accum_forces=Vector3D(0,0,0);
    _angular_accum_forces=Vector3D(0,0,0);
}
int RigidBody::update(double delta_t){
    //Mise à jour des accélérations:
    updateLinearAcceleration(delta_t);
    updateAngularAcceleration(delta_t);

    //Mise à jour des vitesses:
    updateLinearSpeed(delta_t);
    updateAngularSpeed(delta_t);


    //Mise à jour de la position et de l'orientation:
    updatePosition(delta_t);
    updateOrientation(delta_t);

    //Calcul des derived data:
    CalculateDerivedData();

    //Vidage des accumulateurs:
    clearAccums();
}
void RigidBody::addForceAtPoint(const Vector3D & force, const Vector3D & point){

}
void RigidBody::addForceAtBodyPoint(const Vector3D & force, const Vector3D & point){

}
void RigidBody::clearAccums(){

}
void RigidBody::CalculateDerivedData(){

}
void RigidBody::updatePosition(double delta_t){

}
void RigidBody::updateOrientation(double delta_t){

}
void RigidBody::updateLinearSpeed(double delta_t){

}
void RigidBody::updateLinearAcceleration(double delta_t){

}
void RigidBody::updateAngularSpeed(double delta_t){

}
void RigidBody::updateAngularAcceleration(double delta_t){

}
void RigidBody::applyDamping(){

}
