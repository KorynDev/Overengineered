#include "raylib.h"
#include <iostream>

// my incs
#include "entry/entry.h"
#include "camera/camera.h"

void Cam::setup() {
    camera.offset = {0,0};
    camera.rotation = {0};
    camera.target.x += (mx - camera.target.x) * 0.15f;
    camera.target.y += (my - camera.target.y) * 0.15f;
    camera.zoom = 1.0;
}

void Game::init() {
    InitWindow(1280, 720, "Overengineered version 0.01");
    Cam cam;
    cam.setup();
    SetTargetFPS(144);

    while (!WindowShouldClose()) {
        float dt = GetFrameTime();
        BeginDrawing();
        ClearBackground(GRAY);
        cam.pan(4.0f);
        cam.zoom();
        BeginMode2D(cam.camera);

        DrawCircle(400, 700, 20, RED);
        EndMode2D();
        EndDrawing();
    }
    CloseWindow();
}