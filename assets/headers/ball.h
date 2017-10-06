#ifndef BALL_H
#define BALL_H

#include <SDL2/SDL.h>
#include <iostream>
using namespace std;

class Ball {

public:
	Ball(int height, int width, int x, int y);
	~Ball();

	void move(SDL_Rect *player, SDL_Rect *enemy, SDL_Rect *ball);
	void collision(SDL_Rect *player, SDL_Rect *enemy, SDL_Rect *ball);
	int _x, _y, _xVel, _yVel, _height, _width;
};

#endif
