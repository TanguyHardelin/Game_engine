#ifndef OCTREE_H
#define OCTREE_H

#include <iostream>
#include <vector>

#include "RigidBody.h"

class Cell{
    public:
        Cell(Vector3D center,Vector3D size);
        std::vector<Cell *> divide();

        //Getter:
        inline Vector3D getCenter() const{return _center;}
        inline Vector3D getSize() const{return _size;}

    protected:
        Vector3D _center;
        Vector3D _size;
        std::vector<RigidBody *> _objects;

        //Ajouter un parent
};

class Octree{
    public:
    /*
        Octree(int width,int height,int depth);
        void build();                                   //Méthode d'initialisation de l'arbre à appeler au début
        void addObjectToBuffer(RigidBody * rb);         //Ajoute le rigidBody dans un "buffer"
        void apply();
        void clearBuffer();
    */

    protected:
        int                           _depth;
        int                           _width;
        int                           _height;
        std::vector<Cell*>             _all_cell;
};



#endif