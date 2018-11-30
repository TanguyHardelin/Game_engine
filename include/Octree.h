#ifndef OCTREE_H
#define OCTREE_H

#include <iostream>
#include <vector>

#include "RigidBody.h"

/*
    TODO:
        - Parcourt des cellules en profondeur
        - contruction de l'octree
        - Detection de possibilité de collision


*/

class Cell{
    public:
        Cell(Vector3D center,Vector3D size);
        Cell(Vector3D center,Vector3D size,Cell * parent);
        void divide();

        //Getter:
        inline Vector3D getCenter() const{return _center;}
        inline Vector3D getSize() const{return _size;}
        inline bool haveChildren() const{
            if(_children.size()>0) return true;
            return false;
        }
        inline std::vector<Cell *> getChildren() const{return _children;}
        inline Cell* getParent(){return _parent;}
        
    protected:
        Vector3D _center;
        Vector3D _size;
        std::vector<RigidBody *> _objects;

        //Parent:
        Cell * _parent;
        std::vector<Cell *> _children;
        
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