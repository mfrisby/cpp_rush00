#ifndef ASTEROID_HPP
# define ASTEROID_HPP

#include "AEntity.hpp"

class Asteroid : public AEntity
{
	public:
	
		Asteroid( unsigned int posX, unsigned int posY );
		Asteroid( Asteroid const & src);
		virtual ~Asteroid( void );

		Asteroid &			operator=( Asteroid const & rhs );

		unsigned int		getValue(void) const;
		std::string			display( void );
	
	private:
		unsigned int	_value;

};

#endif
