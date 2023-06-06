#include <raylib.h>

void DrawScailer(Vector2 WindowScale, Window window)
{
    window.DrawButton();
    DrawText("Scailer", WindowScale.x / 2, 0, 20, BLACK);
    ClearBackground(GRAY);
}