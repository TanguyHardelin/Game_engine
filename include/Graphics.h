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
        void init(int* argc,char **argv);
        void start();
        void clearScreen();

        void cameraZoomIn();
        void cameraZoomOut();

        void drawSphere(double posX,double posY,double posZ);
        void drawCube(double posX,double posY,double posZ);

    protected:
        Vector3D _position_of_camera;
        Vector3D _position_of_center_point;
        std::vector<GLUquadric*> _all_quadric;
        
};

#endif