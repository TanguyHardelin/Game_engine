#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <chrono>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <unistd.h>
#include <functional>
#include <GL/glut.h>

#include "Vector3D.h"
#include "Particule.h"
#include "UnitTests.h"
#include "Input.h"
#include "Mouse.h"
#include "Keyboard.h"
#include "Graphics.h"

#define SLEEPING_TIME 16666

class Game{
    public:
        Game();
        void start();
        void init(int* argc,char **argv);
        void updateGraphic();
        void gameloop();
        void createNewParticule();
        void makeConstantFrameRate(double elapsed_time);

        inline void addInput(Input * input){_all_inputs.push_back(input);}
        ~Game();

    protected:
        std::vector<Input *> _all_inputs;
        std::vector<Particule *> _all_particules;
        Graphics _graphics;
};

#endif