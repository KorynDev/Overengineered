#pragma once
#include "raylib.h"
#include <vector>

struct HotbarSlot {
    Rectangle bounds;
    int itemID;
};

struct Hotbar {
    std::vector<HotbarSlot> slots;
    int selectedIndex = 0;
};

class HotbarCls {
public:
    void InitHotbar(Hotbar& hotbar, int count, float size, float spacing);
    void UpdateHotbar(Hotbar& hotbar);
    void DrawHotbar(const Hotbar& hotbar);
};