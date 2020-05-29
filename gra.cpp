#include "gra.h"
#include<iostream>
#include<vector>


// prywatne funkcje
void gra::initVariables()
{
    this ->window = nullptr;

    //logika gry
    this->points = 0;
    this->maxEnemies = 4;

}

void gra::initWindow()
{
    this->videomode.height = 600;
    this->videomode.width = 800;
    this ->window = new sf::RenderWindow(this->videomode, "Bomber", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(60);
}

void gra::initEnemies()
{
    this->enemy.setPosition(0, 0);
    this->enemy.setSize(sf::Vector2f(100.f, 100.f));
    this->enemy.setScale(sf::Vector2f(0.5f, 0.5f));
    this->enemy.setFillColor((sf::Color::Red));
    this->enemy.setOutlineColor(sf::Color::Black);
    this->enemy.setOutlineThickness(1.f);


}
//Konsturktory i destruktory
gra::gra()
{
    this->initVariables();
    this->initWindow();
    this->initEnemies();
}
gra::~gra()
{
    delete this->window;
}

//akcesoria
const bool gra::dziala() const
{
    return this->window->isOpen();
}

//funkcje

void gra::spawnEnemy()
{
    this->enemy.setPosition(100, 50);
    this->enemy.setFillColor(sf::Color::Green);
    this->enemies.push_back(this->enemy);
}

void gra::pollEvents()
{
    while (this->window->pollEvent(this->ev))
    {
        switch(this->ev.type)
        {
        case sf::Event::Closed:
            this->window->close();
            break;
        case sf::Event::KeyPressed:
            if(this->ev.key.code == sf::Keyboard::Escape)
                this->window->close();
                break;
        }
    }
}

void gra::updateMousePositions()
{
this->mousePosWindow = sf::Mouse::getPosition(*this->window);
}

void gra::updateEnemies()
{
    if(this->enemies.size() < this->maxEnemies)
    {
        this->spawnEnemy();
    }

    //poruszanie sie
    // w nawiasach predkosci
    for(int i=0; i<this->enemies.size(); i++)
    {
        //granica
       this->enemies[i].move(0.f,0.f);
        if(this->enemies[i].getPosition().y < 0)
       {
             //sprawdzenie czy dotyka granicy mapy
       }
       else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
             this->enemies[i].move(0.f,-2.f);
        }

       if((this->enemies[i].getPosition().y)> 548)
       {
            //sprawdzenie czy dotyka granicy mapy
       }
       else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
       {
            this->enemies[i].move(0.f,2.f);
       }

       if((this->enemies[i].getPosition().x) > 748)
       {
             //sprawdzenie czy dotyka granicy mapy
       }
       else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
             this->enemies[i].move(2.f,0.f);
        }

       if(this->enemies[i].getPosition().x < 0)
       {
             //sprawdzenie czy dotyka granicy mapy
       }
       else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
             this->enemies[i].move(-2.f,0.f);
        }
        // pokazywanie pozycji
      // std::cout<< "(" << enemies[i].getPosition().x << ", " << enemies[i].getPosition().y << ")" << std::endl;
    }
}

void gra::update()
{
    this->pollEvents();

    this->updateMousePositions();

     this->updateEnemies();
}

void gra::renderEnemies()
{
    for(auto&e : this->enemies)
    {
        this->window->draw(e);
    }
}

void gra::render()
{
    //renderowanie gry i kolejnych rzeczy na ekranie

    this->window->clear(sf::Color(125, 161, 232, 255));

    //rysuj przedmioty
    this->renderEnemies();

    this->window->display();
}
