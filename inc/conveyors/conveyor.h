#pragma once
#include "raylib.h"
#include <vector>

class Conveyor {
public:
    void placeConveyor(Camera2D camera);
    void DrawGrid(Camera2D camera);
    enum states { PLACE, SELECTED, PICKUP, NONE };
    states state = NONE;
    struct Tile {
        float x;
        float y;
    };
    bool exists = false;
    std::vector<Tile> placed;
};