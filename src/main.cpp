#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <cmath>
#include <vector>
#include <unistd.h>
#include <GL/glut.h>

#include "Vector3D.h"
#include "Particule.h"
#include "UnitTests.h"
#include "Game.h"

using namespace std;

//Create Game
Game game;

//Create mouse and keyboard:
Mouse *_mouse=new Mouse();
Keyboard *_keyboard=new Keyboard();

void gameloop(){
    game.gameloop();
}
void mouseControl(int button, int state,int x, int y){
    _mouse->handleMouse(button,state,x,y);
}
void keyboardControl(unsigned char key,int x, int y){
    _keyboard->handleKeyboard(key,x,y);
}
int main(int argc, char** argv)
{
    if(argc>1){
        runTests();
    }
    else{
        srand (time(NULL));

        //Initialisation of libs:
        game.init(&argc,argv);

        //Add mouse and keyboard to the game: 
        game.addInput(_mouse);
        game.addInput(_keyboard);

        //Glut display:
        //glutIdleFunc(updateGraphic);

        //Add gameloop:
        glutIdleFunc(gameloop);

        //Add mouse control:
        glutMouseFunc(mouseControl);
        
        //Add keyboard control:
        glutKeyboardFunc(keyboardControl);

        //Start the game:
        game.start();
    }
    

    return 0;
}