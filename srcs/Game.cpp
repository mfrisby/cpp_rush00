#include "Game.hpp"

Game::Game (){
    initscr();              // Initialise la structure WINDOW et autres paramètres 
    cbreak();               //disable buffering of typed characters
    noecho();               //n'affiche pas les touches
    nodelay(stdscr,TRUE);    //getch() non bloquant 
    keypad(stdscr, TRUE);   //capture speical keystrokes
    curs_set(0);//curseur invisible
    this->_nbEnemies = 0;
    this->_nbRockets = 0;
    this->_endGame = false;
    start_color();			/* Start color 			*/
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
    init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(5, COLOR_GREEN, COLOR_BLACK);

}
Game::Game( Game const & src ){
	*this = src;
	return ;
}
Game::~Game( void ){
    endwin();
}

/**************************************/
/**              SCREEN              **/
/**************************************/

bool    Game::setScreenValues(){
    int r, c;
    getmaxyx( stdscr, r, c);
    if (r < 50 || c < 200)
        return false;
    this->_screenY = 200;
    this->_screenX = 50;
    return true;
}

/**************************************/
/**              DRAW                **/
/**************************************/
void    Game::draw(){
    this->setScreenValues();
    clear();
    this->drawBox();
    this->drawPlayer();
    this->drawEnnemies();
    this->drawRockets();
    this->drawScore();
}

void    Game::drawScore(){
    attron(COLOR_PAIR(5));
    const char *score = "Score: ";
    const char *life = "Life: ";

    std::string s = std::to_string(this->_player->getScore());
    this->_cursorX = 5;
    this->_cursorY = 10;//this->_screenY - (s.length()) - 5 - 8;
    this->setCursor();

    char *cstr = new char[s.length() + 1];
    strcpy(cstr, s.c_str());
    addstr(score);
    this->_cursorY += 8;
    this->setCursor();
    addstr(cstr);

    std::string s1 = std::to_string(this->_player->getLife());
    this->_cursorX = 3;
    this->_cursorY = 10;
    this->setCursor();
    char *cstr1 = new char[s1.length() + 1];
    strcpy(cstr1, s1.c_str());
    addstr(life);
    this->_cursorY += 8;
    this->setCursor();
    addstr(cstr1);
    attroff(COLOR_PAIR(5));
}

void    Game::drawShip(std::string s, int x, int y){
    this->_cursorX = x;
    this->_cursorY = y;
    this->setCursor();
    char*toDisplay = this->NSplit(s);
    while (toDisplay != NULL){
        addstr(toDisplay);
        toDisplay = std::strtok(NULL, "\n");
        setCursorDown();
    }
}

void    Game::drawEnnemies(){
    attron(COLOR_PAIR(2));
    int i = 0;
    while (i < this->_nbEnemies){
        this->drawShip(this->_enemies[i]->display(), this->_enemies[i]->getPosX(), this->_enemies[i]->getPosY());
        i++;
    }
    attroff(COLOR_PAIR(2));
}

void    Game::drawRockets(){
    attron(COLOR_PAIR(1));
    int i = 0;
    while (i < this->_nbRockets){
        this->drawShip(this->_rockets[i]->display(), this->_rockets[i]->getPosX(), this->_rockets[i]->getPosY());
        i++;
    }
    attroff(COLOR_PAIR(1));
}

void    Game::drawPlayer(){
    attron(COLOR_PAIR(1));
    this->drawShip(this->_player->display(), this->_player->getPosX(), this->_player->getPosY());
    attroff(COLOR_PAIR(1));
}

void    Game::drawStars(){
    int x = (rand()% 45) + 2;
    int y = (rand()% 190) + 2;
    move(x, y);
    attron(COLOR_PAIR(4));
    addstr(".");
    attroff(COLOR_PAIR(4));
}

void    Game::drawBox(){
    move(0, 0);
    attron(COLOR_PAIR(4));
    vline('*', this->_screenX);
    hline('*', this->_screenY);    
    move(0, this->_screenY-1);
    vline('*', this->_screenX-1);
    move(this->_screenX-1, 0);
    hline('*', this->_screenY-1);
    attroff(COLOR_PAIR(4));
    this->_cursorX = 0;
    this->_cursorY = 0;
    setCursor();
}
char*    Game::NSplit(std::string s){

    char*toDisplay;
    char *cstr = new char[s.length() + 1];
    strcpy(cstr, s.c_str());
    toDisplay = std::strtok(cstr, "\n");
    return toDisplay;
}
/**************************************/
/**              CURSOR              **/
/**************************************/

void    Game::setCursor(){
    move(this->_cursorX, this->_cursorY);
}
void Game::setCursorDown(){
    this->_cursorX += 1;
    setCursor();
}

/**************************************/
/**              TIME                **/
/**************************************/

void    Game::checkTime(){
    this->_time = std::clock();// / 30000;
    if ((this->_time / 30000) - (this->_timeSaved / 30000) > 0){
        this->enemiesMove();
        this->rocketsMove();
        this->draw();
        this->_timeSaved = this->_time;
    }
    if ((this->_time / 100000)- (this->_timeSavedE / 100000)> 1) {
        this->enemiesAppend();
        this->_timeSavedE = this->_time;
    }
    if ((this->_time / 10000) - (this->_timeSaved / 10000) > 1){
        this->drawStars();
    }
}
void    Game::initTime(){
    this->_time = std::clock() /  (CLOCKS_PER_SEC / 2);
    this->_timeSaved = this->_time;
    this->_timeSavedE = this->_time;
}


/**************************************/
/**           COLLISION              **/
/**************************************/

bool    Game::checkEnemiesCollision(){
    int i =0;
    ASimpleShip **e = _enemies;
    while (i < _nbEnemies)
    {
        if (_player->collision(e[i])) {
            this->_player->takeDamage(1);
            this->deleteEnemie(i);
        }
        if (this->_player->getLife() == 0)
            return true;
        i++;
    }
    return false;

}
void    Game::checkBulletCollision(){
    Rocket **r = _rockets;
    ASimpleShip **e = _enemies;
    int i =0;
    int y =0;
    while (y < _nbRockets)
    {
        while (i < _nbEnemies) 
        {
            if (r[y]->collision(e[i]))
            {
                this->deleteEnemie(i);
                this->deleteRocket(y);
                this->_player->addPointScore(1);
                this->draw();
            }
            i++;
        }
        i = 0;
        y++;
    }
}

/**************************************/
/**              OBJETS              **/
/**************************************/

void    Game::enemiesMove(){
    int i = 0;
    while (i < this->_nbEnemies){
        if ((int)this->_enemies[i]->getPosY() <= 0){
            deleteEnemie(i);
        }
        else{
            this->_enemies[i]->move(this->_enemies[i]->getPosX(), this->_enemies[i]->getPosY()-1);
            this->_endGame = checkEnemiesCollision();
        }
        i++;
    }
}
void    Game::rocketsMove(){
    int i = 0;
    while (i < this->_nbRockets){
        if ((int)this->_rockets[i]->getPosY() == (int)_screenY - 2){
            deleteRocket(i);
        }
        else{
            this->_rockets[i]->move(this->_rockets[i]->getPosX(), this->_rockets[i]->getPosY()+1);
            checkBulletCollision();
        }
        i++;
    }
}
void    Game::deleteRocket(int i){
    Rocket **rs = new Rocket*[_nbRockets - 1];
    int index = 0;
    int index2= 0;
    while (index2 < this->_nbRockets){
        if (index2 != i) {
            rs[index] = _rockets[index2];
        }
        else{
            index2++;
            continue;
        }
        index++;
        index2++;
    }
    _rockets = rs;
    this->_nbRockets -= 1;
}
void    Game::deleteEnemie(int i){
    ASimpleShip **enemies = new ASimpleShip*[this->_nbEnemies -1];
    int index = 0;
    int index2= 0;

    while (index2 < this->_nbEnemies){
        if (index2 != i) {
            enemies[index] = _enemies[index2];
        }
        else{
            index2++;
            continue;
        }
        index++;
        index2++;
    }
    _enemies = enemies;
    this->_nbEnemies -= 1;
}

void    Game::enemiesAppend(){
    this->_nbEnemies += 1;

    int x = rand() % 40;
    x += 5;
	Weapon *w2 = new Weapon(2, 1, false); // new weapon for ennemy
	ASimpleShip * s2 =  new ASimpleShip(*w2, x, this->_screenY - 20); // new ennemy
    ASimpleShip **enemies = new ASimpleShip*[this->_nbEnemies];
    this->_cursorY = this->_screenY - 20;
    this->setCursor();

    int i = 0;
    while (i < this->_nbEnemies - 1){
        enemies[i] = _enemies[i];
        i++;
    }
    enemies[i] = s2;
    _enemies = enemies;
}
void    Game::playerShoot(){
    this->_nbRockets += 1;

    Rocket *r = _player->shoot();  
    Rocket **rs = new Rocket*[_nbRockets];  
    
    int i = 0;
    while (i < this->_nbRockets - 1){
        rs[i] = _rockets[i];
        i++;
    }
    rs[i] = r;
    _rockets = rs;
}

void    Game::playerAppend(){
    Weapon *w = new Weapon(2, 1, true);
    this->_player = new Player(0, w, this->_screenX / 2, 5);
    this->_cursorX = this->_screenX / 2;
    this->_cursorY = 5;
    this->setCursor();
}

/**************************************/
/**              GAME                **/
/**************************************/

void    Game::checkKeys(int ch){
    if (ch == KEY_RIGHT){
        if ((int)_player->getPosY() < _screenY - 13){
            _player->move(_player->getPosX(), _player->getPosY() + 1);
            this->_endGame = checkEnemiesCollision();
            draw();
        }
    }
     if (ch == KEY_LEFT){
        if ((int)_player->getPosY() > 1){
            _player->move(_player->getPosX(), _player->getPosY() - 1);
            this->_endGame = checkEnemiesCollision();
            draw();
        }
    }
     if (ch == KEY_UP){
        if ((int)_player->getPosX() > 1){
            _player->move(_player->getPosX() - 1, _player->getPosY());
            this->_endGame = checkEnemiesCollision();
            draw();
        }
    }
     if (ch == KEY_DOWN){
        if ((int)_player->getPosX() < _screenX - 5){
            _player->move(_player->getPosX() + 1, _player->getPosY());
            draw();
        }
    }
    if (ch == 32)
    {
        playerShoot();   
    }
}

void    Game::playerLoose(){
    clear();
    this->_cursorX = (this->_screenX / 2) - 11;
    this->_cursorY = this->_screenY / 2;
    this->setCursor();
    nodelay(stdscr,FALSE);    //getch() non bloquant 
    addstr("You loose!");
    setCursorDown();
    addstr("Press escape to quit.");
    while (getch() != 27){}
}

int    Game::gameLoop(){
    if (!this->setScreenValues()){
        return -1;
    }
    int ch = getch();
    this->initTime();
    this->playerAppend();
    this->enemiesAppend();
    this->draw();
    while (42) {
        if (ch == 27) {
            return 0;//escape key
        }
        if (this->_endGame) {
            this->playerLoose();
            return 0;
        }
        if (!this->setScreenValues())
            {return -1;}
        checkKeys(ch);
        this->checkTime();
        ch = getch();
    }
}

Game &				Game::operator=( Game const & rhs )
{
	if (this != &rhs){
		this->_pause = rhs._pause;
	}
	return (*this);
}
