#include "placement.h"
#include "object.h"
#include "raylib.h"
#include "math.h"

Vector3 getMousePoint(Camera3D *camera, Object **objects, int nbOfObject){
    Ray mouseRay = GetScreenToWorldRay(GetMousePosition(),*camera);
    Object objUnderMouse;
    float distance = -1;
    Vector3 collPoint = {NAN};

    for(int i = 0; i < nbOfObject; i++){
        RayCollision coll = GetRayCollisionBox(mouseRay,GetMeshBoundingBox(objects[i]->mesh));
        if(coll.hit){
            if(distance == -1 || distance>coll.distance){
                distance = coll.distance;
                objUnderMouse = *objects[i];
                collPoint = coll.point;
            }
        }
    }
    return collPoint;
}

bool canPlace(Vector3 placePoint,Object **objects, int nbOfObject){
    if(isnanf(placePoint.x)){
        return false;
    }

    bool noColl = true;
    Vector3 cubeDim = {2,2,2};
    BoundingBox box={
        (Vector3){placePoint.x - (cubeDim.x/2),placePoint.y + 0.001,placePoint.z - (cubeDim.z/2)},
        (Vector3){placePoint.x + (cubeDim.x/2),placePoint.y + cubeDim.y,placePoint.z + (cubeDim.z/2)}
    };

    for(int i = 0; i < nbOfObject; i++){
        if(CheckCollisionBoxes(box,GetMeshBoundingBox(objects[i]->mesh))){
            noColl=false;
        } 
    }
    
    return noColl;
}
