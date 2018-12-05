#include "Octree.h"

using namespace std;

//Ajouter fonction permettant de connaitre toute les cellues non mere
//  Apres dans game on verifie si il y a des collision possibles
//      Si oui on prend les objects
//      On regarde les spheres de collisions
//      Ajouter des tag

Cell::Cell(Vector3D center,Vector3D size):_center(center),_size(size){

}
Cell::Cell(Vector3D center,Vector3D size,Cell * parent):_center(center),_size(size),_parent(parent){

}
void Cell::divide(){
    vector<Cell *> new_cells;
    Vector3D new_size=_size/2;
    //On construit 8 nouvelles cellules:
    _children.push_back(new Cell(Vector3D(_center[0] + new_size[0] ,_center[1] + new_size[1] ,_center[2] + new_size[2]),Vector3D(new_size[0],new_size[1],new_size[2]),this));
    _children.push_back(new Cell(Vector3D(_center[0] + new_size[0] ,_center[1] - new_size[1] ,_center[2] + new_size[2]),Vector3D(new_size[0],new_size[1],new_size[2]),this));
    _children.push_back(new Cell(Vector3D(_center[0] - new_size[0] ,_center[1] + new_size[1] ,_center[2] + new_size[2]),Vector3D(new_size[0],new_size[1],new_size[2]),this));
    _children.push_back(new Cell(Vector3D(_center[0] - new_size[0] ,_center[1] - new_size[1] ,_center[2] + new_size[2]),Vector3D(new_size[0],new_size[1],new_size[2]),this));

    _children.push_back(new Cell(Vector3D(_center[0] + new_size[0] ,_center[1] + new_size[1] ,_center[2] - new_size[2]),Vector3D(new_size[0],new_size[1],new_size[2]),this));
    _children.push_back(new Cell(Vector3D(_center[0] + new_size[0] ,_center[1] - new_size[1] ,_center[2] - new_size[2]),Vector3D(new_size[0],new_size[1],new_size[2]),this));
    _children.push_back(new Cell(Vector3D(_center[0] - new_size[0] ,_center[1] + new_size[1] ,_center[2] - new_size[2]),Vector3D(new_size[0],new_size[1],new_size[2]),this));
    _children.push_back(new Cell(Vector3D(_center[0] - new_size[0] ,_center[1] - new_size[1] ,_center[2] - new_size[2]),Vector3D(new_size[0],new_size[1],new_size[2]),this));
}
void Cell::addObjectToBuffer(RigidBody * rb){
    if(!haveChildren()){
        if((_center-rb->getPosition())<_size){
            /*
            cout<<endl;
            cout<<"_center ";_center.display();
            cout<<"rb->getPosition() ";rb->getPosition().display();
            cout<<"_size ";_size.display();
            cout<<"_center-rb->getPosition()  ";(_center-rb->getPosition()).display();
            cout<<endl;
            */
            _objects.push_back(rb);
        }
    }
    else{
        vector<Cell*> all_children=getChildren();
        for(unsigned i=0;i<all_children.size();i++){
            all_children[i]->addObjectToBuffer(rb);
        }
    }
}
void Cell::clearBuffer(){
    if(!haveChildren()){
        unsigned size=_objects.size();
        for(unsigned i=0;i<size;i++){
            _objects.pop_back();
        }
    }
    else{
        vector<Cell*> all_children=getChildren();
        for(unsigned i=0;i<all_children.size();i++){
            all_children[i]->clearBuffer();
        }
    }
}
bool Cell::IsPossibleCollision(){
    if(_objects.size()>1){
        return true;
    }
    else{
        return false;
    }
}

///////////////////////////////////////////////////////////////////////
//                       OCTREE                                      //
///////////////////////////////////////////////////////////////////////


Octree::Octree(int width,int height,int depth):_depth(depth),_width(width),_height(height){

}
void Octree::build(){
    _all_cell = new Cell(Vector3D(0,0,0),Vector3D(_width,_height,_depth));
    //Premiere division:
    _all_cell->divide();
    //Seconde division:
    vector<Cell *> all_cell=_all_cell->getChildren();
    for(unsigned i=0;i<all_cell.size();i++){
        all_cell[i]->divide();
    }
}                                   
void Octree::addObjectToBuffer(RigidBody * rb){
    _all_cell->addObjectToBuffer(rb);
}      
void Octree::clearBuffer(){
    _all_cell->clearBuffer();
}

std::vector<Cell *> Octree::getAllNoMotherChildren(Cell* c){
    std::vector<Cell *> retour;

    if(!c->haveChildren()){
       retour.push_back(c);
    }
    else{
        vector<Cell*> all_children=c->getChildren();
        for(unsigned i=0;i<all_children.size();i++){
            vector<Cell*> tmp=getAllNoMotherChildren(all_children[i]);
            for(unsigned j=0;j<tmp.size();j++){
                retour.push_back(tmp[j]);
            }
        }
    }
    return retour;
}
std::vector<Cell *> Octree::getAllCells(){
    return getAllNoMotherChildren(_all_cell);
}
Octree::~Octree(){
    if(_all_cell){
        delete _all_cell;
    }
}