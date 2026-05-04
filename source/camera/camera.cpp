#include "raylib.h"
#include "raymath.h"
#include "camera/camera.h"

void Cam::pan(float speed) {
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        DisableCursor();
    }
    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
        EnableCursor();
    }
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        Vector2 dt = GetMouseDelta();
        mx -= dt.x * speed;
        my -= dt.y * speed;
    }
    camera.target.x += (mx - camera.target.x) * 0.15f;
    camera.target.y += (my - camera.target.y) * 0.15f;
}

void Cam::zoom() {
    float wheel = GetMouseWheelMove();

    camera.zoom += wheel * 0.1f;
    camera.zoom = Clamp(camera.zoom, 0.2f, 5.0f);
}