#ifndef RIGIDBODY_CONTACT_MANAGER_H
#define RIGIDBODY_CONTACT_MANAGER_H

#include <iostream>
#include <vector>
#include "Vector3D.h"
#include "RigidBody.h"

typedef struct Contact{
    Vector3D contactPoint;
    Vector3D contactNormal;
    float    interpenetration;
} Contact;

typedef struct CollisionData{
    std::vector<Contact> contacts;
    int contacts_restant;
} CollisionData;

bool generateContacts(RigidBody * a, RigidBody * b, CollisionData * data);



#endif