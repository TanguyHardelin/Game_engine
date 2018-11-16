#ifndef FORCE_REGISTER_H
#define FORCE_REGISTER_H

#include <vector>
#include "ParticuleForceGenerator.h"
#include "Particule.h"
#include "RigidBody.h"
#include  "RigidBodyForceGenerator.h"

//Define struct for force:
struct ParticuleForceRecording{
    Particule *p;
    ParticuleForceGenerator *fg;
} typedef ParticuleForceRecording;

struct RigidBodyForceRecording{
    RigidBody *p;
    RigidBodyForceGenerator *fg;
} typedef RigidBodyForceRecording;


class ForceRegister{
    public:
        //Constructor:
        ForceRegister(){};

        //Methods
        void addForce(Particule *p,ParticuleForceGenerator *fg);
        void deleteForce(Particule *p,ParticuleForceGenerator *fg);

        void addForce(RigidBody *p,RigidBodyForceGenerator *fg);
        void deleteForce(RigidBody *p,RigidBodyForceGenerator *fg);

        void updateAllForce(double delta_t);
        void clearAllForce();

        //Getter:
        inline std::vector<ParticuleForceRecording> getParticuleRegister(){return _particule_register;}
        inline std::vector<RigidBodyForceRecording> getRigidBodyRegister(){return _rigidBody_register;}

    protected:
        std::vector<ParticuleForceRecording> _particule_register;
        std::vector<RigidBodyForceRecording> _rigidBody_register;

};

#endif