#ifndef PLACEMENT_H
#define PLACEMENT_H
#include "raylib.h"
#include "object.h"

Vector3 getMousePoint(Camera3D *camera,Object **objects, int nbOfObject);
bool canPlace(Vector3 placePoint,Object **objects, int nbOfObject);

#endif
