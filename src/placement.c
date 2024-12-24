#include "placement.h"
#include "raylib.h"

void cursorPlacement(Camera3D *camera, BoundingBox box){
    Ray mouseRay = GetScreenToWorldRay(GetMousePosition(),*camera);
    RayCollision coll = GetRayCollisionBox(mouseRay, box);
    if(coll.hit){
        Vector3 cubeDim = {2,2,2};
        Vector3 cubePos = {coll.point.x,coll.point.y + (cubeDim.y/2),coll.point.z};
        DrawCubeWiresV(cubePos,cubeDim,RED);
    }
}
