#include <SFML/Graphics.hpp>
#include <random>
#include <functional>   //check
#include <cstdlib>    //check
#include <cmath>     //check
#include <iostream> // check
#include <vector>

void Welcome_Screen(sf::RenderWindow &window)
{
    sf::Texture texture;
    texture.loadFromFile("welcome.png");
    sf::Sprite background(texture);

    window.clear();
    window.draw(background);
    window.display();
}

bool Collision_Detection(sf::CircleShape &ball1, sf::CircleShape &ball2)
{
    bool collision = false;
    float distance = sqrt(pow(ball2.getPosition().x - ball1.getPosition().x, 2) +
        pow(ball2.getPosition().y - ball1.getPosition().y, 2));
    if (distance <= ball1.getRadius() + ball2.getRadius())
        collision = true;
    return collision;
}

// make random function?


void Test_Mode(sf::RenderWindow &window, sf::Sprite &board)
{
float mass(5);
bool collision;

std::random_device sd;
std::default_random_engine generator(sd());

std::uniform_int_distribution<int> colorOptions(70, 240);
auto colors256 = std::bind(colorOptions, std::ref(generator));

    // Ball at origin
    sf::CircleShape ball1;
    ball1.setRadius(20.3); // have to double check this, I think should be 11.4in
    ball1.setOutlineColor(sf::Color::Black);
    ball1.setOutlineThickness(0);
    sf::Color randColor1 = sf::Color(colors256(), colors256(), colors256());
    ball1.setFillColor(randColor1);
    ball1.setOrigin(ball1.getRadius(), ball1.getRadius());
    ball1.setPosition(350,350); // Center ball
    int v1 = 0;

    // Moving ball
    sf::CircleShape ball2;
    ball2.setRadius(20.3); // have to double check this, I think should be 11.4in
    ball2.setOutlineColor(sf::Color::Black);
    ball2.setOutlineThickness(0);
    sf::Color randColor2 = sf::Color(colors256(), colors256(), colors256());
    ball2.setFillColor(randColor2);
    ball2.setOrigin(ball2.getRadius(), ball2.getRadius());
    std::uniform_int_distribution<int> positionOptions(20.3, 679.7);
    auto randPosition = std::bind(positionOptions, std::ref(generator));
    do
    {// place ball2 in non-overlapping position
        ball2.setPosition(randPosition(), randPosition());
        collision = Collision_Detection(ball1, ball2);
    }
    while (collision == true);

    // done up to here




    std::uniform_int_distribution<int> directionOptions(0,21.3);
    auto semiRandDirection = std::bind(directionOptions, std::ref(generator));
    sf::Vector2f direction(329+semiRandDirection(), 329+semiRandDirection());





    int v2 = 140; // 1 m/s (if 700 pixels is 5m)




    sf::Vector2f momentum2(mass*v2, mass*v2);

    //velocity = std::sqrt(direction.x * direction.x + direction.y * direction.y);

    window.clear();
    window.draw(board);
    window.draw(ball1);
    window.draw(ball2);
    window.display();



    sf::Clock clock;
    sf::Time elapsed = clock.restart();
    sf::Time update_ms = sf::seconds(1.f / 30.f); // might need to set this back to 1/30







}



int main()
{
    int start(0);


    // Create the main window
    sf::VideoMode desktop =  sf::VideoMode::getDesktopMode();
    sf::RenderWindow window(sf::VideoMode(700, 700, desktop.bitsPerPixel), "Curling Sim");
    window.setVerticalSyncEnabled(true);
    int xPos = sf::VideoMode::getDesktopMode().width/2 - 350;
    int yPos = sf::VideoMode::getDesktopMode().height/2 - 350;
    window.setPosition(sf::Vector2i(xPos,yPos));







    // Set the icon
    sf::Image icon;
    if (!icon.loadFromFile("Curling-icon.png"))
        return EXIT_FAILURE;
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    // Game board
    sf::Texture texture;
    texture.loadFromFile("blank.png");   //replace with game board
    sf::Sprite board(texture);


    sf::Clock clock;
    sf::Time elapsed = clock.restart();
    sf::Time update_ms = sf::seconds(1.f / 30.f);




    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Welcome screen
            if (start <= 1) {
                Welcome_Screen(window);
                start++; }

            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();

            // Q pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code
                == sf::Keyboard::Q)
                window.close();

            // T pressed: Test Mode
            if (event.type == sf::Event::KeyPressed && event.key.code
                == sf::Keyboard::T)
            {
                    Test_Mode(window, board);
            }




        }





    }
    return EXIT_SUCCESS;
}
