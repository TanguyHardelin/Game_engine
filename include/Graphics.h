#ifndef GRAPHICS_H
#define GRAPHICS_H

//Includes:
#include <iostream>
#include "Vector3D.h"
#include "Quaternion.h"
#include "Matrix4x4.h"

#include <chrono>
#include <vector>
#include <cmath>
#include <GL/glut.h>

//Window parameters:
#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 700
#define NAME_OF_WINDOW  "GAME_ENGINE"

class Vector3D;

class Graphics{
    public:
        //Constructor:
        Graphics();

        //Getters:
        inline Vector3D getPositionOfCamera(){return _position_of_camera;}
        inline Vector3D getPositionOfCenterPoint(){return _position_of_center_point;}
        //Setters:
        void setPositionOfCamera(Vector3D const& v);
        void setPositionOfCenterPoint(Vector3D const& v);

        //Methods:
        void init(int* argc,char **argv);                           //Initialisation of GLUT
        void start();                                               //Start main loop of GLUT
        void clearScreen();                                         //Clear screen

        void cameraZoomIn();                                        //Zoom
        void cameraZoomOut();                                       //Dezoom

        void addSphere(Vector3D position,double radius,Vector3D color);       //Draw sphere on scene
        void addCube(Vector3D position,Quaternion orientation);       //Draw cube on scene
        void addPlane(Vector3D pos0,Vector3D pos1,Vector3D pos2, Vector3D pos3,Vector3D color);
        void addFloor(Vector3D color);
        
        void draw();

    protected:
        Vector3D _position_of_camera;
        Vector3D _position_of_center_point;
        std::vector<GLUquadric*> _all_quadric;
        
};

#endif