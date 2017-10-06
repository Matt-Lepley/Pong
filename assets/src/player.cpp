#include "player.h"

Player::Player(int height, int width, int x, int y) {
	_height = height;
	_width = width;
	_x = x;
	_y = y;
	_yVel = 0;
	_score = 0;
}

Player::~Player() {

}
