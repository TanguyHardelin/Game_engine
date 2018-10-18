#ifndef GRAPHICS_H
#define GRAPHICS_H

//Includes:
#include <iostream>
#include "Vector3D.h"

#include <chrono>
#include <vector>
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

        void addSphere(double posX,double posY,double posZ);       //Draw sphere on scene
        void addCube(double posX,double posY,double posZ,int red=0,int green=0,int blue=255);       //Draw cube on scene
        void addFloor(int red,int green,int blue);
        
        void draw();

    protected:
        Vector3D _position_of_camera;
        Vector3D _position_of_center_point;
        std::vector<GLUquadric*> _all_quadric;
        
};

#endif