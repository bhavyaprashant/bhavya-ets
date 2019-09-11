#pragma once
#include"Graphics.h"
#include"Keyboard.h"

class Dude
{
public:

	void DudeMovement(const Keyboard& kbd, int speed);
	// Well it's not a good idea to pass keyboard here the player's movement shouldn't be fixed to just one input device.
	void Draw(Graphics& gfx) const;		// const here indicates that the member variables of this class will not be changed!
	// Graphic object cannot be passed by value as it conatains the game window etc. so only it's reference can be passed.
	int GetX() const;
	int GetY() const;
	/*
	static int GetWidth();				// Static functions can't be declared as const as they already don't have objects.
	static int GetHeight();				// A non-static function could also be made to access static data members. No problem in that.
	*/
	int GetWidth() const;				// Shouldn't make them as static as it will effect badly in case in future we try to  make
	int GetHeight() const;				// different dudes with different sizes. In that case, we'd have to make changes at many places

private:

	static constexpr int width = 20;
	static constexpr int height = 20;

	int x = 400;
	int y = 300;
};