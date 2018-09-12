#ifndef PARTICULE_H
#define PARTICULE_H

#include <iostream>
#include "Utils.h"
#include "Vector3D.h"

#define ALIVE_TIME 3.0f

class Particule{
    public:
    //Constructor:
    Particule(Vector3D p,Vector3D s,Vector3D a,double m,double d);

    //Getters:
    inline Vector3D getPosition() const{return _position;};
    inline Vector3D getSpeed() const{return _speed;};
    inline Vector3D getAcceleration() const{return _acceleration;};
    inline double getMass() const{return 1/_reverseMass;};

    //Setters:
    inline void setPosition(Vector3D const & p){_position=p;};
    inline void setSpeed(Vector3D const& s){_speed=s;};
    inline void setAcceleration(Vector3D const& a){_acceleration=a;};
    inline void setMass(double m){_reverseMass=1/m;}

    //Methods:
    int update(float delta_t);              //Integrator

    protected:
    //Atributes:
    Vector3D _position;
    Vector3D _speed;
    Vector3D _acceleration;
    double _reverseMass;
    double _damping;
    double _time_alive;

    //Protected methods:
    void updatePosition(float delta_t);
    void updateSpeed(float delta_t);

};


#endif