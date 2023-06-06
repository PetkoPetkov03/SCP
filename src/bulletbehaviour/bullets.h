#include <raylib.h>

class Bullet
{

public:
    Bullet(Vector2 WindowScale, Vector2 PlayerPosition, float BulletSpeed, int frames, KeyboardKey key, Player *player)
    {

        if (player->CanShoot())
        {
            fired = true;
            if (key == KEY_UP)
            {
                direction.up = true;
                direction.down = false;
                direction.left = false;
                direction.right = false;
                player->Shoot();
            }
            if (key == KEY_DOWN)
            {
                direction.down = true;
                direction.up = false;
                direction.left = false;
                direction.right = false;
                player->Shoot();
            }
            if (key == KEY_LEFT)
            {
                direction.left = true;
                direction.down = false;
                direction.up = false;
                direction.right = false;
                player->Shoot();
            }
            if (key == KEY_RIGHT)
            {
                direction.right = true;
                direction.down = false;
                direction.left = false;
                direction.up = false;
                player->Shoot();
            }
        }else{
            fired = false;
        }

        speed = BulletSpeed;
        position.x = PlayerPosition.x;
        position.y = PlayerPosition.y;
    }

    Vector2 GetPosition() {
        return position;
    }

    void Draw(Vector2 WindowScale)
    {
        if(ShouldDraw()) {
            return DrawCircleV(position, (WindowScale.x / WindowScale.y) * 1.2, MAROON);
        }
    }

    bool ShouldDraw() {
        return fired;
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

    Bullet* GetSelf() {
        return self;
    }

private:
    float speed;
    float damage;
    Vector2 position;
    bool fired;
    struct direction
    {
        bool up;
        bool down;
        bool left;
        bool right;
    } direction;

    Bullet* self;
};