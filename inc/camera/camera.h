#pragma once
#include "raylib.h"

class Cam {
public:
    void setup();
    void pan(float speed);
    void zoom(float amount, float speed, float max);
    Camera2D camera;
    Vector2 mouse = GetMousePosition();
    float mx = mouse.x;
    float my = mouse.y;
};