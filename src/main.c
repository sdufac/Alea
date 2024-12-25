#include "raylib.h"
#include "cameraMovement.h"
#include "placement.h"
#include "object.h"
#include "stdlib.h"
#include "math.h"
#include "assert.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1200;
    const int screenHeight = 675;

    Object* objects= malloc(sizeof(Object));
    int nbOfObjects = 0;

    InitWindow(screenWidth, screenHeight, "Alea");

    //Initializa plane
    Object plane;
    plane.position = (Vector3){0};
    plane.mesh = GenMeshPlane(20,20,2,2);
    plane.force = (Vector3){0};
    plane.model = LoadModelFromMesh(plane.mesh);
    Image planeColor = GenImageColor(1,1,GRAY);
    Texture2D planeTexture = LoadTextureFromImage(planeColor);
    plane.model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = planeTexture;
    UnloadImage(planeColor);

    objects[0] = plane;
    nbOfObjects++;

    // Define the camera to look into our 3d world
    Camera3D camera = { 0 };
    camera.position = (Vector3){ 0.0f, 7.0f, 25.0f };  // Camera position
    camera.target = (Vector3){ 0.0f, 2.0f, 0.0f };      // Camera looking at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;             // Camera mode type

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------

        // Placement 
        //----------------------------------------------------------------------------------
        Vector3 mousePoint = getMousePoint(&camera,&objects,nbOfObjects);
        bool canplace = canPlace(mousePoint,&objects,nbOfObjects);

        // Controls
        //----------------------------------------------------------------------------------
        cameraMovement(&camera,0.015);
        if(canplace && IsKeyPressed(KEY_A)){
            createObject(CUBE,mousePoint,(Vector3){0},&objects,&nbOfObjects);
            assert(objects!= NULL);
        }
        

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
            ClearBackground(RAYWHITE);

            BeginMode3D(camera);
                //Draw place indicator
                if(canplace){
                    Vector3 size;
                    size.x=2.0f;
                    size.y=2.0f;
                    size.z=2.0f;

                    Vector3 position = {
                        mousePoint.x,
                        mousePoint.y + (size.y/2),
                        mousePoint.z
                    };
                    DrawCubeWiresV(position,size,GREEN);
                }else if(!isnanf(mousePoint.x && !canplace)){
                    Vector3 size;
                    size.x=2.0f;
                    size.y=2.0f;
                    size.z=2.0f;
                    Vector3 position = {
                        mousePoint.x,
                        mousePoint.y + (size.y/2),
                        mousePoint.z
                    };
                    DrawCubeWiresV(position,size,RED);
                }
                    

                for(int i = 0; i<nbOfObjects; i++){
                    Object object = objects[i];
                    DrawModel(object.model,object.position,1,WHITE);            
                }
        

            EndMode3D();

            DrawFPS(10, 10);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
