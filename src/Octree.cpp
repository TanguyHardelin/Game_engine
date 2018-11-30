#include "Octree.h"

using namespace std;

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