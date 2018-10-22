#include "Blob.h"

using namespace std;

Blob::Blob(int width,int height,int depth,Vector3D initial_position,Vector3D size,ParticuleContactGenerator* pcg,ForceRegister* fr,Graphics* graphics):_width(width),_height(height),_depth(depth),_initial_position(initial_position),_size(size),_particule_contact_generator(pcg),_force_register(fr),_graphics(graphics){
    buildBlob();
}
void Blob::drawBlob(){
    Vector3D blob_color=Vector3D(72,234,255);
    for(int i=0;i<(int)_all_particules.size();i++){
        if((i%_width+1)<_width && (i+1+_width*_depth)<_all_particules.size() && (i+_width*_depth)<_all_particules.size()){
            _graphics->addPlane(_all_particules[i]->getPosition(),_all_particules[i+1]->getPosition(),_all_particules[i+1+_width*_depth]->getPosition(),_all_particules[i+_width*_depth]->getPosition(),blob_color);
        }
        if((i%_width+1)<_width && (i+_width+1)<_all_particules.size() && (i+_width)<_all_particules.size()){
            _graphics->addPlane(_all_particules[i]->getPosition(),_all_particules[i+1]->getPosition(),_all_particules[i+1+_width]->getPosition(),_all_particules[i+_width]->getPosition(),blob_color);
        }
        if((i%_width+1)<_width && (i+1+_width*_depth)<_all_particules.size() && (i+_width*_depth)<_all_particules.size()){
            _graphics->addPlane(_all_particules[i]->getPosition(),_all_particules[i+1]->getPosition(),_all_particules[i+1+_width*_depth]->getPosition(),_all_particules[i+_width*_depth]->getPosition(),blob_color);
        }
        if((i%_width*_depth+_width)<_width*_depth && (i+_width+_width*_depth)<_all_particules.size() && (i+_width*_depth)<_all_particules.size()){
            _graphics->addPlane(_all_particules[i]->getPosition(),_all_particules[i+_width]->getPosition(),_all_particules[i+_width*_depth+_width]->getPosition(),_all_particules[i+_width*_depth]->getPosition(),blob_color);
        }
        _graphics->addSphere(_all_particules[i]->getPosition(),2*_all_particules[i]->getRadius(),_all_particules[i]->getColor());   
    }
}
void Blob::buildBlob(){
    for(int k=0;k<_height;k++){
        for(int j=0;j<_width;j++){
            for(int i=0;i<_depth;i++){
                _all_particules.push_back(new Particule(Vector3D(_initial_position[0]+i*_size[0],_initial_position[1]+_size[1]*k,_initial_position[2]+j*_size[2]),Vector3D(0,0,0),Vector3D(0,0,0),10,2.5,Vector3D(134,255,92)));
            }
        }
    }
    for(int i=0;i<(int)_all_particules.size();i++){
        if((i%(_width*_depth)-_width)>=0){
            vector<Particule *> particules;
            particules.push_back(_all_particules[i]);
            particules.push_back(_all_particules[i-_width]);
            _all_links.push_back(new ParticuleLinkContact(particules,0.1));        
        }
        if((i%_width-1)>=0){
            vector<Particule *> particules;
            particules.push_back(_all_particules[i]);
            particules.push_back(_all_particules[i-1]);
            _all_links.push_back(new ParticuleLinkContact(particules,0.1));          
        }
        if((i-_width*_depth)>=0){
            vector<Particule *> particules;
            particules.push_back(_all_particules[i]);
            particules.push_back(_all_particules[i-_width*_depth]);
            _all_links.push_back(new ParticuleLinkContact(particules,0.1));
        }
    }
    for(int i=0;i<_width*_depth;i++){
        _force_register->addForce(_all_particules[i],new GravityForce(20));
    }
}
