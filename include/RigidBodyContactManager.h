#ifndef RIGIDBODY_CONTACT_MANAGER_H
#define RIGIDBODY_CONTACT_MANAGER_H

#include <iostream>
#include <vector>
#include "Vector3D.h"
#include "RigidBody.h"

typedef struct ContactType{
    Vector3D* contactPoint;
    Vector3D* contactNormal;
    float    interpenetration;
} ContactType;

typedef struct CollisionData{
    std::vector<ContactType> contacts;
    int contacts_restant;
} CollisionData;

void generateContacts(RigidBody * a, RigidBody * b, CollisionData * data);



#endif