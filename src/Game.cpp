#include "Game.h"

using namespace std;

Game::Game(){
    _all_particules.push_back(new Particule(Vector3D(0,100,0),Vector3D(10,0,0),Vector3D(0,-30,0),10,0.9));

}
void Game::init(int* argc,char **argv){
    _graphics.init(argc,argv);
}

void Game::start(){
    _graphics.start();
}
void Game::updateGraphic(){
     _graphics.clearScreen();
    for(unsigned i=0;i<_all_particules.size();i++){
        _graphics.drawCube(_all_particules[i]->getPosition().getX(),_all_particules[i]->getPosition().getY(),_all_particules[i]->getPosition().getZ());
    }
}
void Game::createNewParticule(){
    _all_particules.push_back(new Particule(Vector3D(rand()%100,10+rand()%50,rand()%100),Vector3D(rand()%5,rand()%5,rand()%5),Vector3D(0,-30,0),10,0.9));
}
void Game::gameloop(){
    //Start the clock for the gameloop:
    static auto start = std::chrono::high_resolution_clock::now();
    static auto last_logic_update = std::chrono::high_resolution_clock::now();

    //Update Input:
    vector <INPUT_KEY> all_key_pressed;
    for(unsigned i=0;i<_all_inputs.size();i++){
        vector <INPUT_KEY> tmp=_all_inputs[i]->getBuffer();
        for(unsigned j=0;j<tmp.size();j++)
            all_key_pressed.push_back(tmp[j]);
    }
    for(unsigned i=0;i<all_key_pressed.size();i++){
        cout<<all_key_pressed[i].name<<" was pressed "<<endl;
    }

    //Get time since the last logic update:
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;

    //Update Logic:
    for(unsigned i=0;i<_all_particules.size();i++){
        _all_particules[i]->getPosition().display();
        if(_all_particules[i]->update(elapsed.count())==-1){
            _all_particules.erase(_all_particules.begin()+i);
            updateGraphic();
            createNewParticule();
        }
        else{
            
        }
    }
    last_logic_update=finish;

    updateGraphic();
    

    //Stop the clock and make constant frame:
    finish = std::chrono::high_resolution_clock::now();
    elapsed = finish - start;
    cout<<"Time between two frame: "<<elapsed.count()<<" s"<<endl;
    start=finish;
    makeConstantFrameRate(elapsed.count());
}
void Game::makeConstantFrameRate(double elapsed_time){
    static long sleeping_time=SLEEPING_TIME;
    if(sleeping_time>SLEEPING_TIME){
        sleeping_time-=elapsed_time*pow(10,6)-SLEEPING_TIME;
    }
    else{
        sleeping_time+=SLEEPING_TIME-elapsed_time*pow(10,6);
    }
    usleep(sleeping_time);
}
Game::~Game(){
    for(unsigned i=0;i<_all_particules.size();i++)
        delete _all_particules[i];
    for(unsigned i=0;i<_all_inputs.size();i++)
        delete _all_inputs[i];
}