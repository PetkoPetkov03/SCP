#include "raylib.h"
#include <vector>
#include <iostream>
#include "player/player.h"
#include "window/window.h"
#include "bulletbehaviour/bullets.h"

int main()
{

    Window window;
    Vector2 WindowScale = window.GetWindowScale();

    InitWindow(WindowScale.x, WindowScale.y, "SCP");
    SetTargetFPS(60);

    Player *player = new Player(WindowScale);
    std::vector<Bullet> ExistingBullets;

    while (!WindowShouldClose())
    {
        BeginDrawing();
        {
            if (IsKeyPressed(KEY_UP))
            {
                Bullet *bullet = new Bullet(WindowScale, player->GetPlayerPosition(), player->GetBulletSpeed(), KEY_UP);
                ExistingBullets.push_back(*bullet);
            }
            if (IsKeyPressed(KEY_DOWN))
            {
                Bullet *bullet = new Bullet(WindowScale, player->GetPlayerPosition(), player->GetBulletSpeed(), KEY_DOWN);
                ExistingBullets.push_back(*bullet);
            }
            if (IsKeyPressed(KEY_LEFT))
            {
                Bullet *bullet = new Bullet(WindowScale, player->GetPlayerPosition(), player->GetBulletSpeed(), KEY_LEFT);
                ExistingBullets.push_back(*bullet);
            }
            if (IsKeyPressed(KEY_RIGHT))
            {
                Bullet *bullet = new Bullet(WindowScale, player->GetPlayerPosition(), player->GetBulletSpeed(), KEY_RIGHT);
                ExistingBullets.push_back(*bullet);
            }
            if (!ExistingBullets.empty())
            {
                for (std::vector<Bullet>::iterator bullet = ExistingBullets.begin(); bullet != ExistingBullets.end(); bullet++)
                {
                    bullet.base()->MoveAuto(WindowScale);
                    bullet.base()->Draw(WindowScale);
                }
            }
            player->Move(WindowScale);
            ClearBackground(RAYWHITE);
            DrawText("Future Scp", WindowScale.x / 2, WindowScale.y / 2, 20, LIGHTGRAY);
            player->Draw(WindowScale);
        }
        EndDrawing();
    }

    CloseWindow();

    return 0;
}