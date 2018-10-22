#include "BuoyancySpring.h"

BuoyancySpring::BuoyancySpring(double max_depth,double obj_volume,double water_height,double density):_max_depth(max_depth),_obj_volume(obj_volume),_water_height(water_height),_density(density){

}
void BuoyancySpring::updateForce(Particule *p,float delta_t){
    double d=(p->getPosition().getY()-_water_height-p->getRadius())/(2*p->getRadius());
    Vector3D force(0,0,0);
    if(d<=0){

    }
    else if(d>=1){
        force[1]=_obj_volume*_density;
    }
    else{
        force[1]=d*_obj_volume*_density;
    }
    if(force.norm()!=0)
        p->addForce(force); 
}