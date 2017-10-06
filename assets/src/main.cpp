#include "game.h"
#include "globals.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {

	Game game("MyGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			globals::SCREEN_WIDTH, globals::SCREEN_HEIGHT, false);

	const int FPS = 60;
	const int MAX_FRAME_TIME = 1000 / FPS;

	int LAST_UPDATE = SDL_GetTicks();

	while(game.running()) {

		game.handleEvents();
		game.update();

		int CURRENT_TIME = SDL_GetTicks();
		int ELAPSED_TIME = CURRENT_TIME - LAST_UPDATE;

		if (ELAPSED_TIME < MAX_FRAME_TIME) {
			SDL_Delay(MAX_FRAME_TIME - ELAPSED_TIME);
		}
		game.render();

		LAST_UPDATE = CURRENT_TIME;
	}

	game.clean();

	return 0;
}
