#include "main.hpp"

std::unordered_map<std::string, std::string> TEXTURE_LIST = {
        {
            "PLAYER_SHIP",
            "imgs/playerShip.png"
        },
        {
            "BACKGROUND_BLUE",
            "imgs/backgroundBlue.png"
        }
    };

int main()
{
    std::cout << "Starting SFML 3 app...\n";
    Managers::AssetResolver assetResolver(ASSETS_PATH, TEXTURE_LIST);
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

    assetResolver.loadAsset("PLAYER_SHIP");
    assetResolver.loadAsset("BACKGROUND_BLUE");

    auto playerTexture = assetResolver.getTexture("PLAYER_SHIP");
    auto backgroundTexture = assetResolver.getTexture("BACKGROUND_BLUE");

    sf::Sprite playerSprite(playerTexture);
    playerSprite.setPosition({600.f, 600.f});

    sf::Sprite backgroundSprite(backgroundTexture);
    backgroundSprite.setPosition({200.f, 0.f});

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
        //std::set<std::string>

        // Rysowanie
        window.clear(sf::Color(30, 30, 30));
        window.draw(backgroundSprite);
        window.draw(playerSprite);
        window.draw(rect);
        window.display();
    }

    std::cout << "SFML app closed cleanly.\n";
    return 0;
}
