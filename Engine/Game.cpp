#include "MainWindow.h"
#include "Game.h"
#include "SpriteCodex.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	rng(rd()),			/////////// ORDER HERE DOESN'T MATTER ///////////
	xDist(0, 775),
	yDist(0, 575),
	vDist(-2, 2),
	box(xDist(rng), yDist(rng))
{
	//for (int i = 1; i < pooN; i++)						// Assert Test (Only Try In Debug Mode)
	for (int i = 0; i < pooN; i++) {
		int x = xDist(rng);
		int y = yDist(rng);
		//poo[i].Init(xDist(rng), yDist(rng), vDist(rng), vDist(rng));
		if (x >= 300 && x <= 400)
			x -= 100;
		else if (x >= 400 && x <= 500)
			x += 100;
		if (y >= 200 && y <= 300)
			y -= 100;
		else if (y >= 300 && y <= 400)
			y += 100;
		poo[i].Init(x, y, vDist(rng), vDist(rng));
	}
}

void Game::Go()
{
	gfx.BeginFrame();
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	////////////////////////////////////////////////	Game Start Check	////////////////////////////////////////////
	box.UpdateColor();
	if (isStarted && !gameOver)
	{
		if (wnd.kbd.KeyIsPressed(VK_CONTROL))
		{
			if (frameControl == 0)
			{
				////////////////////////////////////////////	 Dude Movement  	////////////////////////////////////////////

				if (wnd.kbd.KeyIsPressed(VK_SHIFT))
					dude.DudeMovement(wnd.kbd, 5);
				else
					dude.DudeMovement(wnd.kbd, 2);

				////////////////////////////////////////////	 Poo Mechanics     ////////////////////////////////////////////

				for (int i = 0; i < pooN; i++)
				{
					poo[i].PooMovement();
					poo[i].PooDudeCollision(dude);
					for (int j = 0; j < pooN; j++) {
						if (j == i)
							continue;
						poo[i].PooPooCollision(poo[j]);
					}
				}

				////////////////////////////////////////////	 Box Mechanics     ////////////////////////////////////////////

				box.BoxCollision(dude);
				frameControl++;
			}

			if (frameControl == timeSlowDown)
				frameControl = 0;
			else
				frameControl++;

		}


		else {
			////////////////////////////////////////////	 Dude Movement  	////////////////////////////////////////////

			if (wnd.kbd.KeyIsPressed(VK_SHIFT))
				dude.DudeMovement(wnd.kbd, 5);
			else
				dude.DudeMovement(wnd.kbd, 2);

			////////////////////////////////////////////	 Poo Mechanics     ////////////////////////////////////////////

			for (int i = 0; i < pooN; i++)
			{
				poo[i].PooMovement();
				poo[i].PooDudeCollision(dude);
				for (int j = 0; j < pooN; j++) {
					if (j == i)
						continue;
					poo[i].PooPooCollision(poo[j]);
				}
			}

			////////////////////////////////////////////	 Box Mechanics     ////////////////////////////////////////////

			box.BoxCollision(dude);

		}
	}
	else if (/*isStarted && */gameOver);
	else if (wnd.kbd.KeyIsPressed(VK_RETURN))
		isStarted = true;
}

void Game::ComposeFrame()
{
	//poo[0].Init(0, 0, 0, 0);							// Assert Test (Only Try In Debug Mode)

	if (isStarted && !gameOver && !meter.IsWin())
	{
		box.Draw(gfx);
		dude.Draw(gfx);
		for (int i = 0; i < pooN; i++) {
			poo[i].Draw(gfx);
			if (poo[i].IsCollided())
				gameOver = true;
		}
		if (box.IsCollided()) {
			box.ChangePosition(xDist(rng), yDist(rng));
			meter.Point();
		}
		meter.Draw(gfx);
	}
	else if (/*isStarted && */gameOver && !meter.IsWin()) {
		box.Draw(gfx);
		dude.Draw(gfx);
		for (int i = 0; i < pooN; i++)
			poo[i].Draw(gfx);
		meter.Draw(gfx);
		SpriteCodex::DrawGameOver(358, 268, gfx);
	}
	else if (meter.IsWin()) {
		gameOver = true;
		meter.Draw(gfx);
		SpriteCodex::DrawGameOver(358, 268, gfx);
	}
	else {
		SpriteCodex::DrawTitle(0, 0, gfx);
	}
}
