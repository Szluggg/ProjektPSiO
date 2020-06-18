#include "undesblok.h"

undesblok::undesblok()
{
    this->initText();
    this->initSprite();
}
undesblok::~undesblok()
{

}
void undesblok::initText()
{
    this->undesText.loadFromFile("tekstury/undesblok.png");
}
void undesblok::initSprite()
{
    this->undesSprite.setTexture(this->undesText);
    this->undesSprite.setScale(0.8f, 0.8f);
}
void undesblok::granicablok()
{
    if(playerclass.playSprite.getGlobalBounds().intersects(undesSprite.getGlobalBounds()))
    {
        playerclass.move(0,0);
    }
}
void undesblok::update()
{
    this->granicablok();
}
void undesblok::render(sf::RenderTarget* target)
{
    this->undesSprite.setPosition(160, 160);
    target->draw(this->undesSprite);
    this->undesSprite.setPosition(240, 240);
    target->draw(this->undesSprite);
    this->undesSprite.setPosition(560, 160);
    target->draw(this->undesSprite);
    this->undesSprite.setPosition(480, 240);
    target->draw(this->undesSprite);
    this->undesSprite.setPosition(160, 560);
    target->draw(this->undesSprite);
    this->undesSprite.setPosition(240, 480);
    target->draw(this->undesSprite);
    this->undesSprite.setPosition(480, 480);
    target->draw(this->undesSprite);
    this->undesSprite.setPosition(560, 560);
    target->draw(this->undesSprite);
}
