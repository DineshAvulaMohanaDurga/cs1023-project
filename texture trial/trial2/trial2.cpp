#include <SFML/Graphics.hpp>

int main()
{
        sf::RenderWindow window(sf::VideoMode(800, 600), "SFML art");
        window.setVerticalSyncEnabled(true);

        sf::RenderTexture target;
        if (!target.create(window.getSize().x, window.getSize().y))
                return -1;

        sf::Texture baseballTexture;

        if (!baseballTexture.loadFromFile("baseball.png")) // any baseball texture https://www.fotolia.com/p/202657402
                return -1;

        sf::Sprite baseball(baseballTexture);

        target.clear(sf::Color::White);
        target.draw(baseball, sf::BlendAlpha);
        target.display();

        while (window.isOpen())
        {
                sf::Event event;
                while (window.pollEvent(event))
                {
                        if (event.type == sf::Event::Closed)
                                window.close();
                }

                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                        // draw blood drops over background as many as you like
                        sf::CircleShape circle(5.f, 32u);
                        circle.setPosition(sf::Vector2f(sf::Mouse::getPosition(window)));
                        circle.setFillColor(sf::Color(255, 0, 0, 50));
                        target.draw(circle, sf::BlendAlpha);
                        target.display();
                }

                window.clear();
                window.draw(sf::Sprite(target.getTexture()));
                window.display();
        }
}