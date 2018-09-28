#include "FloatingParticule.h"

FloatingParticule::FloatingParticule(double depth,double volume,double height_of_water,double density):_depth(depth),_volume(volume),_height_of_water(height_of_water),_density(density){

}
void FloatingParticule::updateForce(Particule *p,float delta_t){
    double d=(p->getPosition()[1]-_height_of_water-_depth)/(2*_depth);
    Vector3D force(0,0,0);
    if(d>=1){
        force[1]=_volume*_density;
    }
    else if(d>0 && d<1){
        force[1]=_volume*_density*d;
    }
    p->addForce(force);  
}