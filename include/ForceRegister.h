#ifndef FORCE_REGISTER_H
#define FORCE_REGISTER_H

#include <vector>
#include "ParticuleForceGenerator.h"
#include "Particule.h"

//Define struct for force:
struct ForceRecording{
    Particule *p;
    ParticuleForceGenerator *fg;
} typedef ForceRecording;

class ForceRegister{
    public:
        //Constructor:
        ForceRegister(){};

        //Methods
        void addForce(Particule *p,ParticuleForceGenerator *fg);
        void deleteForce(Particule *p,ParticuleForceGenerator *fg);
        void updateAllForce(double delta_t);
        void clearAllForce();

        //Getter:
        inline std::vector<ForceRecording> getRegister(){return _register;}

    protected:
        std::vector<ForceRecording> _register;

};

#endif