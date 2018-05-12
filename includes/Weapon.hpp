#ifndef WEAPON_HPP
# define WEAPON_HPP

class Rocket;

class Weapon
{
	public:
	
		Weapon( unsigned int speed, unsigned int damage, bool isPlayer);
		Weapon( Weapon const & src );
		virtual ~Weapon( void );

		Weapon &			operator=( Weapon const & rhs );
	
		Rocket	*			makeMissile(unsigned int posX, unsigned int posY);
		unsigned int		getDamage(void) const;
		unsigned int		getSpeed(void) const;
		bool				getIsPlayer(void) const;
	
	private:
		unsigned int	_damage;
		unsigned int	_speed;
		bool			_isPlayer;

};

#endif
