#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Dude.h"
#include "Poo.h"
#include "Box.h"
#include "Meter.h"
#include <random>

class Game
{
public:
	Game(class MainWindow& wnd);
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	void DrawTitle(int x, int y);
	void DrawGameOver(int x, int y);
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	std::random_device rd;									////////ORDER MATTERS/////////
	std::mt19937 rng;
	std::uniform_int_distribution<int> xDist;
	std::uniform_int_distribution<int> yDist;
	std::uniform_int_distribution<int> vDist;
	bool isStarted = false;
	Dude dude;
	Box box;
	Meter meter;
	static constexpr int pooN = 25;
	Poo poo[pooN];
	bool gameOver = false;
	int timeSlowDown = 2;									// timeSlowDown X slowdown
	int frameControl = 0;
	/********************************/
};