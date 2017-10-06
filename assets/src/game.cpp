#include "game.h"
#include "enemy.h"
#include "ball.h"
#include "player.h"
#include "globals.h"

#include <iostream>
#include <random>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
using namespace std;

SDL_Rect enemyRect;


SDL_Rect ballRect;
Ball ball(20, 20, (globals::SCREEN_WIDTH / 2) + 10, (globals::SCREEN_HEIGHT / 2) + 10);

SDL_Rect playerRect;
Player player(100, 20, 30, (globals::SCREEN_HEIGHT / 2) - 50);

Game::Game(const char* title, int x, int y, int width, int height, bool fullscreen) {
	int flags = 0;

	gameOver = false;
	if(fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if(SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		window = SDL_CreateWindow(title, x, y, width, height, flags);

		renderer = SDL_CreateRenderer(window, -1, 0);
		if(renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}

		isRunning = true;

		_enemy = Enemy(100, 20, (globals::SCREEN_WIDTH - 30) - 20, (globals::SCREEN_HEIGHT / 2) - 50);

		playerRect.x = player._x;
		playerRect.y = player._y;
		playerRect.w = player._width;
		playerRect.h = player._height;

		enemyRect.x = _enemy._x;
		enemyRect.y = _enemy._y;
		enemyRect.w = _enemy._width;
		enemyRect.h = _enemy._height;

		ballRect.x = ball._x;
		ballRect.y = ball._y;
		ballRect.w = ball._width;
		ballRect.h = ball._height;

	} else {
		isRunning = false;
	}
}

Game::~Game() {}

void Game::handleEvents() {
	SDL_Event event;
	const Uint8 *keyState = SDL_GetKeyboardState(NULL);


	if(keyState[SDL_SCANCODE_UP]) {
		player._y -= 5;
	}
	if(keyState[SDL_SCANCODE_DOWN]) {
		player._y += 5;
	}
	if(keyState[SDL_SCANCODE_ESCAPE]) {
		isRunning = false;
	}


	SDL_PollEvent(&event);

	switch(event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}

	score();


	// PLAYER, ENEMY, BALL
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, &playerRect);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, &enemyRect);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, &ballRect);


	// SCORE
	if(TTF_Init()==-1) {
	    printf("TTF_Init: %s\n", TTF_GetError());
	    exit(2);
	}

	TTF_Font * font = TTF_OpenFont("assets/fonts/Roboto-Regular.ttf", 50);
	SDL_Color color = { 255, 255, 255, 255 };

	string playerScore = to_string(player._score);
	string enemyScore = to_string(_enemy._score);
	string fullScore = playerScore + " - " + enemyScore;


	SDL_Surface * surface = TTF_RenderText_Solid(font,
			fullScore.c_str(), color);
	SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer,
	  surface);

	SDL_Rect scoreRect;
	scoreRect.x = (globals::SCREEN_WIDTH / 2) - (surface->w / 2);
	scoreRect.y = 10;
	scoreRect.w = surface->w;
	scoreRect.h = surface->h;


	SDL_RenderCopy(renderer, texture, NULL, &scoreRect);
	SDL_RenderPresent(renderer);

	TTF_CloseFont(font);
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
}

void Game::update() {
	_enemy.move();
	ball.move(&playerRect, &enemyRect, &ballRect);

	playerRect.x = player._x;
	playerRect.y = player._y;
	playerRect.w = player._width;
	playerRect.h = player._height;

	enemyRect.x = _enemy._x;
	enemyRect.y = _enemy._y;
	enemyRect.w = _enemy._width;
	enemyRect.h = _enemy._height;

	ballRect.x = ball._x;
	ballRect.y = ball._y;
	ballRect.w = ball._width;
	ballRect.h = ball._height;
}

void Game::render() {
	// SDL_RenderClear(renderer);
	// This is where we would add stuff to render
	// SDL_RenderPresent(renderer);
}

void Game::score() {
	bool scored = false;

	if(ball._x == 0) {
		_enemy._score += 1;
		scored = true;
	}

	if(ball._x == (globals::SCREEN_WIDTH-20)) {
		player._score += 1;
		scored = true;
	}

	if(scored) {
		ball._x = (globals::SCREEN_WIDTH / 2) + 10;
		ball._y = (globals::SCREEN_HEIGHT / 2) + 10;

		random_device rd;
		default_random_engine e1(rd());
		uniform_int_distribution<int> uniform_dist(0, 1);

		int randomVels[] = {2, -2};
		ball._xVel = randomVels[uniform_dist(e1)];
		ball._yVel = randomVels[uniform_dist(e1)];
	}

}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

bool Game::running() {
	return isRunning;
}

