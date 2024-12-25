#ifndef OBJECT_H
#define OBJECT_H
#include "raylib.h"

enum ObjectType{
	CUBE,
	SPHERE,
	CYLINDER
};

typedef struct{
	Mesh mesh;
	Vector3 position;
	Vector3 force;
	Model model;
}Object;

void createObject(enum ObjectType objectType,Vector3 position,Vector3 force,Object **objects,int *nbOfObjects);

#endif
