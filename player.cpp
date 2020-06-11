#include "player.h"
#include "gra.h"
#include<iostream>
#include<vector>


Player::Player()
{
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
    if(!this->playTexture.loadFromFile("C:/Users/Krzysztof/Documents/psio/bomber/tekstury/player.png"))
    {
        std::cout << "Error - nie udalo sie zaladowac tekstury gracza" << std::endl;
    }
}

void Player::initPlayerSprites()
{
    this->playSprite.setTexture(this->playTexture);

    this->playSprite.scale(0.25f, 0.25f);
}

void Player::initPlayers()
{
    this->player.setPosition(0, 0);
    this->player.setSize(sf::Vector2f(100.f, 100.f));
    this->player.setScale(sf::Vector2f(0.5f, 0.5f));
    this->player.setFillColor((sf::Color::Red));

}

// spawnowanie gracza, przeciwnikow
void Player::spawnPlayers()
{
    this->player.setPosition(0,0);
    this->player.setFillColor(sf::Color::Green);
    this->players.push_back(this->player);
}

void Player::updateBoundaries(const sf::RenderTarget* target)
{

}

void Player::updatePlayers()
{
    if(this->players.size() < this->maxPlayers)
    {
        this->spawnPlayers();
    }

    //poruszanie sie
    // w nawiasach predkosci
    for(int i=0; i<this->players.size(); i++)
    {
        //granica
       this->players[i].move(0.f,0.f);
        if(this->players[i].getPosition().y <= 0)
       {
             //sprawdzenie czy dotyka granicy mapy
       }
       else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
             this->players[i].move(0.f,-2.f);
        }

      if((this->players[i].getGlobalBounds().top)>= (800  - (players[i].getSize().y)/2))
      {
            //sprawdzenie czy dotyka granicy mapy
       }
       else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
       {
            this->players[i].move(0.f,2.f);
       }

       if((this->players[i].getPosition().x) >= (800  - (players[i].getSize().x)/2))
       {
             //sprawdzenie czy dotyka granicy mapy
       }
       else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
             this->players[i].move(2.f,0.f);
        }

       if(this->players[i].getPosition().x <= 0)
       {
             //sprawdzenie czy dotyka granicy mapy
       }
       else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
             this->players[i].move(-2.f,0.f);
        }
        // pokazywanie pozycji
       std::cout<< "(" << players[i].getPosition().x << ", " << players[i].getPosition().y << ")" << std::endl;
    }
}

void Player::update(const sf::RenderTarget* target)
{
//    this->updateBoundaries(target);
    this->updatePlayers();
}

void Player::renderPlayers(sf::RenderTarget* target)
{
//    window->draw(this->player);
    for(auto&e : this->players)
    {
        target->draw(e);
    }
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
