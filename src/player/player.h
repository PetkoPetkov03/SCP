#include <raylib.h>

class Player
{
public:
    Player(Vector2 WindowScale)
    {
        speed = WindowScale.x * 0.01;
        bullet_speed = WindowScale.x * 0.01;
        position.x = WindowScale.x / 2;
        position.y = WindowScale.y / 2;
        bullet_capacity = 12;
        health = 24;
        reload_speed = 60 * 3;
        need_to_reload = false;
    }

    void Draw(Vector2 WindowScale)
    {
        return DrawCircleV(position, (WindowScale.x / WindowScale.y) * 16.8, MAROON);
    }

    Vector2 GetPlayerPosition()
    {
        return position;
    }

    float GetBulletSpeed()
    {
        return bullet_speed;
    }

    bool CanShoot() {
        if(bullet_capacity != 0){
            return true;
        }else {
            need_to_reload = true;
            return false;
        }
    }

    int GetClip() {
        return bullet_capacity;
    }

    void GetCurrentFrame(int frame) {
        if(!tick_already_checked && need_to_reload) {
            start_reload_tick = frame;
            tick_already_checked = true;
        }
    }

    void Shoot() {
        bullet_capacity -= 1;
    }

    int GetCurrentHealth() {
        return health;
    }

    void Reload(int tick) {
        if(start_reload_tick != 0 && tick >= start_reload_tick+reload_speed && need_to_reload) {
            bullet_capacity = 12;
            start_reload_tick = 0;
            tick_already_checked = false;
            need_to_reload = false;
        }
    }

    void ForceReload(int frame) {
        bullet_capacity = 0;
        need_to_reload = true;
        GetCurrentFrame(frame);
    }

    void Move(Vector2 WindowScale)
    {
        if (IsKeyDown(KEY_A) && position.x > 0 + (WindowScale.x / WindowScale.y) * 16.8)
        {
            position.x -= 0.5 * speed;
        }
        if (IsKeyDown(KEY_D) && position.x < WindowScale.x - (WindowScale.x / WindowScale.y) * 16.8)
        {
            position.x += 0.5 * speed;
        }
        if (IsKeyDown(KEY_W) && position.y > 0 + (WindowScale.x / WindowScale.y) * 16.8)
        {
            position.y -= 0.5 * speed;
        }
        if (IsKeyDown(KEY_S) && position.y < WindowScale.y - (WindowScale.x / WindowScale.y) * 16.8)
        {
            position.y += 0.5 * speed;
        }
    }

private:
    int health;
    float speed;
    float bullet_speed;
    Vector2 position;
    int bullet_capacity;
    int reload_speed;
    bool need_to_reload;
    int start_reload_tick;
    bool tick_already_checked = false;
};