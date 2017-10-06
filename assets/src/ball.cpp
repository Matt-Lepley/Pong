#include "ball.h"
#include "globals.h"

Ball::Ball(int height, int width, int x, int y) {
	_height = height;
	_width = width;
	_x = x;
	_y = y;
	_yVel = 2;
	_xVel = -2;
}

Ball::~Ball() {

}

void Ball::move(SDL_Rect *player, SDL_Rect *enemy, SDL_Rect *ball) {

	if(_x == 0 || _x == (globals::SCREEN_WIDTH - 20)) {
		_xVel *= -1;
	}
	if(_y == 0 || _y == (globals::SCREEN_HEIGHT - 20)) {
		_yVel *= -1;
	}

	collision(player, enemy, ball);

	_x += _xVel;
	_y += _yVel;
}

void Ball::collision(SDL_Rect *player, SDL_Rect *enemy, SDL_Rect *ball) {

	if(SDL_HasIntersection(player, ball)) {
		_xVel *= -1;
		_x += _xVel;
	}

	if(SDL_HasIntersection(enemy, ball)) {
		_xVel *= -1;
		_x += _xVel;
	}

}

