#include "raylib.h"
#include <iostream>
#include <string>

// my incs
#include "entry/entry.h"
#include "camera/camera.h"
#include "conveyors/conveyor.h"
#include "hotbar/hotbar.h"

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
    Conveyor c;
    Hotbar hotbar;
    HotbarCls hotbarcls;
    hotbarcls.InitHotbar(hotbar, 8, 60, 10);
    hotbar.slots[0].itemID = 1;
    hotbar.slots[1].itemID = 2;
    cam.setup();
    SetTargetFPS(144);

    while (!WindowShouldClose()) {
        float dt = GetFrameTime();
        hotbarcls.UpdateHotbar(hotbar);
        BeginDrawing();
        ClearBackground(GRAY);
        hotbarcls.DrawHotbar(hotbar);
        cam.pan(4.0f);
        cam.zoom();
        BeginMode2D(cam.camera);
        c.DrawGrid(cam.camera);
        c.placeConveyor(cam.camera);
        EndMode2D();
        EndDrawing();
    }
    CloseWindow();
}