#ifndef BLOB_H
#define BLOB_H

#include <vector>
#include <iostream>
#include "Vector3D.h"
#include "Particule.h"
#include "ParticuleLinkContact.h"
#include "ParticuleCableContact.h"
#include "ParticuleContactGenerator.h"
#include "ForceRegister.h"
#include "GravityForce.h"
#include "Graphics.h"

class Blob{
    public:
        Blob(int width,int height,int depth,Vector3D initial_position,Vector3D size,ParticuleContactGenerator* pcg,ForceRegister* fr,Graphics* graphics);

        void drawBlob();

        inline Vector3D getPosition() const{return _all_particules[0]->getPosition();}
        inline std::vector<Particule *> getAllParticules() const{return _all_particules;}
        inline std::vector<ParticuleLinkContact *> getAllLinks() const{return _all_links;}
        inline std::vector<ParticuleCableContact *> getAllCables() const{return _all_cables;}

    protected:
        int _width,_height,_depth;
        Vector3D _initial_position;
        Vector3D _size;
        ParticuleContactGenerator*   _particule_contact_generator;
        ForceRegister*               _force_register;
        Graphics*                    _graphics;

        std::vector<Particule *>                _all_particules;
        std::vector<ParticuleLinkContact *>     _all_links;
        std::vector<ParticuleCableContact *>    _all_cables;

        

        void buildBlob();

};
#endif