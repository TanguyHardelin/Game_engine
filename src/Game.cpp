#include "Game.h"

using namespace std;

/*
    TODO LIST:
    -  Mettre resolution de contact comme vu dans le cour (prioritee de resolution ect ...)
    -  Separation Blob*/

Game::Game(){
    _particule_contact_generator    = ParticuleContactGenerator();
    _particule_contact_resolver     = ParticuleContactResolver();
    _continue_game                  = true;
    
    
    createNewParticule(Vector3D(0,250,100),Vector3D(0,10,0),Vector3D(0,0,0),10,10);
    createNewParticule(Vector3D(0,50,100),Vector3D(0,10,0),Vector3D(0,0,0),10,10);

    _force_register.addForce(_all_particules[0],new GravityForce(10));
    _force_register.addForce(_all_particules[1],new GravityForce(10));
  
    addBlobToGame(new Blob(4,4,4,Vector3D(50,50,50),Vector3D(50,50,50),&_particule_contact_generator,&_force_register,&_graphics));
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
    //_graphics.addFloor(Vector3D(255,255,255));

    //We draw all particules:
    for(int i=0;i<(int)_all_particules.size();i++){
        _graphics.addSphere(_all_particules[i]->getPosition(),2*_all_particules[i]->getRadius(),_all_particules[i]->getColor());   
    }
    //We draw all blobs:
    for(int i=0;i<(int)_all_blobs.size();i++){
        _all_blobs[i]->drawBlob();
    }
    _graphics.draw();
 
}
void Game::createNewParticule(Vector3D position,Vector3D speed,Vector3D acceleration,double mass,double damping){
    //Create the particule
    _all_particules.push_back(new Particule(position,speed,acceleration,mass,5,Vector3D(255,139,59)));

    //Add force:
    //_force_register.addForce(_all_particules[_all_particules.size()-1],new GravityForce(20));
    //_force_register.addForce(_all_particules[_all_particules.size()-1],new DragForce(0.9,0.01));

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
    //Links:
    for(unsigned i=0;i<_all_links.size();i++){
        Vector3D current_length=_all_links[i]->getCurrentLength();
        Vector3D length=_all_links[i]->getLength();
        if(norm(current_length)>norm(length)+norm(length)/100.0f*10.0f || norm(current_length)<norm(length)-norm(length)/100.0f*10.0f){
            _particule_contact_generator.addContact(_all_links[i]);
        }
    }
    //Cables:
    for(unsigned i=0;i<_all_cables.size();i++){
        Vector3D current_length=_all_cables[i]->getCurrentLength();
        Vector3D length=_all_cables[i]->getLength();
        if(norm(current_length)!=norm(length)){
            _particule_contact_generator.addContact(_all_cables[i]);
        }
    }
    //Other contact resolution:
    for(unsigned i=0;i<_all_particules.size();i++){
        for(unsigned j=0;j<_all_particules.size();j++){
            if(i!=j){
                //Simple contact:
                if(norm(_all_particules[i]->getPosition()-_all_particules[j]->getPosition())<=10){
                    vector<Particule *> particules;
                    particules.push_back(_all_particules[j]);
                    particules.push_back(_all_particules[i]);
                    _particule_contact_generator.addContact(new ParticuleContact(particules,0.9));
                }
            }
            if(i==j){
                //Manage floor colision:
                if(_all_particules[i]->getPosition().getY()<_all_particules[i]->getRadius()){
                    vector<Particule *> particules; 
                    particules.push_back(_all_particules[i]);
                    particules.push_back(_all_particules[i]);
                    _particule_contact_generator.addContact(new ParticuleFloorContact(particules,0.9));
                }
            }
        }
    }
    


    vector<ParticuleContact*> all_contacts=_particule_contact_generator.getContacts(); 

    _particule_contact_resolver.resolve(all_contacts,elapsed.count());

    _particule_contact_generator.clearContacts();
    
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
            addBlobToGame(new Blob(2,2,2,Vector3D(100,400,100),Vector3D(50,50,50),&_particule_contact_generator,&_force_register,&_graphics));
        } 
        if(all_key_pressed[i].name=='r'){
            createNewParticule(Vector3D(-500,100,0),Vector3D(400+rand()%200,100+rand()%100,rand()%10),Vector3D(0,-10,0),1+rand()%10,0.9);
            _force_register.addForce(_all_particules[_all_particules.size()-1],new GravityForce(10));
            _force_register.addForce(_all_particules[_all_particules.size()-1],new DragForce(0.01,0.0001));
        } 
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
            camera_position[2]-=30;
            _graphics.setPositionOfCamera(camera_position);
        }
        if(all_key_pressed[i].name=='s'){
            Vector3D camera_position=_graphics.getPositionOfCamera();
            camera_position[2]+=30;
            _graphics.setPositionOfCamera(camera_position);
        }
        if(all_key_pressed[i].name=='a'){
            Vector3D camera_position=_graphics.getPositionOfCamera();
            camera_position[1]+=30;
            _graphics.setPositionOfCamera(camera_position);
        }
        if(all_key_pressed[i].name=='e'){
            Vector3D camera_position=_graphics.getPositionOfCamera();
            camera_position[1]-=30;
            _graphics.setPositionOfCamera(camera_position);
        }

        //Mouvement of all blobs:
        if(all_key_pressed[i].name=='8'){
            for(unsigned i=0;i<_all_particules.size();i++){
                Vector3D pos=_all_particules[i]->getPosition();
                pos[2]-=20;
                _all_particules[i]->setPosition(pos);
            }
        }
        if(all_key_pressed[i].name=='2'){
            for(unsigned i=0;i<_all_particules.size();i++){
                Vector3D pos=_all_particules[i]->getPosition();
                pos[2]+=20;
                _all_particules[i]->setPosition(pos);
            }
        }
        if(all_key_pressed[i].name=='5'){
            for(unsigned i=0;i<_all_particules.size();i++){
                Vector3D pos=_all_particules[i]->getPosition();
                pos[1]+=200;
                _all_particules[i]->setPosition(pos);
            }
        }
        if(all_key_pressed[i].name=='6'){
            for(unsigned i=0;i<_all_particules.size();i++){
                Vector3D pos=_all_particules[i]->getPosition();
                pos[0]+=20;
                _all_particules[i]->setPosition(pos);
            }
        }
        if(all_key_pressed[i].name=='4'){
            for(unsigned i=0;i<_all_particules.size();i++){
                Vector3D pos=_all_particules[i]->getPosition();
                pos[0]-=20;
                _all_particules[i]->setPosition(pos);
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
void Game::addBlobToGame(Blob * blob){
    _all_blobs.push_back(blob);

    vector<ParticuleLinkContact *> all_links=blob->getAllLinks();
    _all_links.insert(_all_links.end(),all_links.begin(),all_links.end());
    
    vector<Particule *> all_particules=blob->getAllParticules();
    _all_particules.insert(_all_particules.end(),all_particules.begin(),all_particules.end());

    vector<ParticuleCableContact *> all_cables=blob->getAllCables();
    if(all_cables.size()>0) _all_cables.insert(_all_cables.end(),all_cables.begin(),all_cables.end());
}
Game::~Game(){
    for(unsigned i=0;i<_all_particules.size();i++)
        delete _all_particules[i];
    for(unsigned i=0;i<_all_links.size();i++)
        delete _all_links[i];
    
    for(unsigned i=0;i<_all_cables.size();i++)
        //delete _all_cables[i];
    
    
    for(unsigned i=0;i<_all_inputs.size();i++)
        delete _all_inputs[i];
}