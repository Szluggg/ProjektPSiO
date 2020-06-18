#include "desblok.h"
#include <vector>
desBlok::desBlok()
{
    this->initText();
    this->initSprite();
    this->initBlok();
}
desBlok::~desBlok()
{

}
void desBlok::initBlok()
{
    this->blok.setPosition(160, 0);
    this->blok.setSize(sf::Vector2f(100.f, 100.f));
    this->blok.setScale(sf::Vector2f(0.5f, 0.5f));
    this->blok.setFillColor((sf::Color::Red));
    this->bloczki.push_back(this->blok);
}
void desBlok::initText()
{
    if(!this->desText.loadFromFile("tekstury/desblok.png"));
    {
        std::cout<<"ERROR - nie wczytano tekstury - desblok.png"<< std::endl;
    }
}
void desBlok::initSprite()
{
    this->desSprite.setTexture(this->desText);
    this->desSprite.scale(0.8f, 0.8f);
}

void desBlok::spawn()
{
    this->blok.setPosition(160,0);
}
void desBlok::update()
{
    this->spawn();
}

void desBlok::render(sf::RenderTarget* target)
{

    //pierwszy rzad
    this->desSprite.setPosition(160, 0);
    target->draw(this->desSprite);
    this->desSprite.setPosition(320, 0);
    target->draw(this->desSprite);
    this->desSprite.setPosition(400, 0);
    target->draw(this->desSprite);
    this->desSprite.setPosition(560, 0);
    target->draw(this->desSprite);
    //drugi rzad
    this->desSprite.setPosition(80, 80);
    target->draw(this->desSprite);
    this->desSprite.setPosition(240, 80);
    target->draw(this->desSprite);
    this->desSprite.setPosition(320, 80);
    target->draw(this->desSprite);
    this->desSprite.setPosition(400, 80);
    target->draw(this->desSprite);
    this->desSprite.setPosition(480, 80);
    target->draw(this->desSprite);
    this->desSprite.setPosition(640, 80);
    target->draw(this->desSprite);
    //trzeci rzad
    this->desSprite.setPosition(80, 160);
    target->draw(this->desSprite);
    this->desSprite.setPosition(240, 160);
    target->draw(this->desSprite);
    this->desSprite.setPosition(320, 160);
    target->draw(this->desSprite);
    this->desSprite.setPosition(400, 160);
    target->draw(this->desSprite);
    this->desSprite.setPosition(480, 160);
    target->draw(this->desSprite);
    this->desSprite.setPosition(640, 160);
    target->draw(this->desSprite);
}

void desBlok::placeholder(sf::RenderTarget* target)
{
    //pierwszy rzad
    this->desSprite.setPosition(160, 0);
    target->draw(this->desSprite);
    this->desSprite.setPosition(320, 0);
    target->draw(this->desSprite);
    this->desSprite.setPosition(400, 0);
    target->draw(this->desSprite);
    this->desSprite.setPosition(560, 0);
    target->draw(this->desSprite);
    //drugi rzad
    this->desSprite.setPosition(80, 80);
    target->draw(this->desSprite);
    this->desSprite.setPosition(240, 80);
    target->draw(this->desSprite);
    this->desSprite.setPosition(320, 80);
    target->draw(this->desSprite);
    this->desSprite.setPosition(400, 80);
    target->draw(this->desSprite);
    this->desSprite.setPosition(480, 80);
    target->draw(this->desSprite);
    this->desSprite.setPosition(640, 80);
    target->draw(this->desSprite);
    //trzeci rzad
    this->desSprite.setPosition(80, 160);
    target->draw(this->desSprite);
    this->desSprite.setPosition(240, 160);
    target->draw(this->desSprite);
    this->desSprite.setPosition(320, 160);
    target->draw(this->desSprite);
    this->desSprite.setPosition(400, 160);
    target->draw(this->desSprite);
    this->desSprite.setPosition(480, 160);
    target->draw(this->desSprite);
    this->desSprite.setPosition(640, 160);
    target->draw(this->desSprite);
}
