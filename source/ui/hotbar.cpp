#include "raylib.h"
#include "hotbar/hotbar.h"
#include <vector>

void HotbarCls::InitHotbar(Hotbar& hotbar, int count, float size, float spacing) {
    hotbar.slots.clear();

    float screenWidth = (float)GetScreenWidth();
    float screenHeight = (float)GetScreenHeight();

    float totalWidth = count * size + (count - 1) * spacing;
    float startX = (screenWidth - totalWidth) / 2.0f;
    float startY = screenHeight - size - 20.0f;

    for (int i = 0; i < count; i++) {
        HotbarSlot slot;
        slot.bounds = {
            startX + i * (size + spacing),
            startY,
            size,
            size
        };
        slot.itemID = -1;

        hotbar.slots.push_back(slot);
    }
}

void HotbarCls::UpdateHotbar(Hotbar& hotbar) {
    Vector2 mouse = GetMousePosition();

    for (int i = 0; i < hotbar.slots.size(); i++) {
        if (CheckCollisionPointRec(mouse, hotbar.slots[i].bounds)) {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                hotbar.selectedIndex = i;
            }
        }
    }
    for (int i = 0; i < hotbar.slots.size(); i++) {
        if (IsKeyPressed(KEY_ONE + i)) {
            hotbar.selectedIndex = i;
        }
    }
}

void HotbarCls::DrawHotbar(const Hotbar& hotbar) {
    Vector2 mouse = GetMousePosition();

    for (int i = 0; i < hotbar.slots.size(); i++) {
        const HotbarSlot& slot = hotbar.slots[i];
        bool hovered = CheckCollisionPointRec(mouse, slot.bounds);
        bool selected = (i == hotbar.selectedIndex);
        Color color = DARKGRAY;
        if (hovered) color = GRAY;
        if (selected) color = GOLD;
        DrawRectangleRec(slot.bounds, color);
        DrawRectangleLinesEx(slot.bounds, 2, BLACK);
        DrawText(TextFormat("%d", i + 1),
                slot.bounds.x + 5,
                slot.bounds.y + 5,
                16,
                WHITE);
        if (slot.itemID != -1) {
            DrawCircle(slot.bounds.x + slot.bounds.width / 2, slot.bounds.y + slot.bounds.height / 2, 10, SKYBLUE);
        }
    }
}