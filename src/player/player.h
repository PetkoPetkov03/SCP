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
    float speed;
    float bullet_speed;
    Vector2 position;
};