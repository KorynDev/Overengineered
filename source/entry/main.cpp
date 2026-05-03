#include "raylib.h"
#include <iostream>

// my incs
#include "entry/entry.h"
#include "camera/camera.h"

void Cam::setup() {
    camera.offset = {0,0};
    camera.rotation = {0};
    camera.target = {0,0};
    camera.zoom = 1.0;
}

void Game::init() {
    InitWindow(1280, 720, "Overengineered version 0.01");
    Cam cam;
    SetTargetFPS(144);

    while (!WindowShouldClose()) {
        float dt = GetFrameTime();
        Vector2 dt = GetMouseDelta();
        Vector2 mouse = GetMousePosition();
        BeginDrawing();
        ClearBackground(BLACK);
        BeginMode2D(cam.camera);



        EndMode2D();
        EndDrawing();
    }
    CloseWindow();
}