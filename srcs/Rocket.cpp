#include "Rocket.hpp"

// STATIC ########################################################

// ###############################################################

// CANONICAL #####################################################

Rocket::Rocket ( unsigned int speed, unsigned int damage, unsigned int posX, unsigned int posY, bool isPlayer ) : AEntity(), _damage(damage)
{
	this->_speed = speed;
	this->_posX = posX;
	this->_posY = posY;
	this->_sizeX = 1;
	this->_sizeY = 1;
	this->_isPlayer = isPlayer;
	return ;
}

Rocket::Rocket ( Rocket const & src ) : AEntity(src)
{
	*this = src;
	return ;
}

Rocket &				Rocket::operator=( Rocket const & rhs )
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

Rocket::~Rocket ( void )
{
	return ;
}

// ###############################################################

// CONSTRUCTOR POLYMORPHISM ######################################

// ###############################################################

// OVERLOAD OPERATOR #############################################

// ###############################################################

// PUBLIC METHOD #################################################

std::string					Rocket::display( void )
{
   return ((std::string)"-");
}

unsigned int				Rocket::getDamage( void ) const
{
	return (this->_damage);
}
// ###############################################################

// PRIVATE METHOD ################################################

// ###############################################################

// EXTERNAL ######################################################

// ###############################################################