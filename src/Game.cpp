#include "Game.h"

using namespace std;

/*
    TODO LIST:
    - Ajouter abstraction pour creer une API pour le moteur de jeux.
    - Revoir asservissement temps entre frame.
    - Thread les calculs physique pour optimiser le temps de calcul.
*/

Game::Game(){
    _particule_contact_generator    = ParticuleContactGenerator();
    _particule_contact_resolver     = NULL;
    _continue_game                  = true;

    /*
    //Demo of blob technologie:
    _all_particules.push_back(new Particule(Vector3D(50,50,50),Vector3D(0,0,0),Vector3D(0,0,0),10,0.9));
    _all_particules.push_back(new Particule(Vector3D(50,150,50),Vector3D(0,0,0),Vector3D(0,0,0),10,0.9));

    vector<Particule *> particules;
    particules.push_back(_all_particules[1]);
    particules.push_back(_all_particules[0]);
    _particule_contact_generator.addLink(new ParticuleLinkContact(particules,0.1,Vector3D(0,100,0)));
    

    for(int i=0;i<2;i++){
        _force_register.addForce(_all_particules[i],new GravityForce(20));
    }
    */

    createBlob();
}
void Game::createBlob(){
    //For the demo we create one particule when the game start
    for(int k=0;k<4;k++){
        for(int j=0;j<4;j++){
            for(int i=0;i<4;i++){
                _all_particules.push_back(new Particule(Vector3D(50+i*50,200+50*k,50+j*50),Vector3D(0,0,0),Vector3D(0,0,0),10,0.9));
            }
        }
    }
    
    
    for(int i=0;i<(int)_all_particules.size();i++){
  
        if((i%16-4)>=0){
            
            vector<Particule *> particules;
            particules.push_back(_all_particules[i]);
            particules.push_back(_all_particules[i-4]);
            _particule_contact_generator.addLink(new ParticuleLinkContact(particules,0.1));
            
            //_force_register.addForce(_all_particules[i],new ParticuleSpring(0.9,50,_all_particules[i-4]));
        }
        /*
        if((i%16+4)<16){
            vector<Particule *> particules;
            particules.push_back(_all_particules[i]);
            particules.push_back(_all_particules[i+4]);
            _particule_contact_generator.addLink(new ParticuleLinkContact(particules,0.99));

            //_force_register.addForce(_all_particules[i],new ParticuleSpring(0.9,50,_all_particules[i+4]));
        }
        */
        if((i%4-1)>=0){
            
            vector<Particule *> particules;
            particules.push_back(_all_particules[i]);
            particules.push_back(_all_particules[i-1]);
            _particule_contact_generator.addLink(new ParticuleLinkContact(particules,0.1));
            
            //_force_register.addForce(_all_particules[i],new ParticuleSpring(0.9,50,_all_particules[i-1]));
        }
        
       /*
        if((i%4+1)<4){
            vector<Particule *> particules;
            particules.push_back(_all_particules[i]);
            particules.push_back(_all_particules[i+1]);
            _particule_contact_generator.addLink(new ParticuleLinkContact(particules,0.99));
            //_force_register.addForce(_all_particules[i],new ParticuleSpring(0.9,50,_all_particules[i+1]));
        }
        */
        
        if((i-16)>=0){
            
            vector<Particule *> particules;
            particules.push_back(_all_particules[i]);
            particules.push_back(_all_particules[i-16]);
            _particule_contact_generator.addLink(new ParticuleLinkContact(particules,0.1));
            
            //_force_register.addForce(_all_particules[i],new ParticuleSpring(0.9,50,_all_particules[i-16]));
        }
        
        /*
        if((i+16)<(int)_all_particules.size()){
            vector<Particule *> particules;
            particules.push_back(_all_particules[i]);
            particules.push_back(_all_particules[i+16]);
            _particule_contact_generator.addLink(new ParticuleLinkContact(particules,0.99));
            //_force_register.addForce(_all_particules[i],new ParticuleSpring(0.9,50,_all_particules[i+16]));
        }
        */
       //_force_register.addForce(_all_particules[i],new GravityForce(20));
       
    }
    for(int i=0;i<16;i++){
        _force_register.addForce(_all_particules[i],new GravityForce(20));
    }
    
    //_all_particules.push_back(new Particule(Vector3D(0,100,0),Vector3D(0,0,0),Vector3D(0,0,0),10,0.9));

    //_all_particules.push_back(new Particule(Vector3D(0,50,0),Vector3D(0,0,0),Vector3D(0,0,0),10,0.9));

    //_force_register.addForce(_all_particules[0],new ParticuleSpring(0.9,50,_all_particules[1]));
    //_force_register.addForce(_all_particules[1],new ParticuleSpring(0.9,50,_all_particules[0]));
    //_force_register.addForce(_all_particules[0],new GravityForce(20));
    /*
    for(int i=0;i<_all_particules.size();i++){
        for(int j=0;j<_all_particules.size();j++){
            if(i!=j){
                _force_register.addForce(_all_particules[i],new ParticuleSpring(0.9,50,_all_particules[j]));
            }
        }
    }
    */

    //_force_register.addForce(_all_particules[_all_particules.size()-1],new GravityForce(20));
    //_force_register.addForce(_all_particules[_all_particules.size()-1],new DragForce(0.9,0.01));

}
void Game::init(int* argc,char **argv){
    //Initialize GLUT:
    _graphics.init(argc,argv);
}

void Game::start(){
    //Start the mainloop of glut
    _graphics.start();
}
void Game::updateGraphic(){
    _graphics.clearScreen();
    _graphics.addFloor(255,255,255);
    for(int i=0;i<(int)_all_particules.size();i++){
        _graphics.addSphere(_all_particules[i]->getPosition().getX(),_all_particules[i]->getPosition().getY(),_all_particules[i]->getPosition().getZ(),5);
        //_graphics.drawSphere(_all_particules[i]->getPosition().getX(),_all_particules[i]->getPosition().getY(),_all_particules[i]->getPosition().getZ());

        //TODO: ameliorer ça!
        if((i%4+1)<4 && (i+1+16)<_all_particules.size() && (i+16)<_all_particules.size()){
            _graphics.addPlane(_all_particules[i]->getPosition(),_all_particules[i+1]->getPosition(),_all_particules[i+1+16]->getPosition(),_all_particules[i+16]->getPosition());
        }
        
    }
    /*
    for(int i=0;i<6;i++){
        for(int j=0;j<(int)_all_particules.size();j++){
            for(int k=0;k<(int)_all_particules.size();k++){
                for(int l=0;l<(int)_all_particules.size();l++){
                    if(i!=j!=l!=k)
                    _graphics.addPlane(_all_particules[i]->getPosition(),_all_particules[j]->getPosition(),_all_particules[k]->getPosition(),_all_particules[l]->getPosition());
                }
            }
        }
    }
    */
    _graphics.draw();
}
void Game::createNewParticule(Vector3D position,Vector3D speed,Vector3D acceleration,double mass,double damping){
    //Create the particule
    _all_particules.push_back(new Particule(position,speed,acceleration,mass,damping));

    //Add force:
    _force_register.addForce(_all_particules[_all_particules.size()-1],new GravityForce(20));
    _force_register.addForce(_all_particules[_all_particules.size()-1],new DragForce(0.9,0.01));

}
void Game::updateLogic(){
    static auto last_logic_update = std::chrono::high_resolution_clock::now();
    //Get time since the last logic update:
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - last_logic_update;
    last_logic_update=finish;

    //Update all forces generators:
    _force_register.updateAllForce(elapsed.count());

    //Update position / speed / acceleration:
    for(unsigned i=0;i<_all_particules.size();i++){
        _all_particules[i]->update(elapsed.count());
    }

    //Detect collisions:
    for(unsigned i=0;i<_all_particules.size();i++){
        for(unsigned j=0;j<_all_particules.size();j++){
            if(i!=j){
                if(norm(_all_particules[i]->getPosition()-_all_particules[j]->getPosition())<=10){
                    vector<Particule *> particules;
                    particules.push_back(_all_particules[j]);
                    particules.push_back(_all_particules[i]);
                    _particule_contact_generator.addContact(new ParticuleContact(particules,0.9));
                }
            }
            if(i==j){
                //Manage floor colision:
                if(_all_particules[i]->getPosition().getY()<0){
                    vector<Particule *> particules; 
                    particules.push_back(_all_particules[i]);
                    particules.push_back(_all_particules[0]);   //0 index is floor
                    _particule_contact_generator.addContact(new ParticuleFloorContact(particules,0.9));
                }
            }
        }
    }

    vector<ParticuleContact*> all_contacts=_particule_contact_generator.getContacts();

    vector<ParticuleContact*> all_links=_particule_contact_generator.getLinks();

    _particule_contact_resolver=new ParticuleContactResolver();

    _particule_contact_resolver->resolveSimpleContacts(all_contacts,elapsed.count());

    _particule_contact_resolver->resolveSimpleContacts(all_links,elapsed.count());

    _particule_contact_generator.clearContacts();  

    delete _particule_contact_resolver;

      
    
    //Clear accumulator of particules:
    _force_register.clearAllForce();
}
void Game::updateInput(){
    vector <INPUT_KEY> all_key_pressed;
    for(unsigned i=0;i<_all_inputs.size();i++){
        vector <INPUT_KEY> tmp=_all_inputs[i]->getBuffer();
        for(unsigned j=0;j<tmp.size();j++)
            all_key_pressed.push_back(tmp[j]);
        _all_inputs[i]->clearBuffer();
    }
    for(unsigned i=0;i<all_key_pressed.size();i++){
        if(all_key_pressed[i].name==SCROOL_WHEEL_UP)
            _graphics.cameraZoomIn();
        if(all_key_pressed[i].name==SCROOL_WHEEL_DOWN)
            _graphics.cameraZoomOut();
        if(all_key_pressed[i].name==32){
            //32 is SPACE
            

        } 
        if(all_key_pressed[i].name=='r')
            createNewParticule(Vector3D(-500,0,0),Vector3D(100+rand()%200,100+rand()%100,rand()%10),Vector3D(0,-10,0),1+rand()%10,0.9);
        if(all_key_pressed[i].name=='c')
            clearAllParticules();
        if(all_key_pressed[i].name=='q'){
            Vector3D camera_position=_graphics.getPositionOfCamera();
            camera_position[0]+=30;
            _graphics.setPositionOfCamera(camera_position);
        }
        if(all_key_pressed[i].name=='d'){
            Vector3D camera_position=_graphics.getPositionOfCamera();
            camera_position[0]-=30;
            _graphics.setPositionOfCamera(camera_position);
        }
        if(all_key_pressed[i].name=='z'){
            Vector3D camera_position=_graphics.getPositionOfCamera();
            camera_position[1]+=30;
            _graphics.setPositionOfCamera(camera_position);
        }
        if(all_key_pressed[i].name=='s'){
            Vector3D camera_position=_graphics.getPositionOfCamera();
            camera_position[1]-=30;
            _graphics.setPositionOfCamera(camera_position);
        }

        //Mouvement of blob:
        if(all_key_pressed[i].name=='8'){
            for(unsigned i=0;i<_all_particules.size();i++){
                Vector3D speed=_all_particules[i]->getPosition();
                speed[2]-=20;
                _all_particules[i]->setPosition(speed);
            }
        }
        if(all_key_pressed[i].name=='2'){
            for(unsigned i=0;i<_all_particules.size();i++){
                Vector3D speed=_all_particules[i]->getPosition();
                speed[2]+=20;
                _all_particules[i]->setPosition(speed);
            }
        }
        if(all_key_pressed[i].name=='5'){
            for(unsigned i=0;i<_all_particules.size();i++){
                Vector3D speed=_all_particules[i]->getPosition();
                speed[1]+=200;
                _all_particules[i]->setPosition(speed);
            }
        }
        if(all_key_pressed[i].name=='6'){
            for(unsigned i=0;i<_all_particules.size();i++){
                Vector3D speed=_all_particules[i]->getPosition();
                speed[0]+=20;
                _all_particules[i]->setPosition(speed);
            }
        }
        if(all_key_pressed[i].name=='4'){
            for(unsigned i=0;i<_all_particules.size();i++){
                Vector3D speed=_all_particules[i]->getPosition();
                speed[0]-=20;
                _all_particules[i]->setPosition(speed);
            }
        }
        
    }
}
void Game::clearAllParticules(){
    unsigned size=_all_particules.size();
    for(unsigned i=0;i<size;i++){
        delete _all_particules[_all_particules.size()-1];
        _all_particules.pop_back();
    }
}
void Game::gameloop(){
    //Start the clock for the gameloop:
    static auto last_time_of_gameloop = std::chrono::high_resolution_clock::now();

    //Update Input:
    updateInput();
    //Update Logic:
    updateLogic();
    //Update Graphics:
    updateGraphic();

    //Stop the clock and make constant frame:
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - last_time_of_gameloop;
    //cout<<"Time between two frame: "<<elapsed.count()<<" s"<<endl;
    last_time_of_gameloop=finish;
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
    if(sleeping_time<100)sleeping_time=100;
    usleep(sleeping_time);
}
Game::~Game(){
    for(unsigned i=0;i<_all_particules.size();i++)
        delete _all_particules[i];
    for(unsigned i=0;i<_all_inputs.size();i++)
        delete _all_inputs[i];
}