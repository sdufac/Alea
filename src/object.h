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
}Object;

Object createObject(enum ObjectType objectType,Vector3 position,Vector3 force);

#endif
