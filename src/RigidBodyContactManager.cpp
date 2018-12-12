#include "RigidBodyContactManager.h"

using namespace std;

void generateContacts(RigidBody * a, RigidBody *b, CollisionData * data){
    //On regarde si on ne regarde pas une collision entres deux murs
    if(a->getTag()!="Wall" || b->getTag()!="Wall"){
        //On calcule l'eqq de plan:
        Vector3D normal(0,0,0);
        double distance=0;
        RigidBody * other;

        if(a->getTag()=="Wall"){
            //Calcul de la normale:
            normal=a->getPosition().normalize();

            //Calcul de la distance:
            distance=a->getPosition().norm();
            distance*=-1;

            other=b;
        }
        if(b->getTag()=="Wall"){
            //Calcul de la normale:
            normal=b->getPosition().normalize();

            //Calcul de la distance:
            distance=b->getPosition().norm();
            distance*=-1;

            other=a;
        }

        vector<Vector3D> all_corners=other->getCorners();
        for(unsigned i=0;i<all_corners.size();i++){
            if(normal.scalarProduct((RigidBody::localToWorld(all_corners[i],other->getTransformMatrix())+other->getPosition()))+distance>=0){
                //On créer le contact:
                ContactType new_contact;
                new_contact.contactPoint=new Vector3D(RigidBody::localToWorld(all_corners[i],other->getTransformMatrix())+other->getPosition());
                new_contact.contactNormal=new Vector3D((*(new_contact.contactPoint)-other->getPosition()).normalize());
                new_contact.rb_contact=other;
                new_contact.interpenetration=normal.scalarProduct((RigidBody::localToWorld(all_corners[i],other->getTransformMatrix())+other->getPosition()))+distance;

                //On rajoute a la liste des contacts:
                data->contacts.push_back(new_contact);
                data->contacts_restant=(int)data->contacts.size();
            }
        }
    }
}