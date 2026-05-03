#include "raylib.h"
#include "camera/camera.h"

Vector2 dt = GetMouseDelta();

void Cam::pan(float speed) {
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        mx += dt.x * speed;
        my += dt.y * speed;
    }
}