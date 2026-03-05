#include "main.hpp"

int main()
{
    std::cout << "Starting SFML 3 app...\n";
    Managers::AssetResolver assetResolver(ASSETS_PATH, TEXTURE_LIST);
    Managers::Drawer drawer(assetResolver);
    GameElements::Background background;
    GameElements::Player player;
    GameElements::Meteor meteor;
    // Tworzenie okna
    sf::RenderWindow window(
        sf::VideoMode({GAME_FILED_H, GAME_FIELD_W}),
        "SFML 3 - Test Window"
    );

    GameCommon::Transform transform;
    transform.x = 10.f;
    transform.y = 20.f;

    window.setFramerateLimit(FRAME_LIMIT);

    // Prosty obiekt do rysowania
    sf::RectangleShape rect;
    rect.setSize({200.f, 120.f});
    rect.setFillColor(sf::Color::Green);
    rect.setPosition({300.f, 240.f});

    assetResolver.loadAsset("PLAYER_SHIP");
    assetResolver.loadAsset("BACKGROUND_BLUE");
    assetResolver.loadAsset("METEOR_1");

    //auto backgroundTexture = assetResolver.getTexture("BACKGROUND_BLUE");


    // sf::Sprite backgroundSprite(backgroundTexture);
    // backgroundSprite.setPosition({200.f, 0.f});

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
        background.update();
        player.update();
        meteor.update();
        auto backgroundTextureMap = background.getTextureStatuses();
        auto textureMap = player.getTextureStatuses();
        auto meteorTextureMap = meteor.getTextureStatuses();
        drawer.addToUpdate(backgroundTextureMap);
        drawer.addToUpdate(textureMap);
        drawer.addToUpdate(meteorTextureMap);
        drawer.update(window);
        
        window.display();
    }

    std::cout << "SFML app closed cleanly.\n";
    return 0;
}
