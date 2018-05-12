#include "ABigShip.hpp"
#include "Weapon.hpp"
#include "Player.hpp"
#include <ctime>

// STATIC ########################################################

// ###############################################################

// CANONICAL #####################################################

ABigShip::ABigShip ( Weapon & weapon, unsigned int posX, unsigned int posY ) : AEntity(), _weapon(weapon)
{
	srand(time(NULL));
	this->_posX = posX;
	this->_posY = posY;
	this->_sizeX = 7;
	this->_sizeY = 17;
	this->_value = 50;
	this->_life = 100;
	return ;
}

ABigShip::ABigShip ( ABigShip const & src , Weapon & weapon) : AEntity(src), _weapon(weapon)
{
	*this = src;
	return ;
}

ABigShip &				ABigShip::operator=( ABigShip const & rhs )
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

ABigShip::~ABigShip ( void )
{
	return ;
}

// ###############################################################

// CONSTRUCTOR POLYMORPHISM ######################################

// ###############################################################

// OVERLOAD OPERATOR #############################################

// ###############################################################

// PUBLIC METHOD #################################################

std::string					ABigShip::display( void )
{
/*	static std::string src[4] = {"       ____,----._\n   ,--'| _|\" o;.  `.____        ____  ,,=====._\n .=|.':| o| ;:;:  .- \\,,`-.===='}.,'\\//       \"`\n-]=|;: |o |  ,.  (  :;)::(     ):;::>}X==========-\n `=| :;|  | ,: @  `-_/``,-`====.}___/\\       _,\n   `--.|__|_ .:  _,' \"\"\"              ``=====''\n       ~  ~`----'",
	"       ____,----._\n   ,--'| _|\" o;.  `.____        ____  ,,=====._\n .=|.':| @| ;:;:  .- \\,,`-.===='}.,'\\//       \"`\n(]=|;: |o |  ,.  (  :;)::(     ):;::>}====X======-\n `=| :;|  | ,: @  `-_/``,-`====.}___/\\       _,\n   `--.|__|_ .:  _,' \"\"\"              ``=====''\n       ~  ~`----'",
	"       ____,----._\n   ,--'| _|\" o;.  `.____        ____  ,,=====._\n .=|.':| @| ;:;:  .- \\,,`-.===='}.,'\\//       \"`\n(]=|;: |o |  ,.  (  :;)::(     ):;::>}========X==-\n `=| :;|  | ,: o  `-_/``,-`====.}___/\\       _,\n   `--.|__|_ .:  _,' \"\"\"              ``=====''\n       ~  ~`----'",
	"       ____,----._\n   ,--'| _|\" o;.  `.____        ____  ,,=====._\n .=|.':| o| ;:;:  .- \\,,`-.===='}.,'\\//       \"`\n(]=|;: |@ |  ,.  (  :;)::(     ):;::>}==========X-\n `=| :;|  | ,: o  `-_/``,-`====.}___/\\       _,\n   `--.|__|_ .:  _,' \"\"\"              ``=====''\n       ~  ~`----'"};

  */ 
   static std::string src = "    , Y  Y . \n   |        |\n   | ()  () |\n    .  ||  , \n8====|    |====8\n      UUUU      ";
   
   return (src);
}

Rocket	*					ABigShip::shoot(void)
{
	return (this->_weapon.makeMissile(this->getMinPosX(), this->getPosY() - 3 + (rand()%6)));
}

Weapon &					ABigShip::getWeapon(void) const
{
	return (this->_weapon);
}

unsigned int				ABigShip::getValue(void) const
{
	return (this->_value);
}
// ###############################################################

// PRIVATE METHOD ################################################

// ###############################################################

// EXTERNAL ######################################################

// ###############################################################
