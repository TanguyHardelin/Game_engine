#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <iostream>
#include <chrono>
#include <vector>
#include <GL/glut.h>

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 700
#define NAME_OF_WINDOW  "GAME_ENGINE"

class Graphics{
    public:
        Graphics();
        void init(int* argc,char **argv);
        void drawSphere(double posX,double posY,double posZ);
        void drawCube(double posX,double posY,double posZ);
        void clearScreen();
        
        void start();
    protected:
        std::vector<GLUquadric*> _all_quadric;
};

#endif