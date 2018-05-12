#ifndef ROCKET_HPP
# define ROCKET_HPP


#include "AEntity.hpp"

class Rocket : public AEntity
{

	public:
	
		Rocket( unsigned int speed, unsigned int damage, unsigned int posX, unsigned int posY, bool isPlayer );
		Rocket( Rocket const & src );
		virtual ~Rocket( void );

		Rocket &			operator=( Rocket const & rhs );
	
		std::string				display();
		unsigned int			getDamage(void) const;

	private:

		unsigned int			_damage;
		bool					_isPlayer;	// true  = gauche vers droite
};											// false = droite vers gauche

#endif
