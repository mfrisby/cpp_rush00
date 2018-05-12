#ifndef AENTITY_HPP
# define AENTITY_HPP

#include <iostream>

class Weapon;

class AEntity
{
	public:
	
		AEntity( void );
		AEntity( Weapon & weapon );
		AEntity( AEntity const & src );
		virtual ~AEntity( void );

		AEntity &			operator=( AEntity const & rhs );
	

		bool					collision(AEntity* p);

		void					move(unsigned int x, unsigned int y);

		void					shoot(AEntity* p);

		void					takeDamage(unsigned int n);

		unsigned int			getLife(void) const;
		unsigned int			getArmor(void) const;
		unsigned int			getSpeed(void) const;
		unsigned int			getPosX(void) const;
		unsigned int			getPosY(void) const;
		unsigned int			getSizeX(void) const;
		unsigned int			getSizeY(void) const;
		unsigned int			getMinPosX(void) const;
		unsigned int			getMinPosY(void) const;
		unsigned int			getMaxPosX(void) const;
		unsigned int			getMaxPosY(void) const;

	protected:

		unsigned int	_life;
		unsigned int	_armor;
		unsigned int	_speed;
		unsigned int	_posX;
		unsigned int	_posY;
		unsigned int	_sizeX;
		unsigned int	_sizeY;
		int				_pStartX;
		int				_pStartY;
		int				_pEndX;
		int				_pEndY;
};

#endif
