#include "raylib.h"
#include <vector>
#include <iostream>
#include "player/player.h"
#include "window/window.h"
#include "bulletbehaviour/bullets.h"
#include "entities/enemies.h"
#include <math.h>

int main()
{

    Window window;
    Vector2 WindowScale = window.GetWindowScale();

    InitWindow(WindowScale.x, WindowScale.y, "SCP");
    SetTargetFPS(60);

    Player *player = new Player(WindowScale);
    std::vector<Bullet> ExistingBullets;

    int NumberOfEnemies = 1+rand()%5;
    std::vector<Enemy> Enemies;

    for(int i = 0; i < NumberOfEnemies; i++) {
        Enemy* SpawnEnemy = new Enemy(WindowScale);
        Enemies.push_back(*SpawnEnemy);
    }

    int FrameTicks = 0;

    std::cout << NumberOfEnemies << std::endl;

    while (!WindowShouldClose())
    {
        FrameTicks++;
        BeginDrawing();
        {
            if (IsKeyPressed(KEY_UP))
            {
                Bullet *bullet = new Bullet(WindowScale, player->GetPlayerPosition(), player->GetBulletSpeed(), FrameTicks, KEY_UP, player);
                ExistingBullets.push_back(*bullet);
            }
            if (IsKeyPressed(KEY_DOWN))
            {
                Bullet *bullet = new Bullet(WindowScale, player->GetPlayerPosition(), player->GetBulletSpeed(), FrameTicks, KEY_DOWN, player);
                ExistingBullets.push_back(*bullet);
            }
            if (IsKeyPressed(KEY_LEFT))
            {
                Bullet *bullet = new Bullet(WindowScale, player->GetPlayerPosition(), player->GetBulletSpeed(), FrameTicks, KEY_LEFT, player);
                ExistingBullets.push_back(*bullet);
            }
            if (IsKeyPressed(KEY_RIGHT))
            {
                Bullet *bullet = new Bullet(WindowScale, player->GetPlayerPosition(), player->GetBulletSpeed(), FrameTicks, KEY_RIGHT, player);
                ExistingBullets.push_back(*bullet);
            }
            if (!ExistingBullets.empty())
            {
                for (std::vector<Bullet>::iterator bullet = ExistingBullets.begin(); bullet != ExistingBullets.end(); bullet++)
                {
                    bullet.base()->MoveAuto(WindowScale);
                    Vector2 position = bullet.base()->GetPosition();
                    bullet.base()->Draw(WindowScale);
                }
            }

            if(IsKeyPressed(KEY_R)){
                player->ForceReload(FrameTicks);
            }

            if(!Enemies.empty()){
                for(std::vector<Enemy>::iterator enemy = Enemies.begin(); enemy != Enemies.end(); enemy++){
                    enemy.base()->Draw(WindowScale);
                }
            }

            player->Move(WindowScale);
            player->GetCurrentFrame(FrameTicks);
            player->Reload(FrameTicks);
            ClearBackground(RAYWHITE);
            DrawText("Future Scp", WindowScale.x / 2, WindowScale.y / 2, 20, LIGHTGRAY);
            std::string bullets = "Bullets: " + std::to_string(player->GetClip());
            DrawText(bullets.c_str(), WindowScale.x - 155, WindowScale.y - 50, 30, BLACK);
            std::string health = "Health: " + std::to_string(player->GetCurrentHealth());
            DrawText(health.c_str(), 10, WindowScale.y - 50, 30, BLACK);
            player->Draw(WindowScale);
            
        }
        EndDrawing();
    }

    CloseWindow();

    return 0;
}