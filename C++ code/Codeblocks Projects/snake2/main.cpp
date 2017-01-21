#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>


// Global directions
enum Direction {Up, Down, Left, Right};

// Reads high scores
void High_Scores(std::vector<int> &top10scores)
{
    top10scores.clear();
    std::string line;
    std::ifstream highscores("highscores.txt");
    while (std::getline(highscores, line))
        top10scores.push_back(stoi(line));
    highscores.close();
}

// Checks new score against high scores
void New_High(std::vector<int> newScores)
{
    std::ofstream fileoutput;
    fileoutput.open("highscores.txt");
    for (int i = 0; i < 10; i++)
        fileoutput << newScores[i] << "\n";
    fileoutput.close();
}

// Writes over high scores file
int Update_Scores(int &score, std::vector<int> &top10scores)
{
    for (int i = 0; i < 10; i++)
    {
        if (score >= top10scores[i])
        {
            for (int j = 9; j >= 0+i; j--)
            {
                top10scores[j] = top10scores[j-1];
            }

            top10scores[i] = score;

            New_High(top10scores);

            High_Scores(top10scores);
            return i;
        }
    }
    return 11;
}

// Start menu
void Welcome_Screen(sf::RenderWindow &window)
{
    sf::Texture texture;
    texture.loadFromFile("welcome.png");
    sf::Sprite background(texture);
    sf::Font font;
    if (!font.loadFromFile("bonzai.ttf"))
        std::cout << "Can't find the font file 'bonzai.ttf'" << std::endl;
    sf::Text text("\n\n\n\n  \t\t\t Welcome!\n\t"
                  "   Press 'Enter' to begin.", font, 50);
    text.setColor(sf::Color::White);
    sf::Text quitText(" 'Esc' to quit", font, 17);
    quitText.setColor(sf::Color::Black);
    sf::Text difficultyText("'1': Beginner, '2': Normal (default), '3': Expert",
                            font, 24);
    difficultyText.setColor(sf::Color::Black);
    difficultyText.setPosition(109, 360);
    window.clear();
    window.draw(background);
    window.draw(text);
    window.draw(quitText);
    window.draw(difficultyText);
    window.display();
}

// Basic collision check for apple placement
bool Collision_Detect(std::vector<sf::RectangleShape> &snakeBody,
                      sf::Sprite &appleSprite)
{
    for (int i = 0; i != snakeBody.size(); i++)
    {
        if (snakeBody[i].getPosition() == appleSprite.getPosition())
            return true;
    }
    return false;
}

// Sets up starting values for game
void New_Game(std::vector<sf::RectangleShape> &snakeBody, int window_width,
              int window_height, std::default_random_engine &engine,
              sf::Sprite &appleSprite, int score, sf::Text &scoreText,
              int lowBounds)
{
    score = 0;
    scoreText.setString("Score: 0");
    snakeBody.clear();
    snakeBody.push_back(sf::RectangleShape(sf::Vector2f(20,20)));
    snakeBody[0].setPosition(window_width / 2, window_height / 2 - 120);
    snakeBody[0].setFillColor(sf::Color(200,255,200));
    snakeBody[0].setOutlineThickness(-1);
    snakeBody[0].setOutlineColor(sf::Color::Black);
    std::uniform_int_distribution<int> xPosition(lowBounds, 39);
    auto randX = std::bind(xPosition, std::ref(engine));
    std::uniform_int_distribution<int> yPosition(lowBounds, 23);
    auto randY = std::bind(yPosition, std::ref(engine));
    do
        appleSprite.setPosition(randX()*20, randY()*20);
    while (Collision_Detect(snakeBody, appleSprite));

    for (int i = 0; i < 2; i++)
    {
        snakeBody.push_back(sf::RectangleShape(sf::Vector2f(20,20)));
        snakeBody[snakeBody.size()-1].setFillColor(sf::Color(100,150,100));
        snakeBody[snakeBody.size()-1].setOutlineThickness(-1);
        snakeBody[snakeBody.size()-1].setOutlineColor(sf::Color::Black);
        snakeBody.back().setPosition(snakeBody.begin()->getPosition().x,
                                     snakeBody.begin()->getPosition().y);
    }
}

//Display all blocks of snake
void Draw_Snake(sf::RenderWindow &window, std::vector<sf::RectangleShape>
                &snakeBody)
{
    for (int i = 0; i != snakeBody.size(); i++)
        window.draw(snakeBody[i]);
}

// Moves snake's head and tail
void Move_Snake(std::vector<sf::RectangleShape> &snakeBody,
                sf::Vector2f &lastPosition,int move)
{
    switch (move)
    {
    case Up:
        snakeBody[0].move(0, -20);
        break;
    case Down:
        snakeBody[0].move(0, 20);
        break;
    case Left:
        snakeBody[0].move(-20, 0);
        break;
    case Right:
        snakeBody[0].move(20, 0);
        break;
    default:
        break;
    }
    sf::Vector2f newPosition(lastPosition);
    if (snakeBody.size() > 1)
    {
        for (int i = 1; i != snakeBody.size(); i++)
        {
            lastPosition = snakeBody[i].getPosition();
            snakeBody[i].setPosition(newPosition);
            newPosition = lastPosition;
        }
    }
}

// Apple placement
bool Apple_Placement(int lowBounds, std::default_random_engine &engine,
                     std::vector<sf::RectangleShape> &snakeBody,
                     sf::Sprite &appleSprite, sf::Clock &immuneTimer)
{
    std::uniform_int_distribution<int> xPosition(lowBounds, 39);
    auto randX = std::bind(xPosition, std::ref(engine));
    std::uniform_int_distribution<int> yPosition(lowBounds, 23);
    auto randY = std::bind(yPosition, std::ref(engine));

    if ((appleSprite.getPosition().x == snakeBody[0].getPosition().x) &&
            (appleSprite.getPosition().y == snakeBody[0].getPosition().y))
    {
        //  for (int i = 0; i < 2; i++)
        //  {
        snakeBody.push_back(sf::RectangleShape(sf::Vector2f(20,20)));
        snakeBody[snakeBody.size()-1].setFillColor(sf::Color(100,150,100));
        snakeBody[snakeBody.size()-1].setOutlineThickness(-1);
        snakeBody[snakeBody.size()-1].setOutlineColor(sf::Color::Black);
        snakeBody.back().setPosition(snakeBody.begin()->getPosition().x,
                                     snakeBody.begin()->getPosition().y);
        //  }
        do
            appleSprite.setPosition(randX()*20, randY()*20);
        while (Collision_Detect(snakeBody, appleSprite));

        immuneTimer.restart();
        return true;
    }
    else
        return false;
}

// Checks body collision and out of bounds
bool Snake_Alive(std::vector<sf::RectangleShape> &snakeBody,
                 sf::Clock &immuneTimer)
{
    if (snakeBody[0].getPosition().x < 0 || snakeBody[0].getPosition().x > 790
            || snakeBody[0].getPosition().y < 0 ||
            snakeBody[0].getPosition().y > 460)
    {
        // snakeBody[0].setFillColor(sf::Color::Yellow);
        return false;
    }

    if(immuneTimer.getElapsedTime().asSeconds() >= .10)
    {
        for (int i = 1; i != snakeBody.size(); i++)
        {
            if (snakeBody[0].getPosition() == snakeBody[i].getPosition())
            {
                // snakeBody[i].setFillColor(sf::Color::Yellow);
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int window_width = 800, window_height = 600;
    int bitsPerPixel = 24, start = 0, mode = 0, score = 0;
    int difficulty = 2, lowBounds = 0;
    float moveSpeed = 0.075;
    bool welcomeOn = true;
    std::vector<int> top10scores;
    std::vector<sf::RectangleShape> snakeBody;
    std::vector<int> move(2); // in case I had movement buffer
    bool currentlyPlaying = false;

    // Create main window
    sf::RenderWindow window(sf::VideoMode(window_width, window_height,
                                          bitsPerPixel), "Snake!", sf::Style::Close);
    window.setVerticalSyncEnabled(true);

    // Set the icon
    sf::Image icon;
    if (!icon.loadFromFile("icon.png"))
        return EXIT_FAILURE;
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    // Game board
    sf::Texture texture;
    texture.loadFromFile("grass.png");   //replace with game board
    sf::Sprite grass(texture);

    // Apple sprite
    sf::Texture appleTexture;
    appleTexture.loadFromFile("applepic.png");   //replace with game board
    sf::Sprite appleSprite(appleTexture);
    appleSprite.setPosition(350,350);

    // Random generator
    std::random_device seed_device;
    std::default_random_engine engine(seed_device());

    // Score box
    sf::RectangleShape scoreBox(sf::Vector2f(window_width, window_height - 480));
    scoreBox.setFillColor(sf::Color(223,255,173));
    scoreBox.setOutlineColor(sf::Color::Black);
    scoreBox.setOutlineThickness(-3.f);
    scoreBox.setPosition(0, 480);

    // Game text
    sf::Font font;
    if (!font.loadFromFile("bonzai.ttf"))
        std::cout << "Can't find the font file 'bonzai.ttf'" << std::endl;
    sf::Text scoreText("Score: ", font, 60);
    scoreText.setColor(sf::Color::Black);
    scoreText.setPosition(314, 497);
    sf::Text pauseText("GAME PAUSED", font, 80);
    pauseText.setColor(sf::Color::Black);
    pauseText.setPosition(174, 185);
    sf::Text overText("  GAME OVER", font, 78);
    overText.setColor(sf::Color::Black);
    overText.setPosition(174, 185);
    sf::Text newquitText("Pause: 'P'\nNew game: 'Enter'\nQuit to"
                         " main menu: 'Q'", font, 20);
    newquitText.setColor(sf::Color::Black);
    newquitText.setPosition(5, 525);
    sf::Text highScoreText("", font, 85);
    highScoreText.setColor(sf::Color::Yellow);

    //High scores
    High_Scores(top10scores);

    if (difficulty == 2)
        lowBounds = 0;

    // Clocks
    sf::Clock moveClock;
    sf::Clock immuneTimer;

    New_Game(snakeBody, window_width, window_height, engine,
             appleSprite, score, scoreText, lowBounds);
    // Main game loop
    while (window.isOpen())
    {
        sf::Vector2f lastPosition(snakeBody[0].getPosition().x,
                                  snakeBody[0].getPosition().y);
        // Event
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Welcome screen
            if (start <= 1)
            {
                Welcome_Screen(window);
                welcomeOn = true;
                start++;
            }
            // Close window: Exit
            if (event.type == sf::Event::Closed)
                window.close();
            // Esc pressed: Exit
            if (event.type == sf::Event::KeyPressed && event.key.code
                    == sf::Keyboard::Escape)
                window.close();
            // Q pressed: Exit to main menu
            if (event.type == sf::Event::KeyPressed && event.key.code
                    == sf::Keyboard::Q)
            {
                start = 1;
                mode = 0;
            }
            // Start game
            if (event.type == sf::Event::KeyPressed && event.key.code
                    == sf::Keyboard::Return)
            {
                welcomeOn = false;
                if (!currentlyPlaying)
                    currentlyPlaying = true;
                move[0] = Down;
                move[1] = Down;

                New_Game(snakeBody, window_width, window_height, engine,
                         appleSprite, score, scoreText, lowBounds);
                mode = 1;
                score = 0;
                moveClock.restart();
                //  inputClock.restart();
                immuneTimer.restart();
            }
            // P pressed: Pause simulation
            if (event.type == sf::Event::KeyPressed && event.key.code
                    == sf::Keyboard::P)
            {
                if (mode == 1)
                {
                    window.draw(pauseText);
                    window.display();
                }
                mode *= -1;
                moveClock.restart();
                immuneTimer.restart();
            }

            // Change difficulty only at welcome screen
            if (welcomeOn == true)
            {
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num1)
                {
                    difficulty = 1;
                    moveSpeed = 0.1;
                }
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num2)
                {
                    difficulty = 2;
                    moveSpeed = 0.075;
                }
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num3)
                {
                    difficulty = 3;
                    moveSpeed = 0.050;
                }
            }
        }
        // Game active
        if (mode == 1)
        {
            window.clear();
            window.draw(grass);
            window.draw(appleSprite);
            Draw_Snake(window, snakeBody);
            window.draw(scoreBox);
            window.draw(appleSprite);
            window.draw(scoreText);
            window.draw(newquitText);

            // Controls
            if((event.type == sf::Event::KeyPressed) &&
                    (event.key.code == sf::Keyboard::W
                     || event.key.code == sf::Keyboard::Up) && move[0] != Down)
                move[1] = Up;

            else if((event.type == sf::Event::KeyPressed)
                    && (event.key.code == sf::Keyboard::S
                        || event.key.code == sf::Keyboard::Down) && move[0] != Up)
                move[1] = Down;

            else if((event.type == sf::Event::KeyPressed)
                    && (move[0] != Right) && (event.key.code == sf::Keyboard::A
                        || event.key.code == sf::Keyboard::Left))
                move[1] = Left;

            else if(event.type == sf::Event::KeyPressed
                    && (event.key.code == sf::Keyboard::D
                        || event.key.code == sf::Keyboard::Right) && move[0] != Left)
                move[1] = Right;

            // Snake speed
            if(moveClock.getElapsedTime().asSeconds() >= moveSpeed)
            {
                move[0] = move[1];
                Move_Snake(snakeBody, lastPosition, move[0]);
                moveClock.restart();
            }

            if(Apple_Placement(lowBounds, engine, snakeBody, appleSprite,
                               immuneTimer))
            {
                // Updates score
                if (difficulty == 1)
                    score += 5;
                else if (difficulty == 2)
                    score += 10;
                else
                    score += 20;
                if (score >= 100)
                    scoreText.setPosition(300, 497);
                else if (score >= 1000)
                    scoreText.setPosition(285, 497);
                std::string newScore = std::to_string(score);
                scoreText.setString("Score: " + newScore);
            }
            // Game over and high scores
            if(!Snake_Alive(snakeBody, immuneTimer))
            {
                window.draw(overText);
                int scorePlacement = Update_Scores(score, top10scores);
                if (scorePlacement != 11)
                {
                    std::string newHighText = std::to_string(scorePlacement+1);
                    highScoreText.setString("#" + newHighText
                                            + " out of top 10 scores!");
                    if (scorePlacement == 9)
                        highScoreText.setPosition(15, 50);
                    else
                        highScoreText.setPosition(30, 50);
                    window.draw(highScoreText);
                }
                mode = 0;
            }
            window.display();
        }
    }
    return EXIT_SUCCESS;
}

    /*
    Issue with linking audio library
    "undefined reference to 'sf::SoundBuffer::SoundBuffer()'
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("Apple_Bite.wav"))
        return -1;
    */
