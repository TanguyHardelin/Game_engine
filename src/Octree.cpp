#include "Octree.h"

using namespace std;

Cell::Cell(Vector3D center,Vector3D size):_center(center),_size(size){

}
vector<Cell *> Cell::divide(){
    vector<Cell *> new_cells;
    Vector3D new_size=_size/2;
    //On construit 8 nouvelles cellules:
    new_cells.push_back(new Cell(Vector3D(_center[0] + new_size[0] ,_center[1] + new_size[1] ,_center[2] + new_size[2]),Vector3D(new_size[0],new_size[1],new_size[2])));
    new_cells.push_back(new Cell(Vector3D(_center[0] + new_size[0] ,_center[1] - new_size[1] ,_center[2] + new_size[2]),Vector3D(new_size[0],new_size[1],new_size[2])));
    new_cells.push_back(new Cell(Vector3D(_center[0] - new_size[0] ,_center[1] + new_size[1] ,_center[2] + new_size[2]),Vector3D(new_size[0],new_size[1],new_size[2])));
    new_cells.push_back(new Cell(Vector3D(_center[0] - new_size[0] ,_center[1] - new_size[1] ,_center[2] + new_size[2]),Vector3D(new_size[0],new_size[1],new_size[2])));

    new_cells.push_back(new Cell(Vector3D(_center[0] + new_size[0] ,_center[1] + new_size[1] ,_center[2] - new_size[2]),Vector3D(new_size[0],new_size[1],new_size[2])));
    new_cells.push_back(new Cell(Vector3D(_center[0] + new_size[0] ,_center[1] - new_size[1] ,_center[2] - new_size[2]),Vector3D(new_size[0],new_size[1],new_size[2])));
    new_cells.push_back(new Cell(Vector3D(_center[0] - new_size[0] ,_center[1] + new_size[1] ,_center[2] - new_size[2]),Vector3D(new_size[0],new_size[1],new_size[2])));
    new_cells.push_back(new Cell(Vector3D(_center[0] - new_size[0] ,_center[1] - new_size[1] ,_center[2] - new_size[2]),Vector3D(new_size[0],new_size[1],new_size[2])));

    return new_cells;
}