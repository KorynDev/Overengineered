#include "raylib.h"
#include <cmath>
#include "conveyors/conveyor.h"

const int TILE_SIZE = 50;

Vector2 WorldToGrid(Vector2 world) {
    return {
        (float)std::floor(world.x / TILE_SIZE),
        (float)std::floor(world.y / TILE_SIZE)
    };
}
Vector2 GridToWorld(Vector2 grid) {
    return {
        grid.x * TILE_SIZE,
        grid.y * TILE_SIZE
    };
}

void Conveyor::placeConveyor(Camera2D camera) {
    Vector2 mouseWorld = GetScreenToWorld2D(GetMousePosition(), camera);
    Vector2 grid = WorldToGrid(mouseWorld);
    Vector2 snapped = GridToWorld(grid);
    if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
        exists = false;
        for (auto& t : placed) {
            if (t.x == snapped.x && t.y == snapped.y) {
                exists = true;
                break;
            }
        }
        if (!exists) {
            placed.push_back({ snapped.x, snapped.y });
        }
    }
    for (auto& t : placed) {
        DrawRectangle(t.x, t.y, TILE_SIZE, TILE_SIZE, BLACK);
    }
}

void Conveyor::DrawGrid(Camera2D camera) {
    Vector2 topLeft = GetScreenToWorld2D({0, 0}, camera);
    Vector2 bottomRight = GetScreenToWorld2D({1280, 720}, camera);
    int startX = floor(topLeft.x / TILE_SIZE) * TILE_SIZE;
    int endX   = floor(bottomRight.x / TILE_SIZE) * TILE_SIZE;
    int startY = floor(topLeft.y / TILE_SIZE) * TILE_SIZE;
    int endY   = floor(bottomRight.y / TILE_SIZE) * TILE_SIZE;
    for (int x = startX; x <= endX; x += TILE_SIZE)
        DrawLine(x, startY, x, endY, Fade(BLACK, 0.2f));
    for (int y = startY; y <= endY; y += TILE_SIZE)
        DrawLine(startX, y, endX, y, Fade(BLACK, 0.2f));
}