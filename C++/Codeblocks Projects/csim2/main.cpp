//csim
#include <SFML/Graphics.hpp>
#include <random>
#include <functional>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <iostream>

void Welcome_Screen(sf::RenderWindow &window)
{
    sf::Texture texture;
    texture.loadFromFile("welcome500.png");
    sf::Sprite background(texture);
    window.clear();
    window.draw(background);
    window.display();
}

sf::Vector2f Direction_Velocities(int window_width, int window_height, sf::Time update_ms,
                                  sf::CircleShape &ball, std::default_random_engine &engine)
{

    /* (this is java)
    float random1 = MathUtils.random(); float random2 = MathUtils.random();
     float randomXPoint = random2*radiusMathUtils.cos(MathUtils.PI2*random1/random2);
     float randomYPoint = random2*radiusMathUtils.sin(MathUtils.PI2*random1/random2);


    std::random_device seed_device;
    std::default_random_engine engine(seed_device());
    //Random Positions
    std::uniform_int_distribution<float> zeroToOne(0, 1);
    auto randDecimal = std::bind(zeroToOne, std::ref(engine));

    */

    //Random Positions                                             NEED RAND FLOAT
   // std::uniform_int_distribution<float> zeroToOne(0, 1);
   // auto randDecimal = std::bind(zeroToOne, std::ref(engine));

    float headingX = window_width / 2;
    float headingY = window_height / 2;

    float xdir = headingX - ball.getPosition().x;
    float ydir = headingY - ball.getPosition().y;
    float speed = 100.0 * update_ms.asSeconds();
  //  std::cout << "xdir: " << xdir << ", ydir: " << ydir << std::endl;
    float multiplier = sqrt((speed * speed)/(xdir * xdir + ydir * ydir));
  //  std::cout << "Multiplier: " << multiplier << std::endl;
    xdir *= multiplier;
    ydir *= multiplier;
  //  std::cout << "new xdir: " << xdir << ", new ydir: " << ydir << std::endl;
    return sf::Vector2f(xdir, ydir);
}



bool Collision_Detection(sf::CircleShape &ball1, sf::CircleShape &ball2)
{
    // Need to figure out if this isn't working properly because of error in calculation or
// if I need to do the bounding box first for performance (probably error in logic somewhere)
    bool collision = false;
    if (ball1.getPosition().x + ball1.getRadius() + ball2.getRadius() > ball2.getPosition().x
            && ball1.getPosition().x < ball2.getPosition().x + ball1.getRadius() + ball2.getRadius()
            && ball1.getPosition().y + ball1.getRadius() + ball2.getRadius() > ball2.getPosition().y
            && ball1.getPosition().y < ball2.getPosition().y + ball1.getRadius() + ball2.getRadius())
    {
        //AABBs are over-lapping
        float distance = sqrt(pow(ball2.getPosition().x - ball1.getPosition().x, 2) +
                              pow(ball2.getPosition().y - ball1.getPosition().y, 2));
        if (distance <= ball1.getRadius() + ball2.getRadius() + 4)
            collision = true;
        return collision;
    }
}



sf::Vector2f Collision_Point(sf::CircleShape &ball1, sf::CircleShape &ball2)
{
    sf::Vector2f collisionPoints;
    collisionPoints.x = ((ball1.getPosition().x * ball2.getRadius()) + (ball2.getPosition().x
                         * ball1.getRadius())) / (ball1.getRadius() + ball2.getRadius());

    collisionPoints.y = ((ball1.getPosition().y * ball2.getRadius()) + (ball2.getPosition().y
                         * ball1.getRadius())) / (ball1.getRadius() + ball2.getRadius());
    return collisionPoints;
}





void Collision_Response(std::vector<float> &masses, sf::CircleShape &ball1, // void?
                        sf::CircleShape &ball2, std::vector<sf::Vector2f> &velocities)
{

    sf::Vector2f normVec = (ball2.getPosition() - ball1.getPosition());

    float length = sqrt((normVec.x * normVec.x) + (normVec.y * normVec.y));
    if (length != 0)
    {
        normVec.x = normVec.x / length;
        normVec.y = normVec.y / length;
    }

std::cout << "Stone 0: " << velocities[0].x << ", " << velocities[0].y << std::endl;
std::cout << "Stone 1: " << velocities[1].x << ", " << velocities[1].y << std::endl;

// SHOULD SLOW DOWN??

float a1 = velocities[0].x * normVec.x + velocities[0].y * normVec.y;
float a2 = velocities[1].x * normVec.x + velocities[1].y * normVec.y;
float optimizedP = (2.0 * (a1 -a2)) / (masses[0] + masses[1]);

sf::Vector2f newV0(velocities[0].x - optimizedP * masses[1] * normVec.x,
                   velocities[0].y - optimizedP * masses[1] * normVec.x);
sf::Vector2f newV1(velocities[1].x - optimizedP * masses[0] * normVec.x,
                   velocities[1].y - optimizedP * masses[0] * normVec.x);

velocities[1].x = newV1.x; velocities[1].y = newV1.y;
velocities[0].x = newV0.x; velocities[0].y = newV0.y;


}





sf::CircleShape Make_Circle(float ball_radius, std::default_random_engine &engine, int window_width,
                            int window_height)
{
    // Create circle
    std::uniform_int_distribution<int> colorOptions(256);
    auto colors256 = std::bind(colorOptions, std::ref(engine));
    sf::CircleShape ball(ball_radius - 2);
    ball.setOutlineThickness(1);
    ball.setOutlineColor(sf::Color::Black);
    ball.setFillColor(sf::Color(colors256(), colors256(), colors256()));
    ball.setOrigin(ball.getRadius(), ball.getRadius());
    ball.setPosition(window_width / 2, window_height / 2);
    return ball;
}


void Test_Mode(sf::Time &elapsed, sf::Time &update_ms, sf::Clock &clock,
               std::vector<sf::CircleShape> &stones, float &ball_radius, int &window_width,
               int &window_height, sf::RenderWindow &window, std::default_random_engine &engine,
               std::vector<float> &masses, float &speed1, float &speed2,
               std::vector<sf::Vector2f> &directions, std::vector<sf::Vector2f> &velocities)
{
    // Create a graphical text to display
    sf::Font font;
    font.loadFromFile("sansation.ttf");
    sf::Text text("\t\t\t\t\t\t\t\t  Press 'p' to pause or 't' ro reset", font, 17);
    text.setColor(sf::Color::Black);

    stones[0].setPosition(window_width / 2, window_height / 2);


/*

    if (Collision_Detection(stones[0], stones[1]))
    {

        Collision_Response(masses, stones[0], stones[1], velocities);

        auto pos0 = stones[0].getPosition();
        sf::Vector2f new_posit0(pos0.x + velocities[0].x, pos0.y + velocities[0].y);
        stones[0].setPosition(new_posit0);

        auto pos1 = stones[1].getPosition();
        sf::Vector2f new_posit1(pos1.x + velocities[1].x, pos1.y + velocities[1].y);
        stones[1].setPosition(new_posit1);

    }

*/



    elapsed += clock.restart();
    while (elapsed >= update_ms)
    {

        std::vector<sf::Vector2f> new_pos(2);
        new_pos[0].x = stones[0].getPosition().x + velocities[0].x; new_pos[0].y = stones[0].getPosition().y + velocities[0].y;

        std::cout << "NEW_POS S1: " << new_pos[0].x << ", " << new_pos[0].y << std::endl;

        new_pos[1].x = stones[1].getPosition().x + velocities[1].x; new_pos[1].y = stones[1].getPosition().y + velocities[1].y;

        if (Collision_Detection(stones[0], stones[1]))
        {
            Collision_Response(masses, stones[0], stones[1], velocities);

        }

        else if (new_pos[1].x - ball_radius < 0)   // left window edge
        {
            velocities[1].x *= -1;
            new_pos[1].x = 0 + ball_radius;
        }
        else if (new_pos[1].x + ball_radius >= window_width)     // right window edge
        {
            velocities[1].x *= -1;
            new_pos[1].x = window_width - ball_radius;
        }
        else if (new_pos[1].y - ball_radius < 0)     // top of window
        {
            velocities[1].y *= -1;
            new_pos[1].y = 0 + ball_radius;
        }
        else if (new_pos[1].y + ball_radius >= window_height)     // bottom of window
        {
            velocities[1].y *= -1;
            new_pos[1].y = window_height - ball_radius;
        }
        stones[0].setPosition(new_pos[0]);
        stones[1].setPosition(new_pos[1]);
        elapsed -= update_ms;
    }

/*

    elapsed += clock.restart();
    while (elapsed >= update_ms)
    {
        auto pos = stones[1].getPosition();
        sf::Vector2f new_pos(pos.x + velocities[1].x, pos.y + velocities[1].y);

        if (new_pos.x - ball_radius < 0)   // left window edge
        {
            velocities[1].x *= -1;
            new_pos.x = 0 + ball_radius;
        }
        else if (new_pos.x + ball_radius >= window_width)     // right window edge
        {
            velocities[1].x *= -1;
            new_pos.x = window_width - ball_radius;
        }
        else if (new_pos.y - ball_radius < 0)     // top of window
        {
            velocities[1].y *= -1;
            new_pos.y = 0 + ball_radius;
        }
        else if (new_pos.y + ball_radius >= window_height)     // bottom of window
        {
            velocities[1].y *= -1;
            new_pos.y = window_height - ball_radius;
        }
        stones[1].setPosition(new_pos);
        elapsed -= update_ms;
    }

*/

    window.clear(sf::Color::White);
    window.draw(text);
    window.draw(stones[1]);
    window.draw(stones[0]);
    window.display();
}






int main()
{
    int window_width = 500, window_height = 500;
    float ball_radius = 28.95605791;
    float ball0_radius = 28.95605791;
    int bpp(24), mode(-1), start(0);
    std::vector<sf::CircleShape> stones(2);
    bool collision;

    // Create window
    sf::RenderWindow window(sf::VideoMode(window_width, window_height, bpp),
                            "Bouncing ball");
    window.setVerticalSyncEnabled(true);


    // Set the icon
    sf::Image icon;
    if (!icon.loadFromFile("Curling-icon.png"))
        return EXIT_FAILURE;
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    // Game board
    sf::Texture texture;
    texture.loadFromFile("blank.png");   //replace with game board
    sf::Sprite board(texture);

    // Random stuff
    std::random_device seed_device;
    std::default_random_engine engine(seed_device());
    //Random Positions
    std::uniform_int_distribution<int> positionOptions(29, 500-29);
    auto randPosition = std::bind(positionOptions, std::ref(engine));




//---------------------




    float mass1 = 50;
    float mass2 = 50;
    float speed1 = 0; // adjust
    float speed2 = 100;
    std::vector<sf::Vector2f> directions(2);
    std::vector<sf::Vector2f> velocities(2);
    std::vector<float> masses(2, 50);


//-------------------


    //Clock & Time
    sf::Clock clock;
    sf::Time elapsed = clock.restart();
    sf::Time update_ms = sf::seconds(1.f / 30.f);

    // Game loop
    while (window.isOpen())
    {
        // Event
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Event loop

            // Welcome screen
            if (start <= 1)
            {
                Welcome_Screen(window);
                start++;
            }

            // Close window: Exit
            if (event.type == sf::Event::Closed)
                window.close();

            // Q pressed: Exit
            if (event.type == sf::Event::KeyPressed && event.key.code
                    == sf::Keyboard::Q)
                window.close();

            // T pressed: Test Mode
            if (event.type == sf::Event::KeyPressed && event.key.code
                    == sf::Keyboard::T)
            {
                stones[0] = Make_Circle(ball0_radius, engine, window_width, window_height);
                stones[1] = Make_Circle(ball_radius, engine, window_width, window_height);



                do
                {
                    stones[1].setPosition(randPosition(), randPosition());
                    collision = Collision_Detection(stones[0], stones[1]);
                }

                while (collision == true);

                //create stone1, randomize position, determine initial velocity (direction here, but change)
                // directions[1].x = 1; directions[1].y = 1;

                velocities[0].x = 0; velocities[0].y = 0;
                velocities[1] = Direction_Velocities(window_width, window_height,
                                update_ms, stones[1], engine);//first velocity

                mode = 1;
            }

            // P pressed: Pause simulation
            if (event.type == sf::Event::KeyPressed && event.key.code
                    == sf::Keyboard::P)
            {
                mode *= -1;
                clock.restart();
            }
        }

        if (mode == 1)
            Test_Mode(elapsed, update_ms, clock, stones,  ball_radius,
                      window_width, window_height, window, engine,
                      masses, speed1, speed2, directions, velocities);

        // Add other cases
    }
    return EXIT_SUCCESS;
}

