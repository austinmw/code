
#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{

    enum Direction {Down, Left, Right, Up};

    sf::Vector2i source(1, Down);

    // Create the main window
    sf::VideoMode desktop =  sf::VideoMode::getDesktopMode();
    sf::RenderWindow window(sf::VideoMode(500, 282, desktop.bitsPerPixel),
                            "SpriteSheet Animation", sf::Style::Titlebar | sf::Style::Close);
    // Changed style from default to prevent window resizing

    // Set the Icon
    sf::Image icon;
    if (!icon.loadFromFile("game-icon.png"))
    {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("ground.png"))
    {
        return EXIT_FAILURE;
    }
    sf::Sprite sprite(texture);


    //Player Sprite
    sf::Texture playerTexture;
    sf::Sprite playerImage;
    if (!playerTexture.loadFromFile("Player.png"))
        std::cout << "Error: could not load player image." << std::endl;
    playerImage.setTexture(playerTexture);


    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                source.y = Up;
                playerImage.move(0, -10);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                source.y = Down;
                playerImage.move(0, 10);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                source.y = Right;
                playerImage.move(7, 0);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                source.y = Left;
                playerImage.move(-10, 0);
            }

            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
            // Escape pressed: exit
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Q)
                window.close();
        }

        // Clear screen
        window.clear();

        // Draw the sprite
        window.draw(sprite);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
                || sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            source.x++;
            if (source.x * 32 >= playerTexture.getSize().x)
                source.x = 0;
        }
        else
            source.x = 1;

        playerImage.setTextureRect(sf::IntRect(source.x * 32, source.y * 32, 32, 32));
        window.draw(playerImage);

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
