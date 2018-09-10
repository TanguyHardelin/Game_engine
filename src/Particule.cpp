#include "Particule.h"

using namespace std;

Particule::Particule(Vector3D p,Vector3D s,Vector3D a,double m,double d):_position(p),_speed(s),_acceleration(a),_reverseMass(1/m),_damping(d),_time_alive(0){
    _acceleration.setY(_acceleration[1]*m);
}

int Particule::update(float delta_t){
    updateSpeed(delta_t);
    updatePosition(delta_t);
    _time_alive+=delta_t;
    //cout<<"Time alive: "<<_time_alive<<endl;
    if(_time_alive>ALIVE_TIME){
        return -1;
    }
    return 0;
}

void Particule::updatePosition(float delta_t){
    _position+=_speed*delta_t;
}
void Particule::updateSpeed(float delta_t){
    _speed=_speed*pow(_damping,delta_t)+_acceleration*delta_t;
}