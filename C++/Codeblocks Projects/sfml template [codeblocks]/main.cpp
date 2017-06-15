#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    // Create the main window
    sf::VideoMode desktop =  sf::VideoMode::getDesktopMode();
    sf::RenderWindow app(sf::VideoMode(1024, 768, desktop.bitsPerPixel), "SFML window");

    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("cb.bmp"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);

	// Start the game loop
    while (app.isOpen())
    {
        // Process events
        sf::Event event;
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                app.close();
        }

        // Clear screen
        app.clear();

        // Draw the sprite
        app.draw(sprite);

        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}
