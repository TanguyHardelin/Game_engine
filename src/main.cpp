#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <cmath>
#include <vector>
#include <unistd.h>
#include <string>
#include <GL/glut.h>

#include "Vector3D.h"
#include "Particule.h"
#include "UnitTests.h"
#include "Utils.h"
#include "Game.h"

using namespace std;

//Create Game
Game game("demoX");

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
void launchGame(int argc, char** argv){
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
int main(int argc, char** argv)
{
    if(argc>1){
        string command(argv[1]);

        if(command == "--runTest"){
            runTests();
        }
        else if(command == "--demo"){
            game=Game("demo");
            launchGame(argc,argv);
        }
        else if(command=="--help"){
            cout<<"\033[32m"<<"\033[1m"<<"["<<"AIDE"<<"] "<<"\033[0m"<<"USAGE: ./GAME_ENGINE --command"<<endl;
            cout<<"\033[32m"<<"\033[1m"<<"["<<"AIDE"<<"] "<<"\033[0m"<<"--command:"<<endl;
            cout<<"\033[32m"<<"\033[1m"<<"["<<"AIDE"<<"] "<<"\033[0m"<<"--runTest: Lance les tests unitaires du programe."<<endl;
            cout<<"\033[32m"<<"\033[1m"<<"["<<"AIDE"<<"] "<<"\033[0m"<<"--demo     Lance la démo du projet."<<endl;
        }
        else{
            cout<<"\033[31m"<<"\033[1m"<<"["<<"COMMAND NOT FOUND"<<"] "<<"\033[0m"<<"./GAME_ENGINE --help pour obtenir de l'aide"<<endl;
        }
        
    }
    else{
        cout<<"\033[31m"<<"\033[1m"<<"["<<"COMMAND NOT FOUND"<<"] "<<"\033[0m"<<"./GAME_ENGINE --help pour obtenir de l'aide"<<endl;
    }
    

    return 0;
}