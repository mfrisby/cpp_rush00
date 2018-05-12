#include "ASimpleShip.hpp"
#include "Player.hpp"
#include "Weapon.hpp"
#include <ctime>

// STATIC ########################################################

// ###############################################################

// CANONICAL #####################################################

ASimpleShip::ASimpleShip ( Weapon & weapon, unsigned int posX, unsigned int posY ) : AEntity(), _weapon(weapon)
{
	this->_posX = posX;
	this->_posY = posY;
	this->_sizeX = 4;
	this->_sizeY = 8;
	this->_value = 5;
	this->_life = 10;
	//this->_pStartX = posX;
	//this->_pStartY = posY;
	//this->_pEndX = posX + 8;
	//this->_pEndY = posY + 4;
	return ;
}

ASimpleShip::ASimpleShip ( ASimpleShip const & src, Weapon & weapon) : AEntity(src), _weapon(weapon)
{
	*this = src;
	return ;
}

ASimpleShip &				ASimpleShip::operator=( ASimpleShip const & rhs )
{
	if (this != &rhs)
	{
		this->_life = rhs.getLife();
		this->_armor = rhs.getArmor();
		this->_speed = rhs.getSpeed();
		this->_posX = rhs.getPosX();
		this->_posY = rhs.getPosY();
	}
	return (*this);
}

ASimpleShip::~ASimpleShip ( void )
{
	return ;
}

// ###############################################################

// CONSTRUCTOR POLYMORPHISM ######################################

// ###############################################################

// OVERLOAD OPERATOR #############################################

// ###############################################################

// PUBLIC METHOD #################################################

std::string					ASimpleShip::display( void )
{
	static std::string src[2] = {"  __\n<(o )___\n ( ._> /\")\n  `---' ", "  __\n<(- )___\n ( ._> /\"\n  `---' "};
   return (src[rand() % 2]);
}

Rocket	*					ASimpleShip::shoot(void)
{
	return (this->_weapon.makeMissile(this->getMinPosX(), this->getPosY()));
}

Weapon &					ASimpleShip::getWeapon(void) const
{
	return (this->_weapon);
}

unsigned int				ASimpleShip::getValue(void) const
{
	return (this->_value);
}
// ###############################################################

// PRIVATE METHOD ################################################

// ###############################################################

// EXTERNAL ######################################################

// ###############################################################
