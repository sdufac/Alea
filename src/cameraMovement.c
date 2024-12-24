#include "cameraMovement.h"
#include "raylib.h"
#include "raymath.h"

void cameraMovement(Camera3D *camera,float turnSpeed){
    if(IsKeyDown(KEY_LEFT)){
        Vector3 vecFromOrigin = Vector3Subtract(camera->position,camera->target);
        Vector3 rotatedVector = Vector3RotateByAxisAngle(vecFromOrigin,(Vector3){0,1,0},turnSpeed - (turnSpeed * 2));

        Vector3 newPosition = Vector3Add(camera->target,rotatedVector);
        camera->position = newPosition;
    }else if(IsKeyDown(KEY_RIGHT)){
        Vector3 vecFromOrigin = Vector3Subtract(camera->position,camera->target);
        Vector3 rotatedVector = Vector3RotateByAxisAngle(vecFromOrigin,(Vector3){0,1,0},turnSpeed);

        Vector3 newPosition = Vector3Add(camera->target,rotatedVector);
        camera->position = newPosition;
    }
}
