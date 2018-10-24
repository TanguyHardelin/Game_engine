#include "Particule.h"

using namespace std;

Particule::Particule(Vector3D p,Vector3D s,Vector3D a,double m,double r,Vector3D color):_position(p),_speed(s),_acceleration(a),_reverseMass(1/(m*1.0f)),_radius(r),_time_alive(0),_color(color),_accum_forces(Vector3D(0,0,0)){
    _acceleration.setY(_acceleration[1]*m);
}

int Particule::update(double delta_t){
    updateAcceleration();
    updateSpeed(delta_t);
    updatePosition(delta_t);
    return 0;
}
void Particule::addForce(const Vector3D & force){
    _accum_forces+=force;
}
void Particule::clearAccum(){
    _accum_forces=0;
}

void Particule::updatePosition(double delta_t){
    _position+=_speed*delta_t;
}
void Particule::updateSpeed(double delta_t){
    _speed+=_acceleration*delta_t;
}
void Particule::updateAcceleration(){
    _acceleration=_accum_forces*1/_reverseMass;
}