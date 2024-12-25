#include "raylib.h"
#include "object.h"
#include "stdlib.h"
#include "assert.h"

void createObject(enum ObjectType objectType,Vector3 position,Vector3 force,Object **objects,int *nbOfObjects){
    Object* temp = realloc(*objects, sizeof(Object*)* (*nbOfObjects+1));
    assert(temp != NULL);

    *objects = temp;

    Object* object = malloc(sizeof(Object));

    if(objectType == CUBE){
        object->mesh = GenMeshCube(2,2,2);
    }else if(objectType == SPHERE){
        object->mesh = GenMeshSphere(1,16,16);
    }else if(objectType == CYLINDER){
        object->mesh = GenMeshCylinder(1,2,2);
    }

    object->position = position;
    object->force = force;
    object->model = LoadModelFromMesh(object->mesh);

    Image color = GenImageColor(1,1,PINK);
    Texture2D texture = LoadTextureFromImage(color);
    object->model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;
    UnloadImage(color);

    (*objects)[*nbOfObjects] = *object;
    (*nbOfObjects)++;
}
