#include <raylib.h>

class Bullet
{

public:
    Bullet(Vector2 WindowScale, Vector2 PlayerPosition, float BulletSpeed, KeyboardKey key)
    {
        if (key == KEY_UP)
        {
            direction.up = true;
        }
        else if (key == KEY_DOWN)
        {
            direction.down = true;
        }
        else if (key == KEY_LEFT)
        {
            direction.left = true;
        }
        else if (key == KEY_RIGHT)
        {
            direction.right = true;
        }

        speed = BulletSpeed;
        position.x = PlayerPosition.x;
        position.y = PlayerPosition.y;
    }

    void Draw(Vector2 WindowScale)
    {
        return DrawCircleV(position, (WindowScale.x / WindowScale.y) * 1.2, MAROON);
    }

    void MoveAuto(Vector2 WindowScale)
    {
        if (direction.up)
        {
            position.y -= 1 * speed;
        }
        else if (direction.down)
        {
            position.y += 1 * speed;
        }
        else if (direction.left)
        {
            position.x -= 1 * speed;
        }
        else if (direction.right)
        {
            position.x += 1 * speed;
        }
    }

private:
    float speed;
    float damage;
    Vector2 position;
    struct direction
    {
        bool up;
        bool down;
        bool left;
        bool right;
    } direction;
};