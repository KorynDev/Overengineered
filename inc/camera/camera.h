#pragma once
#include "raylib.h"

class Cam {
public:
    void setup();
    void pan(float speed);
    void zoom();
    Camera2D camera;
    Vector2 mouse = GetMousePosition();
    float wheel = GetMouseWheelMove();
    float mx = 0;
    float my = 0;
};