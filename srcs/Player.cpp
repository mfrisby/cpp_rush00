#include "Player.hpp"
#include "Weapon.hpp"
#include <ctime>

// STATIC ########################################################

// ###############################################################

// CANONICAL #####################################################

Player::Player ( unsigned int number, Weapon * weapon, unsigned int posX, unsigned int posY ) : AEntity(), _number(number), _score(0), _weapon(weapon)
{
	srand(time(NULL));
	this->_posX = posX;
	this->_posY = posY;
	this->_sizeX = 4;
	this->_sizeY = 12;
	this->_life = 3;
	return ;
}

Player::Player ( Player const & src ) : AEntity(src)
{
	*this = src;
	return ;
}

Player &				Player::operator=( Player const & rhs )
{
	if (this != &rhs)
	{
		this->_number = rhs.getNumber();
		this->_life = rhs.getLife();
		this->_armor = rhs.getArmor();
		this->_speed = rhs.getSpeed();
		this->_score = rhs.getScore();
		this->_posX = rhs.getPosX();
		this->_posY = rhs.getPosY();
		this->_weapon = rhs.getWeapon();
	}
	return (*this);
}

Player::~Player ( void )
{
	delete this->_weapon;	
	return ;
}

// ###############################################################

// CONSTRUCTOR POLYMORPHISM ######################################


// ###############################################################

// OVERLOAD OPERATOR #############################################

// ###############################################################

// PUBLIC METHOD #################################################

std::string					Player::display( void )
{
	static std::string src[5] = {"   __\n   | |_____\n###[==_____>\n   |_|", "   __\n   | |_____\n ##[==_____>\n   |_|", "   __\n   | |_____\n# #[==_____>\n   |_|", "   __\n   | |_____\n## [==_____>\n   |_|", "   __\n   | |_____\n#  [==_____>\n   |_|"};
	
	return (src[rand()%5]);
}

void						Player::setWeapon(Weapon & weapon)
{
	delete this->_weapon;
	this->_weapon = &weapon;
	return ;
}

void						Player::addPointScore(unsigned int n)
{
	this->_score += n;
	return ;
}

Rocket	*					Player::shoot(void)
{
	unsigned int x = this->getPosX() + (this->getSizeX() / 2);
	return (this->_weapon->makeMissile(x, this->getMaxPosY() + 5));
}

unsigned int				Player::getNumber(void) const
{
	return (this->_number);
}
unsigned int				Player::getScore(void) const
{
	return (this->_score);
}
Weapon	*					Player::getWeapon(void) const
{
	return (this->_weapon);
}
// ###############################################################

// PRIVATE METHOD ################################################

// ###############################################################

// EXTERNAL ######################################################

// ###############################################################
