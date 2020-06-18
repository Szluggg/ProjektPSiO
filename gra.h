#ifndef GRA_H
#define GRA_H
#include <player.h>
#include <desblok.h>
#include <undesblok.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

// Klasa ktora dziala jako silnik gry


class gra
{
private:
//gracz
    Player* player;
    desBlok* desblok;
    undesblok* undesBlok;
    void initPlayers();

//variables


//window
    sf::RenderWindow* window;
    sf::VideoMode videomode;
    sf::Event ev;


// obiekty

    std::vector<sf::RectangleShape> enemies;
    sf::RectangleShape enemy;



    sf::Texture tloText;
    sf::Sprite tloSprite;


//Pozycje kursora
    sf::Vector2i mousePosWindow;

// logika gry
    int points;
    float maxPlayers;

//prywatne funkcje
    void initTextures();
    void initSprites();
    void initVariables();
    void initWindow();
    void initEnemies();
    void initDesblok();
    void initUndesblok();
public:


    //kontruktory i destruktory
    gra();
    virtual ~gra();

    //akcesoria
    const bool dziala() const;

    //funkcje
    void spawnEnemy1();
    void spawnEnemy2();
    void spawnEnemy3();

    void spawnDesblok();

    void pollEvents();

    void bomb();


    void killenemy1();
    void killenemy2();
    void killenemy3();
    void killplayer();

    void updateMousePositions();
    void updateEnemies();
    void updatePlayers();

    void update();


    void renderDesblok();
    void renderPlayers();
    void renderEnemies();
    void render();

};



#endif // GRA_H
