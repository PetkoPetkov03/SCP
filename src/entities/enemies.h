#include <raylib.h>
#include <math.h>
#include <iostream>

class Enemy {
    public:
        Enemy(Vector2 WindowScale) {
            position.x = 1+rand()%(int(WindowScale.x) - 50);
            position.y = 1+rand()%(int(WindowScale.y) - 50);
        }

        Vector2 GetPosition() {
            return position;
        }

        void Draw(Vector2 WindowScale) {
            return DrawCircleV(position, (WindowScale.x / WindowScale.y) * 16.8, BLACK);
        }

        void Follow(Vector2 PlayerPosition) {
            
        }

    private:
        int health;
        float speed;
        Vector2 position;
};