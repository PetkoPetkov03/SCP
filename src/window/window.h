#include <raylib.h>

class Window
{
public:
    Window()
    {
        window.x = 1920;
        window.y = 1080;
    }

    Vector2 GetWindowScale(void)
    {
        return window;
    }

private:
    Vector2 window;
};