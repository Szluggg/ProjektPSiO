#ifndef GRA_H
#define GRA_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

// Klasa ktora dziala jako silnik gry


class gra
{
private:

//variables


//window
    sf::RenderWindow* window;
    sf::VideoMode videomode;
    sf::Event ev;


    // obiekty
    std::vector<sf::RectangleShape> enemies;
    sf::RectangleShape enemy;


    //Pozycje kursora
    sf::Vector2i mousePosWindow;

    // logika gry
    int points;
    float maxEnemies;

//prywatne funkcje
    void initVariables();
    void initWindow();
    void initEnemies();

public:

    //kontruktory i destruktory
    gra();
    virtual ~gra();

    //akcesoria
    const bool dziala() const;

    //funkcje
    void spawnEnemy();

    void pollEvents();
    void updateMousePositions();
    void updateEnemies();
    void update();

    void renderEnemies();
    void render();

};

#endif // GRA_H
