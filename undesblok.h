#ifndef UNDESBLOK_H
#define UNDESBLOK_H
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <player.h>
class undesblok
{
private:
    Player playerclass;
    sf::Texture undesText;
    sf::Sprite undesSprite;

    void initText();
    void initSprite();
public:
    undesblok();
    ~undesblok();
    void render(sf::RenderTarget* target);
    void update();
    void granicablok();
};

#endif // UNDESBLOK_H
