#include "enemy.h"
#include "globals.h"
#include <SDL2/SDL.h>

#include <iostream>
using namespace std;

Enemy::Enemy(){};

Enemy::Enemy(int height, int width, int x, int y) {
	_height = height;
	_width = width;
	_x = x;
	_y = y;
	_yVel = 5;
	_score = 0;
}

Enemy::~Enemy(){}

void Enemy::move(){
	if(_y == 0) {
		_yVel = 5;
	}
	if(_y == (globals::SCREEN_HEIGHT-100)) {
		_yVel = -5;
	}

	_y += _yVel;
}
