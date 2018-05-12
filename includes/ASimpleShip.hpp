#ifndef ASIMPLESHIP_HPP
# define ASIMPLESHIP_HPP

#include "IShip.hpp"
#include "AEntity.hpp"

class Rocket ;

class ASimpleShip : public IShip, public AEntity
{
	public:
	
		ASimpleShip( Weapon & weapon, unsigned int posX, unsigned int posY);
		ASimpleShip( ASimpleShip const & src , Weapon & weapon);
		virtual ~ASimpleShip( void );

		ASimpleShip &			operator=( ASimpleShip const & rhs );
	

		std::string				display();
		Rocket *				shoot(void);
		Weapon &				getWeapon(void) const;
		unsigned int			getValue( void ) const;

	private:
		Weapon &		_weapon;
		unsigned int	_value;
};

#endif
