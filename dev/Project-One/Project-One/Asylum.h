#pragma once

#include <vector>
#include "Room.h"
#include <iostream>

class Asylum
{
public:
	Asylum();
	Asylum(int _width, int _height);

	Room& GetRoom(int row, int col);
	int GetWidth() const;
	int GetHeight() const;
	bool IsValidPosition(int row, int col) const;
	void BuildLayout();
	void PrintMap(int playerRow, int playerCol);

private:
	std::vector<std::vector<Room>> grid;
	int width;
	int height;
};