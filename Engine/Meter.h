#pragma once
#include "Graphics.h"

class Meter
{
public:
	void Draw(Graphics& gfx) {
		gfx.DrawRectDim(x, y, width, height, Colors::Green);
	}
	void Point() {
		width += jump;
		if (width >= Graphics::ScreenWidth - 1)
		{
			isWin = true;
			width = Graphics::ScreenWidth - 1;
		}
	}
	bool IsWin() {
		return isWin;
	}
private:
	static constexpr int x = 0;
	static constexpr int y = 5;
	int width = 0;
	static constexpr int height = 15;
	static constexpr int jump = 25;
	bool isWin = false;
};
