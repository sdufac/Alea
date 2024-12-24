#include "raylib.h"
#include "object.h"

Object createObject(enum ObjectType objectType,Vector3 position,Vector3 force){
    Object object;

    if(objectType == CUBE){
        object.mesh = GenMeshCube(2,2,2);
    }else if(objectType == SPHERE){
        object.mesh = GenMeshSphere(1,16,16);
    }else if(objectType == CYLINDER){
        object.mesh = GenMeshCylinder(1,2,2);
    }

    object.position = position;
    object.force = force;
    return object;
}
