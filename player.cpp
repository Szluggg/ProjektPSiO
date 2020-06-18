#include "player.h"
#include "gra.h"
#include<iostream>
#include<vector>


Player::Player()
{
    this->szybkosc = 2;
    this->initPlayers();
    this->initPlayerTextures();
    this->initPlayerSprites();

//    this->player.setPosition(x, y);
//    this->player.setSize(sf::Vector2f(100.f, 100.f));
//    this->player.setScale(sf::Vector2f(0.5f, 0.5f));
//    this->player.setFillColor((sf::Color::Red));

}

Player::~Player()
{

}
void Player::initPlayerTextures()
{
    if(!this->playTexture.loadFromFile("tekstury/player.png"))
    {
        std::cout << "Error - nie udalo sie zaladowac tekstury gracza" << std::endl;
    }
}

void Player::initPlayerSprites()
{
    this->playSprite.setTexture(this->playTexture);

    this->playSprite.scale(0.1f, 0.1f);
}

void Player::initPlayers()
{
//    this->player.setPosition(0, 0);
//    this->player.setSize(sf::Vector2f(100.f, 100.f));
//    this->player.setScale(sf::Vector2f(0.5f, 0.5f));
//    this->player.setFillColor((sf::Color::Red));

}

// spawnowanie gracza, przeciwnikow
void Player::spawnPlayers()
{
    this->player.setPosition(0,0);
//    this->player.setFillColor(sf::Color::Green);
    this->players.push_back(this->player);
}



void Player::move(const float X, const float Y)
{
    this->playSprite.move(this->szybkosc * X, this->szybkosc * Y);
}

void Player::updatePlayers()
{
    if(this->players.size() < this->maxPlayers)
    {
        this->spawnPlayers();
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
         this->move(0.f,-1.f);
    }
   else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
   {
        this->move(0.f,1.f);
   }
   if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
         this->move(1.f,0.f);
    }
   else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
         this->move(-1.f,0.f);
    }
}
void Player::updateBoundaries(const sf::RenderTarget* target)
{
    //granice planszy
    if(this->playSprite.getGlobalBounds().left <= 0.f)
    {
        this->playSprite.setPosition(0.f, this->playSprite.getGlobalBounds().top);
    }
    if (this->playSprite.getGlobalBounds().left + this->playSprite.getGlobalBounds().width >= target->getSize().x)
    {
        this->playSprite.setPosition(target->getSize().x - this->playSprite.getGlobalBounds().width, this->playSprite.getGlobalBounds().top);
    }
    if(this->playSprite.getGlobalBounds().top <= 0.f)
    {
        this->playSprite.setPosition(this->playSprite.getGlobalBounds().left, 0.f);
    }
    if (this->playSprite.getGlobalBounds().top + this->playSprite.getGlobalBounds().height >= target->getSize().y)
    {
        this->playSprite.setPosition(this->playSprite.getGlobalBounds().left, target->getSize().y - this->playSprite.getGlobalBounds().height);
    }

}
void Player::update(const sf::RenderTarget* target)
{
    this->updateBoundaries(target);

    this->updatePlayers();
}

void Player::renderPlayers(sf::RenderTarget* target)
{
//    window->draw(this->player);
 //   for(auto&e : this->players)
//    {
        target->draw(this->playSprite);
//    }
}

// Bomba
void Player::initBombText()
{
    if(!this->bombTexture.loadFromFile("tekstury/bomb.png"))
    {
        std::cout << "Error - tekstura bomby sie nie zaladowala" << std::endl;
    }
}
void Player::initBombSprit()
{
    this->bombSprite.setTexture(this->bombTexture);
}
void Player::bombradius(float x)
{

}
void Player::bomb()
{

}
void Player::spawnbomb()
{
    this->bombka.setPosition(player.getPosition().x, player.getPosition().y);
    this->bombka.setFillColor(sf::Color::Black);
    this->bomby.push_back(this->bombka);
}

void Player::playerbomb()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::E))
    {
        this->spawnbomb();
    }
}
