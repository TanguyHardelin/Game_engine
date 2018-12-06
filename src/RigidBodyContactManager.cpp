#include "RigidBodyContactManager.h"

using namespace std;

bool generateContacts(RigidBody * a, RigidBody *b, CollisionData * data){
    //On regarde si on ne regarde pas une collision entres deux murs
    if(a->getTag()!="Wall" || b->getTag()!="Wall"){
        //On calcule l'eqq de plan:
        Vector3D normal(0,0,0);
        double distance=0;
        RigidBody * other;
        cout<<"-----------------------"<<endl;
        if(a->getTag()=="Wall"){
            normal=a->getPosition();
            distance=a->getPosition().norm();

            cout<<"a= ";a->getPosition().display();
    /*
            for(unsigned i=0;i<3;i++){
                if(normal[i]==0) normal[i]=distance;
                else normal[i]=0;
            }
    */
            normal=normal.normalize();
            cout<<"normal a= ";normal.display();
            other=b;
        }
        if(b->getTag()=="Wall"){
            normal=b->getPosition();
            distance=b->getPosition().norm();

            cout<<"b= ";b->getPosition().display();
    /*
            for(unsigned i=0;i<3;i++){
                if(normal[i]==0) normal[i]=distance;
                else normal[i]=0;
            }
    */
            normal=normal.normalize();
            cout<<"normal b=";normal.display();
            other=a;
        }

        cout<<"other->getPosition() ";other->getPosition().display();
        vector<Vector3D> all_corners=other->getCorners();
        for(unsigned i=0;i<all_corners.size();i++){
            cout<<"normal.scalarProduct((all_corners[i]+b->getPosition()))+distance "<<normal.scalarProduct((all_corners[i]+other->getPosition()))-distance<<endl;
            if(normal.scalarProduct((all_corners[i]+other->getPosition()))+distance<=0){
                cout<<"Collision"<<endl;
            }
        }
        
    }
    return false;
}