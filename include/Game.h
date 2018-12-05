#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <chrono>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <unistd.h>
#include <string>
#include <functional>
#include <GL/glut.h>

#include "Vector3D.h"
#include "Particule.h"
#include "UnitTests.h"
#include "Input.h"
#include "Mouse.h"
#include "Keyboard.h"
#include "Graphics.h"
#include "GravityRigidBodyForce.h"
#include "ForceRegister.h"
#include "GravityForce.h"
#include "DragForce.h"
#include "BungeeSpring.h"
#include "AnchorSpring.h"
#include "ParticuleSpring.h"
#include "ParticuleContactGenerator.h"
#include "ParticuleContactResolver.h"
#include "ParticuleFloorContact.h"
#include "ParticuleLinkContact.h"
#include "ParticuleContact.h"
#include "Blob.h"
#include "RigidBody.h"
#include "Octree.h"


#define SLEEPING_TIME 16666

class Game{
    public:
        //Constructor:
        Game(std::string demo);

        //Getters:
        
        //Setters:
        inline void addInput(Input * input){_all_inputs.push_back(input);}

        //Methods:
        void start();                                                                                               //Start graphic library
        void init(int* argc,char **argv);                                                                           //Init graphic library
        void updateGraphic();                                                                                       //Use for update graphic on game
        void updateLogic();                                                                                         //Use for update logic on game
        void updateInput();                                                                                         //Use for update input on game
        void gameloop();                                                                                            //Gameloop
        void createNewParticule(Vector3D position,Vector3D speed,Vector3D acceleration,double mass,double damping); //Create a new Particule on screen
        void createNewRigidBody(Vector3D position,Vector3D center_of_gravity,Vector3D speed,Vector3D acceleration,Vector3D angular_speed,Vector3D angular_acceleration,Matrix3x3 inverse_inertie_tensor,Vector3D size,double mass,double damping,std::string tag);
        void addBlobToGame(Blob * blob);
        void clearAllParticules();                                                                                  //Remove all particules on screen
        void makeConstantFrameRate(double elapsed_time);                                                            //Make frame constant

        //Destructor:
        ~Game();

    protected:
        std::string                                 _demo_type;
        std::vector<Input *>                        _all_inputs;
        std::vector<Particule *>                    _all_particules;
        std::vector<RigidBody *>                    _all_rigidBody;
        std::vector<ParticuleLinkContact *>         _all_links;
        std::vector<ParticuleCableContact *>        _all_cables;
        std::vector<Blob *>                         _all_blobs;
        Graphics                                    _graphics;
        ForceRegister                               _force_register;
        ParticuleContactGenerator                   _particule_contact_generator;
        ParticuleContactResolver                    _particule_contact_resolver;
        
        Octree*                                     _octree;
        std::vector<Vector3D>                       _octree_color;
        
        bool                                        _continue_game;
       
};

#endif