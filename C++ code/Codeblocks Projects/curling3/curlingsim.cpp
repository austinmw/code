#include <SFML/Graphics.hpp>
#include <random>
#include <functional>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <numeric>
//Functions for use in Stone class definition utilizing Vector2f parameter(s)
float get2DMagnitude(sf::Vector2f vec)
{
return sqrt(pow(vec.x,2)+pow(vec.y,2));
}

float get2DDotProduct(sf::Vector2f vec1,sf::Vector2f vec2)
{
return vec1.x*vec2.x+vec1.y*vec2.y;
}

//Stone class, child of SFML's CircleShape class
class Stone : public sf::CircleShape
    {
    private:

    public:
        Stone(float,float,float, float,bool, int, int);
        sf::Vector2f velocity;
        sf::Vector2f nextpos;
        double mass;
        bool windowBound;
        int window_width;
        int window_height;

        void setVelocity(float x,float y){velocity.x = x; velocity.y = y;};
        void setVelocity(sf::Vector2f p){velocity.x = p.x; velocity.y = p.y;};
        sf::Vector2f getVelocity(){return velocity;}
        float speed(){return std::sqrt(velocity.x*velocity.x+velocity.y*velocity.y);};
        void setwindowwidth(int ww){window_width = ww;};
        void setwindowheight(int wh){window_height= wh;};

        void setnextpos();
        void setwindowbound(bool wb){windowBound = wb;};
        bool getWindowBound(){return windowBound;};
        double m() const { return mass; };
        void setmass(double m){mass = m;};

    };
//Stone class constructor
    Stone::Stone(float xVelocity,float yVelocity,float xInitPos, float yInitPos,
                    bool wb,int ww, int wh)
    {
        sf::Color stoneDefault(160,160,160);
        setRadius(29.f);
        setFillColor(stoneDefault);
        setOrigin(getRadius(),getRadius());
        setPosition(xInitPos,yInitPos);
        setVelocity(xVelocity,yVelocity);
        setwindowwidth(ww);
        setwindowheight(wh);
        setwindowbound(wb);
        setnextpos();
        setmass(5);
    }
//Stone class fucntions (those not already defined inline)
    void Stone::setnextpos()
    {
        nextpos.x = getPosition().x + velocity.x;
        nextpos.y = getPosition().y + velocity.y;
        if(getWindowBound())
        {
            if (nextpos.x - getRadius() < 0) { // left window
                    velocity.x*= -1;
                    nextpos.x = 0 + getRadius();
                } else if (nextpos.x + getRadius()>= window_width) { // right window
                    velocity.x*= -1;
                    nextpos.x = window_width - getRadius();
                } else if (nextpos.y - getRadius()< 0) { // top window
                    velocity.y*= -1;
                    nextpos.y = 0 + getRadius();
                } else if (nextpos.y + getRadius()>= window_height) { // bottom window
                    velocity.y*= -1;
                    nextpos.y = window_height - getRadius();
                }
        }
    }
//Transfer momentum function aka collision function.
    void Collision(Stone &s1, Stone &s2) {
        sf::Vector2f normalVector, unitNormalVector, unitTangentVector, v1normnew, v2normnew, v1tannew, v2tannew;
        float v1tan, v1norm, v2tan, v2norm;
        //Math and physics for collisions
        normalVector = sf::Vector2f(s2.getPosition().x-s1.getPosition().x,s2.getPosition().y-s1.getPosition().y);
        unitNormalVector = sf::Vector2f(normalVector.x/get2DMagnitude(normalVector),normalVector.y/get2DMagnitude(normalVector));
        unitTangentVector = sf::Vector2f((-1)*unitNormalVector.y,unitNormalVector.x);
        v1tan = get2DDotProduct(unitTangentVector,s1.velocity);
        v1norm = get2DDotProduct(unitNormalVector,s1.velocity);
        v2tan = get2DDotProduct(unitTangentVector,s2.velocity);
        v2norm = get2DDotProduct(unitNormalVector,s2.velocity);
        //Post Collision Variables
        v1tannew = v1tan*unitTangentVector;
        v2tannew = v2tan*unitTangentVector;
        v1normnew = sf::Vector2f((v1norm*(s1.mass - s2.mass)+2*s2.mass*v2norm)/(s1.mass+s2.mass)*unitNormalVector.x,
                                (v1norm*(s1.mass - s2.mass)+2*s2.mass*v2norm)/(s1.mass+s2.mass)*unitNormalVector.y);
        v2normnew = sf::Vector2f((v2norm*(s2.mass - s1.mass)+2*s1.mass*v1norm)/(s1.mass+s2.mass)*unitNormalVector.x,
                                (v2norm*(s2.mass - s1.mass)+2*s1.mass*v1norm)/(s1.mass+s2.mass)*unitNormalVector.y);

        sf::Vector2f s1vNew = sf::Vector2f(v1tannew+v1normnew);
        sf::Vector2f s2vNew = sf::Vector2f(v2tannew+v2normnew);
        s1.setVelocity(s1vNew);
        s2.setVelocity(s2vNew);
}

//Functions with Stone parameters
float nextPositionDistance(Stone s1, Stone s2)
{
return sqrt(pow(s1.nextpos.x-s2.nextpos.x,2)+
            pow(s1.nextpos.y-s2.nextpos.y,2));
}
float getDistance(Stone s1, Stone s2)
{
return sqrt(pow(s1.getPosition().x-s2.getPosition().x,2)+
            pow(s1.getPosition().y-s2.getPosition().y,2));
}

bool overlapCheck(std::vector<Stone> vectorOfStones)
{
    bool overlap = false;
    for(int i = 0; i<vectorOfStones.size();i++)
            {
                for (int j = i + 1; j < vectorOfStones.size(); j++)
                    {
                        if(getDistance(vectorOfStones[i],vectorOfStones[j])<=
                        (vectorOfStones[i].getRadius()+vectorOfStones[j].getRadius()))
                                {overlap = true;}
                        if(nextPositionDistance(vectorOfStones[i],vectorOfStones[j])<=
                        (vectorOfStones[i].getRadius()+vectorOfStones[j].getRadius()))
                            {overlap = true;}
                    }
            }
    return overlap;
}

int main()
{
//cross-mode declarations
    int numberOfStones;
    std::vector<Stone> vectorOfStones;
    const int window_width = 500;
    const int window_height = 500;
    const int bpp = 32;
    bool windowbound = true;
//Background curling house image and render window
    sf::Texture background;
    if(!background.loadFromFile("curlinghouse.png"))
        {
        std::cout<<"\n\nCould not load image\n";
        std::cout<<"Please add curlinghouse.png image to working directory\n";
        return -1;
        };
    sf::Sprite backgroundsprite;
    backgroundsprite.setTexture(background);
    backgroundsprite.setScale(sf::Vector2f(window_width/512.f,window_height/512.f));
    background.setSmooth(true);
    sf::RenderWindow window(sf::VideoMode(window_width, window_height, bpp), "Da Curling Club");
    window.setVerticalSyncEnabled(true);

    //generate random velocities and positions.
    std::random_device seed_device;
    std::default_random_engine engine(seed_device());
    std::uniform_real_distribution<float> velocityDistribution(-2, 2);
    std::uniform_real_distribution<float> xPositionDistribution(0, window_width);
    std::uniform_real_distribution<float> yPositionDistribution(0, window_height);
    auto randomVelocity = std::bind(velocityDistribution, std::ref(engine));
    auto randomXPosition = std::bind(xPositionDistribution, std::ref(engine));
    auto randomYPosition = std::bind(yPositionDistribution, std::ref(engine));

    //set clock and frame rate
    sf::Clock clock;
    sf::Time elapsed = clock.restart();
    const sf::Time update_ms = sf::seconds(1.f / 30.f);

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            //quit event
            if ((event.type == sf::Event::Closed) ||
                ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Q))
                )
            {
                window.close();
                break;
            }
            //random mode -- stones not window bound
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::R))
            {
                windowbound = false;
                numberOfStones = 10;
                bool overlap;
                //only accept non-overlapping stone arragements.
                do
                {
                    vectorOfStones.clear();
                    for(int i = 0; i<numberOfStones;i++)
                    {
                        Stone someNewStoneObject(randomVelocity(),randomVelocity(),
                        randomXPosition(),randomYPosition(),windowbound,window_width,window_height);
                        vectorOfStones.push_back(someNewStoneObject);
                    }
                    overlap = overlapCheck(vectorOfStones);
                }
                while (overlap);
            }
            //test mode
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::T))
            {
            windowbound = true;
                vectorOfStones.clear();
                numberOfStones = 2;
                Stone stationaryStone(0,0,250,250,windowbound,window_width,window_height);
                vectorOfStones.push_back(stationaryStone);
                Stone movingStone(0,-2,250-2*stationaryStone.getRadius()+randomXPosition()/4.3,window_height,windowbound,window_width,window_height);
                vectorOfStones.push_back(movingStone);
            }
            //bounce mode -- stones are window bound
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::B))
            {
            windowbound = true;
            numberOfStones = 10;
            bool overlap;
            //only accept non-overlapping stone arragements.
                do
                {
                    vectorOfStones.clear();
                    for(int i = 0; i<numberOfStones;i++)
                    {
                        Stone someNewStoneObject(randomVelocity(),randomVelocity(),
                        randomXPosition(),randomYPosition(),windowbound,window_width,window_height);
                        vectorOfStones.push_back(someNewStoneObject);
                    }
                    //check for overlapping stones
                    overlap = overlapCheck(vectorOfStones);
                }
                while (overlap);
            }
}
        elapsed += clock.restart();
        while (elapsed >= update_ms)
        {
            //check stones for collisions.
            for (int i = 0; i < vectorOfStones.size(); i++)
            {
                for (int j = i + 1; j < vectorOfStones.size(); j++)
                {
                    if(nextPositionDistance(vectorOfStones[i],vectorOfStones[j])<=
                        (vectorOfStones[i].getRadius()+vectorOfStones[j].getRadius()))
                        {Collision(vectorOfStones[i],vectorOfStones[j]);}
                }
            }
            //update positions of stones
            for(int i=0;i<vectorOfStones.size();i++)
            {
                vectorOfStones[i].setnextpos();
                vectorOfStones[i].setPosition(vectorOfStones[i].nextpos.x,vectorOfStones[i].nextpos.y);
            }
            //Handle unbound stones for random mode -- BUG ALERT, program freeze somewhere here.
            if(!windowbound)
            {
                for(int i = 0;i<vectorOfStones.size();i++)
                {
                    bool overlap;
                    float maxX = window_width+vectorOfStones[i].getRadius();
                    float maxY = window_height+vectorOfStones[i].getRadius();
                    float minX = -vectorOfStones[i].getRadius();
                    float minY = -vectorOfStones[i].getRadius();

                            if(vectorOfStones[i].getPosition().x>maxX||vectorOfStones[i].getPosition().x<minX||
                            vectorOfStones[i].getPosition().y>maxY||vectorOfStones[i].getPosition().y<minY)
                                {
                                vectorOfStones.erase(vectorOfStones.begin()+i);

                                Stone someNewStoneObject(randomVelocity(),randomVelocity(),
                                    randomXPosition(),randomYPosition(),windowbound,window_width,window_height);
                                vectorOfStones.push_back(someNewStoneObject);
                                overlap = overlapCheck(vectorOfStones);
                                //only accept non-overlapping stone arragements.
                                while(overlap)
                                    {
                                        vectorOfStones.pop_back();
                                        Stone someNewStoneObject(randomVelocity(),randomVelocity(),randomXPosition(),randomYPosition(),windowbound,window_width,window_height);
                                        vectorOfStones.push_back(someNewStoneObject);
                                        overlap = overlapCheck(vectorOfStones);
                                    }
                                }
                }
            }
            elapsed -= update_ms;
        }
        window.clear(sf::Color(255,255,255));
        window.draw(backgroundsprite);
        for(int i=0;i<vectorOfStones.size();i++)
            {window.draw(vectorOfStones[i]);}
        window.display();
    }
    return 0;
}
