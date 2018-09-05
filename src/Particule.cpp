#include "Particule.h"

Particule::Particule(Vector3D p,Vector3D s,Vector3D a,double m,double d):_position(p),_speed(s),_acceleration(a),_reverseMass(1/m),_damping(d){
}

void Particule::update(float delta_t){
    updateSpeed(delta_t);
    updatePosition(delta_t);
}

void Particule::updatePosition(float delta_t){
    _position+=_speed*delta_t;
}
void Particule::updateSpeed(float delta_t){
    _speed=_speed*pow(_damping,delta_t)+_acceleration*delta_t;
}