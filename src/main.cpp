#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    std::cout << "Starting SFML 3 app...\n";

    // Tworzenie okna
    sf::RenderWindow window(
        sf::VideoMode({800, 600}),
        "SFML 3 - Test Window"
    );

    window.setFramerateLimit(60);

    // Prosty obiekt do rysowania
    sf::RectangleShape rect;
    rect.setSize({200.f, 120.f});
    rect.setFillColor(sf::Color::Green);
    rect.setPosition({300.f, 240.f});

    // Pętla główna
    while (window.isOpen())
    {
        // Obsługa zdarzeń
        while (const std::optional<sf::Event> event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        // Rysowanie
        window.clear(sf::Color(30, 30, 30));
        window.draw(rect);
        window.display();
    }

    std::cout << "SFML app closed cleanly.\n";
    return 0;
}
