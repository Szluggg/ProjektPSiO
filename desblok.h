#ifndef DESBLOK_H
#define DESBLOK_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
class desBlok
{
private:

        sf::Texture desText;
        sf::Sprite desSprite;
        std::vector<sf::RectangleShape> bloczki;
        sf::RectangleShape blok;
        void initText();
        void initSprite();
        void initBlok();
public:
    desBlok();
    ~desBlok();
    void spawn();
    void update();
    void render(sf::RenderTarget* target);
    void placeholder(sf::RenderTarget* target);
};

#endif // DESBLOK_H
