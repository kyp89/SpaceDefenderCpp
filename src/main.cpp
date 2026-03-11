#include "main.hpp"

int main()
{
    std::cout << "Starting SFML 3 app...\n";
    sf::Clock clock;
    Managers::AssetResolver assetResolver(ASSETS_PATH, TEXTURE_LIST);
    Managers::Drawer drawer(assetResolver);
    Managers::ControlsManager controlManager(KEYS_MAPPING);
    Managers::MeteorsManager meteorsManager(50, -50, 950, 1000);
    GameElements::Background background;
    GameElements::Player player;
    GameElements::Laser laser;
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
    assetResolver.loadAsset("METEOR_2");
    assetResolver.loadAsset("METEOR_3");
    assetResolver.loadAsset("METEOR_4");
    assetResolver.loadAsset("GUN");
    assetResolver.loadAsset("LASER");

    // Pętla główna
    while (window.isOpen())
    {
        // Obsługa zdarzeń
        while (auto event = window.pollEvent())
        {   
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }
        float deltaTime = clock.restart().asSeconds();

        window.clear(sf::Color(30, 30, 30));

        background.update();

        controlManager.update();
        player.update(controlManager.getCurrentActions());
        meteorsManager.update(deltaTime);
        laser.update();

        const auto& backgroundTextureMap = background.getDrawableElements();
        const auto& playerDrawableElements = player.getDrawableElements();
        const auto& laserTextureMap = laser.getDrawableElements();
        const auto& meteorsDrawable = meteorsManager.getMeteors();

        drawer.addToUpdate(backgroundTextureMap);
        drawer.addToUpdate(laserTextureMap);
        drawer.addToUpdate(playerDrawableElements);
        for(auto& meteorDrawable: meteorsDrawable) {
            drawer.addToUpdate(meteorDrawable->getDrawableElements());
        }
        drawer.update(window);
        
        window.display();
    }

    std::cout << "SFML app closed cleanly.\n";
    return 0;
}
