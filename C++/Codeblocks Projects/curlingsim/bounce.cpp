#include <SFML/Graphics.hpp>
#include <random>
#include <functional>
#include <cstdlib>
#include <cmath>


int main()
{
    int window_width = 400;
    int window_height = 300;
    float ball_radius = 16.f;
    int bpp = 28;

    sf::RenderWindow window(sf::VideoMode(window_width, window_height, bpp),
      "Bouncing ball");
    window.setVerticalSyncEnabled(true);

    std::random_device seed_device;
    std::default_random_engine engine(seed_device());
    std::uniform_int_distribution<int> distribution(-16, 16);
    auto random = std::bind(distribution, std::ref(engine));

    sf::Vector2f direction(random(), random());
    const float velocity = std::sqrt(direction.x * direction.x + direction.y * direction.y);

//radius approx 41 pixels

    sf::CircleShape ball(ball_radius - 4);
    ball.setOutlineThickness(4);
    ball.setOutlineColor(sf::Color::Black);
    ball.setFillColor(sf::Color::Yellow);
    ball.setOrigin(ball.getRadius(), ball.getRadius());
    ball.setPosition(window_width / 2, window_height / 2);

    sf::Clock clock;
    sf::Time elapsed = clock.restart();
    const sf::Time update_ms = sf::seconds(1.f / 30.f);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if ((event.type == sf::Event::Closed) ||
                ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))) {
                window.close();
                break;
            }
        }

        elapsed += clock.restart();
        while (elapsed >= update_ms) {
            const auto pos = ball.getPosition();
            const auto delta = update_ms.asSeconds() * velocity;
            sf::Vector2f new_pos(pos.x + direction.x * delta, pos.y + direction.y * delta);

            if (new_pos.x - ball_radius < 0) { // left window edge
                direction.x *= -1;
                new_pos.x = 0 + ball_radius;
            } else if (new_pos.x + ball_radius >= window_width) { // right window edge
                direction.x *= -1;
                new_pos.x = window_width - ball_radius;
            } else if (new_pos.y - ball_radius < 0) { // top of window
                direction.y *= -1;
                new_pos.y = 0 + ball_radius;
            } else if (new_pos.y + ball_radius >= window_height) { // bottom of window
                direction.y *= -1;
                new_pos.y = window_height - ball_radius;
            }
            ball.setPosition(new_pos);

            elapsed -= update_ms;
        }

        window.clear(sf::Color(30, 30, 120));
        window.draw(ball);
        window.display();
    }

    return EXIT_SUCCESS;
}
