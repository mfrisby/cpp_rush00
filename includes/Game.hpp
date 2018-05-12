#ifndef GAME_HPP
# define GAME_HPP

#include <ncurses.h>
#include "ABigShip.hpp"
#include "ASimpleShip.hpp"
#include "Weapon.hpp"
#include "Asteroid.hpp"
#include "Rocket.hpp"
#include "Player.hpp"
#include "Game.hpp"
#include <iostream>
class Game
{
	public:
	
		Game();
		Game( Game const & src );
		~Game( void );

		Game &			operator=( Game const & rhs );
        int            gameLoop(void);
        bool            setScreenValues();
        void            checkTime();
        void            initTime();
        void            playerAppend();
        void            enemiesAppend();
        void            enemiesMove();
        void            rocketsMove();
        void            checkBulletCollision();
        bool            checkEnemiesCollision();
        void            deleteRocket(int i);
        void            deleteEnemie(int i);
        void            playerShoot();
        void            playerLoose();
        void            checkKeys(int ch);
        /**************************************/
        /**              DRAW                **/
        /**************************************/
        void            drawShip(std::string s, int x, int y);
        void            drawPlayer();
        void            drawEnnemies();
        void            drawRockets();
        void            drawScore();
        void            drawStars();
        char            *NSplit(std::string s);
        void            draw();
        void            drawBox();
        void            setCursor();
        void            setCursorDown();

    private:
        bool            _pause;
        int             _cursorX;
        int             _cursorY;
        int             _screenX;
        int             _screenY;
        int             _time;
        int             _timeSaved;
        int             _timeSavedE;
        ASimpleShip     **_enemies;
        Rocket          **_rockets;
        int             _nbRockets;
        int             _nbEnemies;
        Player          *_player;
        bool            _endGame;
};

#endif
