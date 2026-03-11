#include "main.hpp"

int main()
{
    std::cout << "Starting SFML 3 app...\n";
    sf::Clock clock;
    Managers::AssetResolver assetResolver(ASSETS_PATH, TEXTURE_LIST);
    Managers::Drawer drawer(assetResolver);
    Managers::ControlsManager controlManager(KEYS_MAPPING);
    Managers::MeteorsManager meteorsManager(50, -50, 950, 1000);
    Managers::LaserManager laserManager(-100);
    GameElements::Background background;
    GameElements::Player player;
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
        laserManager.update();
        player.update(controlManager.getCurrentActions());
        laserManager.emit(controlManager.getCurrentActions(), player.getLasersEmitterPoints(), deltaTime);
        meteorsManager.update(deltaTime);

        const auto& backgroundTextureMap = background.getDrawableElements();
        const auto& playerDrawableElements = player.getDrawableElements();
        const auto& meteorsDrawable = meteorsManager.getMeteors();
        const auto& lasersDrawable = laserManager.getLasers();

        drawer.addToUpdate(backgroundTextureMap);
        drawer.addToUpdate(playerDrawableElements);
        for(auto& meteorDrawable: meteorsDrawable) {
            drawer.addToUpdate(meteorDrawable->getDrawableElements());
        }
        for(auto& laser: lasersDrawable) {
            drawer.addToUpdate(laser->getDrawableElements());
        }
        drawer.update(window);
        
        window.display();
    }

    std::cout << "SFML app closed cleanly.\n";
    return 0;
}
