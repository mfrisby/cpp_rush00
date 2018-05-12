#include "Weapon.hpp"
#include "Rocket.hpp"

// STATIC ########################################################

// ###############################################################

// CANONICAL #####################################################

Weapon::Weapon ( unsigned int speed, unsigned int damage, bool isPlayer ) : _damage(damage), _speed(speed), _isPlayer(isPlayer)
{
	return ;
}

Weapon::Weapon ( Weapon const & src )
{
	*this = src;
	return ;
}

Weapon &				Weapon::operator=( Weapon const & rhs )
{
	if (this != &rhs)
	{
		this->_speed = rhs.getSpeed();
		this->_damage = rhs.getDamage();
		this->_isPlayer = rhs.getIsPlayer();
	}
	return (*this);
}

Weapon::~Weapon ( void )
{
	return ;
}

// ###############################################################

// CONSTRUCTOR POLYMORPHISM ######################################

// ###############################################################

// OVERLOAD OPERATOR #############################################

// ###############################################################

// PUBLIC METHOD #################################################

Rocket	*				Weapon::makeMissile(unsigned int posX, unsigned int posY)
{
	Rocket *r = new Rocket(this->_speed, this->_damage, posX, posY, this->_isPlayer);
	return (r);
}

unsigned int			Weapon::getDamage(void) const
{
	return (this->_damage);
}
unsigned int			Weapon::getSpeed(void) const
{
	return (this->_speed);
}
bool					Weapon::getIsPlayer(void) const
{
	return (this->_isPlayer);
}
// ###############################################################

// PRIVATE METHOD ################################################

// ###############################################################

// EXTERNAL ######################################################

// ###############################################################