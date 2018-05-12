#ifndef ABIGSHIP_HPP
# define ABIGSHIP_HPP

#include "IShip.hpp"
#include "AEntity.hpp"

class Rocket ;

class ABigShip : public IShip, public AEntity
{
	public:
	
		ABigShip( Weapon & weapon, unsigned int posX, unsigned int posY );
		ABigShip( ABigShip const & src, Weapon & weapon );
		virtual ~ABigShip( void );

		ABigShip &			operator=( ABigShip const & rhs );

		std::string				display();
		Rocket *				shoot(void);
		Weapon &				getWeapon(void) const;
		unsigned int			getValue( void ) const;

	private:
		Weapon &		_weapon;
		unsigned int	_value;

};

#endif
