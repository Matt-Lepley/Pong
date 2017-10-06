#ifndef GAME_H
#define GAME_H

#include "enemy.h"

#include <SDL2/SDL.h>

class Game {

public:
	Game(const char* title, int x, int y, int width, int height, bool fullscreen);
	~Game();

	void handleEvents();
	void update();
	void render();
	void clean();

	void score();
	bool running();

private:
	bool isRunning;
	bool gameOver;

	SDL_Window* window;
	SDL_Renderer* renderer;

	Enemy _enemy;
};

#endif
