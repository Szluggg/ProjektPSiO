#include "gra.h"
#include "player.h"
#include "desblok.h"
#include<iostream>
#include<vector>


// prywatne funkcje
void gra::initVariables()
{
    this ->window = nullptr;

    //logika gry
    this->points = 0;
    this->maxPlayers = 4;

}
void gra::initTextures()
{
    if(!this->tloText.loadFromFile("tekstury/tlo.jpg"))
    {
        std::cout<<"blad - tekstura sie nie zaladowala" << std::endl;
    }
}

void gra::initSprites()
{
    this->tloSprite.setTexture(this->tloText);
}


void gra::initWindow()
{
    this->videomode.height = 800;
    this->videomode.width = 800;
    this ->window = new sf::RenderWindow(this->videomode, "Bomber", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(60);

}

void gra::initPlayers()
{
    this->player = new Player();
}

void gra::initDesblok()
{
    this->desblok = new desBlok();
}
void gra::initUndesblok()
{
    this->undesBlok = new undesblok();
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
    this->initTextures();
    this->initSprites();
    this->initPlayers();
    this->initEnemies();
    this->initDesblok();
    this->initUndesblok();
}
gra::~gra()
{
    delete this->window;
    delete this->player;
    delete this->desblok;
    delete this->undesBlok;
}

//akcesoria
const bool gra::dziala() const
{
    return this->window->isOpen();
}

//funkcje
void gra::killplayer()
{

}

void gra::bomb()
{

}





void gra::spawnEnemy1()
{
    this->enemy.setPosition(0, 750);
    this->enemy.setFillColor(sf::Color::Red);
    this->enemies.push_back(this->enemy);
}

void gra::spawnEnemy2()
{
    this->enemy.setPosition(750, 750);
    this->enemy.setFillColor(sf::Color::Blue);
    this->enemies.push_back(this->enemy);
}

void gra::spawnEnemy3()
{
    this->enemy.setPosition(750, 0);
    this->enemy.setFillColor(sf::Color::Yellow);
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
    if(this->enemies.size() < this->maxPlayers)
    {
        this->spawnEnemy1();
        this->spawnEnemy2();
        this->spawnEnemy3();
    }
}

//update
void gra::update()
{
    this->pollEvents();

    this->updateMousePositions();


    this->desblok->update();
    this->player->update(this->window);
    this->undesBlok->update();
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
    window->draw(this->tloSprite);
    this->initSprites();

    //rysuj przedmioty
    this->player->renderPlayers(this->window);
    this->renderEnemies();
    this->undesBlok->render(this->window);
    this->desblok->render(this->window);
    this->window->display();
}
