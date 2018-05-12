#ifndef ISHIP_HPP
# define ISHIP_HPP

#include <iostream>

class Rocket ;

class IShip
{
	public:
		virtual ~IShip() {}

		virtual Rocket			* shoot( void ) = 0;
		virtual unsigned int	getValue( void ) const = 0;
};

#endif
