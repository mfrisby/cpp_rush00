#ifndef PLAYER_HPP
# define PLAYER_HPP

#include "AEntity.hpp"

class Rocket;

class Player : public AEntity
{
	public:
	
		Player( unsigned int number, Weapon * weapon, unsigned int posX, unsigned int posY );
		Player( Weapon & weapon );
		Player( Player const & src );
		virtual ~Player( void );

		Player &			operator=( Player const & rhs );
	

		std::string				display();
		Rocket	*				shoot(void);

		void					setWeapon(Weapon & weapon);
		Weapon 	*				getWeapon(void) const;
		unsigned int			getNumber(void) const;
		unsigned int			getScore(void) const;
		void					addPointScore(unsigned int n);

	private:

		unsigned int	_number;
		unsigned int	_score;
		Weapon *		_weapon;
};

#endif
