#ifndef ENEMY_H
#define ENEMY_H

#include <SDL2/SDL.h>

class Enemy {

public:
	Enemy();
	Enemy(int height, int width, int x, int y);
	~Enemy();

	void move();

	int _height, _width, _x, _y, _yVel, _score;
private:

};


#endif
