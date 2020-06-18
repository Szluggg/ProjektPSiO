#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class Player
{


private:
    friend class gra;
    friend class undesblok;
    // obiekty
        Player* gracz;

        sf::Texture playTexture;
        sf::Sprite playSprite;
        std::vector<sf::RectangleShape> players;
        sf::RectangleShape player;
        std::vector<sf::CircleShape> bomby;
        sf::CircleShape bombka;

        float szybkosc;
        sf::Texture bombTexture;
        sf::Sprite bombSprite;

        //prywatne funkcje
            void initPlayerTextures();
            void initPlayerSprites();
            void initPlayers();
            void initBombText();
            void initBombSprit();
public:

    //kontruktory i destruktory
    Player();
    virtual ~Player();
    int maxPlayers = 4;

// funkcje
    void bombradius(float x);
    void bomb();
    void spawnbomb();
    void playerbomb();

    void spawnPlayers();
    void move(const float X, const float Y);
    void killplayer();
    void updatePlayers();
    void updateBoundaries(const sf::RenderTarget* target);
    void update(const sf::RenderTarget* target);
    void renderPlayers(sf::RenderTarget* target);
};
#endif // PLAYER_H
