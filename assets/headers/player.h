#ifndef PLAYER_H
#define PLAYER_H

class Player {

public:

	Player(int height, int width, int x, int y);
	~Player();

	void move();

	int _height, _width, _x, _y, _yVel, _score;
private:


};

#endif
