#pragma once
#include "Graphics.h"
#include "Dude.h"
#include <assert.h>

class Poo
{
public:

	//Poo(int x, int y, int vx, int vy);		// Can't be used for arrays. So will have let default constructors do their work.
	void Init(int x, int y, int vx, int vy);
	void PooMovement();
	void PooDudeCollision(const Dude& dude);		// dude can be passed by value or by reference!
	void PooPooCollision(const Poo& pooN);
	void Draw(Graphics& gfx) const;		// const here indicates that the member variables of this class will not be changed!
	// Graphic object cannot be passed by value as it conatains the game window etc. so only it's reference can be passed.
	bool IsCollided() const;
	int GetX() const;
	int GetY() const;
	int GetWidth() const;
	int GetHeight() const;

private:

	static constexpr int width = 24;
	static constexpr int height = 24;

	int x;
	int y;
	int vx;
	int vy;
	bool isCollided = false;
	bool isPooPooCollided = false;
	bool isInit = false;
};
