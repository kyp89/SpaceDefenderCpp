#include "main.hpp"

int main()
{
    std::cout << "Starting SFML 3 app...\n";
    Managers::AssetsManager assetManager();
    // Tworzenie okna
    sf::RenderWindow window(
        sf::VideoMode({GAME_FILED_H, GAME_FIELD_W}),
        "SFML 3 - Test Window"
    );

    window.setFramerateLimit(FRAME_LIMIT);

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
