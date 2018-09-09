#include "Utils.h"

using namespace std;

void log(std::string msg){
    cout<<"\033[31m"<<"\033[1m"<<"[LOG] "<<"\033[0m"<<msg<<endl;
}
void log(std::string header,std::string msg){
    cout<<"\033[31m"<<"\033[1m"<<"["<<header<<"] "<<"\033[0m"<<msg<<endl;
}
void log(std::string header,std::string msg,bool check_is_valid){
    if(check_is_valid)
        cout<<"\033[42m"<<"\033[1m"<<"OK"<<"\033[0m "<<"\033[31m"<<"\033[1m"<<"["<<header<<"] "<<"\033[0m"<<msg<<endl;
    else
        cout<<"\033[41m"<<"\033[1m"<<"KO"<<"\033[0m "<<"\033[31m"<<"\033[1m"<<"["<<header<<"] "<<"\033[0m"<<msg<<endl;
}

void drawCube(){
    gluLookAt(3,4,2,1,1,1,0,0,1);

    GLUquadric* params;
    params = gluNewQuadric();

    gluQuadricDrawStyle(params,GLU_FILL);

    gluSphere(params,1.0,100,100);

    
}