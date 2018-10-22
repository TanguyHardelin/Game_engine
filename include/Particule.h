#ifndef PARTICULE_H
#define PARTICULE_H

#include <iostream>
#include "Utils.h"
#include "Vector3D.h"

#define ALIVE_TIME 3.0f

class Particule{
    public:
    //Constructor:
    Particule(Vector3D p,Vector3D s,Vector3D a,double m,double r,Vector3D color);

    //Getters:
    inline Vector3D getPosition() const{return _position;};
    inline Vector3D getSpeed() const{return _speed;};
    inline Vector3D getAcceleration() const{return _acceleration;};
    inline Vector3D getColor() const{return _color;}
    inline double getRadius() const{return _radius;}
    inline double getMass() const{return 1/_reverseMass;};

    //Setters:
    inline void setPosition(Vector3D const & p){_position=p;};
    inline void setSpeed(Vector3D const& s){_speed=s;};
    inline void setAcceleration(Vector3D const& a){_acceleration=a;};
    inline void setColor(Vector3D const & new_color){_color=new_color;}
    inline void setMass(double m){_reverseMass=1/m;}

    //Methods:
    int update(double delta_t);              //Integrator
    void addForce(const Vector3D & force);
    void clearAccum();

    protected:
    //Atributes:
    Vector3D _position;
    Vector3D _speed;
    Vector3D _acceleration;
    double _reverseMass;
    double _radius;
    double _time_alive;
    Vector3D _color;

    Vector3D _accum_forces;

    //Protected methods:
    void updatePosition(double delta_t);
    void updateSpeed(double delta_t);
    void updateAcceleration();

};


#endif