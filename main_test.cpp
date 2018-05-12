#include "ABigShip.hpp"
#include "ASimpleShip.hpp"
#include "Weapon.hpp"
#include "Asteroid.hpp"
#include "Rocket.hpp"
#include "Player.hpp"
#include <iostream>
#include <iomanip>

int main(void)
{

	Weapon *w = new Weapon(2, 1, true); // speed, damage and belongs_to player
	Weapon *w2 = new Weapon(2, 1, false); // speed, damage and belongs_to player
	Player * p1 =  new Player(1, w, 50, 40); // number_player weapon, posX and posY
	ABigShip * s1 =  new ABigShip(*w2, 50, 40); // weapon, posX and posY
	ASimpleShip * s2 =  new ASimpleShip(*w2, 50, 40); // weapon, posX and posY
	Asteroid* a =  new Asteroid(20, 20); // weapon, posX and posY

	std::cout << "Player :\npos: x ==> " << p1->getPosX() << std::endl;
	std::cout << "pos: y ==> " << p1->getPosY() << std::endl;
	std::cout << "display :"  << std::endl << p1->display() << std::endl;

	p1->move(30, 30);
	std::cout << "speed      : " << p1->getSpeed() << std::endl;
	std::cout << "size ship  : x ==> " << p1->getSizeX() << " y ==> " << p1->getSizeY() << std::endl;
	std::cout << "center     : x ==> " << p1->getPosX() << " y ==> " << p1->getPosY() << std::endl;
	std::cout << "up left    : x ==> " << p1->getMinPosX() << " y ==> " << p1->getMinPosY() << std::endl;
	std::cout << "down left  : x ==> " << p1->getMinPosX() << " y ==> " << p1->getMaxPosY() << std::endl;
	std::cout << "up right   : x ==> " << p1->getMaxPosX() << " y ==> " << p1->getMinPosY() << std::endl;
	std::cout << "down right : x ==> " << p1->getMaxPosX() << " y ==> " << p1->getMaxPosY() << std::endl;

	std::cout << "\n\nBigShip :\npos: x ==> " << s1->getPosX() << std::endl;
	std::cout << "pos: y ==> " << s1->getPosY() << std::endl;
	std::cout << "display :"  << std::endl << s1->display() << std::endl;

	s1->move(40, 30);
	std::cout << "speed      : " << s1->getSpeed() << std::endl;
	std::cout << "size ship  : x ==> " << s1->getSizeX() << " y ==> " << s1->getSizeY() << std::endl;
	std::cout << "center     : x ==> " << s1->getPosX() << " y ==> " << s1->getPosY() << std::endl;
	std::cout << "up left    : x ==> " << s1->getMinPosX() << " y ==> " << s1->getMinPosY() << std::endl;
	std::cout << "down left  : x ==> " << s1->getMinPosX() << " y ==> " << s1->getMaxPosY() << std::endl;
	std::cout << "up right   : x ==> " << s1->getMaxPosX() << " y ==> " << s1->getMinPosY() << std::endl;
	std::cout << "down right : x ==> " << s1->getMaxPosX() << " y ==> " << s1->getMaxPosY() << std::endl;


	std::cout << "\n\nAsteroid :\npos: x ==> " << a->getPosX() << std::endl;
	std::cout << "pos: y ==> " << a->getPosY() << std::endl;
	std::cout << "display :"  << std::endl << a->display() << std::endl;
	a->move(40, 30);
	std::cout << "speed      : " << a->getSpeed() << std::endl;
	std::cout << "size ship  : x ==> " << a->getSizeX() << " y ==> " << a->getSizeY() << std::endl;
	std::cout << "center     : x ==> " << a->getPosX() << " y ==> " << a->getPosY() << std::endl;
	std::cout << "up left    : x ==> " << a->getMinPosX() << " y ==> " << a->getMinPosY() << std::endl;
	std::cout << "down left  : x ==> " << a->getMinPosX() << " y ==> " << a->getMaxPosY() << std::endl;
	std::cout << "up right   : x ==> " << a->getMaxPosX() << " y ==> " << a->getMinPosY() << std::endl;
	std::cout << "down right : x ==> " << a->getMaxPosX() << " y ==> " << a->getMaxPosY() << std::endl;

	std::cout << "\n\nSimpleShip :\npos: x ==> " << s2->getPosX() << std::endl;
	std::cout << "pos: y ==> " << s2->getPosY() << std::endl;
	std::cout << "display :"  << std::endl << s2->display() << std::endl;

	s2->move(20, 30);
	std::cout << "speed      : " << s2->getSpeed() << std::endl;
	std::cout << "size ship  : x ==> " << s2->getSizeX() << " y ==> " << s2->getSizeY() << std::endl;
	std::cout << "center     : x ==> " << s2->getPosX() << " y ==> " << s2->getPosY() << std::endl;
	std::cout << "up left    : x ==> " << s2->getMinPosX() << " y ==> " << s2->getMinPosY() << std::endl;
	std::cout << "down left  : x ==> " << s2->getMinPosX() << " y ==> " << s2->getMaxPosY() << std::endl;
	std::cout << "up right   : x ==> " << s2->getMaxPosX() << " y ==> " << s2->getMinPosY() << std::endl;
	std::cout << "down right : x ==> " << s2->getMaxPosX() << " y ==> " << s2->getMaxPosY() << std::endl;
	std::cout << "down right : x ==> " << s2->getMaxPosX() << " y ==> " << s2->getMaxPosY() << std::endl;
	std::cout << "\n\ncollision Player-Big         : " << p1->collision(s1) << std::endl;
	std::cout << "collision Big-Player         : " << s1->collision(p1) << std::endl;
	std::cout << "collision Player-Simple      : " << p1->collision(s2) << std::endl;
	std::cout << "collision Simple-Player      : " << s1->collision(p1) << std::endl;
	std::cout << "collision Big-Simple         : " << p1->collision(s2) << std::endl;
	std::cout << "collision Simple-Big         : " << s1->collision(p1) << std::endl;
	std::cout << "collision Player-Asteroid    : " << p1->collision(a) << std::endl;

	Rocket *r = p1->shoot();
	Rocket *r2 = s1->shoot();
	Rocket *r3 = s2->shoot();

	std::cout << "\n\nRocket Player   : x ==> " << r->getPosX() << " y ==> " << r->getPosY() << std::endl;
	std::cout << "Rocket Big      : x ==> " << r2->getPosX() << " y ==> " << r2->getPosY() << std::endl;
	std::cout << "Rocket Simple   : x ==> " << r3->getPosX() << " y ==> " << r3->getPosY() << std::endl;
	
	std::cout << "\n\nScore player          : " << p1->getScore() << std::endl;
	std::cout << "Value Simple (score)  : " << s2->getValue() << std::endl;
	std::cout << "Value Big (score)     : " << s1->getValue() << std::endl;
	p1->addPointScore(s1->getValue());
	p1->addPointScore(s2->getValue());
	std::cout << "Score player          : " << p1->getScore() << std::endl;
	std::cout << "\nLife player            : " << p1->getLife() << std::endl;
	std::cout << "Life Simple            : " << s2->getLife() << std::endl;
	std::cout << "Life Big               : " << s1->getLife() << std::endl;
	std::cout << "Life Asteroid          : " << a->getLife() << std::endl;
	p1->takeDamage(r3->getDamage());
	s2->takeDamage(r->getDamage());
	std::cout << "Life player            : " << p1->getLife() << std::endl;
	std::cout << "Life Simple            : " << s2->getLife() << std::endl;
	return (0);
}