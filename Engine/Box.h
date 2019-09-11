#pragma once
#include "Graphics.h"
#include "Dude.h"

class Box
{
public:
	Box(int x, int y);
	void Draw(Graphics& gfx) const;
	void BoxCollision(const Dude& dude);
	bool IsCollided() const;
	void ChangePosition(int x, int y);
	void UpdateColor();
private:
	static constexpr int side = 28;
	//Color c = Colors::Red;
	Color c = { 127,0,0 };
	int x;
	int y;
	bool isCollided = false;
	bool colorIncreasing = true;
};