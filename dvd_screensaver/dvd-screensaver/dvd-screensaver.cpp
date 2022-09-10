#include <SFML/Graphics.hpp>

double x=50;
double y=50;
double xadd=-0.2;
double yadd=0.2;

std::string colors[3] = {"red","green","blue"};
std::string color;
int i=0;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 700), "DVD-Screensaver");
    sf::Sprite sprite;
    sf::Texture texture;
    texture.loadFromFile("dvd.png");
    sprite.setTexture(texture);
    sprite.setScale(sf::Vector2f(0.15,0.15));
    sprite.setPosition(sf::Vector2f(x,y));

// change the size to 100x100
    

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        if(i>=3){
            i=0;
        }

        color=colors[i];

        if(x>=1050 || x<=0){
            xadd*=-1;
            if(color=="red"){
                sprite.setColor(sf::Color::Red);
            }
            else if(color=="green"){
                sprite.setColor(sf::Color::Green);
            }
            else if(color=="blue"){
                sprite.setColor(sf::Color::Blue);
            }
            i++;
            
        }
        if(y>=550 || y<=0){
            yadd*=-1;
            if(color=="red"){
                sprite.setColor(sf::Color::Red);
            }
            else if(color=="green"){
                sprite.setColor(sf::Color::Green);
            }
            else if(color=="blue"){
                sprite.setColor(sf::Color::Blue);
            }
            i++;
        }

        x+=xadd;
        y+=yadd;
        sprite.setPosition(sf::Vector2f(x,y));
        window.clear();
        window.draw(sprite);
        window.display();
        
    }

    return 0;
}
