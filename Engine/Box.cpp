#include "Box.h"

Box::Box(int x, int y) {
	this->x = x;
	this->y = y;
}

void Box::Draw(Graphics& gfx) const
{
	gfx.DrawRectDim(x, y, side, side, c);
}

void Box::BoxCollision(const Dude& dude)
{
	const int dudeRight = dude.GetX() + dude.GetWidth();
	//const int dudeRight = dude.GetX() + Dude::GetWidth();			// This can also be used instead of above statement.
	const int dudeBottom = dude.GetY() + dude.GetHeight();
	//const int dudeBottom = dude.GetY() + Dude::GetHeight();		// This can also be used instead of above statement.

	const int right = x + side;
	const int bottom = y + side;

	if (dude.GetX() <= right && dudeRight >= x && dude.GetY() <= bottom && dudeBottom >= y)
		isCollided = true;
}

bool Box::IsCollided() const
{
	return isCollided;
}

void Box::ChangePosition(int x, int y)
{
	this->x = x;
	this->y = y;
	isCollided = false;
}

void Box::UpdateColor()
{
	if (colorIncreasing) {
		if (c.GetR() >= 253) {
			colorIncreasing = false;
		}
		else {
			c = Color(c.GetR() + 2, c.GetG() + 4, c.GetB() + 4);
		}
	}
	else {
		if (c.GetR() <= 127) {
			colorIncreasing = true;
		}
		else {
			c = Color(c.GetR() - 2, c.GetG() - 4, c.GetB() - 4);
		}
	}
}
