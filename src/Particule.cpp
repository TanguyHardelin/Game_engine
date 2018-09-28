#include "Particule.h"

using namespace std;

Particule::Particule(Vector3D p,Vector3D s,Vector3D a,double m,double d):_position(p),_speed(s),_acceleration(a),_reverseMass(1/(m*1.0f)),_damping(d),_time_alive(0),_accum_forces(Vector3D(0,0,0)){
    _acceleration.setY(_acceleration[1]*m);
}

int Particule::update(double delta_t){
    updateAcceleration();
    updateSpeed(delta_t);
    updatePosition(delta_t);
    /*
    _time_alive+=delta_t;
    if(_time_alive>ALIVE_TIME){
        return -1;
    }
    */
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
    cout<<"accum forces: ";
    _accum_forces.display();
    _acceleration=_accum_forces*1/_reverseMass;
}