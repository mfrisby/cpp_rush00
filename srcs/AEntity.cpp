#include "AEntity.hpp"
#include "Weapon.hpp"
#include "ABigShip.hpp"
#include "ASimpleShip.hpp"

// STATIC ########################################################

// ###############################################################

// CANONICAL #####################################################

AEntity::AEntity ( void ) : _life(1), _armor(0), _speed(1), _posX(0), _posY(0), _sizeX(0), _sizeY(0)
{
	return ;
}

AEntity::AEntity ( AEntity const & src )
{
	*this = src;
	return ;
}

AEntity &				AEntity::operator=( AEntity const & rhs )
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

AEntity::~AEntity ( void )
{
	return ;
}

// ###############################################################

// CONSTRUCTOR POLYMORPHISM ######################################

// ###############################################################

// OVERLOAD OPERATOR #############################################

// ###############################################################

// PUBLIC METHOD #################################################

bool						AEntity::collision(AEntity* p)
{
	if (this->getMinPosX() >= p->getMinPosX() && this->getMinPosX() <=  p->getMaxPosX()
		&& this->getMinPosY() >= p->getMinPosY() && this->getMinPosY() <=  p->getMaxPosY() )
		return (true);
	if (this->getMinPosX() >= p->getMinPosX() && this->getMinPosX() <=  p->getMaxPosX()
		&& this->getMaxPosY() >= p->getMinPosY() && this->getMaxPosY() <=  p->getMaxPosY() )
		return (true);
	if (this->getMaxPosX() >= p->getMinPosX() && this->getMaxPosX() <=  p->getMaxPosX()
		&& this->getMinPosY() >= p->getMinPosY() && this->getMinPosY() <=  p->getMaxPosY() )
		return (true);
	if (this->getMaxPosX() >= p->getMinPosX() && this->getMaxPosX() <=  p->getMaxPosX()
		&& this->getMaxPosY() >= p->getMinPosY() && this->getMaxPosY() <=  p->getMaxPosY() )
		return (true);
	return (false);
}

void						AEntity::shoot(AEntity* p)
{
	(void)p;
	return ;
}

void						AEntity::move(unsigned int x, unsigned int y)
{
	this->_posX = x;
	this->_posY = y;
}

void						AEntity::takeDamage(unsigned int n)
{
	this->_life -= n;
	/*int damage;

	damage = n ;//- this->_armor;
	if ((int)this->_life >= damage)
		this->_life -= n;
	else
		this->_life = 0;*/
	return ;
}

unsigned int				AEntity::getLife(void) const
{
	return (this->_life);
}
unsigned int				AEntity::getArmor(void) const
{
	return (this->_armor);
}
unsigned int				AEntity::getSpeed(void) const
{
	return (this->_speed);
}
unsigned int				AEntity::getPosX(void) const
{
	return (this->_posX);
}
unsigned int				AEntity::getPosY(void) const
{
	return (this->_posY);
}
unsigned int				AEntity::getSizeX(void) const
{
	return (this->_sizeX);
}
unsigned int				AEntity::getSizeY(void) const
{
	return (this->_sizeY);
}
unsigned int				AEntity::getMinPosX(void) const
{
	if (this->_sizeX == 1)
		return this->_posX;
	return (this->_posX - (this->_sizeX / 2));
}
unsigned int				AEntity::getMinPosY(void) const
{
	if (this->_sizeY == 1)
		return this->_posY;
	return (this->_posY - (this->_sizeY / 2));
}
unsigned int				AEntity::getMaxPosX(void) const
{
	if (this->_sizeX == 1)
		return this->_posX;
	return (this->_posX + (this->_sizeX / 2));
}
unsigned int				AEntity::getMaxPosY(void) const
{
	if (this->_sizeY == 1)
		return this->_posY;
	return (this->_posY + (this->_sizeY / 2));
}
// ###############################################################

// PRIVATE METHOD ################################################

// ###############################################################

// EXTERNAL ######################################################

// ###############################################################
