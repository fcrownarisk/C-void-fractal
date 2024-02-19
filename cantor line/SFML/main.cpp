#include <SFML/Graphics.hpp>
#include"CantorFractal.h"
using namespace sf;
int main()
{
    RenderWindow window(VideoMode(1000, 1000), L"����� ������", Style::Default);

    window.setVerticalSyncEnabled(true);

    CircleShape shape(100.f, 3);
    shape.setPosition(100, 100);
    shape.setFillColor(Color::Magenta);
       while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        window.clear(Color::Black);
        CantorFractal cantorFractal(0.333);
        int iter = 8;
        float length = 995;
        Vector2f startPos = Vector2f(5, 10);
        cantorFractal.draw(window,iter,length, startPos);
        //window.draw(line,2,Lines);
        window.display();
    }
    return 0;
}